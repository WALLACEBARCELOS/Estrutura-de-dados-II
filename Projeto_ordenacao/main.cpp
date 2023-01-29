#include "ordenacao.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*void menu(){
	cout << "\n\n\n\n\n\n\n\n";
	cout << "\n=================\n";
	cout << "MENU DE IMPRESSÃO\n";
	cout << "===================\n";
	cout << "1- Vetor original \n";
	cout << "2- Vetor ordenado bubbleSort\n";
	cout << "3- Vetor ordenado insertionSort\n"; 
	cout << "4- Vetor ordenado selectSort\n"; 
	cout << "4- Vetor ordenado quickSort\n"; 
}*/

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	
	int i, aux, op;
	
	Ordenacao o;
	
	
	do{
		cout << "Selecione uma opção\n";
		cout << "Informe 1 para iniciar ou X para sair: ";
		cin >> op;
		switch (op)
		{
			case 1:
				cout << "\n\nInforme o tamanho do vetor: ";
				cin >> i;
				
				system("cls");
				
				cout << "\n==================";
				cout << "\nTEMPO DE EXECUÇÃO";
				cout << "\n==================";
				o.Alocando(i);
				o.tempoExecucaoBubbleSort();
				o.tempoExecucaoselectSort();
				o.tempoExecucaoinsertionSort();
				o.tempoExecucaoshellSort();
				o.tempoExecucaoquicksort();
				o.tempoExecucaomergeSort();
				o.tempoExecucaoradixSort();
				cout << "\n\n\n\n";
				break;
				
				
			default:
				cout << "Programa encerrado!";
				break;
		}
			
					
	}while(op==1);
	
	 



	

	
	
	return 0;
}
