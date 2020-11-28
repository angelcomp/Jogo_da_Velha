/*

*                        Ciência da Computação - PUC Poços de Caldas

* Modelagem e Construção de Aplicações 3D
* Professor: Will Machado
* 2º periodo

* Aluna: Angelica dos Santos
* Contato: santosangelicassp@gmail.com

* Trabalho: Implementação de Transformações Afins em OpenGL
* Data entrega projeto: 03/10/2020


*                                       Proposta:

*       > Implementar o jogo da velha em Open GL


*   1 - Desenhar o tabuleiro.

*   2 - Posição da jogada de um jogador deve ser definida através do clique do mouse.

*   3 - A cada jogada, exibir um texto informando se é a vez do jogador 'X' ou do jogador 'O'.

*   4 - Exibir um texto informando quando um jogador ganhar o jogo e quando empatar.

*   5 - Exibir o nome do desenvolvedor da aplicação em algum lugar da tela.

*   6 - Assim que o jogo terminar, questionar o usuário se ele deseja reiniciar o jogo.

*   Entregar todo o código do projeto (executável e código-fonte), inserindo o arquivo executável na raiz.

*       |~~~~~~~~~~~~~~~~~~~~~~ É RECOMENDADO COMPILAR NO TERMINAL (LINUX) ~~~~~~~~~~~~~~~~~~~~~~~~|

*       |  >>>>>>>>>        gcc -Wall veia.c -lGL -lGLU -lglut -lGLEW -o veia           <<<<<<<<<  |

*       |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|

*/

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <string.h>
#include <stdio.h>
#include <math.h>


void background(void);
void desenhoString(void *fonte,const char string[],float a,float b);
void hashtag(void);
void printaFigura(void);
void confereWin(void);

float x,y;

int casaClicada = 0;
int dentro = 1;
int start = 0;
int veia = 0;
int check = 0;
int player = 0;
int ganhador = 100;
int i = 0;
int restart = 0;

int jogadas[9] = {9, 9, 9, 9, 9, 9, 9, 9, 9};

void ganhouH1(void)
{
    glColor3f(0, 1, 0);
    glLineWidth(25);
    glBegin(GL_LINES);
        glVertex2i(54, 465);
        glVertex2i(521, 465);
    glEnd();
}
void ganhouH2(void)
{
    glColor3f(0, 1, 0);
    glLineWidth(25);
    glBegin(GL_LINES);
        glVertex2i(54, 320);
        glVertex2i(521, 320);
    glEnd();
}
void ganhouH3(void)
{
    glColor3f(0, 1, 0);
    glLineWidth(25);
    glBegin(GL_LINES);
        glVertex2i(54, 159);
        glVertex2i(521, 159);
    glEnd();
}

void ganhouL1(void)
{
    glColor3f(0, 1, 0);
    glLineWidth(25);
    glBegin(GL_LINES);
        glVertex2i(135, 530);
        glVertex2i(135, 90);
    glEnd();
}
void ganhouL2(void)
{
    glColor3f(0, 1, 0);
    glLineWidth(25);
    glBegin(GL_LINES);
        glVertex2i(285, 530);
        glVertex2i(285, 90);
    glEnd();
}
void ganhouL3(void)
{
    glColor3f(0, 1, 0);
    glLineWidth(25);
    glBegin(GL_LINES);
        glVertex2i(436, 530);
        glVertex2i(436, 90);
    glEnd();
}

void ganhouD1(void)
{
    glColor3f(0, 1, 0);
    glLineWidth(25);
    glBegin(GL_LINES);
        glVertex2i(70, 520);
        glVertex2i(500, 95);
    glEnd();
}
void ganhouD2(void)
{
    glColor3f(0, 1, 0);
    glLineWidth(25);
    glBegin(GL_LINES);
        glVertex2i(70, 90);
        glVertex2i(500, 520);
    glEnd();
}

void confereWin()
{
    if(jogadas[0] == 1 && jogadas[1] == 1 && jogadas[2] == 1){
        ganhador = 1;
        dentro = 0;
        restart = 1;

        ganhouH1();
    }
    else if(jogadas[0] == 0 && jogadas[1] == 0 && jogadas[2] == 0) {
        ganhador = 2;
        dentro = 0;
        restart = 1;

        ganhouH1();
    }
    else if(jogadas[3] == 1 && jogadas[4] == 1 && jogadas[5] == 1){
        ganhador = 1;
        dentro = 0;
        restart = 1;

        ganhouH2();
    }
    else if(jogadas[3] == 0 && jogadas[4] == 0 && jogadas[5] == 0) {
        ganhador = 2;
        dentro = 0;
        restart = 1;

        ganhouH2();
    }
    else if(jogadas[6] == 1 && jogadas[7] == 1 && jogadas[8] == 1){
        ganhador = 1;
        dentro = 0;
        restart = 1;

        ganhouH3();
    }
    else if(jogadas[6] == 0 && jogadas[7] == 0 && jogadas[8] == 0) {
        ganhador = 2;
        dentro = 0;
        restart = 1;

        ganhouH3();
    }
    else if(jogadas[0] == 1 && jogadas[3] == 1 && jogadas[6] == 1){
        ganhador = 1;
        dentro = 0;
        restart = 1;

        ganhouL1();
    }
    else if(jogadas[0] == 0 && jogadas[3] == 0 && jogadas[6] == 0) {
        ganhador = 2;
        dentro = 0;
        restart = 1;

        ganhouL1();
    }
    else if(jogadas[1] == 1 && jogadas[4] == 1 && jogadas[7] == 1){
        ganhador = 1;
        dentro = 0;
        restart = 1;

        ganhouL2();
    }
    else if(jogadas[1] == 0 && jogadas[4] == 0 && jogadas[7] == 0) {
        ganhador = 2;
        dentro = 0;
        restart = 1;

        ganhouL2();
    }
    else if(jogadas[2] == 1 && jogadas[5] == 1 && jogadas[8] == 1){
        ganhador = 1;
        dentro = 0;
        restart = 1;

        ganhouL3();
    }
    else if(jogadas[2] == 0 && jogadas[5] == 0 && jogadas[8] == 0) {
        ganhador = 2;
        dentro = 0;
        restart = 1;

        ganhouL3();
    }
    else if(jogadas[0] == 1 && jogadas[4] == 1 && jogadas[8] == 1){
        ganhador = 1;
        dentro = 0;
        restart = 1;

        ganhouD1();
    }
    else if(jogadas[0] == 0 && jogadas[4] == 0 && jogadas[8] == 0) {
        ganhador = 2;
        dentro = 0;
        restart = 1;

        ganhouD1();
    }
    else if(jogadas[2] == 1 && jogadas[4] == 1 && jogadas[6] == 1){
        ganhador = 1;
        dentro = 0;
        restart = 1;

        ganhouD2();
    }
    else if(jogadas[2] == 0 && jogadas[4] == 0 && jogadas[6] == 0) {
        ganhador = 2;
        dentro = 0;
        restart = 1;

        ganhouD2();
    }
}

// PRINTA FIGURA
void printaFigura(void)
{
    player = (player % 2);
    if (dentro)
    {
        glPointSize(55);
        glLineWidth(15);

        if (player == 0) // XIS
        {
            glColor3f(1,0,0.5);
            glBegin(GL_LINES);
                glVertex2i(x-27.5,y-27.5);
                glVertex2i(x+27.5,y+27.5);
                glVertex2i(x+27.5,y-27.5);
                glVertex2i(x-27.5,y+27.5);
            glEnd();
        }

        else // circulo
        {
            glColor3f(1, 1, 1);
            float theta;
            int posX = x;
            int posY = y;
            int radio = 33;
            glBegin(GL_POLYGON);
                for(int i=0; i<360; i++)
                {
                    theta = i*3.14/180;
                    glVertex2f(posX + radio*cos(theta), posY + radio*sin(theta));
                }
            glEnd();
        }
        dentro = 0;
        printf("\nJOGADAS = %d", veia);
    }
}

void display() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 940 , 0, 580);

    glColor3f(0.419, 0.137, 0.556);

    background();
    //if(ganhador == 100) {
        hashtag();
    //}
}


void mouse(int button, int state, int mousex, int mousey) {
    x = mousex;
    y = 580 - mousey;

    if(button == GLUT_LEFT_BUTTON && state == GLUT_UP) {


        //BOTAO START
        if ((x >= 661 &&  x <= 887) && (y >= 303 && y <= 359))
        {
            start = 1;
            player = 1;
        }

        if(start) {

            //quadrante 1
            if((x >= 82 &&  x <= 203) && (y >= 407 && y <= 519)) {
                casaClicada = 0;
                if(jogadas[casaClicada] == 9)
                {
                    dentro = 1;
                    printaFigura();
                    jogadas[casaClicada] = player;
                    player ++;
                    veia ++;
                }
            }

            //quadrante 2
            else if((x >= 216 &&  x <= 363) && (y >= 407 && y <= 519)) {
                casaClicada = 1;
                if(jogadas[casaClicada] == 9)
                {
                    dentro = 1;
                    printaFigura();
                    jogadas[casaClicada] = player;
                    player ++;
                    veia ++;
                }
            }

            //quadrante 3
            else if((x >= 376 &&  x <= 494) && (y >= 407 && y <= 519)) {
                casaClicada = 2;
                if(jogadas[casaClicada] == 9)
                {
                    dentro = 1;
                    printaFigura();
                    jogadas[casaClicada] = player;
                    player ++;
                    veia ++;
                }
            }

            //quadrante 4
            else if((x >= 82 &&  x <= 203) && (y >= 248 && y <= 395)) {
                casaClicada = 3;
                if(jogadas[casaClicada] == 9)
                {
                    dentro = 1;
                    printaFigura();
                    jogadas[casaClicada] = player;
                    player ++;
                    veia ++;
                }
            }

            //quadrante 5
            else if((x >= 216 &&  x <= 363) && (y >= 248 && y <= 395)) {
                casaClicada = 4;
                if(jogadas[casaClicada] == 9)
                {
                    dentro = 1;
                    printaFigura();
                    jogadas[casaClicada] = player;
                    player ++;
                    veia ++;
                }
            }

            //quadrante 6
            else if((x >= 376 &&  x <= 494) && (y >= 248 && y <= 395)) {
                casaClicada = 5;
                if(jogadas[casaClicada] == 9)
                {
                    dentro = 1;
                    printaFigura();
                    jogadas[casaClicada] = player;
                    player ++;
                    veia ++;
                }
            }

            //quadrante 7
            else if((x >= 71 &&  x <= 203) && (y >= 105 && y <= 235)) {
                casaClicada = 6;
                if(jogadas[casaClicada] == 9)
                {
                    dentro = 1;
                    printaFigura();
                    jogadas[casaClicada] = player;
                    player ++;
                    veia ++;
                }
            }

            //quadrante 8
            else if((x >= 216 &&  x <= 363) && (y >= 105 && y <= 235)) {
                casaClicada = 7;
                if(jogadas[casaClicada] == 9)
                {
                    dentro = 1;
                    printaFigura();
                    jogadas[casaClicada] = player;
                    player ++;
                    veia ++;
                }
            }

            //quadrante 9
            else if((x >= 376 &&  x <= 494) && (y >= 105 && y <= 235)) {
                casaClicada = 8;
                if(jogadas[casaClicada] == 9)
                {
                    dentro = 1;
                    printaFigura();
                    jogadas[casaClicada] = player;
                    player ++;
                    veia ++;
                }
            }
            else {
                dentro = 0;
            }
            confereWin();
            if(veia == 9 && ganhador == 100) {
                ganhador = 50; //EMPATE, JA SE FORAM TODAS AS JOGADAS
            }
        }
    }

    else if ((button == GLUT_RIGHT_BUTTON && state == GLUT_UP) || restart == 1)
    {   glColor3f(0,0,0);

        glClearColor(0.7, 0.7, 0.7, 1000);
        glClear(GL_COLOR_BUFFER_BIT);
        start = 0;
        restart = 0;
        player = 0;
        veia = 0;
        for(i = 0; i < 9; i++)
        {
            jogadas[i] = 9;
        }
        glutPostRedisplay();
    }
}

void background(void) {

    //fundo roxo lado direito
    glColor3f(0.419, 0.137, 0.556);
    glBegin(GL_POLYGON);
        glVertex2f(580, 580);
        glVertex2f(550, 467);
        glVertex2f(550, 170);
        glVertex2f(580, 0);
        glVertex2f(940, 0);
        glVertex2f(940, 580);
    glEnd();
    glFlush();

    if(!start) {
        ganhador = 100;
        //frase inicio game
        glColor3f(1,1,0);
        desenhoString(GLUT_BITMAP_TIMES_ROMAN_24, "INÍCIO DO JOGO", 680, 400);

        //botao start
        glColor3f(0.8, 0.8, 0.8);
        glBegin(GL_POLYGON);
            glVertex2f(660, 360);
            glVertex2f(890, 360);
            glVertex2f(890, 300);
            glVertex2f(660, 300);
        glEnd();

        glColor3f(0, 0, 0);
        desenhoString(GLUT_BITMAP_TIMES_ROMAN_24, "START", 735, 325);
        glFlush();
    }
    else if (start == 1 && ganhador == 100 ){
        printf("\nPLAYER %d", player);
        if(player == 1)
        {
            glColor3f(1,1,1);
            desenhoString(GLUT_BITMAP_TIMES_ROMAN_24, "Vez do Jogador: 1", 690, 400);
            desenhoString(GLUT_BITMAP_TIMES_ROMAN_24, "     BOLINHA", 690, 350);
        }
        else if (player == 2)
        {
            glColor3f(1,0,0.2);
            desenhoString(GLUT_BITMAP_TIMES_ROMAN_24, "Vez do Jogador: 2", 690, 400);
            desenhoString(GLUT_BITMAP_TIMES_ROMAN_24, "          XIS", 690, 350);
        }
        glFlush();
    }
    else if (start == 1 && (ganhador == 1 || ganhador == 2)) {
        if (ganhador == 1)
        {
            glColor3f(1,1,1);
            desenhoString(GLUT_BITMAP_TIMES_ROMAN_24, "  AEEEE! JOGADOR 1 VENCEUU!", 558, 400);
            desenhoString(GLUT_BITMAP_TIMES_ROMAN_24, "      ~~ BOLINHA ~~", 620, 355);

            glColor3f(1,1,0);
            desenhoString(GLUT_BITMAP_TIMES_ROMAN_24, "   CLIQUE PARA JOGAR", 600, 180);
            desenhoString(GLUT_BITMAP_TIMES_ROMAN_24, "       NOVAMENTE", 620, 150);
        }
        else if (ganhador == 2)
        {
            glColor3f(1,1,1);
            desenhoString(GLUT_BITMAP_TIMES_ROMAN_24, "  AEEEE! JOGADOR 2 VENCEUU!", 558, 400);
            desenhoString(GLUT_BITMAP_TIMES_ROMAN_24, "       ~~ XIS ~~", 657, 355);

            glColor3f(1,1,0);
            desenhoString(GLUT_BITMAP_TIMES_ROMAN_24, "   CLIQUE PARA JOGAR", 600, 180);
            desenhoString(GLUT_BITMAP_TIMES_ROMAN_24, "        NOVAMENTE", 620, 150);
        }

        glFlush();
        start = 0;
        veia = 0;
    }
    else if (start == 1 && ganhador == 50){
        glColor3f(1,1,0);
        desenhoString(GLUT_BITMAP_TIMES_ROMAN_24, "DEU VEIA   T-T", 655, 400);

        desenhoString(GLUT_BITMAP_TIMES_ROMAN_24, "   CLIQUE PARA JOGAR", 600, 180);
        desenhoString(GLUT_BITMAP_TIMES_ROMAN_24, "        NOVAMENTE", 620, 150);
        restart = 1;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc,argv);

    glutInitWindowSize(940,580);
    glutInitWindowPosition(600,100);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutCreateWindow("Jogo da véia");

    glClearColor(0.7, 0.7, 0.7, 1000);
    glClear(GL_COLOR_BUFFER_BIT);

    glutDisplayFunc(display);

    glutMouseFunc(mouse);
    glutMainLoop();
}

void desenhoString(void *fonte,const char string[],float a,float b) {
	unsigned int i;
	glRasterPos2f(a,b);
	for(i=0;i<strlen(string);i++)
	{
		glutBitmapCharacter(fonte,string[i]);
	}
}

void hashtag(void) {
    glColor3f(0,0,0);

    desenhoString(GLUT_BITMAP_TIMES_ROMAN_24, "Jogo da Velha!", 219, 550);

    desenhoString(GLUT_BITMAP_TIMES_ROMAN_24, "Desenvolvido por Angelica", 175, 30);

    //tamanho linhas
    glLineWidth(10);

    //cor das linhas
    glColor3f(0.419, 0.137, 0.556);

    //linha horizontal inferior
    glBegin(GL_LINES);
        glVertex2f(80, 240);
        glVertex2f(500, 240);
    glEnd();
    glFlush();

    //linha horizontal superior
    glBegin(GL_LINES);
        glVertex2f(80, 400);
        glVertex2f(500, 400);
    glEnd();
    glFlush();

    //linha vertical esquerda
    glBegin(GL_LINES);
        glVertex2f(210, 100);
        glVertex2f(210, 520);
    glEnd();
    glFlush();

    //linha vertical direita
    glBegin(GL_LINES);
        glVertex2f(370, 100);
        glVertex2f(370, 520);
    glEnd();
    glFlush();
}
