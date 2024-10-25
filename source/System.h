#pragma once

// Type definitions
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;

typedef signed char s8;
typedef signed short s16;
typedef signed long s32;
typedef signed long long s64;

typedef float f32;
typedef double f64;

// ASM definitions
#define r0 % r0
#define r1 % r1
#define sp % r1
#define r2 % r2
#define toc % r2
#define r3 % r3
#define r4 % r4
#define r5 % r5
#define r6 % r6
#define r7 % r7
#define r8 % r8
#define r9 % r9
#define r10 % r10
#define r11 % r11
#define r12 % r12
#define r13 % r13
#define r14 % r14
#define r15 % r15
#define r16 % r16
#define r17 % r17
#define r18 % r18
#define r19 % r19
#define r20 % r20
#define r21 % r21
#define r22 % r22
#define r23 % r23
#define r24 % r24
#define r25 % r25
#define r26 % r26
#define r27 % r27
#define r28 % r28
#define r29 % r29
#define r30 % r30
#define r31 % r31

#define f0 0
#define f1 1
#define f2 2
#define f3 3
#define f4 4
#define f5 5
#define f6 6
#define f7 7
#define f8 8
#define f9 9
#define f10 10
#define f11 11
#define f12 12
#define f13 13
#define f14 14
#define f15 15
#define f16 16
#define f17 17
#define f18 18
#define f19 19
#define f20 20
#define f21 21
#define f22 22
#define f23 23
#define f24 24
#define f25 25
#define f26 26
#define f27 27
#define f28 28
#define f29 29
#define f30 30
#define f31 31

#define PRAGMA _Pragma

#define offsetof(_TYPE, _MEMBER) __builtin_offsetof(_TYPE, _MEMBER)

#define ASM(...) __asm__(#__VA_ARGS__)

#define ASM_FUNCTION(_PROTOTYPE, ...)                                                              \
    [[__gnu__::__naked__]] _PROTOTYPE                                                              \
    {                                                                                              \
        ASM(__VA_ARGS__);                                                                          \
    }

#define ASM_METHOD(...)                                                                            \
    __attribute__((__naked__)) {                                                                   \
        ASM(__VA_ARGS__);                                                                          \
    }

typedef struct {
    unsigned int* addr;
    unsigned int* dest;
} __replace_struct;

struct __replace_struct_int {
    unsigned int* addr;
    void (*dest)();
};

typedef struct {
    unsigned int* addr;
    unsigned int size;
    unsigned int* dest;
} _MRel_ReplaceRel;

typedef struct {
    unsigned int* addr;
    unsigned int size;
    unsigned int* dest;
} _MRel_InsertData;

#define address(_ADDRESS) _Clang::__external__(#_ADDRESS)

#define _REPLACE_THUNK(_ADDR)                                                                      \
    [[__gnu__::__section__("replaced")]] void __replaced_func_##_ADDR()                            \
    {                                                                                              \
        __builtin_unreachable();                                                                   \
    }                                                                                              \
    extern unsigned int __ext_##_ADDR __asm__("ext_" #_ADDR);                                      \
    [[__gnu__::__section__("replace_array"                                                         \
    )]] constinit __replace_struct_int __replace_entry_##_ADDR = {                                 \
      &__ext_##_ADDR, &__replaced_func_##_ADDR                                                     \
    };

#if 0
#  define REPLACE(_ADDR, _PROTOTYPE)                                                               \
      _REPLACE_THUNK(_ADDR)                                                                        \
      [[__gnu__::__section__("replaced")]] _PROTOTYPE

#  define REPLACE_ASM(_ADDR, _PROTOTYPE, ...)                                                      \
      _REPLACE_THUNK(_ADDR)                                                                        \
      [[__gnu__::__section__("replaced")]] [[__gnu__::__naked__]] _PROTOTYPE                       \
      {                                                                                            \
          ASM(__VA_ARGS__);                                                                        \
      }
#else
#  define REPLACE(_ADDR, _PROTOTYPE) [[_Clang::external(#_ADDR)]] _PROTOTYPE

#  define REPLACE_ASM(_ADDR, _PROTOTYPE, ...)                                                      \
      [[_Clang::external(#_ADDR)]] [[gnu::naked]] _PROTOTYPE                                       \
      {                                                                                            \
          ASM(__VA_ARGS__);                                                                        \
      }

#endif

#define _REPLACE_THUNK_DATA(_ADDR, _LENGTH)                                                        \
    [[__gnu__::__section__("replaced")]] void __replaced_func_##_ADDR()                            \
    {                                                                                              \
        __builtin_unreachable();                                                                   \
    }                                                                                              \
    extern unsigned int __ext_##_ADDR __asm__("ext_" #_ADDR);                                      \
    [[__gnu__::__section__("replace_data_array")]]                                                 \
    constinit _MRel_ReplaceRel __replace_data_entry_##_ADDR = {                                    \
      &__ext_##_ADDR, _LENGTH, reinterpret_cast<unsigned int*>(&__replaced_func_##_ADDR)           \
    };

#define REPLACE_DATA(_ADDR, _LENGTH, ...)                                                          \
    _REPLACE_THUNK_DATA(_ADDR, _LENGTH)                                                            \
    [[__gnu__::__section__("replaced")]] __VA_ARGS__

#define INSERT_DATA(_ADDR, _LENGTH, ...)                                                           \
    extern "C" {                                                                                   \
    extern unsigned int ext_##_ADDR;                                                               \
    extern unsigned int replaced_data_##_ADDR;                                                     \
    __attribute__((__section__(".replinsertarray"))                                                \
    ) _MRel_InsertData _MRel_InsertData_##_ADDR = {&ext_##_ADDR, _LENGTH, &replaced_data_##_ADDR}; \
    }                                                                                              \
    asm(".section .replaced." #_ADDR "\n"                                                          \
        ".global replaced_data_" #_ADDR "\n"                                                       \
        ".p2align 2\n"                                                                             \
        "replaced_data_" #_ADDR ":\n");                                                            \
    __attribute__((__section__(".replaced." #_ADDR))) __VA_ARGS__

#if 0

#  define EXTERN_TEXT(_ADDR, _PROTOTYPE)                                                           \
      PRAGMA("clang diagnostic push")                                                              \
      PRAGMA("clang diagnostic ignored \"-Wreturn-type\"")                                         \
      [[__gnu__::__section__(".external." #_ADDR)]] [[__gnu__::__weak__]] _PROTOTYPE               \
      {                                                                                            \
          __builtin_unreachable();                                                                 \
      }                                                                                            \
      PRAGMA("clang diagnostic pop")

#else

#  define EXTERN_TEXT(_ADDR, _PROTOTYPE) [[_Clang::external(#_ADDR)]] _PROTOTYPE
#endif

#define EXTERN_TEXT_INLINE(_ADDR, _PROTOTYPE)                                                      \
    [[__gnu__::__section__(".external." #_ADDR)]] _PROTOTYPE

#define EXTERN_TEXT_STATIC(_ADDR, _PROTOTYPE) EXTERN_TEXT(_ADDR, _PROTOTYPE)

#define EXTERN_REPL(_ADDR, _PROTOTYPE)                                                             \
    [[__gnu__::__section__("extern")]] void __extern_func_##_ADDR()                                \
    {                                                                                              \
        __builtin_unreachable();                                                                   \
    }                                                                                              \
    PRAGMA("clang diagnostic push")                                                                \
    PRAGMA("clang diagnostic ignored \"-Wreturn-type\"")                                           \
    [[__gnu__::__section__("extern")]] [[__gnu__::__weak__]] [[__gnu__::__naked__]] _PROTOTYPE     \
    {                                                                                              \
        ASM(nop; b ext_##_ADDR + 4;);                                                              \
    }                                                                                              \
    PRAGMA("clang diagnostic pop")                                                                 \
    extern unsigned int __ext2_##_ADDR __asm__("ext_" #_ADDR);                                     \
    [[__gnu__::__section__("extern_array")]]                                                       \
    constinit __replace_struct_int __extern_entry_##_ADDR = {                                      \
      &__ext2_##_ADDR, &__extern_func_##_ADDR                                                      \
    };

#define EXTERN_TEXT_C(_ADDR, _PROTOTYPE) EXTERN_TEXT(_ADDR, extern "C" _PROTOTYPE)

#define EXTERN_DATA(_ADDR, _PROTOTYPE) [[__gnu__::__section__(".external." #_ADDR)]] _PROTOTYPE

#define EXTERN_TEXT_CONSTRUCTOR(_ADDR, _PROTOTYPE) EXTERN_TEXT(_ADDR, _PROTOTYPE)

/**
 * Define an external function by its symbol name only
 */
#define EXTERN_SYMBOL(_ADDR, _NAME)                                                                \
    void __ext_sym_##_ADDR() asm(_NAME);                                                           \
    [[__gnu__::__section__(".external." #_ADDR)]] void __ext_sym_##_ADDR()                         \
    {                                                                                              \
        __builtin_unreachable();                                                                   \
    }

#define FILL(_START, _END) u8 _##_START[_END - _START]

#define INCBIN(_FILE, _NAME)                                                                       \
    extern "C" u8 _NAME[];                                                                         \
    extern "C" u32 _NAME##_size;                                                                   \
    asm(".section .rodata\n"                                                                       \
        ".global " #_NAME "\n"                                                                     \
        "" #_NAME ":\n"                                                                            \
        ".incbin " #_FILE "\n"                                                                     \
        ".global " #_NAME "_size\n"                                                                \
        "" #_NAME "_size:\n"                                                                       \
        ".long . - " #_NAME "\n")

template <class T>
constexpr T ToUncached(T addr)
{
    u32 addrVal = u32(addr);
    addrVal |= 0xC0000000;
    return (T) addrVal;
}

#define restrict __restrict

struct [[__gnu__::__packed__]] __offset_assert {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wzero-length-array"
    int empty[0];
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

template <class T>
struct __get_this {
    typedef T type;
};

template <class T>
struct __get_this<T&> {
    typedef T type;
};

#define OFFSET_ASSERT(_OFFSET)                                                                     \
    __offset_assert _offset_assert_##_OFFSET = []() -> __offset_assert {                           \
        PRAGMA("clang diagnostic push")                                                            \
        PRAGMA("clang diagnostic ignored \"-Winvalid-offsetof\"")                                  \
        static_assert(                                                                             \
          __builtin_offsetof(__get_this<decltype(*this)>::type, _offset_assert_##_OFFSET) ==       \
          _OFFSET                                                                                  \
        );                                                                                         \
        PRAGMA("clang diagnostic pop") return __offset_assert{};                                   \
    }()