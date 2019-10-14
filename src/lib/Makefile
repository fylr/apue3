CC:= /usr/bin/gcc
AR:= /usr/bin/ar
CPPFLAGS:= -I ../include/

SRCS:= $(shell ls *.c)
LIBS:= liberr.a

all: $(LIBS)

libcp1.a: liberr.a
	ln -sf $< $@

libcp2.a: liberr.a
	ln -sf $< $@

liberr.a: error.o
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
	rm -rf $(LIBS) *.a *.o *.d

cp1-clean:
	rm -rf libcp1.a error.o error.d

cp2-clean:
	rm -rf libcp2.a error.o error.d

.PHONY: all clean cp1 cp1-clean
