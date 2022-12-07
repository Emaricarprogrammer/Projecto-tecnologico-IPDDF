#include<stdio.h>
#include<locale.h>
#include<windows.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

//V�riaveis globais

//v�riaveis do tipo char
char nome[30];
char apelido[30];
char nascimento;
char morada;
char sexo;
char resp;
char resp2;

//v�riaveis do tipo int

int telefone[12];
int pin=0;
int i;
int numerosaleatorios;
int opcao2;
int o;
int numcliente;
int numconta;
int numconta_segundo;
int iban[21];
int k;

//v�riaveis do tipo float
float valor_levantar;
float dinheirodaconta=5000.00;
float saldo;
float levantamento;
float valor_transferir;
float novo_saldo;

//Fun��o Gest�o de conta
void gestaodeconta(){
	
	//Instru��o para pegar a data
	
	struct tm *data_hora_actual;
	time_t segundos;
	time(&segundos);
	data_hora_actual=localtime(&segundos);
	
	//Menu principal
	
	//==========================================================================
		printf("\n\t======================");
		printf("\tMenu Gest�o de conta");
		printf("\t======================");
		printf("\n\t1. Abrir conta");
		printf("\n\t2. Consultar Saldo");
		printf("\n\t3. Levantamentos");
		printf("\n\t4. Consultar movimentos");
		printf("\n\t5. Transfer�ncia");
		printf("\n\t6. Pagamento");
		printf("\n\t7. Consultar IBAN/N de conta");
		printf("\n\t0. Sair\n");
		printf("\tEscolha uma op��o:");scanf("%d",&opcao2);
		
		while(opcao2!=1 && opcao2!=2 && opcao2!=3 && opcao2!=4 && opcao2!=5 && opcao2!=6 && opcao2!=0 && opcao2!=7){
		printf("\n\t======================");
		// enquanto as op��es forem diferentes o sistema far�:
		printf("\n\tOp��o inv�lida,escolha uma op��o v�lida:");scanf("%d",&opcao2);}
	//==========================================================================

	//Limpe a tela
	
	system("cls");
	
	//==========================================================================
	switch(opcao2){
		
		//Abrir conta
		case 1:
			for(o=0;o<1;o++){
		//formulario de ab conta
		printf("\n\t======================");
		printf("\tF�rmulario de abertura de conta");
		printf("\t======================");
		printf("\n\tSeu primeiro nome:");scanf("%s",&nome[o]);
		printf("\n\tSeu Apelido:");scanf("%s",&apelido[o]);
		printf("\n\tSexo:");scanf("%s",&sexo);
		
		while(sexo!='M' && sexo!='m' && sexo!='Masculino' && sexo!='masculino' && sexo!='MASCULINO' && sexo!='F' && sexo!='f' && sexo!='Femenino' && sexo!='femenino' && sexo!='FEMENINO'){
		printf("\n\t======================");
		// enquanto sexo for diferente de dos sexos v�lidos tantos escritos em letra mai�sculas como min�sculas o sistema far�:
		printf("\n\tsexo inv�lido,digite um sexo v�lido:");scanf("%s",&sexo);
		}
		// caso contr�rio continue
		printf("\n\tSua data de nascimento:");scanf("%s",&nascimento);
		printf("\n\tSua Morada:");scanf("%s",&morada);
		printf("\n\tSeu n�mero de telefone :9");scanf("%d",&telefone[o]);
		printf("\n\tCrie um PIN:");scanf("%d",&pin);
		while(pin<1000 || pin>=10000)
		{
			printf("\n\tCrie um PIN com 4 digitos:");scanf("%d",&pin);
			
		}
		}
	//==========================================================================
		//Gerando numeros aleatorios
		srand(time(NULL));
		numerosaleatorios= 100000+rand()%900000;
		
		//n�mero do cliente
		numcliente=rand()%100;
	//==========================================================================
	//Mensagem de abertura de conta
		printf("\n\t======================");
		printf("\tAbertura de conta concluida");
		printf("\t======================");
		printf("\n\tAbertura de conta feito com sucesso.");
		break;
		
		//Consulatr saldo
		case 2:
		printf("\n\t======================");
		printf("\tConsulta de Saldo");
		printf(" ======================\n");
			printf("\tInsira o seu N� de conta:");scanf("%d",&numconta);
		//condic�o composta
		if(numconta!=numerosaleatorios){
		printf("\tEst� conta n�o existe.");
		}
		else{
		printf("\n\t======================");
		printf("\tConsulta de Saldo");
		printf(" ======================");
		printf("\n\tCliente:%d",numcliente);
		printf("\n\tNome do(a) cliente:%s-%s",nome,apelido);
		printf("\n\tN� de conta:%d%c%c100",numerosaleatorios,nome[0],apelido[0]);
		
		printf("\n\tSaldo contabil�stico:%2.2fAOA",dinheirodaconta);
		printf("\n\tTipo de conta: corrente");
		printf("\n\tData de cria��o da conta:%d/%d/%d\n",data_hora_actual->tm_mday,data_hora_actual->tm_mon+1,data_hora_actual->tm_year+1900);
		}
		
		//pare
		break;
	//==========================================================================
		
		//Levantamentos
		case 3:
		printf("\n\t======================");
		printf("\tLevantamentos");
		printf(" ======================");
			printf("\n\tInsira o seu N� de conta:");scanf("%d",&numconta);
		//condi��es aninhadas
		if(numconta==numerosaleatorios ){
			printf("\tInsira o valor que deseja levantar:");scanf("%f",&valor_levantar);
			saldo=5000.00;
			levantamento = saldo-valor_levantar;
				if(saldo==0){
					printf("\tN�o ser� poss�vel efetuar o seu pedido. O teu saldo � negativo");
					}
						else if(saldo!=0 && saldo<valor_levantar){
							printf("\tCaro cliente o teu saldo � inferior!");
						}
			else{
				printf("\n\t======================");
				printf("\tRecibo de levantamento");
				printf(" ======================");
				printf("\n\tValor leventado:%2.2f\n",valor_levantar);
				printf("\tDisp�e de:%2.2fKz\n",levantamento);
			}
		}
		else{
			printf("\tCaro �suario, este n�mero de conta n�o condiz com o seu n�mero de conta, por favor reinicie o sistema");
		}
		//pare
		break;
		//==========================================================================
		
	//Consultar saldo
	case 4:
		printf("\n\t======================");
		printf("\tSeus Movimentos");
		printf("\t======================");
		printf("\n\tInsira o seu N� de conta:");scanf("%d",&numconta);
		//condi��o composta
		if(numconta==numerosaleatorios){
			printf("\n\tD�bito|-|%d/%d/%d|%f",data_hora_actual->tm_mday,data_hora_actual->tm_mon+1,data_hora_actual->tm_year+1900,levantamento);
		}
		else{
			printf("\n\tCaro �suario, este n�mero de conta n�o condiz com o seu n�mero de conta, por favor reinicie o sistema");
		}
		//pare
		break;
		//==========================================================================
	
	//Transf�rencias
	
	case 5:
		printf("\n\t======================");
		printf("\tTransf�rencias");
		printf("\t======================");
		printf("\n\tInsira o seu N� de conta:");scanf("%d",&numconta);
		//condi��o composta
		if(numconta!=numerosaleatorios){
		printf("\tEst� conta n�o existe.");
		}
		else{
		
		printf("\n\tInsira o  N� de conta a transf�rir:");scanf("%d",&numconta_segundo);
		printf("\n\tInsira o valor a transf�rir:");scanf("%f",&valor_transferir);
		novo_saldo=saldo-valor_transferir;
		//condi��o composta

	   if(valor_transferir>dinheirodaconta){
			printf("\n\tCaro cliente, o seu saldo n�o � suficiente");
		}

		else if(valor_transferir<500.00){
			printf("\n\tN�o ser� possiv�l efectuar uma transf�rencia abaixo de 500.00kz");
		}
		else{
			printf("\n\tTransf�riu:%2.2fKz,disp�e de:%2.2fKz\n",valor_transferir,novo_saldo);
		}
	}
		//pare
		break;
		//==========================================================================
		
	//Consulta de IBAN
	
	case 7:
		srand(time(NULL));
		printf("\n\t======================");
		printf("\tSeu IBAN");
		printf(" ======================\n\tIban: AOA");	
		for(k=0;k<21;k++){iban[k]=rand()%10;
		printf("%d",iban[k]);
		}		
		printf("\n\tN� conta: %d%c%c100",numerosaleatorios,nome[0],apelido[0]);
		//pare
		break;
	case 0:
	system("PAUSE");
	break;
	//==========================================================================
		
	
}

}
//==========================================================================
// fun��o Gest�o de utilizador
int gestaoutilizador(){
		//todas as v�riaveis do tipo inteiro
		int novopin1;
		int pinantigo;
		int novopin2;
		int novopin;
		int i;
		int opcao3;
		// menu gest�o de utilizador
		printf("\n\t======================");
		printf("\tGest�o de Utilizador");
		printf("\t======================"); 
		printf("\n\t1. Alterar PIN");
		printf("\n\t2. Sair");
		printf("\n\tEscolha uma op��o:");scanf("%d",&opcao3);
	//==========================================================================
		switch(opcao3){
		case 1:
		printf("\n\tDigite o seu antigo pin:");scanf("%d",&pinantigo);
		printf("\n\tDigite o seu novo PIN:");scanf("%d",&novopin1);
		printf("\n\tDigite novamente seu novo PIN:");scanf("%d",&novopin2);
	//==========================================================================
		// enquanto o novo pin for diferente do pin de confirma��o, o programa insistir� que o user refa�a todos os procedimentos, at� que os pins sejam iguais
		while(novopin1!=novopin2){
		printf("\n\tPins diferentes, verifique e digite correctamente");
		printf("\n\tDigite o seu antigo:");scanf("%d",&pinantigo);
		printf("\n\tDigite o seu novo PIN:");scanf("%d",&novopin1);
		printf("\n\tDigite novamente seu novo PIN:");scanf("%d",&novopin2);
		}
		novopin=novopin1;
		printf("\n\tPin alterado com sucesso");
	
}
}
//==========================================================================
// fun��o principal
int main(int argc, char *argv[]){
	//loop infinito
	for(;;){
	int opcao;
	int k;
	setlocale(LC_ALL,"");
	//menu principal

//==========================================================================

	printf("\n\t======================");
	printf("\tMenu Principal");
	printf("\t======================"); 
	printf("\n\t1. Gest�o de conta");
	printf("\n\t2. Gest�o de utilizador");
	printf("\n\t3. Sair");
	printf("\n\tEscolha uma op��o:");scanf("%d",&opcao);

//==========================================================================
	while(opcao!=1 && opcao !=2 && opcao!=3){
		printf("\n\t======================");
		printf("\n\tOp��o inv�lida,escolha uma op��o v�lida:");scanf("%d",&opcao);
		
	}
	//estrutura de escolha
	switch(opcao){
		case 1:
			gestaodeconta();
			break;
		case 2:
			gestaoutilizador();
		case 3:
		system("PAUSE");		
	}
//==========================================================================
	
	

}

}


