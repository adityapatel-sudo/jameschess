CC = gcc
CFLAGS = -Wall -Wextra -std=c11

SRCS = board.c minimax.c run.c
OBJS = $(SRCS:.c=.o)
TARGET = chess_ai

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^


%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<


clean:
	rm -f $(OBJS) $(TARGET)