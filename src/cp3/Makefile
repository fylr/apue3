CC:= /usr/bin/gcc
AR:= /usr/bin/ar
MAKE:= /usr/bin/make

CPPFLAGS:= -I ../include/ -ansi -Wall -DLINUX -D_GNU_SOURCE 

LIBCP3:= ../lib/libcp3.a
#PROGS := seek hole mycat fileflags setfl
SRCS:= $(shell ls *.c)
PROGS:= $(basename $(SRCS))

all: $(PROGS)

$(LIBCP3): ../lib/error.c ../include/apue.h 
	$(MAKE) -C ../lib/ libcp3.a

%: %.o $(LIBCP3)
	$(CC) $(CPPFLAGS) -o $@ $< $(LIBCP3)

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
	$(MAKE) -C ../lib/ cp3-clean

.PHONY: all clean
