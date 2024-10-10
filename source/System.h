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

#define offsetof(_TYPE, _MEMBER) __builtin_offsetof(_TYPE, _MEMBER)

#define ASM(...) asm(#__VA_ARGS__)

#define ASM_FUNCTION(_PROTOTYPE, ...)                                                              \
    __attribute__((naked)) _PROTOTYPE                                                              \
    {                                                                                              \
        ASM(__VA_ARGS__);                                                                          \
    }

typedef struct {
    unsigned int* addr;
    unsigned int* dest;
} __replace_struct;

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

#define REPLACE(addr, prototype)                                                                   \
    extern "C" {                                                                                   \
    extern unsigned int ext_##addr;                                                                \
    extern unsigned int replaced_func_##addr;                                                      \
    __attribute__((__section__(".replarray")))                                                     \
    __replace_struct replstruct_##addr = {&ext_##addr, &replaced_func_##addr};                     \
    asm(".section .replaced." #addr "\n"                                                           \
        ".global replaced_func_" #addr "\n"                                                        \
        ".p2align 2\n"                                                                             \
        "replaced_func_" #addr ":\n");                                                             \
    }                                                                                              \
    __attribute__((__section__(".replaced." #addr))) prototype

#define REPLACE_ASM(addr, prototype, ...)                                                          \
    extern "C" {                                                                                   \
    extern unsigned int ext_##addr;                                                                \
    extern unsigned int replaced_func_##addr;                                                      \
    __attribute__((__section__(".replarray")))                                                     \
    __replace_struct replstruct_##addr = {&ext_##addr, &replaced_func_##addr};                     \
    asm(".section .replaced." #addr "\n"                                                           \
        ".global replaced_func_" #addr "\n"                                                        \
        ".p2align 2\n"                                                                             \
        "replaced_func_" #addr ":\n");                                                             \
    }                                                                                              \
    __attribute__((__section__(".replaced." #addr))) __attribute__((__naked__)) prototype          \
    {                                                                                              \
        ASM(__VA_ARGS__);                                                                          \
    }

#define REPLACE_DATA(_ADDR, _LENGTH, ...)                                                          \
    extern "C" {                                                                                   \
    extern unsigned int ext_##_ADDR;                                                               \
    extern unsigned int replaced_data_##_ADDR;                                                     \
    __attribute__((__section__(".replrelarray")))                                                  \
    _MRel_ReplaceRel _MRel_ReplaceRel_##_ADDR = {&ext_##_ADDR, _LENGTH, &replaced_data_##_ADDR};   \
    }                                                                                              \
    asm(".section .replaced." #_ADDR "\n"                                                          \
        ".global replaced_data_" #_ADDR "\n"                                                       \
        ".p2align 2\n"                                                                             \
        "replaced_data_" #_ADDR ":\n");                                                            \
    __attribute__((__section__(".replaced." #_ADDR))) __VA_ARGS__

#define INSERT_DATA(_ADDR, _LENGTH, ...)                                                           \
    extern "C" {                                                                                   \
    extern unsigned int ext_##_ADDR;                                                               \
    extern unsigned int replaced_data_##_ADDR;                                                     \
    __attribute__((__section__(".replinsertarray")))                                               \
    _MRel_InsertData _MRel_InsertData_##_ADDR = {&ext_##_ADDR, _LENGTH, &replaced_data_##_ADDR};   \
    }                                                                                              \
    asm(".section .replaced." #_ADDR "\n"                                                          \
        ".global replaced_data_" #_ADDR "\n"                                                       \
        ".p2align 2\n"                                                                             \
        "replaced_data_" #_ADDR ":\n");                                                            \
    __attribute__((__section__(".replaced." #_ADDR))) __VA_ARGS__

#define EXTERN_TEXT(addr, prototype)                                                               \
    _Pragma("GCC diagnostic push");                                                                \
    _Pragma("GCC diagnostic ignored \"-Wreturn-type\"");                                           \
    __attribute__((__section__(".external." #addr))) __attribute__((__weak__)) prototype           \
    {                                                                                              \
        __builtin_unreachable();                                                                   \
    }                                                                                              \
    _Pragma("GCC diagnostic pop");

#define EXTERN_TEXT_INLINE(addr, prototype)                                                        \
    __attribute__((__section__(".external." #addr))) prototype

#define EXTERN_TEXT_STATIC(addr, prototype) EXTERN_TEXT(addr, prototype)

#define EXTERN_REPL(addr, prototype)                                                               \
    extern "C" {                                                                                   \
    extern unsigned int ext_##addr;                                                                \
    extern unsigned int extern_func_##addr;                                                        \
    __attribute__((__section__(".externarray")))                                                   \
    __replace_struct externstruct_##addr = {&ext_##addr, &extern_func_##addr};                     \
    asm(".section .extern_repl." #addr "\n"                                                        \
        ".global extern_func_" #addr "\n"                                                          \
        ".p2align 2\n"                                                                             \
        "extern_func_" #addr ":\n");                                                               \
    }                                                                                              \
    _Pragma("GCC diagnostic push");                                                                \
    _Pragma("GCC diagnostic ignored \"-Wreturn-type\"");                                           \
    __attribute__((__section__(".extern_repl." #addr))) __attribute__((__weak__))                  \
    __attribute__((__naked__)) prototype                                                           \
    {                                                                                              \
        ASM(nop; b ext_##addr + 4;);                                                               \
    }                                                                                              \
    _Pragma("GCC diagnostic pop");

#define EXTERN_TEXT_C(addr, prototype)                                                             \
    _Pragma("GCC diagnostic push");                                                                \
    _Pragma("GCC diagnostic ignored \"-Wreturn-type\"");                                           \
    __attribute__((__section__(".external." #addr)))                                               \
    __attribute__((__weak__)) extern "C" prototype                                                 \
    {                                                                                              \
        __builtin_unreachable();                                                                   \
    }                                                                                              \
    _Pragma("GCC diagnostic pop");

#define EXTERN_DATA(addr, prototype) __attribute__((__section__(".external." #addr))) prototype

#define EXTERN_TEXT_CONSTRUCTOR(addr, prototype) EXTERN_TEXT(addr, prototype)

/**
 * Define an external function by its symbol name only
 */
#define EXTERN_SYMBOL(_ADDRESS, _NAME)                                                             \
    void __ext_sym_##_ADDRESS() asm(_NAME);                                                        \
    __attribute__((__section__(".external." #_ADDRESS))) void __ext_sym_##_ADDRESS()               \
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
