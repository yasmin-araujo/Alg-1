# Exercício 3

## Especificação

Rudinei adora abrir múltiplas abas em seu navegador. Às vezes existem tantas abas abertas que já não é mais possível ver o nome ou o ícone das mesmas. Sendo assim, sua função é ajudar o professor com um algoritmo que gerencie e organize todas as suas abas abertas.

O programa deve simular a abertura e o reposicionamento de novas abas. 
Deve-se utilizar uma lista encadeada (esta poderá ser simplesmente ou duplamente encadeada, contudo, 
a sua escolha deve ser justificada) para armazenar as guias, que possuem duas informações: 
título (40 caracteres) e URL (512 caracteres). 
O programa deverá possuir as seguintes funcionalidades em seu menu (já listadas com seus respectivos IDs para entrada):

- Incluir nova aba (1): inclui-se o novo elemento no final da lista encadeada, recebendo como parâmetros o título e a URL do mesmo;

- Alterar posição da aba (2): considerando que as abas possuem posições numeradas (1, 2, 3, …, n), 
recebe-se como entrada a nova posição da aba (que deve ser 1 ou maior) e o seu título; 
a partir disso o nó da aba é reposicionado de forma com que ela fique na posição indicada. 
Caso o título informado não exista, o programa não deve fazer nada, apenas retornar ao menu de opções. 
Caso a nova posição exceda o número total de abas, basta reposicioná-la como último elemento da lista;

- Imprimir (3): é listado na tela a configuração das abas. Cada linha deve conter somente uma aba, no seguinte formato: [titulo1] [url1]\n … [titulon] [urln]\n;

- Sair (4): toda a memória alocada é desalocada e o programa é finalizado.


### Exemplo de Entrada

Abaixo, após abertas 3 abas, alteramos uma delas para a posição 1 e outra para a posição 10; em seguida, o resultado é impresso na tela e o programa é finalizado.

```
1
Youtube 
http://www.youtube.com.br
1
USP
http://www.usp.br
1
Facebook
http://www.facebook.com
2
USP
1
2
Youtube
10
3
4
```

### Exemplo de saída

```
USP http://www.usp.br
Facebook http://www.facebook.com
Youtube  http://www.youtube.com.br
```