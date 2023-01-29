//Calculadora_OO.h
//Objetiva prototipar a classe
#include <math.h>
#include <stdlib.h>

class Calculadora_OO{
	//declarar atributos
	public:
		float n1; //atributo numero 1
	 	float n2; //atributo numero 1
	
	//declarar cabeçalhos de metodos
	public:
		Calculadora_OO(); //Construtor - polimorfismo
		Calculadora_OO(float nn1, float nn2); //Construtor - polimorfismo
		
		~Calculadora_OO(); //Destrutor - executado ao fim ou término de uso de objeto de classe, também sem retorno por padrão.
		
		float soma();
		float soma(float nn1, float nn2);
		
		float subtracao();
		float subtracao(float nn1, float nn2);
		
		float multiplicacao();
		float multiplicacao(float nn1, float nn2);
		
		float divisao();
		float divisao(float nn1, float nn2);
		
		float raizn1();
		float raizn1(float nn1);
		
		float potencia();
		float potencia(float nn1, float nn2);
	
}; //toda classe se encerra com ; (padrão da ling. C++)
