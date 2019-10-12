CC := /usr/bin/gcc
CPPFLAGS := -I ../include/
PROGS := ls1 mycat getcputc hello shell1 testerror uidgid shell2

all: $(PROGS)

$(PROGS): %: %.c ../include/ ../lib/error.c
	$(CC) $(CPPFLAGS) ../lib/error.c $< -o $@

clean:
	rm -rf $(PROGS)

.PHONY: all clean
