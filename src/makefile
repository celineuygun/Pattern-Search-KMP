CC=gcc
CFLAGS=-g -O2
LDFLAGS=-lm

DEPS = lib/dynamicArr.h lib/hash.h lib/utils.h originalKMP.h optimizedKMP.h
OBJS = lib/dynamicArr.o lib/hash.o lib/utils.o originalKMP.o optimizedKMP.o main.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

main: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -rf *.o */*.o main 