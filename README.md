# Estruturas de Dados em C

Este repositório apresenta implementações de **estruturas de dados lineares** desenvolvidas em **C**, utilizando o conceito de **TAD (Tipo Abstrato de Dado)**.  
Cada estrutura foi separada em arquivos `.h` e `.c` para reforçar o encapsulamento e a modularidade.

## 🧠 Estruturas Implementadas

- **Pilha com Arranjo (Estática)**
  - Implementada como TAD (`pilha.h` e `pilha.c`)
  - Operações: `push`, `pop`, `top`, `isEmpty`, `isFull`
  - Uso de vetor fixo e controle por índice de topo

- **Fila com Arranjo Circular**
  - Implementada como TAD (`fila.h` e `fila.c`)
  - Operações: `enqueue`, `dequeue`, `front`, `isEmpty`, `isFull`
  - Índices circulares evitam deslocamento de elementos no vetor

- **Lista Encadeada Simples**
  - Implementada como TAD (`lista.h` e `lista.c`)
  - Cada nó contém um valor e ponteiro para o próximo
  - Inserção, remoção e busca em posições arbitrárias

- **Lista Duplamente Encadeada**
  - Implementada como TAD (`lista_dupla.h` e `lista_dupla.c`)
  - Cada nó possui ponteiros para o anterior e o próximo
  - Inserção e remoção otimizadas em ambas as extremidades

## 🧩 Organização do Projeto

Na pasta **TAD** cada **TAD** separado, com:
- **Arquivo `.h`**: definição das estruturas e protótipos das funções.  
- **Arquivo `.c`**: implementação das funções do TAD.  
- **Arquivo `main.c`**: exemplo de uso e testes.

## ⚙️ Compilação e Execução

Para compilar uma estrutura individual ou use o Makefile:

```bash
gcc main.c estrutura.c -o programa
./programa
