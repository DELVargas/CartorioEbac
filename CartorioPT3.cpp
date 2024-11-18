#include <stdio.h>  //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

    int registro()
{
    char arquivo[40];
	char cpf[40];
    char nome[40];
    char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado:" );
	scanf("%s", cpf);
		
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf (file,cpf); //salvar o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file= fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file= fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file= fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");

}

    int consultar()
{
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf [40];
	char conteudo [200];
	
	printf ("Digite o CPF a ser consultado:");
	scanf("%s", cpf);
	
	FILE *file;
	file= fopen (cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel localizar o arquivo!. \n");
	} 
  
    while(fgets(conteudo,200, file) != NULL)
  {
        printf("\nEssas s�o as informa��es do usu�rio:");
        printf("%s", conteudo);
        printf("\n\n");
  }
  
    system("pause");
  
}

    int deletar()
{
    printf("Voc� escolheu deletar o nomes!\n");
    system("pause");
}


    int main () 
{
    int opcao=0; // Definindo vari�veis
    int laco=1;

    for(laco = 1; laco == 1;)
{

    system("cls");
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem

    printf("\tCart�rio EBAC\t\n\n"); //Inicio do menu
    printf("Escolha a op��o desejada do menu:\n\n");
    printf("\t1 - Registrar Nomes\n");
    printf("\t2 - Consultar Nomes\n");
    printf("\t3 - Deletar Nomes\n\n"); 
    printf("\t4 - Sair do sistema \n");
	printf("Op��o: "); //fim do menu

    scanf("%d", &opcao); // Armazenando a escolha do usu�rio

    system ("cls");

    switch(opcao)
{
    case 1:
    registro();
    break;

    case 2:
    consultar();
    break;

    case 3:
    deletar();
    break;
    
    case 4:
    	printf("Obrigado por utilizar o sistema!\n");
    	return 0;
		break;
    
    	

    default:
    printf("Voc� escolheu uma op��o inv�lida!\n");
    system("pause");
    break;

} //fim da sele��o

}
}
