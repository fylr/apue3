CC:= /usr/bin/gcc
AR:= /usr/bin/ar
MAKE:= /usr/bin/make

CPPFLAGS:= -I ../include/ -ansi -Wall -DLINUX -D_GNU_SOURCE

LIBCP10:= ../lib/libcp10.a
#SRCS:= $(shell ls *.c)
#PROGS:= $(basename $(SRCS))
PROGS:= sigusr reenter child sleep1 sleep2 tsleep2 read1 read2 setops critical mask suspend1 suspend2 abort systest2 system sigtstp

all: $(PROGS)

$(LIBCP10): ../lib/error.c ../lib/signal.c ../lib/prmask.c ../include/apue.h
	$(MAKE) -C ../lib/ libcp10.a

%: %.o $(LIBCP10)
	$(CC) $(CPPFLAGS) -o $@ $< $(LIBCP10)

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
	$(MAKE) -C ../lib/ cp10-clean

.PHONY: all clean
