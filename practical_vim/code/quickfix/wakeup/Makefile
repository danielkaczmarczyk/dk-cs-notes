TARGET=wakeup
CC=gcc
OBJS=wakeup.o
SRCS=wakeup.c

${TARGET}: ${OBJS}
	${CC} -o ${TARGET} ${OBJS}

clean:
	rm -rf *.o ${TARGET}

wakeup.o: wakeup.c
