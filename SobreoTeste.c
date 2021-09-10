#include "project_lib.h"

void geraSobreTeste (void)
{
    FILE *Sobre; // 
    Sobre = fopen ("REFERENCIAL_TEÓRICO.TXT", "w");
       
    
	if ( Sobre == NULL )
	{
		printf ("\nErro ao abrir as informações do teste!");
		getch();
		exit(0);
	}
	
	fprintf(Sobre,"REFERENCIAL TEÓRICO\n");
	fprintf(Sobre,"===================\n\n");
	
    fprintf(Sobre, "Segundo Albert Merabian, em seu livro “Silent Messages”, o poder de influência das palavras não passa de 7%%, enquanto a forma como as palavras\n"); 
	fprintf(Sobre, "são ditas e a fisiologia representam 38%% e 55%% deste poder, respectivamente.\n\n");
	
	fprintf(Sobre, "Para Merabian 55%% do impacto da comunicação é não-verbal. Corresponde à postura, gestos e contato visual da pessoa enquanto se comunica.\n\n");
	
	fprintf(Sobre, "O tom da voz representa 38%% do impacto da comunicação.\n\n");
	
	fprintf(Sobre, "Por fim, as palavras propriamente ditas detêm 7%% do impacto da comunicação.\n\n");
	
	fprintf(Sobre, "Assim sendo, conclui Merabian, não é o que dizemos, mas como dizemos que faz a diferença na comunicação.\n\n");
	
	fprintf(Sobre, "As portas da percepção são os nossos sentidos, nossos olhos, nariz, ouvidos, boca e pele, nossos únicos pontos de contato com o mundo exterior.\n");
	fprintf(Sobre, "Da mesma forma que utilizamos os sentidos para filtrarmos as experiências, utilizamos os sentidos para estruturar nosso pensamento e nossa comunicação.\n\n");
	
	fprintf(Sobre, "De acordo com a Programação Neurolinguística existem os seguintes sistemas representacionais.\n\n");
	
	fprintf(Sobre, "- Auditivo\n");
	fprintf(Sobre, "- Digital\n");
	fprintf(Sobre, "- Cinestésico\n");
	fprintf(Sobre, "- Visual\n\n");
	
	fprintf(Sobre, "Algumas pessoas captam melhor as mensagens do mundo exterior através da audição, são as pessoas chamadas auditivas.\n");
	fprintf(Sobre, "Outras pessoas sentem necessidade de perguntar muito, necessitam de muitas informações e fatos. Estas são as digitais.\n");
	fprintf(Sobre, "As cinestésicas aprendem melhor por meio das sensações táteis, como o tato, a temperatura, a umidade, as sensações internas e as emoções.\n");
	fprintf(Sobre, "Já as pessoas visuais aprendem melhor quando se valendo da visão.\n\n");
	
	fprintf(Sobre, "Cada pessoa tem um sistema representacional predominante e adequar a comunicação ao sistema representacional dominante dela é fundamental"); 
	fprintf(Sobre, " para diálogos eficientes.\n\n");
	
    fclose (Sobre);

    system("notepad REFERENCIAL_TEÓRICO.TXT");
}

int main()
{
	system("cls");
	geraSobreTeste();
   	return(0);
}


	
	
