CC = gcc
CFLAGS = -Wall -Iinclude 
LIBFLAG = -fPIC

LIB_NAME = cripto
LIB_ESTAT = $(LIB_DIR)/lib$(LIB_NAME).a
LIB_DINAM = $(LIB_DIR)/lib$(LIB_NAME).so

SRC_DIR = src
LIB_DIR = lib
BUILD_DIR = build
BIN_DIR = bin

SRCS = src/bases.c src/hash.c src/senhas.c src/cifras.c
HEADERS = include/bases.h include/hash.h include/senhas.h include/cifras.h
MAIN = app/main.c
TARGET_ESTAT = $(BIN_DIR)/programa_estat
TARGET_DINAM = $(BIN_DIR)/programa_dinam
OBJS = build/bases.o build/hash.o build/senhas.o build/cifras.o

TEST_SRC = testes/testes_main.c
TEST_TARGET = $(BIN_DIR)/testes_runner

PREFIX ?= /usr/local
INST_LIB = $(PREFIX)/lib
INST_INC = $(PREFIX)/include/$(LIB_NAME)

all: $(LIB_ESTAT) $(LIB_DINAM) $(TARGET_ESTAT) $(TARGET_DINAM)

clean:
	rm -rf $(LIB_DIR) $(BUILD_DIR) $(BIN_DIR)

run: $(TARGET_ESTAT)
	./$(TARGET_ESTAT)

run-dinamico: $(TARGET_DINAM)
	./$(TARGET_DINAM)

test: $(TEST_TARGET)
	./$(TEST_TARGET)


install: $(LIB_ESTAT) $(LIB_DINAM) $(HEADERS)
	mkdir -p $(INST_LIB) $(INST_INC)
	cp $(LIB_ESTAT) $(INST_LIB)/
	cp $(LIB_DINAM) $(INST_LIB)/
	cp $(HEADERS) $(INST_INC)/

$(BUILD_DIR)/main.o: $(MAIN) $(HEADERS)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET_ESTAT): $(BUILD_DIR)/main.o $(LIB_ESTAT)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $< $(LIB_ESTAT) -o $@

$(TARGET_DINAM): $(BUILD_DIR)/main.o $(LIB_DINAM)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $< -o $@ -L$(LIB_DIR) -l$(LIB_NAME) -Wl,-rpath,'$$ORIGIN/../$(LIB_DIR)'

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c 
	mkdir -p $(BUILD_DIR)
	$(CC) $(LIBFLAG) $(CFLAGS) -c $< -o $@ 

$(LIB_ESTAT): $(OBJS) 
	mkdir -p $(LIB_DIR)
	ar rcs $@ $^ 

$(LIB_DINAM): $(OBJS) 
	mkdir -p $(LIB_DIR)
	$(CC) -shared -o $@ $^

$(TEST_TARGET): $(TEST_SRC) $(LIB_ESTAT) $(HEADERS) 
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(TEST_SRC) $(LIB_ESTAT) -o $@

$(BUILD_DIR)/bases.o: include/bases.h
$(BUILD_DIR)/cifras.o: include/cifras.h
$(BUILD_DIR)/hash.o: include/hash.h
$(BUILD_DIR)/senhas.o: include/senhas.h

.PHONY: all clean run run-dinamico test install