#include "ordenacao.h"



Ordenacao::Ordenacao(){
    this->tamanho = 0;
    this->vetor= (int*) malloc(this->tamanho * sizeof(int));
}


void Ordenacao::Alocando(int x)
{
    this->tamanho = x;
    this->vetor= (int*) malloc(this->tamanho * sizeof(int));
    
    srand(time(NULL));

    for (int i = 0; i < this->tamanho; i++)
    {
        this->vetor[i] = rand() % 100;
    }
}

//void Ordenacao::imprimebubbleSort(int* copia)
//{
//	int i;
//	printf("[");
//	for (i = 0; i < this->tamanho; i++)
//	{
//		printf(" %d", this->copia[i]);
//	}
//	printf(" ]");
//}

/*void Ordenacao::CopiarVetor(int tamanho)
{
	for(int i = 0; i < tamanho; i++)
	{
		int* this->copia[i] = this->vetor[i];
	}
}*/

void Ordenacao::bubbleSort()
{	
	int* copia = (int*) malloc(this->tamanho * sizeof(int));
	for (int i=0; i < this->tamanho; i++){
        copia[i] = this->vetor[i];
    }
    
	int k, j, aux;
	for(k = 0; k < this->tamanho; k++)
	{
		for(j = 0; j < this->tamanho - 1; j++)
		{
			if(copia[j] > copia[j + 1])
			{
				aux = copia[j];
				copia[j] = copia[j + 1];
				copia[j + 1] = aux;
			}
		}
	}
}

void Ordenacao::tempoExecucaoBubbleSort(){
    clock_t inicio = clock();
    bubbleSort();
    clock_t fim = clock();
    double t = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    cout << "\nBUBBLESORT - " << t << " segundos" << endl;
}

void Ordenacao::selectSort(){	
	int aux;
	int* copia = (int*) malloc(this->tamanho * sizeof(int));
	
	for (int i=0; i < this->tamanho; i++){
        copia[i] = this->vetor[i];
    }
	
    for (int indice = 0; indice < tamanho; ++indice) {
    	
        int indiceMenor = indice;
        for (int indiceSeguinte = indice+1; indiceSeguinte < tamanho; ++indiceSeguinte) {
            if (copia[indiceSeguinte] < copia[indiceMenor]) {
                indiceMenor = indiceSeguinte;
            }
        }
        int aux = copia[indice];
        copia[indice] = copia[indiceMenor];
        copia[indiceMenor] = aux;
    }
}

void Ordenacao::tempoExecucaoselectSort(){
    clock_t inicio = clock();
    selectSort();
    clock_t fim = clock();
    double t = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    cout << "\SELECTSORT - " << t << " segundos" << endl;
}

void Ordenacao::insertionSort() {
	
	int aux;
	int* copia = (int*) malloc(this->tamanho * sizeof(int));
	
	for (int i=0; i < this->tamanho; i++){
        copia[i] = this->vetor[i];
    }

    for (int i = 1; i < this->tamanho; i++) {
		int escolhido = copia[i];
		int j = i - 1;
		
		while ((j >= 0) && (copia[j] > escolhido)) {
			copia[j + 1] = copia[j];
			j--;
		}
		
		copia[j + 1] = escolhido;
	}
}

void Ordenacao::tempoExecucaoinsertionSort(){
    clock_t inicio = clock();
    insertionSort();
    clock_t fim = clock();
    double t = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    cout << "INSERTIONSORT - "  << t << " segundos" << endl;
}
 
void Ordenacao::quicksort(int* copia, int inicio, int fim){	
	
	int i, j, pivo, aux;
	i = inicio;
	j = fim-1;
	pivo = copia[(inicio + fim) / 2];
	while(i <= j)
	{
		while(copia[i] < pivo && i < fim)
		{
			i++;
		}
		while(copia[j] > pivo && j > inicio)
		{
			j--;
		}
		if(i <= j)
		{
			aux = copia[i];
			copia[i] = copia[j];
			copia[j] = aux;
			i++;
			j--;
		}
	}
	if(j > inicio)
		quicksort(copia, inicio, j+1);
	if(i < fim)
		quicksort(copia, i, fim);
}

void Ordenacao::tempoExecucaoquicksort(){
    int* copia = (int*) malloc(this->tamanho * sizeof(int));
	
	for (int i=0; i < this->tamanho; i++){
    	copia[i] = this->vetor[i];
	}
	clock_t inicio = clock();
    quicksort(copia, 0, this->tamanho);
    clock_t fim = clock();
    double t = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    cout << "\QUICKSORT - " << t << " segundos" << endl;
}


void Ordenacao::shellSort() {
	
	int aux;
	int* copia = (int*) malloc(this->tamanho * sizeof(int));
	
	for (int i=0; i < this->tamanho; i++){
        copia[i] = this->vetor[i];
    }
    
    int i, j, value;
    int h = 1;
    while(h < this->tamanho) {
        h = 3*h+1;
    }
    while (h > 0) {
        for(i = h; i < this->tamanho; i++) {
            value = copia[i];
            j = i;
            while (j > h-1 && value <= copia[j - h]) {
                copia[j] = copia[j - h];
                j = j - h;
            }
            copia[j] = value;
        }
        h = h/3;
    }
}

void Ordenacao::tempoExecucaoshellSort(){
    clock_t inicio = clock();
    shellSort();
    clock_t fim = clock();
    double t = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    cout << "\SHELLSORT - " << t << " segundos" << endl;
}

void Ordenacao::merge(int* copia, int ini, int meio, int fim, int* vetor2) {
    int esq = ini;
    int dir = meio;
    for (int i = ini; i < fim; ++i) {
        if ((esq < meio) and ((dir >= fim) or (vetor[esq] < vetor[dir]))) {
            vetor2[i] = copia[esq];
            ++esq;
        }
        else {
            vetor2[i] = copia[dir];
            ++dir;
        }
    }
    for (int i = ini; i < fim; ++i) {
        copia[i] = vetor2[i];
    }
}

void Ordenacao::mergeSort(int* copia, int inicio, int fim, int* vetor2) {
    if ((fim - inicio) < 2) return;
    
    int meio = ((inicio + fim)/2);
    mergeSort(copia, inicio, meio, vetor2);
    mergeSort(copia, meio, fim, vetor2);
    merge(copia, inicio, meio, fim, vetor2);
}

void Ordenacao::tempoExecucaomergeSort(){
	int* copia = (int*) malloc(this->tamanho * sizeof(int));
	int* vetor2 = (int*) malloc(this->tamanho * sizeof(int));
	
	for (int i=0; i < this->tamanho; i++){
        copia[i] = this->vetor[i];
    }
    
	clock_t inicio = clock();
    mergeSort(copia, 0, this->tamanho, vetor2);
    clock_t fim = clock();
    double t = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
	
	cout << "\MERGESORT - " << t << " segundos" << endl;
}

void Ordenacao::radixSort() {
	int* copia = (int*) malloc(this->tamanho * sizeof(int));
	
	for (int i=0; i < this->tamanho; i++){
        copia[i] = this->vetor[i];
    }
    
    int i;
    int *b;
    int maior = 0;
    int exp = 1;

    b = (int *)calloc(this->tamanho, sizeof(int));

    for (i = 0; i < this->tamanho; i++) {
        if (copia[i] > maior)
    	    maior = copia[i];
    }

    while (maior/exp > 0) {
        int bucket[10] = { 0 };
    	for (i = 0; i < this->tamanho; i++)
    	    bucket[(copia[i] / exp) % 10]++;
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i = this->tamanho - 1; i >= 0; i--)
    	    b[--bucket[(copia[i] / exp) % 10]] = copia[i];
    	for (i = 0; i < this->tamanho; i++)
    	    copia[i] = b[i];
    	exp *= 10;
    }    
}
void Ordenacao::tempoExecucaoradixSort(){
	clock_t inicio = clock();
    radixSort();
    clock_t fim = clock();
    double t = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
	cout << "\RADIXSORT - " << t << " segundos" << endl;
}



