
//bibiliotecas
//----------------
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <unistd.h>

//constante
//-----------------
#define coluna 40
#define linhas 20
#define SNAKE_MAX_LEN 256
#define foods 10
//-------------------
// variaveis globais
// vetor undimensional que forma uma matriz
char board[coluna * linhas];
int isGameOver = 0;
int score = 1;
char teclapressionada = 'w';


/* se x ou y estiver nos extremos da matriz
(linha 0 coluna 0)
ele prenche o espaço com #
*/

void limpatela(){
    system("cls"); //limpar a tela.

}

void fill_board(){
    int x,y;
    for(y = 0; y < linhas; y++){
        for(x = 0; x < coluna; x++){
            if(x == 0|| y == 0|| x == coluna -1|| y == linhas -1){
                board[y * coluna + x] = '#';
            }else{
                 board[y * coluna + x] = ' ';
            }
        }
    }

}

/*
a funcao abaixo imprime cada caractere com o putch
e quebra a linha usando o \n
*/
void print_board(){
    int x,y;

    printf("SNAKE GAME\n");

    for(y = 0; y < linhas; y++){
        for(x = 0; x < coluna; x++){
            putch(board[y * coluna + x]);

        }
        putch('\n');
    }
}

struct Snakepart {
    int x , y;

};

struct Snake{
    int lenght;
    struct Snakepart part[SNAKE_MAX_LEN];
};


//desenhar a cobra
//int snakeX = 5;
//int snakeY = 5;

struct Snake snake;

struct Food{
    int x, y;
    int consumed;
};
struct Food food[foods];

void draw_snake(){
    //board[snakeY * coluna + snakeX] = '@';
    int i;
    for(i = snake.lenght-1; i > 0; i--){
        board[snake.part[i].y * coluna + snake.part[i].x] = 'o';
       // snake.part[i];
    }
    board[snake.part[0].y * coluna + snake.part[0].x] = 'O';
}
//mover a cobra
void move_snake(int deltaX, int deltaY){
    int i;

    for(i = snake.lenght-1; i > 0; i--){
        snake.part[i] = snake.part[i-1];

    }
    snake.part[0].x += deltaX;
    snake.part[0].y += deltaY;
}

//leitura do teclado para a cobra
char read_keyboard(){
     int ch = getch();
//condicionais para mover cima, lados, baixo.
    switch(ch){
        case 'w':
                move_snake(0, -1);
                teclapressionada = 'w';
                    break;
        case 's':
                move_snake(0, 1);
                teclapressionada = 's';
                    break;
        case 'a':
                move_snake(-1,0 );
                teclapressionada = 'a';
                    break;
        case 'd':
                move_snake(1, 0);
                teclapressionada = 'd';
                    break;

    }
}

void drawn_food(){
    int i;
    for(i = 0; i < foods; i++){
        if(!food[i].consumed){
            board[food[i].y * coluna + food[i].x] = '+';
        }
    }
}

void setup_food(){

    food[0].x = 1 + rand() % (coluna -2);
    food[0].y = 1 + rand() % (linhas -2);
    food[0].consumed = 0;


}

void gerar_food(){

    food[0].x = 1 + rand() % (coluna -2);
    food[0].y = 1 + rand() % (linhas -2);
    food[0].consumed = 0;

}

void setup_snake(){
    snake.lenght =1;
    snake.part[0].x = 1 + rand() % (coluna -2);
    snake.part[0].y = 1 + rand() % (linhas  -2);

}

void game_rules(){
    int i;

    for(i = 0; i< foods; i++){
        if(!food[i].consumed ){
            if(food[i].x == snake.part[0].x && food[i].y == snake.part[0].y){
                    food[i].consumed = 1;
                    snake.lenght++;
                    score++;
                    gerar_food();
               }
            }
    }
        if(snake.part[0].x == 0 || snake.part[0].x == coluna -1 ||
           snake.part[0].y == 0 || snake.part[0].y == linhas -1){
                isGameOver = 1;
           }

        for(i = 1; i < snake.lenght; i++){
            if(snake.part[0].x == snake.part[i].x &&
                snake.part[0].y == snake.part[i].y ){
                    isGameOver = 1;
                    break;
            }
        }
}

void auto_move(){
    switch(teclapressionada){
        case 'w': move_snake(0, -1); break;
        case 's': move_snake(0, 1); break;
        case 'a': move_snake(-1, 0); break;
        case 'd': move_snake(1, 0); break;
    }
}
/*void menu(){

    do{
        printf("===============================\n");
        printf("        SNAKE GAME DONE        \n");
        printf("===============================");
        Printf("         NOVO JOGO             \n");

    }while(continuar == 0)

}*/


int main(int argc, char** argv){
    //variables

    srand(time(0));

    snake.lenght = 0;
    snake.part[0].x = 1 + rand() % (coluna -2);
    snake.part[0].y = 1 + rand() % (linhas -2);

    setup_snake();
    setup_food();

   while(!isGameOver){
        limpatela();
        fill_board();
        drawn_food();
        draw_snake();
        game_rules();
        print_board();
        printf("PONTOS: %d\n",score * 10);
        if(!isGameOver){
           // le o teclado se houver uma entrada
           if(kbhit()){

                read_keyboard();
           }else {
                auto_move();
                usleep(100000);

           }

        }

    }

    printf("FIM DE JOGO!!");
    while(1) getch();

    return 0;
}


