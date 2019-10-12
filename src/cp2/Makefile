CC := /usr/bin/gcc
CPPFLAGS := -I ../include/
PROGS1 := conf
PROGS2 := pathalloc openmax

all: $(PROGS1) $(PROGS2)

$(PROGS1): conf.c.modified ../include/ ../lib/error.c
	mv $< $<.c
	$(CC) $(CPPFLAGS) ../lib/error.c $<.c -o $@
	mv $<.c $<

$(PROGS2): %: %.c ../include/ ../lib/error.c
	$(CC) $(CPPFLAGS) ../lib/error.c $< -o $@

clean:
	rm -rf $(PROGS1) $(PROGS2)

.PHONY: all clean
