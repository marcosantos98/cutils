CFLAGS=-Wextra -Werror -Wall

TESTS=bench_test.exe vec_test.exe strb_test.exe

%.exe: %.c
	cc $(CFLAGS) -o $@ $<

all: $(TESTS)
