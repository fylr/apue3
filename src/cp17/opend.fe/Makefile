CC:= /usr/bin/gcc
AR:= /usr/bin/ar
MAKE:= /usr/bin/make

CPPFLAGS:= -I ../../include/ -Wall -DLINUX -D_GNU_SOURCE
LDFLAGS:= -pthread

LIBCP17:= ../../lib/libcp17.a
SRCS:= $(shell ls *.c)
PROGS:= opend.fe

all: $(PROGS)

$(PROGS): $(SRCS:.c=.o) $(LIBCP17)
	$(CC) $(CPPFLAGS) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) -c $(CPPFLAGS) $(LDFLAGS) -o $@ $<

%.d: %.c
	@set -e; rm -f $@; \
	$(CC) -MM $(CPPFLAGS) $(LDFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

-include $(SRCS:.c=.d)

clean:
	rm -rf $(PROGS) *.o *.d

.PHONY: all clean
