CC=gcc
SUB_DIR=$(shell ls -l | grep ^d | awk '{if($$9 != "debug") print $$9}')
ROOT_DIR=$(shell pwd)
OBJ_DIR=$(ROOT_DIR)/student
flag=-Wall -g -O
cflag=-Wall -g -I$(ROOT_DIR)/student
CUR_SOURCE=stu_main.c
CUR_OBJ=${patsubst %.c,%.o,%(CUR_SOURCE)}

export CC ROOT_DIR flag cflag 

all:struct1 a fpointer struct_stu stumain

struct1:struct1.c
	${CC} ${flag} $< -o $@

a:a.c
	${CC} ${flag} $<  -o $@

fpointer:func_pointer.c
	${CC} ${flag} $< -o $@

struct_stu:struct_stu.c
	${CC} ${flag} $< -o $@

stumain: $(CUR_SOURCE)  $(SUB_DIR)
	${CC}  ${cflag} -c $^  -o $(OBJ_DIR)/$@

malloc1:malloc1.c
	${CC} ${flag} $< -o  malloc1
malloc2:malloc2.c
	${CC} ${flag} $^ -o  malloc2

union1:union1.c
	${CC} ${flag} $^ -o union1
union2:union2.c
	${CC} ${flag} $^ -o $@
union3:union3.c
	${CC} ${flag} $^ -o $@

## 编译子目录关键
$(SUB_DIR):echo
	make -C $@

echo:
	@echo $(SUB_DIR)

clean:
	rm -rf *.o struct1 a fpointer struct_stu malloc1 malloc2 union1 union2 union3
