CC = gcc
LD = gcc
CFLAGS = -I. -O0
OBJS = header.o tablehotfix.o regularhotfix.o meshhotfix.o
PROGS_OBJS = dialog.o
PROGS = dialog
LIBRARIES = libbl3mod.a
PREFIX = /usr/local

all: $(LIBRARIES) $(PROGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(PROGS): $(LIBRARIES) $(PROGS_OBJS)
	$(CC) -c dialog.c
	$(LD) -o dialog dialog.c -L. -lbl3mod

$(LIBRARIES): $(OBJS)
	ar cr libbl3mod.a $(OBJS)

.PHONY: clean

clean:
	rm -f $(OBJS) $(PROGS_OBJS) $(LIBRARIES) $(PROGS)
