CC:= /usr/bin/gcc
AR:= /usr/bin/ar
MAKE:= /usr/bin/make

CPPFLAGS:= -I ../include/ -Wall -DLINUX -D_GNU_SOURCE
LDFLAGS:= -pthread

LIBCP13:= ../lib/libcp13.a
#SRCS:= $(shell ls *.c)
#PROGS:= $(basename $(SRCS))
PROGS:= init single reread reread2

all: $(PROGS)

$(LIBCP13): ../lib/error.c ../lib/lockfile.c ../include/apue.h
	$(MAKE) -C ../lib/ libcp13.a

%: %.o $(LIBCP13)
	$(CC) $(CPPFLAGS) $(LDFLAGS) -o $@ $< $(LIBCP13)

%.o: %.c
	$(CC) -c $(CPPFLAGS) $(LDFLAGS) -o $@ $<

%.d: %.c
	@set -e; rm -f $@; \
	$(CC) -MM $(CPPFLAGS) $(LDFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

-include $(addsuffix .d,$(PROGS))

clean:
	rm -rf $(PROGS) *.o *.d
	$(MAKE) -C ../lib/ cp13-clean

.PHONY: all clean
