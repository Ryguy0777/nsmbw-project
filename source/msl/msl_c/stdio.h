#pragma once

#include <stdarg.h>
#include <stddef.h>

extern "C" {

#define NULL ((void*) 0)

#define FILENAME_MAX 256

typedef struct _FILE FILE;

typedef unsigned long __file_handle;

typedef unsigned long fpos_t;

typedef void* __ref_con;
typedef void (*__idle_proc)(void);
typedef int (*__pos_proc)(
  __file_handle file, fpos_t* position, int mode, __ref_con ref_con
);
typedef int (*__io_proc)(
  __file_handle file, unsigned char* buff, size_t* count, __ref_con ref_con
);
typedef int (*__close_proc)(__file_handle file);

typedef struct {
    unsigned int open_mode : 2;
    unsigned int io_mode : 3;
    unsigned int buffer_mode : 2;
    unsigned int file_kind : 3;

    unsigned int binary_io : 1;
} __file_modes;

typedef struct {
    unsigned int io_state : 3;
    unsigned int free_buffer : 1;
    unsigned char eof;
    unsigned char error;
} __file_state;

struct _FILE {
    __file_handle handle;
    __file_modes mode;
    __file_state state;

    unsigned char char_buffer;
    unsigned char char_buffer_overflow;
    unsigned char ungetc_buffer[2];

    unsigned long position;
    unsigned char* buffer;
    unsigned long buffer_size;
    unsigned char* buffer_ptr;
    unsigned long buffer_len;
    unsigned long buffer_alignment;
    unsigned long saved_buffer_len;
    unsigned long buffer_pos;
    __pos_proc position_proc;
    __io_proc read_proc;
    __io_proc write_proc;
    __close_proc close_proc;
    __ref_con ref_con;
};

#define EOF (-1)

#define SEEK_CUR 1
#define SEEK_END 2
#define SEEK_SET 0

/* 0x802E1850 */
int vprintf(const char* restrict format, va_list ap);

/* 0x802E18CC */
int vsnprintf(
  char* restrict s, size_t n, const char* restrict format, va_list ap
);

/* 0x802E1954 */
int vsprintf(char* restrict s, const char* restrict format, va_list ap);

/* 0x802E19D8 */
int snprintf(char* restrict s, size_t n, const char* restrict format, ...);

/* 0x802E1ACC */
int sprintf(char* restrict s, const char* restrict format, ...);

//
} // extern "C"