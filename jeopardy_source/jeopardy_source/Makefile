CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SOURCES = jeopardy.c questions.c players.c
OBJECTS = $(SOURCES:.c=.o)
EXE = jeopardy.exe

all: $(EXE)

$(EXE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJECTS) $(EXE)
