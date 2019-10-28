CC:= /usr/bin/gcc
AR:= /usr/bin/ar
MAKE:= /usr/bin/make

CPPFLAGS:= -I ../include/ -Wall -DLINUX -D_GNU_SOURCE

LIBCP4:= ../lib/libcp4.a
#PROGS := seek hole mycat fileflags setfl
SRCS:= $(shell ls *.c)
PROGS:= $(basename $(SRCS))

all: $(PROGS)

$(LIBCP4): ../lib/error.c ../lib/pathalloc.c ../include/apue.h 
	$(MAKE) -C ../lib/ libcp4.a

%: %.o $(LIBCP4)
	$(CC) $(CPPFLAGS) -o $@ $< $(LIBCP4)

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
	$(MAKE) -C ../lib/ cp4-clean

.PHONY: all clean
