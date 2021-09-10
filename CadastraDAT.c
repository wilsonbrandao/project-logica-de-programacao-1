/* Biblioteca Utilizada */
#include "project_lib.h"

/* Função que grava os registros no arquivo DAT */
void gravarNoDAT(void)
{
	int   i; /*inicializa variavel local de indice */
    FILE *Arq; /* Inicializa ponteiro Arq para armazenar arquivo DAT */

	Arq = fopen ("TESTE_SISTEMA_REPRESENTACIONAL.DAT", "w"); /* Abre o arquivo DAT em modo write */
	if ( Arq == NULL ) /*Verifica se o arquivo foi aberto corretamente */
	{
		printf ("\nErro ao abrir o arquivo!");
		getch(); /*Aguarda o pressionar de uma tecla */
		exit(0);
	}	

	for ( i=0 ; i<5; i++ ) /* Loop FOR para gravar registros no arquivo DAT */
	{
		fwrite ( &reg[i], sizeof(reg[i]), 1, Arq ); 
		if (ferror(Arq)) /* Verifica se o registro foi gravado */
		{
			printf ("\nErro ao gravar o registro [%i]", i+1); /*Mostra qual registro não foi gravado */
			getch(); /*Aguarda o pressionar de uma tecla */
			break;
		} 
	}
	
	fclose (Arq); /* Fecha o arquivo armazenado em Arq */
	system("cls"); /*limpa a tela */
	printf ("\nArquivo TESTE_SISTEMA_REPRESENTACIONAL.DAT gerado com sucesso!");
	getch(); /*Aguarda o pressionar de uma tecla */
}

/* Função Principal */
int main()
{
   gravarNoDAT(); /* Chama a função que grava os registros no arquivo DAT */
   return(0);
}
