CC=gcc
CUR_DIR=$(shell pwd)
flag=-Wall -g -O -I$(CUR_DIR)
CUR_SOURCE=$(wildcard *.c)
CUR_OBJ=${patsubst %.c,%.o,$(CUR_SOURCE)}
OBJS=*.o

all: $(CUR_OBJ) out

student:student.c
	${CC} ${flag} -c $^ -o $@

smain:stu_main.c
	${CC} ${flag} -c $^ -o $@

echo:
	@echo $(CUR_OBJ)
$(CUR_OBJ):%.o:%.c
	${CC} ${flag} -c $^ -o $@
	
out:$(OBJS)
	${CC} -o $@ $^


clean:
	rm -rf *.o student main smain out
