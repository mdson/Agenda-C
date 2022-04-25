#include <stdlib.h>  
#include <stdio.h>  
#include <conio.h>  
#include <string.h>
typedef struct{ 
	char PrimeiroNome[15];  
	char UltimoNome[15];  
	char ddd[6];  
	char telefone[12];
}agenda;

FILE *aqagenda, *aqagenda2, *aqagenda3; 
agenda contatin;
void NomeTel(); 
void PrintContatos();
void PrimeiraParte(int *aux);
void Editar();
void Excluir();

int main(){ 
int opinici, numlistar, numadc = 0, sublistar, *aux, sair = 0, contador = 0, i = 0, auxcont, auxnumlistar, listarpornome = 1;
char letra[2], *ptrLetra, nome[15];
	printf("\t\t\t\t\tBem-vindo a agenda!\n");  
	printf("\n");  
	printf("Tecle ENTER para ir a agenda...");  
	getchar();  
	while(sair == 0){  
		aux = &opinici;  
		PrimeiraParte(aux);  
		switch(opinici){  
		case 1: 
		    system("cls");  
		    printf("\t\t\t\t\tAdicione um contato a sua agenda: \n");  
		    printf("\n");  
		    do{
		    NomeTel(); 
		    printf("\nContato armazenado!\n");  
		    printf("\n");  
		    do{ 
		    printf("\nDeseja armazenar mais algum contato? Digite 1 para SIM e 2 para NAO: ");  
		    scanf("%i", &numadc);  
		    }while(numadc < 1 || numadc > 2);   
		}while(numadc != 2);  
		    printf("\nTecle QUALQUER TECLA para continuar com a agenda e voltar ao menu inicial...");
		    getche();
		    system("cls");  
		break;
		
		    case 2:  
		        system("cls");  
		        printf("\t\t\t\t\tLista de Contatos: \n");  
		        printf("\n"); 
		        PrintContatos(); 
		        printf("\n\n");
		        printf("Acoes disponiveis: \n");
				printf("\n");
				printf("\tEditar contato (1)\n");
				printf("\tApagar contato (2)\n");
				printf("\tPesquisar por letra inicial do primeiro nome (3)\n");
				printf("\tVoltar ao menu inicial (4)\n");
				printf("\n");
				do{
				printf("Digite o numero, de uma das opcoes listadas, para realizar uma acao: ");
				scanf("%i", &sublistar);
				}while(sublistar < 1 || sublistar > 4);
				aqagenda = fopen("agenda.txt", "r+b");
				if(fread(&contatin, sizeof(agenda), 1, aqagenda) < 1 && sublistar != 4 || aqagenda == NULL){
					printf("\nNenhum contato na agenda para fazer alteracoes!\n");
					printf("\nTecle QUALQUER TECLA para continuar com a agenda e voltar ao menu inicial...");
					getche();
					system("cls");
					remove("agenda.txt");
					fclose(aqagenda);
					break;
				}else{
				fclose(aqagenda);
			}
				if(sublistar == 1){
					Editar();
					}
				if(sublistar == 2){
					Excluir();
				}
				if(sublistar == 3){
					aqagenda = fopen("agenda.txt", "r");
					system("cls");
					printf("\t\t\t\t\tListar contatos pela primeira letra do nome: \n");
					printf("\n");
					printf("Digite uma letra, de sua preferencia, para pesquisar \nnomes de contatos que comecem com essa letra: ");
					scanf("%1s", letra);
					printf("\n");
					printf("\nContatos Encontrados:   ");
					listarpornome = 1;
					while(fread(&contatin, sizeof(agenda), 1, aqagenda) == 1){
						if(contatin.PrimeiroNome[0] == letra[0] || letra[0] + 32 == contatin.PrimeiroNome[0] || letra[0] - 32 == contatin.PrimeiroNome[0]){
							printf("%i. %s %s\n\t\t\t", listarpornome, contatin.PrimeiroNome, contatin.UltimoNome);
							listarpornome++;
							}
						}
					if(listarpornome < 2){
						printf("\n\nNENHUM CONTATO COM ESSA INICIAL FOI ARMAZENADO!\n");
						}
						fclose(aqagenda);
					}
		        printf("\nTecle QUALQUER TECLA para continuar com a agenda e voltar ao menu inicial..."); 
		        getche(); 
		        system("cls"); 
		    break; 
		
		        case 3:  
		                system("cls");  
		                printf("\t\t\t\t\t************************\n");  
		                printf("\t\t\t\t\t***");  
		                printf(" AGENDA ENCERRADA ***\n");  
		                printf("\t\t\t\t\t************************\n");  
		                sair = 1;  
		            break; 

		            default: 
		                        printf("\n\n");  
		                        printf("Opcao invalida!\nDigite uma das opcoes listadas acima!\n");  
		                        printf("Pressione qualquer tecla...");  
		                        getche();  
		                        system("cls");  
    }
} 
system("pause"); 
return 0; 
}
void NomeTel(){
	aqagenda = fopen("agenda.txt", "a+b");
	if(aqagenda == NULL){
		printf("\n\nFalha na abertura do arquivo!\n");
	}  
	printf("\nDigite o primeiro nome do contato: ");  
	scanf("%14s", contatin.PrimeiroNome);  
	printf("Digite o ultimo nome do contato: ");  
	scanf("%14s", contatin.UltimoNome);  
	printf("Digite o DDD do contato: ");  
	scanf("%5s", contatin.ddd);  
	printf("Digite o numero do contato: ");  
	scanf("%11s", contatin.telefone); 
	fseek(aqagenda, 0, SEEK_END); 
	fwrite(&contatin, sizeof(agenda), 1, aqagenda); 
	fclose(aqagenda); 
}
void PrintContatos(){ 
	aqagenda = fopen("agenda.txt", "r+b");
	if(aqagenda == NULL){
		printf("\t\t\t\t     NENHUM CONTATO ADICIONADO!\n");
	}
	while(fread(&contatin, sizeof(agenda), 1, aqagenda) == 1){ 
		printf("\n\nContato:\n");  
		printf("\nPrimeiro nome do contato: %s", contatin.PrimeiroNome);  
		printf("\nUltimo nome do contato: %s", contatin.UltimoNome); 
		printf("\nNumero do contato: (%s) %s", contatin.ddd, contatin.telefone);  
		printf("\n\n");
	}
fclose(aqagenda); 
}
void PrimeiraParte(int *aux){  
	system("cls");  
	printf("\t\t\t\tOpcoes disponiveis na agenda: \n");  
	printf("\n");  
	printf("Adicionar um contato a agenda (1)\n");  
	printf("\nListar contatos da agenda (2)\n");  
	printf("\nSair da agenda (3)\n");  
	printf("\nDigite o numero, de uma das opcoes listadas, para realizar uma acao: ");  
	scanf("%i", aux);
}
void Editar(){
	char nome[15];
	short sla = 0, sla2 = 0;
	aqagenda = fopen("agenda.txt", "r+b");
	aqagenda2 = fopen("agenda2.txt", "w+b");
	printf("\n");
	printf("Digite, exatamente, o primeiro nome do contato o qual deseja editar: ");
	fflush(stdin);
	gets(nome);
	rewind(aqagenda);
	while(fread(&contatin, sizeof(agenda), 1, aqagenda) == 1){
		if(strcmp(nome,contatin.PrimeiroNome) != 0){
			sla2++;
		}else{
			sla++;
		}
	}
	if(sla == 0){
			fclose(aqagenda);
			fclose(aqagenda2);
			remove("agenda2.txt");
			printf("Nenhum contato com esse nome foi armazenado!");
		}else{
			rewind(aqagenda);
			while(fread(&contatin, sizeof(agenda), 1, aqagenda) == 1){
				if(strcmp(nome,contatin.PrimeiroNome) != 0){
					fwrite(&contatin, sizeof(agenda), 1, aqagenda2);
				}else{
					printf("\nDigite as novas informacoes do contato: \n");
					printf("\tDigite o primeiro nome do contato: ");  
					scanf("%14s", contatin.PrimeiroNome);  
					printf("\tDigite o ultimo nome do contato: ");  
					scanf("%14s", contatin.UltimoNome);  
					printf("\tDigite o DDD do contato: ");  
					scanf("%5s", contatin.ddd);  
					printf("\tDigite o numero do contato: ");  
					scanf("%11s", contatin.telefone);
					printf("\tContato editado!\n");
					fwrite(&contatin, sizeof(agenda), 1, aqagenda2);
				}
			}
		fclose(aqagenda);
		fclose(aqagenda2);
		remove("agenda.txt");
		rename("agenda2.txt","agenda.txt");
		}
	}
void Excluir(){
	char nome[15];
	short sla = 0, sla2 = 0;
	aqagenda = fopen("agenda.txt", "r+b");
	aqagenda2 = fopen("agenda2.txt", "w+b");
	aqagenda3 = fopen("agenda3.txt","w");
	printf("\nDigite, exatamente, o primeiro nome do contato o qual deseja editar: ");
	fflush(stdin);
	gets(nome);
	rewind(aqagenda);
	while(fread(&contatin, sizeof(agenda), 1, aqagenda) == 1){
		if(strcmp(nome,contatin.PrimeiroNome) != 0){
			sla2++;
		}else{
			sla++;
		}
	}
	if(sla == 0){
			fclose(aqagenda);
			fclose(aqagenda2);
			remove("agenda2.txt");
			printf("Nenhum contato com esse nome foi armazenado!");
		}else{
			rewind(aqagenda);
			while(fread(&contatin, sizeof(agenda), 1, aqagenda) == 1){
				if(strcmp(nome,contatin.PrimeiroNome) != 0){
					fwrite(&contatin, sizeof(agenda), 1, aqagenda2);
				}else{
					printf("\t\t\t\t\t\t\tContato apagado!\n");
					fwrite(&contatin, sizeof(agenda), 1, aqagenda3);
				}
			}
		fclose(aqagenda);
		fclose(aqagenda2);
		fclose(aqagenda3);
		remove("agenda.txt");
		remove("agenda3.txt");
		rename("agenda2.txt","agenda.txt");
		}
}
