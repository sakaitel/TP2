CC = gcc
CFLAGS = -Wall -Iinclude

SRCS = src/bases.c src/senhas.c
MAIN = app/main.c
TARGET = build/programa

TEST_SRC = testes/testes_main.c
TEST_TARGET = build/testes_runner

all: $(TARGET)

$(TARGET): $(SRCS) $(MAIN)
	mkdir -p build
	$(CC) $(CFLAGS) $(SRCS) $(MAIN) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

run-dinamico:
	./$(TARGET)

test: $(SRCS) $(TEST_SRC)
	mkdir -p build
	$(CC) $(CFLAGS) $(SRCS) $(TEST_SRC) -o $(TEST_TARGET)
	./$(TEST_TARGET)

install: $(TARGET)
	mkdir -p bin
	cp $(TARGET) bin/

clean:
	rm -rf build bin