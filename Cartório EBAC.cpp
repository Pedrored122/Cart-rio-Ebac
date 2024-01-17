//int main é a função principal, que vai fazer tudo que tá la dentro rodar
// {} é a divisória onde tu que estiver dentro é a função
// () mostram q é uma função
// printf é a função que leva o texto ao usuário
// "" tudo que tiver dentro é texto para o usuário
// \n é uma função para pular linha do texto
// setlocale é para setar a linguagem
// \t é para fazer paragráfo
// ; fim do comando
//char funciona muito bem para gerenciamento de strings
//%s = string
//string = conjunto de variáveis


#include <stdio.h>  //biblioteca de comunicação com o usuário (somente texto)
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável pelas strings

int registrar() //nova função que vai pra dentro do case
{
	setlocale(LC_ALL, "Portuguese");
	char arquivo[40]; // variável "char"= caracteres
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("\t Por favor digite o CPF que deseja cadastrar: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //comando responsável por copiar os valores de string
	
	FILE *file; //cria o arquivo
	file= fopen(arquivo, "w"); //cria o documento que armazena os dados a
	fprintf(file, cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" atualiza o documento
	fprintf(file, ","); //pular para o próximo
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
	printf("\t O CPF citado não existe no banco de dados!. \n\n");
}
	
    while(fgets(conteudo, 200, file) != NULL) //Pesquisar no banco de dados
{
	system("cls");
	printf("\t Aqui estão todas as informações cadastradas: \n\n");
	printf("%s", conteudo);
	printf("\n\n");
}
    system("pause");
}

int deletar()
{
	char cpf[40];

	printf("\t Digite o CPF referente ao usuário que deseja deletar: ");
	scanf("%s", cpf);
    system("cls");
    
    remove(cpf);

	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		system("cls");
		printf("\t O usuário não foi encontrado no sistema! \n\n");
		system("pause");
	}
}


int main() // Função principal
{
	int opcao=0; // Definindo Variáveis
	int loop=1; // Definir repetição/loop = quando acabar volta pro lugar marcado
	
	for(loop=1;loop=1;) // Início do loop
	{
	 system("cls"); // Limpar a Tela
	 
	 setlocale(LC_ALL, "Portuguese"); // Definir idioma
	
 	 printf("### Cartório da EBAC ###\n\n"); //Início do Menu
 	 printf("Escolha a opção desejada abaixo:\n\n");
	 printf("\t 1- Registrar Nomes\n\n");
	 printf("\t 2- Consultar Nome\n\n");
	 printf("\t 3- Deletar Nomes\n\n");
	 printf("Opção: "); // Fim do Menu
	
	 scanf("%d", &opcao); // Armazenamento a escikha do usuário
	
	 system("cls"); 
	
	 switch(opcao)
	   {
		 case 1:
			registrar(); //função chamada
			break; // fim do caso
			
		 case 2:
			consultar();
			break;
		
		 case 3:
			deletar();
			break;
		
		 default: // Quando é uma opção não existente
			printf("A opção escolhida não existe\n");
			system("pause");
			break;
	    }
    } // Fim do Loop
}

