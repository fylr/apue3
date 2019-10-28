CC:= /usr/bin/gcc
AR:= /usr/bin/ar
MAKE:= /usr/bin/make

CPPFLAGS:= -I ../include/ -Wall -DLINUX -D_GNU_SOURCE

LIBCP6:= ../lib/libcp6.a
SRCS:= $(shell ls *.c)
PROGS:= $(basename $(SRCS))

all: $(PROGS)

$(LIBCP6): ../lib/error.c ../include/apue.h 
	$(MAKE) -C ../lib/ libcp6.a

%: %.o $(LIBCP6)
	$(CC) $(CPPFLAGS) -o $@ $< $(LIBCP6)

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
	$(MAKE) -C ../lib/ cp6-clean

.PHONY: all clean
