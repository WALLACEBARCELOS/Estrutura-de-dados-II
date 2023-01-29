#include"no_dado.h"


no_dado::no_dado(){
	this->prox = 0;
	this->ant = 0;
}

no_dado::no_dado(int i, no_dado* l){
	this->info = i;	
	this->prox = l;
}
