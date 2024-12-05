CC	    := clang
CFLAGS	:= -O3 -I. -Wno-pointer-sign
CLIBS	=

all: lzx.c
	$(CC) $(CFLAGS) -o ../../macos/lzx lzx.c $(CLIBS) -Wno-deprecated-declarations

clean:
	rm -f ../../macos/lzx
