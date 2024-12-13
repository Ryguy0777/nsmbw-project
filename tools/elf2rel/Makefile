CC	= clang
COPTS	= -O2 -I. -std=c++20
CLIBS	= -lc++

all: elf2rel.cpp elf2rel.h
	$(CC) $(COPTS) -o ../../macos/elf2rel elf2rel.cpp $(CLIBS) -Wno-deprecated-declarations

clean:
	rm -f ../../macos/elf2rel
