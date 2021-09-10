#include "project_lib.h"

void geraSobreTeste (void)
{
    FILE *Sobre; // 
    Sobre = fopen ("REFERENCIAL_TE�RICO.TXT", "w");
       
    
	if ( Sobre == NULL )
	{
		printf ("\nErro ao abrir as informa��es do teste!");
		getch();
		exit(0);
	}
	
	fprintf(Sobre,"REFERENCIAL TE�RICO\n");
	fprintf(Sobre,"===================\n\n");
	
    fprintf(Sobre, "Segundo Albert Merabian, em seu livro �Silent Messages�, o poder de influ�ncia das palavras n�o passa de 7%%, enquanto a forma como as palavras\n"); 
	fprintf(Sobre, "s�o ditas e a fisiologia representam 38%% e 55%% deste poder, respectivamente.\n\n");
	
	fprintf(Sobre, "Para Merabian 55%% do impacto da comunica��o � n�o-verbal. Corresponde � postura, gestos e contato visual da pessoa enquanto se comunica.\n\n");
	
	fprintf(Sobre, "O tom da voz representa 38%% do impacto da comunica��o.\n\n");
	
	fprintf(Sobre, "Por fim, as palavras propriamente ditas det�m 7%% do impacto da comunica��o.\n\n");
	
	fprintf(Sobre, "Assim sendo, conclui Merabian, n�o � o que dizemos, mas como dizemos que faz a diferen�a na comunica��o.\n\n");
	
	fprintf(Sobre, "As portas da percep��o s�o os nossos sentidos, nossos olhos, nariz, ouvidos, boca e pele, nossos �nicos pontos de contato com o mundo exterior.\n");
	fprintf(Sobre, "Da mesma forma que utilizamos os sentidos para filtrarmos as experi�ncias, utilizamos os sentidos para estruturar nosso pensamento e nossa comunica��o.\n\n");
	
	fprintf(Sobre, "De acordo com a Programa��o Neurolingu�stica existem os seguintes sistemas representacionais.\n\n");
	
	fprintf(Sobre, "- Auditivo\n");
	fprintf(Sobre, "- Digital\n");
	fprintf(Sobre, "- Cinest�sico\n");
	fprintf(Sobre, "- Visual\n\n");
	
	fprintf(Sobre, "Algumas pessoas captam melhor as mensagens do mundo exterior atrav�s da audi��o, s�o as pessoas chamadas auditivas.\n");
	fprintf(Sobre, "Outras pessoas sentem necessidade de perguntar muito, necessitam de muitas informa��es e fatos. Estas s�o as digitais.\n");
	fprintf(Sobre, "As cinest�sicas aprendem melhor por meio das sensa��es t�teis, como o tato, a temperatura, a umidade, as sensa��es internas e as emo��es.\n");
	fprintf(Sobre, "J� as pessoas visuais aprendem melhor quando se valendo da vis�o.\n\n");
	
	fprintf(Sobre, "Cada pessoa tem um sistema representacional predominante e adequar a comunica��o ao sistema representacional dominante dela � fundamental"); 
	fprintf(Sobre, " para di�logos eficientes.\n\n");
	
    fclose (Sobre);

    system("notepad REFERENCIAL_TE�RICO.TXT");
}

int main()
{
	system("cls");
	geraSobreTeste();
   	return(0);
}


	
	
