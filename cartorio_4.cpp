#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar o valor das strings
	
	FILE *file; //cria o aquivo
	file = fopen(arquivo, "w"); //criar o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //acessa o arquivo e o "a" significa atualizar uma infroma��o/incluir mais informa��o no arquivo
	fprintf(file, ","); //salva uma informa��o dentro do arquivo/incluir a v�rgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //acessa o arquivo e o "a" significa atualizar uma informa��o/incluir mais informa��o no arquivo
	fprintf(file,nome); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //acessa o arquivo e o "a" significa atualizar uma informa��o/incluir mais informa��o no arquivo
	fprintf(file, ","); //salva uma informa��o dentro do arquivo/incluir a v�rgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",sobrenome); //refere-se a string
	
	file = fopen(arquivo, "a"); //acessa o arquivo e o "a" significa atualizar uma informa��o/incluir mais informa��o no arquivo
	fprintf(file,sobrenome); //salvo o valor da vari�vel
	fclose(file);
	
	file = fopen(arquivo, "a"); //acessa o arquivo e o "a" signica atualizar uma informa��o/incluir mais informa��o no arquivo
	fprintf(file, ","); //salva uma informa��o dentro do arquivo/incluir a v�rgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",cargo); //refere-se a string
	
	file = fopen(arquivo, "a"); //acessa o arquivo e o "a" significa atualizar uma informa��o/incluir mais informa��o no arquivo 
	fprintf(file,cargo); //salva uma informa��o dentro do arquivo/incluir a v�rgula
	fclose(file); //fecha o arquivo 
	
	system("pause"); //serve para dar um pause na tela
	
}		

int consulta()
{
	setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //coletando informa��o do usu�rio
	scanf("%s",cpf); //refere-se a string
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //acessa o arquivo e o "r" significa ler o arquivo
	
	if(file == NULL) //valida��o
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado! .\n"); //mostra uma informa��o ao usu�rio
	}
	
	while(fgets(conteudo, 200, file) != NULL) //valida��o do enquanto
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); //mostra uma informa��o ao usu�rio
		printf("%s", conteudo); //salva o conte�do que est� dentro da string
		printf("\n\n"); //serva para pular linhas
	}
	
	system("pause"); //serve para dar um pause na tela
	
	
	system("pause"); //serve para dar um pause na tela
	
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //coletando informa��o do usu�rio 
	scanf("%s",cpf); //refere-se a string
	
	remove(cpf); //serve para acessar a pasta e deletar um arquivo 
	
	FILE *file; //abre o arquivo
	file = fopen(cpf,"r"); // acessa o arquivo e o "r" significa ler o arquivo 
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n"); //mostra uma informa��o ao usu�rio
		system("pause"); //serve para dar um pause na tela
	}
}

int main()
{
	int opcao=0; //Definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
	
		setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
	
		printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o: ");//fim do menu

		scanf("%d", &opcao); //armazenamento a escolha do usu�rio
	
		system("cls"); //reponsavel po limpar a tela
		
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registro(); //chamada de func�es
			break;
			
			case 2:
			consulta(); //chamada de func�es 
			break; 
			
			case 3:
			deletar(); //chamada de func��es
			break;
			
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n"); //mosgra uma informa��o ao usu�rio
			system("pause"); //serve para dar um pause na tela
			break;
			
			
		} //fim de sele��o
		
}
}
