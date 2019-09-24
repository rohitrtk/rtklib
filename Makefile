CFLAGS = -g -Wall
OBJS = main.o list/rtk_list.o array/rtk_array.o stack/rtk_stack.o sort/rtk_sort.o string/rtk_string.o
HDRS = rtk_list.h rtk_array.h rtk_stack.h rtk_random.h rtk_sort.h rtk_string.h

all: main

main: $(OBJS)
	gcc ${CFLAGS} -o $@ $^

%.o: %.c $(HDRS)
	gcc ${CFLAGS} -c $<

clean:
	rm *.o main ${OBJS}