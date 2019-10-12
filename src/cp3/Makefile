CC := /usr/bin/gcc
CPPFLAGS := -I ../include/
PROGS := seek hole mycat fileflags setfl

all: $(PROGS)

$(PROGS): %: %.c ../include/ ../lib/error.c
	$(CC) $(CPPFLAGS) ../lib/error.c $< -o $@

clean:
	rm -rf $(PROGS)

.PHONY: all clean
