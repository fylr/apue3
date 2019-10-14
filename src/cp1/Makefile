CC:= /usr/bin/gcc
AR:= /usr/bin/ar
MAKE:= /usr/bin/make

CPPFLAGS:= -I ../include/

LIBCP1:= ../lib/libcp1.a
PROGS:= ls1 mycat getcputc hello shell1 testerror uidgid shell2

all: $(PROGS)

$(LIBCP1): ../lib/error.c ../include/apue.h 
	$(MAKE) -C ../lib/ libcp1.a

%: %.o $(LIBCP1)
	$(CC) $(CPPFLAGS) -o $@ $< $(LIBCP1)

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
	$(MAKE) -C ../lib/ cp1-clean

.PHONY: all clean
