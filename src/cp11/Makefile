CC:= /usr/bin/gcc
AR:= /usr/bin/ar
MAKE:= /usr/bin/make

CPPFLAGS:= -I ../include/ -Wall -DLINUX -D_GNU_SOURCE
LDFLAGS:= -pthread

LIBCP11:= ../lib/libcp11.a
SRCS:= $(shell ls *.c)
PROGS:= $(basename $(SRCS))
#PROGS:= threadid exitstatus badexit2 cleanup mutex1 mutex2 mutex3 timedlock rwlock condvar barrier

all: $(PROGS)

$(LIBCP11): ../lib/error.c ../include/apue.h
	$(MAKE) -C ../lib/ libcp11.a

%: %.o $(LIBCP11)
	$(CC) $(CPPFLAGS) $(LDFLAGS) -o $@ $< $(LIBCP11)

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
	$(MAKE) -C ../lib/ cp11-clean

.PHONY: all clean
