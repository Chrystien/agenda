#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct{
    char tel[15];
    char ema[40];
    char nom[40];
}agenda;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	int op, m, b;
	int i = 1;
	int d= 0;
	
	char nome[40];
	agenda *pon = (agenda*) calloc (i,sizeof(agenda));
	
	do{
	
	printf("--------AGENDA--------\n");
	printf("------Menu------\n");
	printf("Escolha a opção: \n");
	printf("1- Cadastrar\n");
    printf("2- Pesquisar cliente\n");
	printf("3- excluir cliente\n");
	printf("4- Listar todos\n");
	printf("5- Sair\n");
	scanf("%d", &op);
	
	switch(op){
	case 1:
		printf("1- Cadastrar\n");
	    printf("Informe o nome: \n ");
		scanf("%s", &pon[i-1].nom);
		printf("Informe o telefone: \n");
	    scanf("%s", &pon[i-1].tel);
		printf("Informe o email: \n");
		scanf("%s", &pon[i-1].ema);
		printf("Número de registro: %d\n", i);
		i++;
		pon = (agenda*) realloc(pon, i * sizeof(agenda));
		break;

	case 2:
		printf("2- pesquisar cliente\n");
		printf("Nome: ");
		scanf(" %[^\n]s",nome);
			for(m = 0; m <= i; m++){
				d = stricmp(nome,pon[m].nom);
				if(d == 0)
				{
				printf("Numero de registro %i\n",(m+1));
				printf("Nome: %s\n",pon[m].nom);
				printf("Telefone: %s\n",pon[m].tel);
				printf("Email: %s\n",pon[m].ema);
					}
				}
				break;
	case 3:
		printf("3- excluir cliente\n");
		printf("Numero de Registro: ");
		scanf("%i",&b);
			if(b <= i){
			printf("Nome: %s\n",pon[b-1].nom);
			printf("Telefone: %s\n",pon[b-1].tel);
			printf("Email: %s\n",pon[b-1].ema);
			
			printf("Cadastro excluido\n");
			for(m = 0; m <= i; m++){
			if((b - 1) != m){
			    strcpy(pon[d].nom,pon[m].nom);
			    strcpy(pon[d].tel,pon[m].tel);
				strcpy(pon[d].ema,pon[m].ema);
			d++; 
						}
					}
			pon = (agenda*) realloc(pon, d * sizeof(agenda));
			i--;	
			}else
			printf("Registro não encontrado\n"); 
				break;
	case 4:
		printf("Listar todos\n");
		for(m = 0; m < (i - 1); m++)
				{
		printf("Numero de registro %i\n",(m+1));
		printf("Nome: %s\n",pon[m].nom);
		printf("Telefone: %s\n",pon[m].tel);
		printf("Email: %s\n",pon[m].ema);
				}
		break;
	case 5:
		printf("Sair\n");
		break;
	default: 
	   printf("Opção inválida!\n");
		}
    system("pause");
	system("cls");
	}while((op < 5) || (op < 0));
	pon = NULL;
	return 0;
}
