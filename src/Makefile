CC:= /usr/bin/gcc
AR:= /usr/bin/ar
MAKE:= /usr/bin/make

CPPFLAGS:= -I ../include/ -ansi -Wall -DLINUX -D_GNU_SOURCE

SRCS:= $(shell ls -d cp*) lib

all: $(SRCS)
	@for sub_dir in $(SRCS); do \
		$(MAKE) -C $$sub_dir; \
	done

clean: $(SRCS)
	@for sub_dir in $(SRCS); do \
                $(MAKE) -C $$sub_dir clean; \
        done

.PHONY: all clean
