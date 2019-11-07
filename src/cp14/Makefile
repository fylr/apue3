CC:= /usr/bin/gcc
AR:= /usr/bin/ar
MAKE:= /usr/bin/make

CPPFLAGS:= -I ../include/ -Wall -DLINUX -D_GNU_SOURCE
LDFLAGS:= -lrt

LIBCP14:= ../lib/libcp14.a
SRCS:= $(shell ls *.c)
PROGS:= $(basename $(SRCS))
#PROGS:= nonblockw deadlock mandatory rot13a rot13c2 mcopy2

all: $(PROGS)

$(LIBCP14): ../lib/error.c ../lib/setfl.c ../lib/clrfl.c ../lib/lockreg.c ../lib/tellwait.c ../include/apue.h
	$(MAKE) -C ../lib/ libcp14.a

%: %.o $(LIBCP14)
	$(CC) $(CPPFLAGS) $(LDFLAGS) -o $@ $< $(LIBCP14)

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
	$(MAKE) -C ../lib/ cp14-clean

.PHONY: all clean
