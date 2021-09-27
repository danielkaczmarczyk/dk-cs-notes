AS = nasm

CFLAGS = -g -Wall -Wextra -pedantic -Werror
LDFLAGS =
ASFLAGS = -g -F dwarf -Werror

ifeq ($(shell uname -s),Darwin)
	ALL_LDFLAGS = -Wl,-pie -Wl,-fatal_warnings
	ALL_ASFLAGS = -f macho64 --prefix _
else
	ALL_LDFLAGS = -pie -Wl,--fatal-warnings
	ALL_ASFLAGS = -f elf64
endif

ALL_CFLAGS = -std=c99 -fPIE -m64 $(CFLAGS)
ALL_LDFLAGS += $(LDFLAGS)
ALL_ASFLAGS += $(ASFLAGS)

EXCLUSIONS = hello_linux.o hello_mac.o
C_OBJS = $(patsubst %.c,%.o,$(wildcard *.c))
AS_OBJS = $(patsubst %.asm,%.o,$(wildcard *.asm))
ALL_OBJS = $(filter-out $(EXCLUSIONS),$(C_OBJS) $(AS_OBJS) vendor/unity.o)

CC_CMD = $(CC) $(ALL_CFLAGS) -c -o $@ $<

all: tests
	@./$<

tests: $(ALL_OBJS)
	@$(CC) $(ALL_CFLAGS) $(ALL_LDFLAGS) -o $@ $(ALL_OBJS)

%.o: %.asm
	@$(AS) $(ALL_ASFLAGS) -o $@ $<

%.o: %.c
	@$(CC_CMD)

vendor/unity.o: vendor/unity.c vendor/unity.h vendor/unity_internals.h
	@$(CC_CMD)

clean:
	@rm -f *.o vendor/*.o tests

.PHONY: all clean
