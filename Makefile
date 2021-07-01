CC = x86_64-w64-mingw32-gcc
LD = x86_64-w64-mingw32-gcc
CFLAGS = -I. -O0
OBJS = header.o tablehotfix.o regularhotfix.o meshhotfix.o utilunique.o utilgame.o
LIBRARIES = libbl3mod.a
PREFIX = /usr/local

all: $(LIBRARIES)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

progs: $(LIBRARIES)
	make -C EXAMPLES

$(LIBRARIES): $(OBJS)
	ar cr libbl3mod.a $(OBJS)

.PHONY: clean

clean:
	make -C EXAMPLES clean
	rm -f $(OBJS) $(LIBRARIES)
