CC = gcc
CFLAGS = -Wall -g
OBJ = src/main.o src/tower.o src/utils.o

TARGET = jenga_game

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET) tower_log.txt

