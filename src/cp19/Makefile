CC:= /usr/bin/gcc
AR:= /usr/bin/ar
MAKE:= /usr/bin/make

CPPFLAGS:= -I ../include/ -Wall -DLINUX -D_GNU_SOURCE

LIBCP19:= ../lib/libcp19.a
SRCS:= $(shell ls *.c)
PROGS:= $(basename $(SRCS))
# PROGS:= pty

all: $(PROGS)

$(LIBCP19): ../lib/error.c ../lib/ptyopen.c ../lib/ptyfork.c ../lib/loop.c ../lib/driver.c ../lib/ttymodes.c ../lib/signalintr.c ../lib/writen.c ../lib/spipe.c ../include/apue.h
	$(MAKE) -C ../lib/ libcp19.a

%: %.o $(LIBCP19)
	$(CC) $(CPPFLAGS) -o $@ $< $(LIBCP19)

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
	$(MAKE) -C ../lib/ cp19-clean

.PHONY: all clean
