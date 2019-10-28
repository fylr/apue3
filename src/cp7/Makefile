CC:= /usr/bin/gcc
AR:= /usr/bin/ar
MAKE:= /usr/bin/make

CPPFLAGS:= -I ../include/ -Wall -DLINUX -D_GNU_SOURCE

LIBCP7:= ../lib/libcp7.a
SRCS:= $(shell ls *.c)
PROGS:= $(basename $(SRCS))
#PROGS:= hello1 doatexit echoarg cmd1 cmd2 testjmp opendata getrlimit

all: $(PROGS)

$(LIBCP7): ../lib/error.c ../include/apue.h 
	$(MAKE) -C ../lib/ libcp7.a

%: %.o $(LIBCP7)
	$(CC) $(CPPFLAGS) -o $@ $< $(LIBCP7)

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
	$(MAKE) -C ../lib/ cp7-clean

.PHONY: all clean
