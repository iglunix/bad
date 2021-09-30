.POSIX:
CFLAGS+=-D_POSIX_C_SOURCE=200112L

all: bad

bad: bad.c

clean:
	rm -f bad
