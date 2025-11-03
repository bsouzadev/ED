# Nome do executável final
TARGET = relogio

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -std=c11

# Arquivos-objeto
OBJS = main.o relogio.o

# Regra padrão (gera o executável)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compila o main.c
main.o: main.c relogio.h
	$(CC) $(CFLAGS) -c main.c

# Compila o relogio.c
relogio.o: relogio.c relogio.h
	$(CC) $(CFLAGS) -c relogio.c

# Executa o programa
run: $(TARGET)
	@echo "./relogio"
	@./$(TARGET)

# Limpa os arquivos compilados
clean:
	rm -f $(OBJS) $(TARGET)

# Recompila tudo do zero
rebuild: clean $(TARGET)
