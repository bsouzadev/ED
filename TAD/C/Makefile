# Makefile para o TAD Racional

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -g

# Nome do executável
TARGET = main

# Arquivos-objeto
OBJS = main.o racional.o

# Regra padrão: compilar tudo
all: $(TARGET)

# Compilação do executável
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(CFLAGS)

# Compilar main.o
main.o: main.c racional.h
	$(CC) -c main.c $(CFLAGS)

# Compilar racional.o
racional.o: racional.c racional.h
	$(CC) -c racional.c $(CFLAGS)

# Executar o programa
run: $(TARGET)
	./$(TARGET)

# Limpar arquivos temporários
clean:
	rm -f *.o $(TARGET)
