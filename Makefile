
# code details

EXE_DIR = t
EXE = $(EXE_DIR)

SRC= main.c commands.c split.c pipeline.c redirect.c determine.c colour.c list.c

# generic build details

CC=      gcc
COPT=    -g
CFLAGS= -lm -g

# compile to  object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(COPT) -c -o $@ $<

# build executable

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS)  -o $(EXE)

# clean up compilation

clean:
	rm -f $(OBJ) $(EXE)

# dependencies

main.o:  main.c commands.c
commands.o: commands.c commands.h
split.o:	split.c commands.h
pipeline.o:	pipeline.c commands.h
redirect.o:	redirect.c commands.h
determine.o:	determine.c commands.h
colour.o:	colour.c commands.h
list.o:	list.c commands.h
