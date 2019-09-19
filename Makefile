CFLAGS = -g -Wall
OBJS = main.o list/rtk_list.o array/rtk_array.o stack/rtk_stack.o
HDRS = rtk_list.h rtk_array.h rtk_stack.o

all: main

main: $(OBJS)
	gcc ${CFLAGS} -o $@ $^

%.o: %.c $(HDRS)
	gcc ${CFLAGS} -c $<

clean:
	rm *.o main ${OBJS}