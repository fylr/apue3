CC:= /usr/bin/gcc
AR:= /usr/bin/ar
MAKE:= /usr/bin/make

CPPFLAGS:= -I ../include/ -Wall -DLINUX -D_GNU_SOURCE

LIBCP8:= ../lib/libcp8.a
SRCS:= $(shell ls *.c)
PROGS:= $(basename $(SRCS))
#PROGS:= fork1 vfork1 wait1 fork2 tellwait1 tellwait2 exec1 echoall exec2 systest1 systest3 pruids test1 pracct nice times1

all: $(PROGS)

$(LIBCP8): ../lib/error.c ../lib/prexit.c ../lib/tellwait.c ../lib/system.c ../include/apue.h
	$(MAKE) -C ../lib/ libcp8.a

%: %.o $(LIBCP8)
	$(CC) $(CPPFLAGS) -o $@ $< $(LIBCP8)

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
	$(MAKE) -C ../lib/ cp8-clean

.PHONY: all clean
