CC:= /usr/bin/gcc
AR:= /usr/bin/ar
MAKE:= /usr/bin/make

CPPFLAGS:= -I ../include/ -Wall -DLINUX -D_GNU_SOURCE
LDFLAGS:= -pthread

LIBCP15:= ../lib/libcp15.a
SRCS:= $(shell ls *.c)
PROGS:= $(basename $(SRCS))
#PROGS:= pipe1 pipe2 tellwait popen2 popen myuclc popen1 add2 pipe4 add2stdio tshm devzero slock

all: $(PROGS)

$(LIBCP15): ../lib/error.c ../lib/tellwait.c ../include/apue.h
	$(MAKE) -C ../lib/ libcp15.a

%: %.o $(LIBCP15)
	$(CC) $(CPPFLAGS) ${LDFLAGS} -o $@ $< $(LIBCP15)

%.o: %.c
	$(CC) -c $(CPPFLAGS) ${LDFLAGS} -o $@ $<

%.d: %.c
	@set -e; rm -f $@; \
	$(CC) -MM $(CPPFLAGS) ${LDFLAGS} $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

-include $(addsuffix .d,$(PROGS))

clean:
	rm -rf $(PROGS) *.o *.d
	$(MAKE) -C ../lib/ cp15-clean

.PHONY: all clean
