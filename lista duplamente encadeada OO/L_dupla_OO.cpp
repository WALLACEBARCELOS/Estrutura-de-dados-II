#include "L_dupla_OO.h"

//inicializadon a lista como vazia
Lista::Lista(){
	this->cabeca = 0;
	this->qtd = 0;
}

Lista::~Lista(){
	this->libera();
	this->qtd = 0;
}


void Lista::insere_ordenado(int i){
	no_dado* novo = new no_dado(); //Criando um ponteiro para o novo no dado
	no_dado* ant = new no_dado(); //Criando um ponteiro para o no dado anterior
	no_dado* p = this->cabeca; // atribuindo a lista para o auxliar P
	novo->info = i;
	
	//caso a lista esteja vazia
	if(p==0){
		novo->prox = 0; // proxmo nao recebe nada
		novo->ant= 0;// anterior  nao recebe nada
		this->last = novo; // 
		this->cabeca = novo; // o  cabeça aponta para o novo no
		this->qtd++; // incrementa a quantidade de no inserido
		return;
	}
	//caso a lista tenha apenas um no dado
	if(p->ant==0 && p->prox==0){
		//ordenando: caso o novo elemento seja menos dos que ja estao na lista
		if(p->info<=i){
			p->prox = novo; //o proximo elemento vai receber o ponteiro do novo elemento
			novo->prox = 0; // o novo proximimo elemento não vai existir
			novo->ant = p; // o anterior vai ser a lista antes da adição do novo no 
			this->last = novo;
			
		//ordenando: caso o novo elemento seja maior dos que ja estao na lista	
		}else{	
			novo->ant = 0; // nao vai existir elemento anterior
			novo->prox = p; // o novo proximo vai ser a lista antes da adição do novo elemento
			p->ant = novo;//o anterior vai receber o novo elemento
			this->last = p;
			this->cabeca = novo;// o no cabeça vai começar a ser o novo elemento
		}
		
	//caso a lista tenha dois ou mais elementos
	}else{ 
	
	
		for(;p!=NULL && i>p->info; (ant=p) && (p=p->prox));	
		
		if(p==0){//ultimo no a ser inserido
			ant->prox = novo;
			novo->ant = ant;
			novo->prox = 0;
			this->last = novo;
			this->qtd++;
			return;
		}
		
		if(p->ant==0 && i<p->info){//primeiro 
			novo->prox = p;
			p->ant = novo;
			this->cabeca = novo;
			this->qtd++;
			return;
		}
				
		novo->ant = p->ant;
		p->ant->prox = novo;
		novo->prox = p;
		p->ant = novo;
		if(novo->prox==0){
			this->last = novo;
		}
	}
	qtd++;
}

void Lista::imprime_fim(){
	no_dado* p = this->last;
	
	if(p==0){
		cout<<"Lista vazia! "<<endl;
		return;
	}
	cout<<"\nInfo: ";
	for(; p!=0; p=p->ant)
		cout<< p->info <<" - ";
	cout<<endl;
}

void Lista::imprime_inicio(){
	if (this->cabeca!=0){
		no_dado* p; /* variável auxiliar para percorrer a lista */
		printf("\nInfo = ");
		for (p = this->cabeca; p != NULL; p = p->prox)
			printf("%d - ", p->info);
		printf("\n");	
	} else cout << "\nLista vazia!\n";
}

void Lista::libera(){
	no_dado* p = this->cabeca;
	 while (p != NULL) {
	 	no_dado* t = p->prox; 
		free(p); 
		this->qtd--; 
	 	p = t; 
	 }
	 this->cabeca = 0; 
	 this->last = 0;
}


void Lista::remove_inicio(){
	no_dado* p = this->cabeca;
	if(p==0){
		cout<< "\nLista vazia\n";
		return;
	}
	
	if(p->ant==0 && p->prox==0){
		free(p);
		this->cabeca = 0;
		this->last = 0;
		this->qtd--;
		return;
	}
	
	p->prox->ant = 0;
	this->cabeca = p->prox;
	free(p);
}

void Lista::remove_fim(){
	no_dado* p = this->last;

	if(p==0){
		cout<< "Lista Vazia!"<< endl;
		return;	
	}
	
	if(p->ant==0 && p->prox==0){
		free(p);
		this->cabeca = 0;
		this->last = 0;
		this->qtd--;
		return;
	}
	
	no_dado* anter = p->ant;
	anter->prox = 0;
	free(p);
	this->last = anter;
}

void Lista::remove_elemento(int i){
	no_dado* p = this->cabeca;
	
	if(p==0){ 
		cout<< "Lista Vazia!"<< endl;
		return;	
	}
	
	for(;p->info!=i && p!=0; p=p->prox);
	
	if(p->info==i){
	
		if(p->ant==0 && p->prox==0){ 
			free(p);
			this->cabeca = 0;
			this->last = 0;
			this->qtd--;
			return;	
		}
		
		if(p->ant==0 && p->info==i){
			p->prox->ant = 0;
			this->cabeca = p->prox;
			free(p);
			this->qtd--;
			return;
		}
		
		if(p->ant!=0 && p->prox!=0){
			p->ant->prox = p->prox;
			p->prox->ant = p->ant;
			this->qtd--;
			free(p);
			return;
		}
		
		p->ant->prox = 0;
		this->last = p->ant;
		free(p);
		this->qtd--;
		
	}else
		cout<<"Elemento não encontrado" <<endl;
}

void Lista::buscar_elemento(int i){
	no_dado* p = this->cabeca;
	
	if(p==0){
		cout<<"Lista vazia! "<<endl;
		return;	
	}
	
	for(;p!=0; p=p->prox){
		if(p->info==i){
		cout<<"\nElemento encontrado" <<endl;
		return;
		}
	}
	cout<<"\nElemento não encontrado" <<endl;	
}
