CC:= /usr/bin/gcc
AR:= /usr/bin/ar
MAKE:= /usr/bin/make

CPPFLAGS:= -I ../include/ -Wall -DLINUX -D_GNU_SOURCE

LIBCP18:= ../lib/libcp18.a
SRCS:= $(shell ls *.c)
PROGS:= $(basename $(SRCS))
# PROGS:= settty csize t_isatty t_ttyname t_getpass t_raw winch

all: $(PROGS)

$(LIBCP18): ../lib/error.c ../lib/isatty.c ../lib/ttyname.c ../lib/ctermid.c ../lib/getpass.c ../lib/ttymodes.c ../include/apue.h
	$(MAKE) -C ../lib/ libcp18.a

%: %.o $(LIBCP18)
	$(CC) $(CPPFLAGS) -o $@ $< $(LIBCP18)

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
	$(MAKE) -C ../lib/ cp18-clean

.PHONY: all clean
