//int main � a fun��o principal, que vai fazer tudo que t� la dentro rodar
// {} � a divis�ria onde tu que estiver dentro � a fun��o
// () mostram q � uma fun��o
// printf � a fun��o que leva o texto ao usu�rio
// "" tudo que tiver dentro � texto para o usu�rio
// \n � uma fun��o para pular linha do texto
// setlocale � para setar a linguagem
// \t � para fazer paragr�fo
// ; fim do comando
//char funciona muito bem para gerenciamento de strings
//%s = string
//string = conjunto de vari�veis


#include <stdio.h>  //biblioteca de comunica��o com o usu�rio (somente texto)
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel pelas strings

int registrar() //nova fun��o que vai pra dentro do case
{
	setlocale(LC_ALL, "Portuguese");
	char arquivo[40]; // vari�vel "char"= caracteres
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("\t Por favor digite o CPF que deseja cadastrar: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //comando respons�vel por copiar os valores de string
	
	FILE *file; //cria o arquivo
	file= fopen(arquivo, "w"); //cria o documento que armazena os dados a
	fprintf(file, cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" atualiza o documento
	fprintf(file, ","); //pular para o pr�ximo
	fclose(file);
	
    printf("\t Por favor digite o NOME que deseja cadastrar: ");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("\t Por favr digite o SOBRENOME que deseja cadastrar: ");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("\t Por favor digite o CARGO que deseja cadastrar: ");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);
    
    system("pause");
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
    char cpf[40];
    char conteudo[200];
	
    printf("\t Digite o CPF que deseja consultar: ");
    scanf("%s", cpf);
  	
    FILE *file;
    file = fopen(cpf, "r"); //Apenas ler o conteudo
  	
    if(file == NULL) // SE NAO HOUVER
{
	system("cls");
	printf("\t O CPF citado n�o existe no banco de dados!. \n\n");
}
	
    while(fgets(conteudo, 200, file) != NULL) //Pesquisar no banco de dados
{
	system("cls");
	printf("\t Aqui est�o todas as informa��es cadastradas: \n\n");
	printf("%s", conteudo);
	printf("\n\n");
}
    system("pause");
}

int deletar()
{
	char cpf[40];

	printf("\t Digite o CPF referente ao usu�rio que deseja deletar: ");
	scanf("%s", cpf);
    system("cls");
    
    remove(cpf);

	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		system("cls");
		printf("\t O usu�rio n�o foi encontrado no sistema! \n\n");
		system("pause");
	}
}


int main() // Fun��o principal
{
	int opcao=0; // Definindo Vari�veis
	int loop=1; // Definir repeti��o/loop = quando acabar volta pro lugar marcado
	
	for(loop=1;loop=1;) // In�cio do loop
	{
	 system("cls"); // Limpar a Tela
	 
	 setlocale(LC_ALL, "Portuguese"); // Definir idioma
	
 	 printf("### Cart�rio da EBAC ###\n\n"); //In�cio do Menu
 	 printf("Escolha a op��o desejada abaixo:\n\n");
	 printf("\t 1- Registrar Nomes\n\n");
	 printf("\t 2- Consultar Nome\n\n");
	 printf("\t 3- Deletar Nomes\n\n");
	 printf("Op��o: "); // Fim do Menu
	
	 scanf("%d", &opcao); // Armazenamento a escikha do usu�rio
	
	 system("cls"); 
	
	 switch(opcao)
	   {
		 case 1:
			registrar(); //fun��o chamada
			break; // fim do caso
			
		 case 2:
			consultar();
			break;
		
		 case 3:
			deletar();
			break;
		
		 default: // Quando � uma op��o n�o existente
			printf("A op��o escolhida n�o existe\n");
			system("pause");
			break;
	    }
    } // Fim do Loop
}

