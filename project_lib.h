/* Bibliotecas Ultilizadas*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>

/* Tipos pr�-definidos */
typedef struct
{
    int  NroFrase;
    char frase[100];
    int  cinestesico;
    char item_1[100];
    int  auditivo;
    char item_2[100];
    int  visual;
    char item_3[100];
    int  digital;
    char item_4[100];
}registro;

registro  reg[5] = 
{
    {1, "Eu tomo decis�es importantes baseado em",       	   0,"intui��o",                                                             0, "o que me soa melhor",                                   0, "o que me parece melhor",                                       0, "um estudo preciso e minucioso do assunto"},
    {2, "Durante uma discuss�o eu sou mais influenciado por",  0,"se eu entro em contato ou n�o com os sentimentos reais do outro",      0, "o tom da voz da outra pessoa",                          0, "se eu posso ou n�o ver o argumento da outra pessoa",           0, "a l�gica do argumento da outra pessoa"},
    {3, "Eu comunico mais facilmente o que se passa comigo",   0,"pelos sentimentos que compartilho"	,                                0, "pelo tom da minha voz",                                 0, "do modo como me visto e aparento",                             0, "pelas palavras que escolho"},
    {4, "� muito f�cil para mim",                              0,"escolher os m�veis mais confort�veis",                                 0, "achar o volume e a sintonia ideais num sistema de som", 0, "escolher as combina��es de cores mais ricas e atraentes",      0, "selecionar o ponto mais relevante relativo a um assunto interessante"},
    {5, "Eu me percebo assim",           	                   0,"eu sou muito sens�vel � maneira como a roupa veste o meu corpo",       0, "se estou muito em sintonia com os sons dos ambientes",  0, "eu respondo fortemente �s cores e � apar�ncia de uma sala",    0, "se sou muito capaz de raciocinar com fatos dados novos"}
};

typedef struct{
    char name[100]; 
    char pront[20]; // -> prontu�rio
    char arquivo[120]; // nome do arquivo
}person;

person user;

