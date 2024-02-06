#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//inicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar o valor das strings
	
	FILE *file; //cria o aquivo
	file = fopen(arquivo, "w"); //criar o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //acessa o arquivo e o "a" significa atualizar uma infromação/incluir mais informação no arquivo
	fprintf(file, ","); //salva uma informação dentro do arquivo/incluir a vírgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //acessa o arquivo e o "a" significa atualizar uma informação/incluir mais informação no arquivo
	fprintf(file,nome); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //acessa o arquivo e o "a" significa atualizar uma informação/incluir mais informação no arquivo
	fprintf(file, ","); //salva uma informação dentro do arquivo/incluir a vírgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",sobrenome); //refere-se a string
	
	file = fopen(arquivo, "a"); //acessa o arquivo e o "a" significa atualizar uma informação/incluir mais informação no arquivo
	fprintf(file,sobrenome); //salvo o valor da variável
	fclose(file);
	
	file = fopen(arquivo, "a"); //acessa o arquivo e o "a" signica atualizar uma informação/incluir mais informação no arquivo
	fprintf(file, ","); //salva uma informação dentro do arquivo/incluir a vírgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",cargo); //refere-se a string
	
	file = fopen(arquivo, "a"); //acessa o arquivo e o "a" significa atualizar uma informação/incluir mais informação no arquivo 
	fprintf(file,cargo); //salva uma informação dentro do arquivo/incluir a vírgula
	fclose(file); //fecha o arquivo 
	
	system("pause"); //serve para dar um pause na tela
	
}		

int consulta()
{
	setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //coletando informação do usuário
	scanf("%s",cpf); //refere-se a string
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //acessa o arquivo e o "r" significa ler o arquivo
	
	if(file == NULL) //validação
	{
		printf("Não foi possivel abrir o arquivo, não localizado! .\n"); //mostra uma informação ao usuário
	}
	
	while(fgets(conteudo, 200, file) != NULL) //validação do enquanto
	{
		printf("\nEssas são as informações do usuário: "); //mostra uma informação ao usuário
		printf("%s", conteudo); //salva o conteúdo que está dentro da string
		printf("\n\n"); //serva para pular linhas
	}
	
	system("pause"); //serve para dar um pause na tela
	
	
	system("pause"); //serve para dar um pause na tela
	
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: "); //coletando informação do usuário 
	scanf("%s",cpf); //refere-se a string
	
	remove(cpf); //serve para acessar a pasta e deletar um arquivo 
	
	FILE *file; //abre o arquivo
	file = fopen(cpf,"r"); // acessa o arquivo e o "r" significa ler o arquivo 
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n"); //mostra uma informação ao usuário
		system("pause"); //serve para dar um pause na tela
	}
}

int main()
{
	int opcao=0; //Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
	
		setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
	
		printf("### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção: ");//fim do menu

		scanf("%d", &opcao); //armazenamento a escolha do usuário
	
		system("cls"); //reponsavel po limpar a tela
		
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro(); //chamada de funcões
			break;
			
			case 2:
			consulta(); //chamada de funcões 
			break; 
			
			case 3:
			deletar(); //chamada de funcções
			break;
			
			
			default:
			printf("Essa opção não está disponível!\n"); //mosgra uma informação ao usuário
			system("pause"); //serve para dar um pause na tela
			break;
			
			
		} //fim de seleção
		
}
}
