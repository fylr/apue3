CC:= /usr/bin/gcc
AR:= /usr/bin/ar

CPPFLAGS:= -I ../include/ -ansi -Wall -DLINUX -D_GNU_SOURCE

SRCS:= $(shell ls *.c)
LIBS:= liberror.a liberror-pathalloc.a

all: $(LIBS)

libcp1.a libcp2.a libcp3.a libcp5.a: liberror.a
	ln -sf $< $@

libcp4.a: liberror-pathalloc.a
	ln -sf $< $@

liberror.a: error.o
	$(AR) -rsv $@ $?

liberror-pathalloc.a: error.o pathalloc.o
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

cp3-clean:
	rm -rf libcp3.a error.o error.d

cp4-clean:
	rm -rf libcp4.a error.o error.d pathalloc.o pathalloc.d

cp5-clean:
	rm -rf libcp5.a error.o error.d

.PHONY: all clean
