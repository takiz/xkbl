# xkbl

CC = gcc
CFLAGS = -Wall
LIBS = -lX11

SRC = xkbl.c

xkbl:
	${CC} ${CFLAGS} ${SRC} -o $@ ${LIBS}

clean:
	rm -f *.o xkbl
