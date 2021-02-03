CC = gcc
CFLAGS=-g -Wall -DNDEBUG
OBJFILES = ex22.o
TARGET = ex22

all: $(TARGET)

$(TARGET): obj $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES)

obj:
	-c -o $(OBJFILES) ex22.c

clean:
		rm -rf $(TARGET) *.dSYM

