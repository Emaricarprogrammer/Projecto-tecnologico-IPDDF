#include<stdio.h>
#include<locale.h>
#include<windows.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

//Váriaveis globais

//váriaveis do tipo char
char nome[30];
char apelido[30];
char nascimento;
char morada;
char sexo;
char resp;
char resp2;
char numconta_segundo;

//váriaveis do tipo int

int telefone[12];
int pin=0;
int i;
int numerosaleatorios;
int opcao2;
int o;
int numcliente;
int numconta;
int iban[21];
int k;

//váriaveis do tipo float
float valor_levantar;
float dinheirodaconta=5000.00;
float saldo;
float levantamento;
float valor_transferir;
float novo_saldo;

//Função Gestão de conta
void gestaodeconta(){
	
	//Instrução para pegar a data
	
	struct tm *data_hora_actual;
	time_t segundos;
	time(&segundos);
	data_hora_actual=localtime(&segundos);
	
	//Menu principal
	
	//=========================================================================
		printf("\n\t======================");
		printf("\tMenu Gestão de conta");
		printf("\t======================");
		printf("\n\t1. Abrir conta");
		printf("\n\t2. Consultar Saldo");
		printf("\n\t3. Levantamentos");
		printf("\n\t4. Consultar movimentos");
		printf("\n\t5. Transferência");
		printf("\n\t6. Pagamento");
		printf("\n\t7. Consultar IBAN/N de conta");
		printf("\n\t0. Sair\n");
		printf("\tEscolha uma opção:");scanf("%d",&opcao2);
		
		while(opcao2!=1 && opcao2!=2 && opcao2!=3 && opcao2!=4 && opcao2!=5 && opcao2!=6 && opcao2!=0 && opcao2!=7){
		printf("\n\t======================");
		// enquanto as opções forem diferentes o sistema fará:
		printf("\n\tOpção inválida,escolha uma opção válida:");scanf("%d",&opcao2);}
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
		printf("\tFórmulario de abertura de conta");
		printf("\t======================");
		printf("\n\tSeu primeiro nome:");scanf("%s",&nome[o]);
		printf("\n\tSeu Apelido:");scanf("%s",&apelido[o]);
		printf("\n\tSexo:");scanf("%s",&sexo);
		
		while(sexo!='M' && sexo!='m' && sexo!='Masculino' && sexo!='masculino' && sexo!='MASCULINO' && sexo!='F' && sexo!='f' && sexo!='Femenino' && sexo!='femenino' && sexo!='FEMENINO'){
		printf("\n\t======================");
		// enquanto sexo for diferente de dos sexos válidos tantos escritos em letra maiúsculas como minúsculas o sistema fará:
		printf("\n\tsexo inválido,digite um sexo válido:");scanf("%s",&sexo);
		}
		// caso contrário continue
		printf("\n\tSua data de nascimento:");scanf("%s",&nascimento);
		printf("\n\tSua Morada:");scanf("%s",&morada);
		printf("\n\tSeu número de telefone :9");scanf("%d",&telefone[o]);
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
		
		//Gerando número do cliente
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
			printf("\tInsira o seu Nº de conta:");scanf("%d",&numconta);
		//condicão composta
		if(numconta!=numerosaleatorios){
		printf("\tEstá conta não existe.");
		}
		else{
		printf("\n\t======================");
		printf("\tConsulta de Saldo");
		printf(" ======================");
		printf("\n\tCliente:%d",numcliente);
		printf("\n\tNome do(a) cliente:%s-%s",nome,apelido);
		printf("\n\tNº de conta:%d%c%c100",numerosaleatorios,nome[0],apelido[0]);
		
		printf("\n\tSaldo contabilístico:%2.2fAOA",dinheirodaconta);
		printf("\n\tTipo de conta: corrente");
		printf("\n\tData de criação da conta:%d/%d/%d\n",data_hora_actual->tm_mday,data_hora_actual->tm_mon+1,data_hora_actual->tm_year+1900);
		}
		
		//pare
		break;
	//==========================================================================
		
		//Levantamentos
		case 3:
		printf("\n\t======================");
		printf("\tLevantamentos");
		printf(" ======================");
			printf("\n\tInsira o seu Nº de conta:");scanf("%d",&numconta);
		
		//condições aninhadas
		if(numconta==numerosaleatorios ){
			printf("\tInsira o valor que deseja levantar:");scanf("%f",&valor_levantar);
			saldo=5000.00;
			levantamento = saldo-valor_levantar;
				if(saldo==0){
					printf("\tNão será possível efetuar o seu pedido. O teu saldo é negativo");
					}
						else if(saldo!=0 && saldo<valor_levantar){
							printf("\tCaro cliente o teu saldo é inferior!");
						}
			else{
				printf("\n\t======================");
				printf("\tRecibo de levantamento");
				printf(" ======================");
				printf("\n\tValor leventado:%2.2f\n",valor_levantar);
				printf("\tDispõe de:%2.2fKz\n",levantamento);
			}
		}
		else{
			printf("\tCaro úsuario, este número de conta não condiz com o seu número de conta, por favor reinicie o sistema");
		}
		//pare
		break;
		//==========================================================================
		
	//Consultar saldo
	case 4:
		printf("\n\t======================");
		printf("\tSeus Movimentos");
		printf("\t======================");
		printf("\n\tInsira o seu Nº de conta:");scanf("%d",&numconta);
		//condição composta
		if(numconta==numerosaleatorios){
			printf("\n\tDébito|-|%d/%d/%d|%2.2f",data_hora_actual->tm_mday,data_hora_actual->tm_mon+1,data_hora_actual->tm_year+1900,levantamento);
		}
		else{
			printf("\n\tCaro úsuario, este número de conta não condiz com o seu número de conta, por favor reinicie o sistema");
		}
		//pare
		break;
		//==========================================================================
	
	//Transfêrencias
	
	case 5:
		printf("\n\t======================");
		printf("\tTransfêrencias");
		printf("\t======================");
		printf("\n\tInsira o seu Nº de conta:");scanf("%d",&numconta);
		
		//condição composta
		if(numconta!=numerosaleatorios){
		printf("\tEstá conta não existe.");
		}
		else{
		
		printf("\n\tInsira o  Nº de conta a transfêrir:");scanf("%s",&numconta_segundo);
		printf("\n\tInsira o valor a transfêrir:");scanf("%f",&valor_transferir);
		novo_saldo=saldo-valor_transferir;
		
		//condição composta
	   if(valor_transferir>dinheirodaconta){
			printf("\n\tCaro cliente, o seu saldo não é suficiente");
		}

		else if(valor_transferir<500.00){
			printf("\n\tNão será possivél efectuar uma transfêrencia abaixo de 500.00kz");
		}
		else{
			printf("\n\tTransfêriu:%2.2fKz,dispõe de:%2.2fKz\n",valor_transferir,novo_saldo);
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
		printf("\n\tNº conta: %d%c%c100",numerosaleatorios,nome[0],apelido[0]);
		//pare
		break;
	case 0:
	system("PAUSE");
	break;
	//==========================================================================
		
	
}

}
//==========================================================================
// função Gestão de utilizador
int gestaoutilizador(){
		//todas as váriaveis do tipo inteiro
		int novopin1;
		int pinantigo;
		int novopin2;
		int novopin;
		int i;
		int opcao3;
		// menu gestão de utilizador
		printf("\n\t======================");
		printf("\tGestão de Utilizador");
		printf("\t======================"); 
		printf("\n\t1. Alterar PIN");
		printf("\n\t2. Sair");
		printf("\n\tEscolha uma opção:");scanf("%d",&opcao3);
	//==========================================================================
		switch(opcao3){
		case 1:
		printf("\n\tDigite o seu antigo pin:");scanf("%d",&pinantigo);
		printf("\n\tDigite o seu novo PIN:");scanf("%d",&novopin1);
		printf("\n\tDigite novamente seu novo PIN:");scanf("%d",&novopin2);
	//==========================================================================
		// enquanto o novo pin for diferente do pin de confirmação, o programa insistirá que o user refaça todos os procedimentos, até que os pins sejam iguais
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
// função principal
int main(int argc, char *argv[]){
	//loop infinito
	for(;;){
	int opcao;
	int k;
	setlocale(LC_ALL,"");
	//menu principal

//==========================================================================
	system("color f0 ");
	printf("\n\t======================");
	printf("\tMenu Principal");
	printf("\t======================"); 
	printf("\n\t1. Gestão de conta");
	printf("\n\t2. Gestão de utilizador");
	printf("\n\t3. Sair");
	printf("\n\tEscolha uma opção:");scanf("%d",&opcao);

//==========================================================================
	while(opcao!=1 && opcao !=2 && opcao!=3){
		printf("\n\t======================");
		printf("\n\tOpção inválida,escolha uma opção válida:");scanf("%d",&opcao);
		
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


