PREFIX = /usr/local

CC = gcc
CFLAGS = -Wall -O2
LIBS = -lX11
SRC = xkbl.c
BINPROGS = xkbl

all:
	${CC} ${CFLAGS} ${SRC} -o $(BINPROGS) ${LIBS}

install: all
	install -dm755 $(DESTDIR)$(PREFIX)/bin
	install -m755 $(BINPROGS) $(DESTDIR)$(PREFIX)/bin

clean:
	rm -f $(BINPROGS)

.PHONY: all install clean