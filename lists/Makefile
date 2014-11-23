CC = gcc
CFLAGS = -std=c99 $(DEBUG)

OBJS = main.o list.o

main: $(OBJS)
	$(CC) $(OBJS) -o $@

$(OBJS): list.h
	$(CC) $(CFLAGS) -c $*.c
	
debug:
	$(MAKE) $(MAKEFILE) DEBUG="-g -DLOG_LEVEL=1" 

clean:
	rm -f main main.o list.o


