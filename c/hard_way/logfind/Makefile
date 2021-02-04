CFLAGS=-g -Wall #-DNDEBUG
TARGET= logfind

all: clean $(TARGET)
	./logfind || true
	./logfind max frog int

clean:
		rm -rf $(TARGET) *.dSYM

