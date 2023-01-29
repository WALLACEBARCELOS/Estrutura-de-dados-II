//Desenvolver métodos de classe
//Lista.cpp

#include "Lista.h"

//construtor
Lista::Lista(){
	this->cabeca = 0; //inicializa lista vazia
	this->qtd = 0;
}

//destrutor
Lista::~Lista(){
	this->libera(); //ideia é liberar free toda memória alocada
	this->qtd = 0;
}

void Lista::insere_inicio(int i){
	//no_dado* novo = (no_dado*) malloc(sizeof(no_dado));
	//novo->info = i;
 	//novo->prox = this->cabeca;
 	no_dado* novo = new no_dado(i, this->cabeca);
  	this->cabeca = novo; //adiciona a partir do início
  	this->qtd++; //incrementa o contador de nó-dado
}

void Lista::imprime(){
	if (!this->isEmpty(this->cabeca)){
		no_dado* p; /* variável auxiliar para percorrer a lista */
		printf("Info = ");
		for (p = this->cabeca; p != NULL; p = p->prox)
			printf("%d - ", p->info);
		printf("\n");	
	} else printf("Lista está vazia!\n");
}

void Lista::vazia(){
	if (!this->isEmpty(this->cabeca))
		printf("Lista não está vazia!\n");
	else
		printf("Lista está vazia!\n");
}

void Lista::libera(){
	no_dado* p = this->cabeca;
	 while (p != NULL) {
	 	no_dado* t = p->prox; // guarda referência para o próximo elemento
		free(p); /* libera a memória apontada por p */
		this->qtd--; //decrementa contador de qtd
	 	p = t; /* faz p apontar para o próximo */
	 }
	 this->cabeca = 0; //inicializa lista vazia
}

void Lista::tamanho(){
	printf("Tamanho ou qtd de elementos: %d\n", this->qtd);
}

//tratamento métodos privados
bool Lista::isEmpty(no_dado* l){
	return l==NULL;
}

void Lista::buscaInt(int i){
	if(!this->isEmpty(this->cabeca)){
		no_dado* p;
		
		for(p=this->cabeca; p!=NULL; p=p->prox){
			if(p->info == i){
				cout << "Numero encontrado:" << p->info << endl;
				return;
			}	
		}
		cout << "Numero nao encontrado!";
	}
	else{
		cout << "Lista esta vazia!";	
	}		
}

void Lista::retira(int i){	
	if(!this->isEmpty(this->cabeca)){
		no_dado* ant=NULL;
		no_dado* p = this->cabeca;
		
		for(;p!=NULL; (ant=p) && (p=p->prox)){
			if(p->info == i){
				ant->prox = p->prox;
				free(p);
				p = ant;
				cout << "O numero " << i << " foi retirado!";				
				this->qtd--; 
				return;
			}														
		}
		cout << "O numero nao foi encontrado!";	
	}
	else{
		cout << "Lista esta vazia!";
	}
}

void Lista::insereFim(int i){
	no_dado* novo= new no_dado(i, NULL);
	no_dado* p = this->cabeca;
	
	if(!this->isEmpty(this->cabeca)){
		for(; p->prox!=NULL; p=p->prox);
		p->prox = novo;
	}else{
		this->cabeca = novo;	
	}
}

void Lista::retira_Inicio(){
	if(!this->isEmpty(this->cabeca)){
		no_dado* p = this->cabeca;
		this->cabeca = p->prox;
		free(p);
	}else
		cout << "Lista vazia!" << endl;	
}

void Lista::retira_Fim(){
	if(!this->isEmpty(this->cabeca)){
		no_dado* p = this->cabeca;
		if(p->prox==NULL){
			free(p);
			this->cabeca = NULL;
			return;
		}
		no_dado* ant = NULL; 
		for(; p->prox!=NULL; (ant=p)&&(p=p->prox));
		ant->prox = NULL;
		free(p);
	
	}else
		cout<< "Lista vazia!" << endl;
}

void Lista::imprime_Inicio(){
	if(!this->isEmpty(this->cabeca)){
		no_dado* p = this->cabeca;
		cout<< "Info: " << p->info << endl;
	}else
		cout<< "Lista vazia!" << endl;
}

void Lista::imprime_Fim(){
		if(!this->isEmpty(this->cabeca)){
		no_dado* p = this->cabeca;
		for(; p->prox!=NULL; p= p->prox);
		cout<< "Info: " << p->info << endl;
	}else
		cout<< "Lista vazia!" << endl;
}

















