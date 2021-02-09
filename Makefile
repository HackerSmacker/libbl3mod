CC = gcc
LD = gcc
CFLAGS = -I. -O0
OBJS = header.o tablehotfix.o regularhotfix.o
LIBRARIES = libbl3mod.a
MANUALS_PS = manual.ps
MANUALS_PDF = manual.pdf
MANUALS_TEXT = manual.txt
PREFIX = /usr/local

all: $(LIBRARIES)

%.txt: %.ms
	@echo " TROFF   " $< " TEXT"
	# @groff -Tascii -ms -Z $< | grotty -c | sed 's/[\x01-\x1F\x7F]//g' | sed 's/\([A-Za-z.,()]\)\1\+/\1/g' > $@
	@groff -Tascii -ms -Z $< | grotty -c | sed 's/[\x01-\x1F\x7F]//g' > $@


%.ps: %.ms
	@echo " TROFF   " $<
	@groff -Tps -ms $< > $@

%.pdf: %.ps
	@echo " PS2PDF   " $<
	@ps2pdf $< $@

%.o: %.c
	@echo " CC   " $<
	@$(CC) $(CFLAGS) -c -o $@ $<

$(LIBRARIES): $(CPROTOS) $(OBJS)
	@echo " AR    libbl3mod"
	@ar cr libbl3mod.a $(OBJS)

manual: $(MANUALS_PS) $(MANUALS_PDF) $(MANUALS_TEXT)

.PHONY: clean

clean:
	rm -f *.o *.a $(MANUALS_PS) $(MANUALS_PDF) $(MANUALS_TEXT)
