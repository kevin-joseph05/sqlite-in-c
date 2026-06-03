CFLAGS = -Wall -Wextra -std=c11 -g
OBJS = sqlite.o cli.o lexer.o parser.o vm.o pager.o btree.o table.o io_helpers.o

sqlite: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f sqlite $(OBJS)

.PHONY: clean
