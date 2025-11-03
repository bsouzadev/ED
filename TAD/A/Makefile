# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -std=c99 -g

# Nome do executável (SEM ESPAÇOS)
TARGET = programa_funcionario

# Arquivos objeto
OBJS = main.o funcionario.o

# Regra principal
all: $(TARGET)

# Ligação dos objetos para criar o executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compilação do main.c
main.o: main.c funcionario.h
	$(CC) $(CFLAGS) -c main.c

# Compilação do funcionario.c
funcionario.o: funcionario.c funcionario.h
	$(CC) $(CFLAGS) -c funcionario.c

# Limpeza dos arquivos gerados
clean:
	rm -f *.o $(TARGET).exe

# Limpeza mais agressiva (inclui executável sem .exe no Windows)
clean-all:
	rm -f *.o $(TARGET) $(TARGET).exe

# Recompilar tudo
rebuild: clean all

# Executar o programa
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean clean-all rebuild run