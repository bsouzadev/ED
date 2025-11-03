# 🧠 Estrutura de Dados — Listas, Pilhas e Filas

Repositório dedicado à resolução de exercícios práticos sobre **estruturas de dados lineares** em linguagem de programação (C, Python, ou outra de sua escolha).  
Os problemas exploram o comportamento e a implementação de **listas encadeadas**, **pilhas (stacks)**, **filas (queues)** e **deques (double-ended queues)**.

---

## 📘 Conteúdo

### 1. Lista Encadeada — Maior sequência de zeros
Escreva uma função que receba uma **lista encadeada contendo apenas 0 e 1** e retorne as **posições inicial e final da maior sequência de zeros consecutivos**.  
Em caso de empate, deve-se retornar a primeira ocorrência.

**Exemplo:**  
Entrada: `{0,1,1,0,0,0,1,0,0,0}`  
Saída: `pini = 4`, `pfim = 6`, sequência `S = {0,0,0}`

---

### 2. Pilha — Verificação de Parênteses
Implemente um programa que verifique se uma **expressão matemática** possui os parênteses agrupados corretamente.  
Condições:
1. O número de parênteses abertos e fechados deve ser igual.  
2. Todo parêntese aberto deve ser fechado na ordem correta.

**Exemplos:**  
- Inválida: `((A+B)` ou `A+B(` (violam a condição 1)  
- Inválida: `)A+B(` ou `(A+B))–(C+D)` (violam a condição 2)

---

### 3. Pilha — Sequência de Operações I e R
Considere uma pilha com os elementos `1, 2, 3, 4`.  
Determine a sequência de operações **Inserção (I)** e **Remoção (R)** necessária para obter a saída desejada.  

**Exemplo:**  
Saída desejada: `4 3 2 1`  
Operações: `IIIIRRRR`

---

### 4. Pilha — Validação de Sequências Possíveis
Verifique se é possível gerar as sequências **325641** e **154623** a partir de uma pilha com inserções e remoções como no exercício anterior.  
Caso possível, descreva a sequência de operações (I e R).  
Explique também **por que certas sequências são impossíveis**, como `4231`.

---

### 5. Pilha — Regra de Validação
Defina uma **regra simples** para determinar se uma sequência de operações `I` e `R` é **válida**.  
(Dica: nunca se pode remover de uma pilha vazia.)

---

### 6. Pilha — Verificação de Palíndromos
Escreva uma função que utilize uma **pilha de caracteres** para verificar se uma palavra é um **palíndromo**, isto é, se pode ser lida da mesma forma da esquerda para a direita e vice-versa.

**Exemplo:**  
`arara` → palíndromo  
`casa` → não é palíndromo

---

### 7. Pilha — Estado Final
Dadas as operações:  
`I(10), I(20), R, I(30), I(45), I(21), R, R`  
Determine o **estado final da pilha**.

---

### 8. Pilha — String da forma xCy
Escreva um algoritmo que determine se uma **string de entrada** é da forma `xCy`,  
onde:
- `x` contém apenas as letras `A` e `B`;
- `y` é o **inverso de x**.

Exemplo:  
Entrada: `ABABBA C ABBABA` → válida  
Observação: o programa deve **ler caractere a caractere**, sem acessar diretamente toda a string.

---

### 9. Deque — Implementação com Lista Encadeada
Implemente um **TAD Deque (Double-Ended Queue)** utilizando **listas simplesmente encadeadas**.  
O Deque deve conter as operações:
- `insere_inicio()`
- `insere_fim()`
- `remove_inicio()`
- `remove_fim()`

---

## 🧩 Objetivos de Aprendizagem

- Compreender o comportamento de estruturas de dados lineares.
- Aplicar operações básicas de **inserção** e **remoção** em listas, pilhas e filas.
- Praticar o raciocínio algorítmico e a análise de **ordem de operações**.
- Implementar TADs (Tipos Abstratos de Dados) com **listas encadeadas**.

---

## 🚀