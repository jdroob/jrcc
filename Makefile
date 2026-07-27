CC = cc
MAKE = make
INCLUDES = include
SRC = src
OBJ = obj
BIN = bin
LIBS = -lm
ARGS =
CFLAGS = -Wall -Wconversion -g -O0 -Wno-sequence-point -Wno-unused-function
DEBUG_CFLAGS = -DDEBUG
EXE = jrcc

SOURCES = $(wildcard $(SRC)/*.c)
OBJECTS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES))

.PHONY: default setup clean

default: $(EXE)

$(EXE): $(OBJECTS)
	$(CC) $(OBJECTS) -I$(INCLUDES) $(LIBS) -o $(BIN)/$(EXE)

$(OBJ)/%.o: $(SRC)/%.c | setup
	$(CC) -c $< -I$(INCLUDES) $(LIBS) $(CFLAGS) -o $@

setup:
	mkdir -p $(OBJ)
	mkdir -p $(BIN)

debug: CFLAGS+=$(DEBUG_CFLAGS)
debug: default

clean:
	rm -rf $(OBJ) $(BIN)

run:
	@$(BIN)/$(EXE) $(ARGS)
