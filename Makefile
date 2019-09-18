CFLAGS = -g -Wall
OBJS = main.o list/rtk_list.o array/rtk_array.o
HDRS = rtk_list.h rtk_array.h

all: main

main: $(OBJS)
	gcc ${CFLAGS} -o $@ $^

%.o: %.c $(HDRS)
	gcc ${CFLAGS} -c $<

clean:
	rm *.o main ${OBJS}