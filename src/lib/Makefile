CC:= /usr/bin/gcc
AR:= /usr/bin/ar

CPPFLAGS:= -I ../include/ -ansi -Wall -DLINUX -D_GNU_SOURCE

SRCS:= $(shell ls *.c)
LIBS:= liberror.a liberpa.a liberrpetwst.a

all: $(LIBS)

libcp1.a libcp2.a libcp3.a libcp5.a libcp6.a libcp7.a libcp8.a libcp9.a: liberror.a
	ln -sf $< $@

libcp4.a: liberpa.a
	ln -sf $< $@

libcp8.a: liberrpetwst.a
	ln -sf $< $@

liberror.a: error.o
	$(AR) -rsv $@ $?

liberpa.a: error.o pathalloc.o
	$(AR) -rsv $@ $?

liberrpetwst.a: error.o prexit.o tellwait.o system.o
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

cp6-clean:
	rm -rf libcp6.a error.o error.d

cp7-clean:
	rm -rf libcp7.a error.o error.d

cp8-clean:
	rm -rf libcp8.a error.o error.d prexit.o prexit.d tellwait.o tellwait.d system.o system.d

cp9-clean:
	rm -rf libcp9.a error.o error.d

.PHONY: all clean
