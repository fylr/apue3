CC:= /usr/bin/gcc
AR:= /usr/bin/ar
MAKE:= /usr/bin/make

CPPFLAGS:= -I ../../include/ -Wall -DLINUX -D_GNU_SOURCE
LDFLAGS:= -pthread

LIBCP17:= ../../lib/libcp17.a
BASE_SRCS:= cliargs.c client.c main.c request.c
PROGS:= opend.poll opend.select

all: $(PROGS)

opend.poll: $(BASE_SRCS:.c=.o) loop.poll.o $(LIBCP17)
	$(CC) $(CPPFLAGS) $(LDFLAGS) -o $@ $^

opend.select: $(BASE_SRCS:.c=.o) loop.select.o $(LIBCP17)
	$(CC) $(CPPFLAGS) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) -c $(CPPFLAGS) $(LDFLAGS) -o $@ $<

%.d: %.c
	@set -e; rm -f $@; \
	$(CC) -MM $(CPPFLAGS) $(LDFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

-include $(BASE_SRCS:.c=.d)
-include loop.poll.d
-include loop.select.d


clean:
	rm -rf $(PROGS) *.o *.d

.PHONY: all clean
