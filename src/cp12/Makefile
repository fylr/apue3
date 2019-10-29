CC:= /usr/bin/gcc
AR:= /usr/bin/ar
MAKE:= /usr/bin/make

CPPFLAGS:= -I ../include/ -Wall -DLINUX -D_GNU_SOURCE
LDFLAGS:= -pthread

LIBCP12:= ../lib/libcp12.a
SRCS:= $(shell ls *.c)
PROGS:= $(basename $(SRCS))
#PROGS:= detach timeout getenv1 getenv2 getenv3 suspend atfork

all: $(PROGS)

$(LIBCP12): ../lib/error.c ../include/apue.h
	$(MAKE) -C ../lib/ libcp12.a

%: %.o $(LIBCP12)
	$(CC) $(CPPFLAGS) $(LDFLAGS) -o $@ $< $(LIBCP12)

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
	$(MAKE) -C ../lib/ cp12-clean

.PHONY: all clean
