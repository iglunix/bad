.POSIX:
CFLAGS+=-D_POSIX_C_SOURCE=200112L

PREFIX?=/usr/local

all: bad

bad: bad.c

install: bad
	install -d $(DESTDIR)/$(PREFIX)/bin
	install -Dm755 bad $(DESTDIR)/$(PREFIX)/bin/
clean:
	rm -f bad
