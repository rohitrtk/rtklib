CFLAGS = -g -Wall
OBJS = main.o list/rtk_list.o

all: main

main: $(OBJS)
	gcc ${CFLAGS} -o $@ $^

%.o: %.c rtk_list.h
	gcc ${CFLAGS} -c $<

clean:
	rm *.o main rtk_list.o