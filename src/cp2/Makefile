CC:= /usr/bin/gcc
AR:= /usr/bin/ar
MAKE:= /usr/bin/make

CPPFLAGS:= -I ../include/ -Wall -DLINUX -D_GNU_SOURCE

LIBCP2:= ../lib/libcp2.a
#PROGS:= conf pathalloc openmax
SRCS:= $(shell ls *.c) conf.c
PROGS:= $(basename $(SRCS))

all: $(PROGS)

$(LIBCP2): ../lib/error.c ../include/apue.h 
	$(MAKE) -C ../lib/ libcp2.a

conf.c: conf.c.modified
	ln -sf $< $@

%: %.o $(LIBCP2)
	$(CC) $(CPPFLAGS) -o $@ $< $(LIBCP2)

%.o: %.c conf.c
	$(CC) -c $(CPPFLAGS) -o $@ $<

%.d: %.c conf.c
	@set -e; rm -f $@; \
	$(CC) -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

-include $(addsuffix .d,$(PROGS))

clean:
	rm -rf $(PROGS) *.o *.d conf.c
	$(MAKE) -C ../lib/ cp2-clean

.PHONY: all clean
