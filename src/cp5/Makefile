CC:= /usr/bin/gcc
AR:= /usr/bin/ar
MAKE:= /usr/bin/make

CPPFLAGS:= -I ../include/ -ansi -Wall -DLINUX -D_GNU_SOURCE

LIBCP5:= ../lib/libcp5.a
#PROGS := getcputc fgetsfputs buf tempfiles mkstemp memstr
SRCS:= $(shell ls *.c)
PROGS:= $(basename $(SRCS))

all: $(PROGS)

$(LIBCP5): ../lib/error.c ../include/apue.h 
	$(MAKE) -C ../lib/ libcp5.a

%: %.o $(LIBCP5)
	$(CC) $(CPPFLAGS) -o $@ $< $(LIBCP5)

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
	$(MAKE) -C ../lib/ cp5-clean

.PHONY: all clean
