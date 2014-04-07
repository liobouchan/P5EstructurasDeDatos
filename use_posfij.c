#include "posfij.h"

int main(){
	char Exp[50],E1[50],E2[50],EPOS[50],EPRE[50];
	system ("cls");
	Clear(EPRE,50);
	Clear(EPOS,50);
	Clear(E1,50);
	Clear(E2,50);
	
	do{
		printf("%s","Introduzca la expresi¢n infija: ");
		Input(Exp);
		if(Ver_Cad(Exp)!=igual){
			printf("La expresi¢n \'%s\' no es valida",Exp);
			switch(Ver_Cad(Exp)){
				case izq:
					printf("Le faltan parentesis derechos.");
					break;
				case der:
					printf("Le faltan parentesis izquierdos.");
					break;
				case none:
					printf("Ya que no es funcion valida.");
					break;
			}
			getch();
			system ("cls");
		}
	}while(Ver_Cad(Exp)!=igual);
	Add(E1,Exp);
	Add(E2,Exp);
	Conv_Pre(E1,EPRE);
	
/*Invertimos la Expresi¢n*/
	Invertir(EPRE);
	printf("%s %s\n","Su conversi¢n a Prefija es: ",EPRE);
	Conv_Pos(E2,EPOS);
	printf("%s %s\n","Su conversi¢n a Postfija es: ",EPOS);
	getch();
}
