#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <time.h>

using namespace std;

class Ordenacao{
	
	private:
		int tamanho;
		int* vetor;
		
	public:
		Ordenacao();
		void Alocando(int x);
		//void CopiarVetor(int x);
		void bubbleSort();
		void tempoExecucaoBubbleSort();
	//	void imprimebubbleSort();
		void selectSort();
		void tempoExecucaoselectSort();
		void insertionSort();
		void tempoExecucaoinsertionSort();
		void quicksort(int* copia, int inicio, int fim);
		void tempoExecucaoquicksort();
		void shellSort();
		void tempoExecucaoshellSort();
		void merge(int* copia, int ini, int meio, int fim, int* vetor2);
		void mergeSort(int* copia, int inicio, int fim, int* vetor2);
		void tempoExecucaomergeSort();
		void radixSort();
		void tempoExecucaoradixSort();
};
