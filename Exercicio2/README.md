# Exercício 2

## Especificação

Construa um TAD lista sequencial que possua os métodos necessários para receber um conjunto de números inteiros e retornar, ao final, uma lista sem repetições - ou seja, uma lista sequencial onde cada número apareça somente uma vez, respeitando a ordem de inserção.

A implementação esperada deve resolver o problema de modo ótimo (eficiente). Sendo assim, no output, deve-se imprimir na tela, além da lista sem repetições e seu número de elementos, a quantidade de comparações realizadas para a criação da mesma. Atente-se ao fato de que a quantidade de comparações leva em consideração somente as comparações necessárias para verificar se o número está ou não presente na lista.

Por fim, sabe-se que o tamanho máximo de itens aceitos na lista é 100. Logo, caso a mesma possua um número superior de elementos, apenas a frase “Lista cheia. Impossível realizar o processamento.” deverá ser impressa.

A entrega deverá ser feita através de um .zip contendo os arquivos .c, .h e o makefile.


### Exemplo de Entrada

Recebe-se a quantidade de itens a serem inseridos na primeira linha e os itens em si, separados por espaços, na segunda linha.

```
4
3 2 3 4
```

### Exemplo de saída

Imprime-se a lista final, sem repetições, com seus respectivos elementos separados por um “\t” na primeira linha, o número de elementos na segunda e a quantidade total de comparações para criação da mesma na terceira.

```
3    2    4    
Tamanho da lista: 3
Total de comparações: 4
```