CC = x86_64-w64-mingw32-gcc
LD = x86_64-w64-mingw32-gcc
CFLAGS = -I.. -O0
OBJS =  gen_extreme_unrarity.o gen_no_guardian_cap.o gen_no_modifiers.o gen_pearls.o gen_events.o gen_cooldown.o gen_thirdperson.o
PROGS = gen_extreme_unrarity gen_no_guardian_cap gen_no_modifiers gen_pearls gen_events gen_cooldown gen_thirdperson
LIBRARIES = libbl3mod.a
LIBDIR = ..
PREFIX = /usr/local

all: $(PROGS) 

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(PROGS): $(OBJS)
	$(LD) -o gen_extreme_unrarity gen_extreme_unrarity.o -L$(LIBDIR) -lbl3mod
	$(LD) -o gen_no_guardian_cap gen_no_guardian_cap.o -L$(LIBDIR) -lbl3mod
	$(LD) -o gen_no_modifiers gen_no_modifiers.o -L$(LIBDIR) -lbl3mod
	$(LD) -o gen_pearls gen_pearls.o -L$(LIBDIR) -lbl3mod
	$(LD) -o gen_events gen_events.o -L$(LIBDIR) -lbl3mod
	$(LD) -o gen_cooldown gen_cooldown.o -L$(LIBDIR) -lbl3mod
	$(LD) -o gen_thirdperson gen_thirdperson.o -L$(LIBDIR) -lbl3mod

.PHONY: clean

clean:
	rm -f $(OBJS) $(PROGS)
