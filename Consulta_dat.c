/* Biblioteca Utilizada */
#include "project_lib.h"

/* Função para consultar o arquivo .DAT e gravar no arquivo .TXT */
void consultaDAT (void)
{
    registro aux;
	
    FILE *Quest; /* questionário */
    Quest = fopen ("QUESTIONÁRIO_1.TXT", "w"); /*Abre o arquivo TXT em modo Write */
    
    FILE *Arq;
	Arq = fopen ("TESTE_SISTEMA_REPRESENTACIONAL.DAT", "r"); /*recebe o .dat */
    
    
	if ( Quest == NULL ) /* Verifica se o arquivo na varialvel Quest foi gerado */
	{
		printf ("\nErro ao gerar o Questionário!");
		getch();
		exit(0);
	}	
    
	if ( Arq == NULL ) /* Verifica se o arquivo na varialvel Arq foi aberto corretamente*/
	{
		printf ("\nNenhum teste cadastrado!");
		getch();
		exit(0);
	}	
	
	/* Inicia variaveis do Cabeçalho do Arquivo */
	int i = 0;
    char Nrofrase[] = {"NroFrase"};
    char frase[] = {"Frase"};
    char cinestesico[] = {"C"};
    char item1[] = {"item_1"};
    char auditivo[] = {"A"};
    char item2[] = {"item_2"};
    char visual[] = {"V"};
    char item3[] = {"item_3"};
    char digital[] = {"D"};
    char item4[] = {"item_4"};

	/* Escreve no arquivo o cabeçalho */
    fprintf(Quest, "%s  %30s %27s %s %60s %s %50s %s %54s %s\n",Nrofrase, frase, cinestesico, item1, auditivo, item2, visual, item3, digital, item4);
    fprintf(Quest, "======================================================================================================================================================================================================================================================================================================================================\n");
    
    /* Loop while que ler arquivo dat e grava os dados no arquivo txt */
    while(!feof(Arq))
    {
        fread ( &aux, sizeof(aux), 1, Arq );
		if (ferror(Arq)) /*verifica se leu o registro */
		{
			printf ("\nErro ao ler o registro do teste!");
			getch();
			break;
		}

		if ( !feof(Arq) ) /* verifica se é o fim do arquivo e grava os dados no arquivo .TXT */
		{
            fprintf(Quest, "%3d %60s %3d %-63s %3d %-53s %3d %-57s %3d %-60s\n",
                    aux.NroFrase,
                    aux.frase,
                    aux.cinestesico,
                    aux.item_1,
                    aux.auditivo,
                    aux.item_2,
                    aux.visual,
                    aux.item_3,
                    aux.digital,
                    aux.item_4
            );
	   }

    }
    fprintf(Quest, "======================================================================================================================================================================================================================================================================================================================================\n");
    fclose (Arq); /* fecha o arquivo .dat*/
    fclose(Quest); /* fecha o arquivo .txt*/
    printf ("\n\aSeu arquivo foi gerado com sucesso!"); 

    system("notepad QUESTIONÁRIO_1.txt"); /* Abre o arquivo no bloco de notas */
    getch (); /*Aguarda o pressionar de uma tecla */
}

/* Função principal */
int main()
{
	system("cls"); /*Limpa a tela */
	consultaDAT(); /*Chama a Função consultaDAT() */
   	return(0); 
}
