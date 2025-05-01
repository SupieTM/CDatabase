SRC = main.c ./src/*.c
HEADER = ./include/*.h
FLAG = -Wall -g
G = gcc
EXEC = DB

$(EXEC) : $(SRC)
	$(G) $^ $(FLAG) -o $@

clean:
	del /p *.exe
