CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

SRCS = board.c minimax.c run.c
SRC_DIR = src
OBJS = $(SRCS:.c=.o)
OBJ_DIR = headers
TARGET = chess_ai


all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^


%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $< -I$(OBJ_DIR)


clean:
	rm -f $(OBJS) $(TARGET)