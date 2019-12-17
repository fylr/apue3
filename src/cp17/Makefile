CC:= /usr/bin/gcc
AR:= /usr/bin/ar
MAKE:= /usr/bin/make

CPPFLAGS:= -I ../include/ -Wall -DLINUX -D_GNU_SOURCE
LDFLAGS:= -pthread

LIBCP17:= ../lib/libcp17.a
# SRCS:= $(shell ls *.c)
# PROGS:= $(basename $(SRCS))
PROGS:= pollmsg sendmsg bindunix
SUB_DIRS:= open.fe opend.fe open opend

all: $(PROGS) sub_all

sub_all: $(SUB_DIRS) $(LIBCP17)
	@for i in $(SUB_DIRS); do \
		$(MAKE) -C $$i; \
	done

$(LIBCP17): ../lib/error.c ../lib/spipe.c ../lib/recvfd.c ../lib/senderr.c ../lib/sendfd.c ../lib/writen.c \
 ../lib/bufargs.c ../lib/cliconn.c ../lib/errorlog.c ../lib/daemonize.c ../lib/servaccept.c ../lib/servlisten.c ../include/apue.h
	$(MAKE) -C ../lib/ libcp17.a

%: %.o $(LIBCP17)
	$(CC) $(CPPFLAGS) $(LDFLAGS) -o $@ $< $(LIBCP17)

%.o: %.c
	$(CC) -c $(CPPFLAGS) $(LDFLAGS) -o $@ $<

%.d: %.c
	@set -e; rm -f $@; \
	$(CC) -MM $(CPPFLAGS) $(LDFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

-include $(addsuffix .d,$(PROGS))

clean: sub_clean
	rm -rf $(PROGS) *.o *.d
	$(MAKE) -C ../lib/ cp17-clean

sub_clean: $(SUB_DIRS)
	@for i in $^; do \
		$(MAKE) -C $$i clean; \
	done

.PHONY: all clean
