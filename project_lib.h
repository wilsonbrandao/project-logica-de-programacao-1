/* Bibliotecas Ultilizadas*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>

/* Tipos pré-definidos */
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
    {1, "Eu tomo decisões importantes baseado em",       	   0,"intuição",                                                             0, "o que me soa melhor",                                   0, "o que me parece melhor",                                       0, "um estudo preciso e minucioso do assunto"},
    {2, "Durante uma discussão eu sou mais influenciado por",  0,"se eu entro em contato ou não com os sentimentos reais do outro",      0, "o tom da voz da outra pessoa",                          0, "se eu posso ou não ver o argumento da outra pessoa",           0, "a lógica do argumento da outra pessoa"},
    {3, "Eu comunico mais facilmente o que se passa comigo",   0,"pelos sentimentos que compartilho"	,                                0, "pelo tom da minha voz",                                 0, "do modo como me visto e aparento",                             0, "pelas palavras que escolho"},
    {4, "É muito fácil para mim",                              0,"escolher os móveis mais confortáveis",                                 0, "achar o volume e a sintonia ideais num sistema de som", 0, "escolher as combinações de cores mais ricas e atraentes",      0, "selecionar o ponto mais relevante relativo a um assunto interessante"},
    {5, "Eu me percebo assim",           	                   0,"eu sou muito sensível à maneira como a roupa veste o meu corpo",       0, "se estou muito em sintonia com os sons dos ambientes",  0, "eu respondo fortemente às cores e à aparência de uma sala",    0, "se sou muito capaz de raciocinar com fatos dados novos"}
};

typedef struct{
    char name[100]; 
    char pront[20]; // -> prontuário
    char arquivo[120]; // nome do arquivo
}person;

person user;

