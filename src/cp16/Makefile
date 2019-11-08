CC:= /usr/bin/gcc
AR:= /usr/bin/ar
MAKE:= /usr/bin/make

CPPFLAGS:= -I ../include/ -Wall -DLINUX -D_GNU_SOURCE

LIBCP16:= ../lib/libcp16.a
SRCS:= $(shell ls *.c)
PROGS:= $(basename $(SRCS))
# PROGS:= findsvc ruptime ruptimed ruptimed-fd ruptime-dg ruptimed-dg

all: $(PROGS)

$(LIBCP16): ../lib/error.c ../lib/clconn2.c ../lib/initsrv2.c ../lib/init.c ../lib/setfd.c ../include/apue.h
	$(MAKE) -C ../lib/ libcp16.a

%: %.o $(LIBCP16)
	$(CC) $(CPPFLAGS) -o $@ $< $(LIBCP16)

%.o: %.c
	$(CC) -c $(CPPFLAGS) -o $@ $<

%.d: %.c
	@set -e; rm -f $@; \
	$(CC) -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

-include $(addsuffix .d,$(PROGS))

clean:
	rm -rf $(PROGS) *.o *.d
	$(MAKE) -C ../lib/ cp16-clean

.PHONY: all clean
