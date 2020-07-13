//Leitura de arquivo
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{

	FILE *pont_arq, *aux;
	char texto_str[900];
	char texto [1000000];
	char nome[20], nome1[20], nome2[20];
	int i,j,l,result;
	int soma = 0, cesar;
	printf("Nome do arquivo de entrada (sem o \".txt\"): ");
	scanf("%s", nome1);
	printf("Palavra chave para decriptografar: ");
	scanf(" %[^\n]s", nome);
	printf("Nome do arquivo de sainda (sem o \".txt\"): ");
	scanf("%s", nome2);
	for(i=0;i<strlen(nome);i++){
		//printf(" %d", nome[i]);
		soma+= nome[i]; 
	}
	
	/*
	printf("\n");
	for(i=0;i<strlen(nome);i++){
		printf(" %c", nome[i]);
	}
	*/
	//printf("\n%d", soma%26);
	cesar = soma%26;
	//abrindo o arquivo_frase em modo "somente leitura"
	strcat(nome1,".txt");
	pont_arq = fopen(nome1, "r");
	if(pont_arq == NULL){
		printf("aquivo não encontrado");
		return 0;
	}
	//enquanto não for fim de arquivo o looping será executado
	//e será impresso o texto
	while (fgets(texto_str, 900, pont_arq) != NULL){
		strcat(texto,texto_str);
	}

	j = strlen(texto);
	for(i=0; i< j;i++){
		texto[i] -= cesar;
		printf("%c",texto[i]);
	}
	fclose(pont_arq);
	strcat(nome2,".txt");
	pont_arq = fopen("dec.txt", "wt");  // Cria um arquivo texto para gravação
	if (pont_arq == NULL) // Se nào conseguiu criar
	{
		printf("Problemas na CRIACAO do arquivo\n");
		return 0;
	}
	result = fprintf(pont_arq,texto);				  
	if (result == EOF)	    
	printf("Erro na Gravacao\n");
	//fechando o arquivo
	fclose(pont_arq);

	return (0);
}
/*
FILE *arq;
  int i;
  int result;
  clrscr();
  arq = fopen("ArqGrav.txt", "wt");  // Cria um arquivo texto para gravação
  if (arq == NULL) // Se nào conseguiu criar
  {
     printf("Problemas na CRIACAO do arquivo\n");
     return;
  }
  for (i = 0; i<10;i++)
  {
// A funcao 'fprintf' devolve o número de bytes gravados 
// ou EOF se houve erro na gravação
      result = fprintf(arq,"Linha %d\n",i);  					  
      if (result == EOF)		    
	  printf("Erro na Gravacao\n");
  }
  fclose(arq);*/