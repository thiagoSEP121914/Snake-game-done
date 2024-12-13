Snake Game em C
Este é um simples jogo de Snake (Cobrinha), desenvolvido em C, onde o objetivo é controlar a cobrinha que cresce à medida que ela come a comida na tela. O jogo termina quando a cobrinha colide com as paredes ou com o próprio corpo.

Requisitos
Compilador de C (como GCC)
Sistema operacional compatível com a biblioteca conio.h (Windows ou sistemas com suporte)
Como Executar
Clone o repositório:

bash
Copiar código
git clone <URL_DO_REPOSITORIO>
Navegue até a pasta do projeto:

bash
Copiar código
cd SnakeGame
Compile o código usando o GCC:

bash
Copiar código
gcc snake.c -o snake
Execute o jogo:

bash
Copiar código
./snake
Controles
Setas do teclado: Movem a cobrinha para cima, baixo, esquerda e direita.
Esc: Encerra o jogo.
Objetivo
O objetivo do jogo é guiar a cobrinha para comer a comida (representada por um caractere especial, como '*') sem bater nas paredes ou no corpo da própria cobrinha. A cada comida consumida, a cobrinha cresce em tamanho.

Funcionalidades
Tela de Jogo: Exibição da cobrinha, comida e pontuação.
Crescente de Tamanho: A cobrinha cresce à medida que come a comida.
Fim de Jogo: O jogo termina quando a cobrinha bate nas paredes ou no seu próprio corpo.
Pontuação: A pontuação aumenta à medida que a cobrinha come a comida.
Como Jogar
Ao iniciar, a cobrinha começa a se mover automaticamente em uma direção.
Use as setas do teclado para alterar a direção da cobrinha.
Tente coletar a comida e evitar colisões.
Quando o jogo terminar, sua pontuação será exibida.
Licença
Este projeto está licenciado sob a MIT License. Veja o arquivo LICENSE para mais detalhes.

Contribuição
Sinta-se à vontade para fazer um fork deste projeto, adicionar novas funcionalidades ou melhorar a lógica do jogo. Qualquer contribuição será bem-vinda!

Tela do Jogo
Aqui você pode incluir uma imagem de exemplo do jogo em execução, caso tenha alguma captura de tela.
