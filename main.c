/* Projeto da Disciplina de LG1A1 - Instituto Federal de Educação, Ciência e Tecnologia de São Paulo */
/* Bibliotecas Utilizadas */
#include "project_lib.h"

//oi né

/*Protótipo das funções*/
void login();
char menu (void);
void admin ( char tecla );
char verificaRepostas(int resp);
char captura_teste();
int main();

/* Construção das funçõess */

/* Corpo do programa */
int main()
{
	char  opc, teste = 'v';
	setlocale (LC_ALL, "portuguese");

	do{
		login();
	
		if(strcmp(user.name, "MASTER") == 0)
		{
			system("cls");
	
			do{	
				opc = menu();
				admin(opc);
			}
			while ( opc != '0');
			exit(0);
			teste = 'f';
		}
		else{
				teste = captura_teste(); getch();	
			}
	}while( teste == 'f'); /* quando o usuário comum tenta fazer o teste (se logando) sem existir o dat volta do início*/

	return(0);
}

void login(){
	setlocale (LC_ALL, "portuguese");
	int i;
	char opc, vname = 'w'; 
	
	do{
		
			system ("cls"); system ("mode 94,17"); system ("color 70"); /*estilizando o prompt */
			printf("\n\n   Faça login para que possa realizar o teste para identificar seu perfil representacional!\n");
			printf("______________________________________________________________________________________________\n\n");
			printf("\n\n                           |   Digite seu nome: ");
			fflush(stdin); gets(user.name); /*recebendo nome do usuário*/
			
			if((user.name[0] == ' ' && user.name[1] == ' ') || (user.name[0] == ' ' && user.name[1] == '\n') || user.name[0] == '\n' || user.name[0] == '\0' || user.name[1] == '\0' || (user.name[0] == ' ' && user.name[1] == '\0')) {
				printf("\n                                    Digite um nome válido!"); getch();
				vname = 'w';
			}
			else{
				vname = 'r';
			}	 
		
		
	}while(vname == 'w');
	
	/*passa o nome digitado para maiúsculo e substitui os espaaços em branco do nome  por "_" */
	for(i=0; i<strlen(user.name); i++){
		user.name[i] = toupper(user.name[i]);
		
		if(user.name[i] == ' ') 
			user.name[i] = '_';	 	
	}

	/*Limpa o nome do arquivo*/
	for(i=0; i<strlen(user.arquivo); i++) /*evita que tenha lixo de memória no nome do arquivo colocando null terminator nele todo*/
		user.arquivo[i] = '\0'; 


	if(strcmp(user.name, "MASTER") != 0){ /*strcmp -> se for igual retorna 0 */
		
		char vpront = 'w' ;
		
		/*recebe e verifica se o prontuário está correto - 7 caracteres*/
		do{
			system("cls"); system ("mode 94,17"); system ("color 70");
		
			printf("\n\n   Faça login para que possa realizar o teste para identificar seu perfil representacional!\n");
			printf("______________________________________________________________________________________________\n\n");
			printf("\n\n                           |   Digite seu nome: %s", user.name);

			printf("\n\n                           |   Digite seu prontuário: ");
			fflush(stdin); gets(user.pront); /*recebe o prontuário*/
			
			if(strlen(user.pront) == 7)
				vpront = 'r'; /*prontuário está correto*/
			else{
				printf("\n                                  Prontuário inválido!"); 
				getch();
			}
		}while(vpront == 'w'); 
		
		/*Gera o nome do arquivo - concatena as strings colocando underline*/
		strcat(user.arquivo, "RESULTADO_");
		strcat(user.arquivo, user.name);
		strcat(user.arquivo, "_");
		strcat(user.arquivo, user.pront);
		strcat(user.arquivo, ".txt");
	}
	else{
		strcat(user.arquivo, "RESULTADO_");
		strcat(user.arquivo, user.name);
		strcat(user.arquivo, ".txt");
	}
}

/* Função para mostrar Menu e capturar escolha do usuário */
char menu (void) /*mostra o menu e captura escolha do usuário*/
{ 
  char   escolha; /* Inicializa variável local para capturar escolha do usuário */
  do /* Loop DO WHILE para construção do menu */
  {	setlocale(LC_ALL, ""); /* Configura caracteres para idioma padrão */
	system ("cls"); system ("mode 56,17"); system ("color 70"); 
    printf ("\n========================================================");
	printf ("\n         TESTE DOS SISTEMAS REPRESENTACIONAIS          ");
    printf ("\n========================================================");
	printf ("\n         1. Cadastrar Questionário                     ");
	printf ("\n         2. Visualizar questionário                    ");
	printf ("\n         3. Realizar teste                             ");
	printf ("\n         4. Sobre o teste                              ");
	printf ("\n         F. Fim                                        ");
	printf ("\n========================================================");
	printf ("\n         Escolha -> "); fflush(stdin); escolha = getche(); /* Captura escolha do usuário */

	/*Testa se o usuário digitou opção inválida */
	if(escolha == 'f' || escolha == 'F') escolha = '0';
	
	/*verifica se o que recebeu está correto*/
	if (escolha < '0' || escolha > '4') 
	{	system ("cls");
		printf ("\n ERRO AO ESCOLHER!");
		getch(); 
	}
  }
  while ( escolha < '0' || escolha > '4' ); /* Mantem Loop enquanto escolhas forem menor que 0 e maior que 4 */
  return(escolha); /* Retorna escolha */
}


void admin ( char tecla ) /*a partir da escolheceu direciona para uma parte do projeto*/
{
   switch ( tecla )
   {
   	 case 'f': case 'F': exit(0); 							break;
   	 case '1': system("CadastraDAT.exe");					break;
   	 case '2': system("Consulta_dat.exe");					break;
   	 case '3': captura_teste(); getch();					break;
   	 case '4': system("SobreoTeste");	                    break;
   }	
}



char quest; /*recebe se deve ou não reexibir/exibir a questão -> y = deve reexibir/exibir n = não deve reexibir/exibir*/
int respostas[5]; /*armazena quais respostas (1,2,3 ou 4) já foram escolhidas */

char verificaRepostas(int resp){ /*f quando deu errado e tem que repetir todo o item e v quando pode passar para o próximo*/
	int i; 
	
	
	if(respostas[1] == 1 && respostas[2] == 2 && respostas[3] == 3 && respostas[4] == 4){ /*quando verifica que a questão foi respondida inteira*/																								
		respostas[1] = 0;                                                                  /* zera o vetor*/  
		respostas[2] = 0; 
		respostas[3] = 0;
		respostas[4] = 0;
	}
	
	/*verifica se a resposta é menor que 1 ou maior que 4 -> errado*/
	if(resp < 1 || resp > 4){
        printf("\n  Apenas valores entre 1 e 4 são permitidos!"); getch();
        quest = 'y'; /*tem que reexibir*/
        system("cls");
		return 'f';
	}
	else{
		for(i = 1; i < 5; i++){
			if(resp == i){
				if(respostas[i] == resp){
			        quest = 'y'; /*reexibir*/
			        system("cls");
					return 'f';
				}
				else{
					respostas[i] = resp;
					quest = 'y';
					return 'v';
				}		
			}					
		}
	}
}

char captura_teste(){
	char resultado[20], opc;
	int i = 0;
	
	
	
	FILE * Arq;
	Arq = fopen ("TESTE_SISTEMA_REPRESENTACIONAL.DAT", "r");
	
	if(Arq == NULL){
		if(strcmp(user.name, "MASTER") != 0){
		printf("\n              Não há nada registrado no teste! Contate o Master do software!");
		return ('f');
		getch();			
		}
		else{
			printf("\n\n             Não há nada registrado no teste! ");
			return ('f');
			getch();	
		}
	}
	
	registro regaux;
	registro reg[5];
	

    while(!feof(Arq))
    {
        fread ( &regaux, sizeof(regaux), 1, Arq );

		if (ferror(Arq)){
			printf ("\nErro ao ler o registro do CADASTRO.DAT");
			return 'f';
			getch();
		}
		/* Testar se leu EOF */
		if ( !feof(Arq) ){
		    reg[i] = regaux;
            i++;
	    }
    }
    fclose (Arq);
    

	int cine = 0, aud = 0, visu = 0, digi = 0;
    
    for(i = 0; i<5; i++)
    {
        	quest = 'y';
        	
			do{
				
				if(quest == 'y'){
					system("cls"); system ("mode 82,27"); system ("color 70");
					printf ("\n\n         Nas frases a seguir, pontue com:\n\n         4 a que melhor descreve você;\n         3 a próxima melhor descrição; \n         2 a próxima melhor; e \n         1 aquela que menos descreve você.");
		            printf("\n\n         %d. %s         \n\n         [a]%s\n         [b]%s\n         [c]%s\n         [d]%s",
		            reg[i].NroFrase, reg[i].frase, reg[i].item_1, reg[i].item_2, reg[i].item_3, reg[i].item_4); 
					printf("\n\n         [a] --> ");
					quest = 'n';
				}
					
				fflush(stdin); scanf("%i", &reg[i].cinestesico);
			}while(verificaRepostas(reg[i].cinestesico) == 'f');
			
			cine += reg[i].cinestesico;
			
			
            
            do{
            	          	
            	if(quest == 'y'){
            		system("cls"); system ("mode 82,27"); system ("color 70");
					printf ("\n\n         Nas frases a seguir, pontue com:\n\n         4 a que melhor descreve você;\n         3 a próxima melhor descrição; \n         2 a próxima melhor; e \n         1 aquela que menos descreve você.");
		            printf("\n\n         %d. %s         \n\n         [a]%s\n         [b]%s\n         [c]%s\n         [d]%s",
		            reg[i].NroFrase, reg[i].frase, reg[i].item_1, reg[i].item_2, reg[i].item_3, reg[i].item_4); 
					printf("\n\n         [a] --> %i", reg[i].cinestesico);  
					printf("\n\n         [b] --> ");   
					quest = 'n';
				}
				 
				fflush(stdin); scanf("%i", &reg[i].auditivo);
				
				opc = verificaRepostas(reg[i].auditivo);
			}while(opc == 'f');
			
			aud += reg[i].auditivo;
			
			
			do{				
				
				if(quest == 'y'){
					system("cls"); system ("mode 82,27"); system ("color 70");
					printf ("\n\n         Nas frases a seguir, pontue com:\n\n         4 a que melhor descreve você;\n         3 a próxima melhor descrição; \n         2 a próxima melhor; e \n         1 aquela que menos descreve você.");
		            printf("\n\n         %d. %s         \n\n         [a]%s\n         [b]%s\n         [c]%s\n         [d]%s",
		            reg[i].NroFrase, reg[i].frase, reg[i].item_1, reg[i].item_2, reg[i].item_3, reg[i].item_4); 
					printf("\n\n         [a] --> %i", reg[i].cinestesico);  
					printf("\n\n         [b] --> %i", reg[i].auditivo);  
					printf("\n\n         [c] --> ");  
					quest = 'n';
				}
				
				fflush(stdin); scanf("%i", &reg[i].visual);
				
				opc = verificaRepostas(reg[i].visual);
			}while(opc == 'f');
				
			visu += reg[i].visual;	
				
			do{	
				
				if(quest == 'y'){
					system("cls"); system ("mode 82,27"); system ("color 70");
					printf ("\n\n         Nas frases a seguir, pontue com:\n\n         4 a que melhor descreve você;\n         3 a próxima melhor descrição; \n         2 a próxima melhor; e \n         1 aquela que menos descreve você.");
		            printf("\n\n         %d. %s         \n\n         [a]%s\n         [b]%s\n         [c]%s\n         [d]%s",
		            reg[i].NroFrase, reg[i].frase, reg[i].item_1, reg[i].item_2, reg[i].item_3, reg[i].item_4); 
					printf("\n\n         [a] --> %i", reg[i].cinestesico);  
					printf("\n\n         [b] --> %i", reg[i].auditivo);  
					printf("\n\n         [c] --> %i", reg[i].visual );  
					printf("\n\n         [d] --> "); 
					quest = 'n';
				}
				fflush(stdin); scanf("%i", &reg[i].digital);
				
				opc = verificaRepostas(reg[i].digital);
			}while(opc == 'f');  
			
			digi += reg[i].digital;
    }

	system("cls");
   	
    cine *= 2;
    aud *= 2;
    visu *= 2;
    digi *= 2;
    int maior;
    
    if(cine > aud && cine > visu && cine > digi)
    	strcpy(resultado, "Cinestésico");
    else
    	if(aud > cine && aud > visu && aud > digi)
    		strcpy(resultado, "Auditivo");
    	else
    		if(visu > cine && visu > aud && visu > digi)
    			strcpy(resultado, "Visual");
			else
				strcpy(resultado, "Digital");	
    	

    char arquivoTeste[256];

    snprintf (arquivoTeste, sizeof(arquivoTeste), "%s", user.arquivo);
    FILE * resultTest = fopen(arquivoTeste, "w");

    fprintf(resultTest, "======================================================= PERFIL REPRESENTACIONAL DE %s ===================================================\n", user.name);
    fprintf(resultTest, "                                        %d%% Visual    %d%% Auditivo    %d%% Cinestésico   %d%% Digital\n", visu, aud, cine, digi);
	fprintf(resultTest, "=========================================================================================================================================\n");

    fprintf(resultTest, "Algumas pessoas captam melhor as mensagens do mundo exterior através da auditivo, são as pessoas chamadas auditivas.\n");
    fprintf(resultTest, "Outras pessoas sentem necessidade de perguntar muito, necessitam de muitas informações e fatos. Estas são as digitais.\n");
    fprintf(resultTest, "As cinestésicas aprendem melhor por meio das sensacões táteis, como o tato, a temperatura, a umidade, as sensações internas e as emoções.\n");
    fprintf(resultTest, "Já as pessoas visuais aprendem melhor quando se valendo da visão.\n\n");

    fprintf(resultTest, "=========================================================================================================================================\n");
    fprintf(resultTest, "Seu perfil: %s\n", resultado);
    fprintf(resultTest, "=========================================================================================================================================\n");

    //Termina a gravação e exibe o arquivo
    fclose(resultTest);
    system(user.arquivo);
    return 'v';
    
}

