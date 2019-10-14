CC:= /usr/bin/gcc
AR:= /usr/bin/ar
CPPFLAGS:= -I ../include/

SRCS:= $(shell ls *.c)
LIBS:= libcp1.a

all: $(LIBS)

libcp1.a: error.o
	$(AR) -rsv $@ $?

%.o: %.c
	$(CC) -c $(CPPFLAGS) -o $@ $<

%.d: %.c
	@set -e; rm -f $@; \
	$(CC) -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

-include $(SRCS:.c=.d)

clean:
	rm -rf $(LIBS) *.o *.d

cp1-clean:
	rm -rf libcp1.a error.o error.d

.PHONY: all clean cp1 cp1-clean
