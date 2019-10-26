Especificação

Sejam os TADs PONTO e CIRCULO, definidos na imagem anexa. Desenvolva um programa cliente (denominado main.c) que crie um ponto p e um círculo r (definidos pelo usuário através do stdin) e chame a função distancia(PONTO* p, CIRCULO* r) para calcular a distância e, consequentemente, verificar se p é interior, exterior ou pertence à circunferência r, imprimindo o resultado.

Sabe-se que um ponto p é interior a um círculo r se a distância entre p e o ponto central do círculo é menor que o raio de r; ainda, um ponto é considerado pertencente à circunferência se a distância entre os pontos for o próprio raio. A distância em questão é dada por uma equação que pode ser encontrada na segunda imagem anexa.

Por fim, acima da função distancia(PONTO*, CIRCULO*) deve constar um comentário justificando a escolha do .c onde a mesma foi implementada.

Modificações nos .h propostos serão aceitas mediante justificativa através dos comentários.

O output deverá seguir o seguinte padrão:

    printf("O ponto é interior à circunferência.\nDistância: %.2f\n", dist);
    printf("O ponto é exterior à circunferência.\nDistância: %.2f\n", dist);
    printf("O ponto pertence à circunferência.\nDistância: %.2f\n", dist);

A entrega deverá ser feita através de um .zip contendo os arquivos .c, .h e o makefile.

Exemplo de Entrada

2 5
3 2 5

Exemplo de saída

O ponto é interior à circunferência.
Distância: 3.16
