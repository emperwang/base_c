BUILD_DIR=./build
CC=gcc
AS=nasm
LD=ld
ASFLAGS=-f elf
CFLAGS=-Wall -c -fno-builtin -W -Wstrict-prototypes -Wmissing-prototypes

$(BUILD_DIR)/example1.o: example1.c
	$(CC) $(CFLAGS) $< -o $@

$(BUILD_DIR)/example2.o: example2.c
	$(CC) $(CFLAGS) $< -o $@

$(BUILD_DIR)/example3.o: example3.c
	$(CC) $(CFLAGS) $< -o $@

$(BUILD_DIR)/example4.o: example4.c
	$(CC) $(CFLAGS) $< -o $@

$(BUILD_DIR)/example5.o: example5.c
	$(CC) $(CFLAGS) $< -o $@
$(BUILD_DIR)/example6.o: example6.c
	$(CC) $(CFLAGS) $< -o $@

$(BUILD_DIR)/cmd1: $(BUILD_DIR)/example1.o
	$(CC) $^ -o $@

$(BUILD_DIR)/cmd2: $(BUILD_DIR)/example2.o
	$(CC) $^ -o $@

$(BUILD_DIR)/cmd3: $(BUILD_DIR)/example3.o
	$(CC) $^ -o $@

$(BUILD_DIR)/cmd4: $(BUILD_DIR)/example4.o
	$(CC) $^ -o $@

$(BUILD_DIR)/cmd5: $(BUILD_DIR)/example5.o
	$(CC) $^ -o $@

$(BUILD_DIR)/cmd6: $(BUILD_DIR)/example6.o
	$(CC) $^ -o $@

.PHONY: clean distclean dir
clean:
	@cd $(BUILD_DIR) && $(RM) *.o

distclean:
	@cd $(BUILD_DIR) && $(RM) *.o cmd cmd* && $(RM) -r $(BUILD_DIR)

dir:
	if [[ ! -d $(BUILD_DIR) ]]; then mkdir $(BUILD_DIR); fi
# $(BUILD_DIR)/cmd6
build: $(BUILD_DIR)/cmd1 $(BUILD_DIR)/cmd2 $(BUILD_DIR)/cmd3 $(BUILD_DIR)/cmd4 $(BUILD_DIR)/cmd5 

all: dir build