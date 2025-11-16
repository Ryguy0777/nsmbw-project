#pragma once

#include "Asm.h"
#include "Types.h"

#define PRAGMA(...) _Pragma(#__VA_ARGS__)

#define address(_ADDRESS) _Clang::__external__(#_ADDRESS)

#define address_data(_ADDRESS) __gnu__::__section__(".external." #_ADDRESS)

struct _MRel_replace_array_entry {
    unsigned int* addr;
    unsigned int* dest;
};

struct _MRel_extern_array_entry {
    unsigned int* addr;
    void (*dest)();
};

#define EXTERN_TEXT_INLINE(_ADDR, _PROTOTYPE)                                                      \
    [[__gnu__::__section__(".external." #_ADDR)]] _PROTOTYPE

#define EXTERN_REPL(_ADDR, _PROTOTYPE)                                                             \
    [[__gnu__::__section__("extern")]] void _MRel_extern_func_##_ADDR()                            \
    {                                                                                              \
        __builtin_unreachable();                                                                   \
    }                                                                                              \
    PRAGMA(clang diagnostic push)                                                                  \
    PRAGMA(clang diagnostic ignored "-Wreturn-type")                                               \
    [[__gnu__::__section__("extern")]] [[__gnu__::__weak__]] [[__gnu__::__naked__]] _PROTOTYPE     \
    {                                                                                              \
        ASM(nop; b ext_##_ADDR + 4;);                                                              \
    }                                                                                              \
    PRAGMA(clang diagnostic pop)                                                                   \
    extern unsigned int _MRel_ext2_##_ADDR __asm__("ext_" #_ADDR);                                 \
    [[__gnu__::__section__("extern_array")]] [[__gnu__::__used__]]                                 \
    constinit _MRel_extern_array_entry _MRel_extern_array_entry_##_ADDR = {                        \
      &_MRel_ext2_##_ADDR, &_MRel_extern_func_##_ADDR                                              \
    };

/**
 * Define an external function by its symbol name only
 */
#define EXTERN_SYMBOL(_ADDR, _NAME)                                                                \
    void __ext_sym_##_ADDR() asm(_NAME);                                                           \
    [[__gnu__::__section__(".external." #_ADDR)]] void __ext_sym_##_ADDR()                         \
    {                                                                                              \
        __builtin_unreachable();                                                                   \
    }

#define FILL(_START, _END) u8 __##_START[_END - _START]

#define restrict __restrict

struct [[__gnu__::__packed__]] __offset_assert {
    template <class T>
    struct utype;

    template <class T>
    struct utype<T*> {
        using type = T;
    };

    template <class T>
    using u = utype<T>::type;

    template <unsigned Offset, unsigned ExpectedOffset>
    static consteval __offset_assert test()
    {
        static_assert(Offset == ExpectedOffset);
        return {};
    }

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wzero-length-array"
    [[no_unique_address]] int empty[0];
#pragma clang diagnostic pop
};

static_assert(sizeof(__offset_assert) == 0);

#define _SIZE_ASSERT3(_SIZE, _COUNTER)                                                             \
    constexpr void __size_assert_##_COUNTER()                                                      \
    {                                                                                              \
        static_assert(__datasizeof(*this) == _SIZE);                                               \
    }

#define _SIZE_ASSERT2(_SIZE, _COUNTER) _SIZE_ASSERT3(_SIZE, _COUNTER)

#define _SIZE_ASSERT1(_SIZE, _COUNTER) _SIZE_ASSERT2(_SIZE, _COUNTER)

#define SIZE_ASSERT(_SIZE) _SIZE_ASSERT2(_SIZE, __COUNTER__)

#define OFFSET_ASSERT(_OFFSET)                                                                     \
    [[no_unique_address]] __offset_assert __assert_##_OFFSET = __offset_assert::test<              \
      __builtin_offsetof(__offset_assert::u<decltype(this)>, __assert_##_OFFSET), _OFFSET>()

#define BIT_FLAG(_BIT) (1 << _BIT)

#define REMOVED(_NAME) Removed_##_NAME
