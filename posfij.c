#include "posfij.h"

char Simb[4][3]={{'(',')','\0'},{'-a','+','\0'},{'/','*','\0'},{'^','\0','\0'}};

void Input(char Exp[]){ //se incrimenta en i hasta encontrarse con /n//
	int i;
	for(i=0;(Exp[i] = getchar()) != '\n';++i);
	Exp[i]='\0';
}

/*Esta funci¢n limpia n espacios en Text*/
void Clear(char Text[],int n){
	int i;
	for(i=0;i<n;i++)
	Text[i]='\0';
}

/*Calcula la prioridad entre exp1 y exp2

-1 si exp1 < exp2
0 si exp1 == exp2
1 si exp1 > exp2*/ //valida las exprexiones tecleadas (signos)//
int Priority(char exp1,char exp2){
	int i,j,p1,p2;
	for(i=0;i<4;i++)
	for(j=0;j<3;j++){
		if(exp1==Simb[i][j])
			p1=i;
		if(exp2==Simb[i][j])
			p2=i;
	}
	if(p1<p2)
		i=-1;
	else if(p1==p2)
		i=0;
	else if(p1>p2)
		i=1;
		
	return(i);
}

/*Hace lo mismo que strlen(text), candidad de caracteres en la cadena */
int length(char text[]){
	int n;
	for(n=0;text[n]!='\0';++n);
	return(n);
}

/*Agrega la cadena B en A*/ //concatenar las cadenas (juntarlas) el ultimo elemento de A es el primero B//
void Add(char A[],char B[]){
	int n1,n2,i;
	n1=length(A);
	n2=length(B);
	for(i=n1;i<(n1+n2);i++)
		A[i]=B[i-n1];
	A[i]='\0';
}

/*Verifica si text es una cadena valida*/
Par Ver_Cad(char text[]){
	int i,n,cont1,cont2,TOPE;
	char PILA[50],elem;
	Par val=none;
	n=length(text);
	if(n>0){
		TOPE=0;
		cont1=cont2=0;
		for(i=0;i<n;i++){
			elem=text[i];
			if(elem=='('){
				PILA[TOPE]=elem;
				TOPE+=1;
				PILA[TOPE]='\0';
			}
			else
			if(elem==')')
				if(TOPE>0){
					if(PILA[TOPE-1]=='('){
						TOPE-=1;
						PILA[TOPE]='\0';
					}
				}
				else{
					PILA[TOPE]=elem;
					TOPE+=1;
					PILA[TOPE]='\0';
				}
		}
		if(TOPE>0){
			for(i=0;i<TOPE;i++){
				if(PILA[i]=='(')
					cont1+=1;
				if(PILA[i]==')')
					cont2+=1;
			}
			if(cont1<cont2)
				val=der;
			if(cont1>cont2)
				val=izq;
		}
		else
		val=igual;
	}
	else
		val=none;
		
	return(val);
}

/*Verifica si Expr es simbolo o no*/  //verifica si son simbolos// ************************

bool IfSimb(char Expr){
	int i,j;
	bool val;
	val=False;
	for(i=0;i<4;i++)
		for(j=0;j<3;j++)
			if(Expr==Simb[i][j])
				val=True;
	
	return(val);
}

/*Agrega un caracter a la cadena Exp1,añade un caracter al ultimo de la cadena EXp1 de EXp2*/
void Append(char Exp1[],char Exp2){
	int n;
	n=length(Exp1);
	Exp1[n]=Exp2;
}

/*Invierte el sentido de una cadena de caracteres*/
void Invertir(char Expr[]){
	int i,n;
	char *var;
	n=length(Expr);
	var=(char *) malloc((n+1)*sizeof(char));	//*var -> proceso malloc -> var[n+1];sizeof(tamaño del tipo de caracter)//
	for(i=0;i<n;i++)
		*(var+(n-i)-1)=Expr[i];
	for(i=0;i<n;i++)
		Expr[i]=*(var+i);
	*(var+i)='\0';
	free(var);//liberara la mamoria reservada con malloc//
}

/*Elimina el ultimo elemento de Text*/
void Rec_Exp_Pre(char Text[]){
	int n;
	n=length(Text);
	Text[n-1]='\0';
}

/*Convierte una expresion EI (Infija) a una espresi¢n EPRE (Prefija)*/
void Conv_Pre(char EI[],char EPRE[]){
	int TOPE,n;
	char Simbolo,PILA[50];
	Clear(PILA,50);
	/*Hacer TOPE <- -1*/
	TOPE=-1;
	n=length(EI);
	/*Mientras EI sea diferente de la cadena vacia*/
	while(EI[0]!='\0'){
		n-=1;
		/*Tomamos el simbolo mas a la derecha*/
		Simbolo=EI[n];
		/*Recortamos la expresi¢n*/
		Rec_Exp_Pre(EI);
		/*Si el simbolo es parentesis derecho*/
		if(Simbolo==')'){
			TOPE+=1;
			/*Colocamos el simbolo en la pila*/
			PILA[TOPE]=Simbolo;
		}
		/*Si el simbolo es izquierdo*/
		else if(Simbolo=='('){
			while(PILA[TOPE]!=')'){
				Append(EPRE,PILA[TOPE]);
				PILA[TOPE]='\0';
				TOPE-=1;
			}
			/*Sacamos el par‚ntesis de la pila*/
			PILA[TOPE]='\0';
			TOPE-=1;
		}
		/*Si es operando*/
		else if(IfSimb(Simbolo)==False)
			Append(EPRE,Simbolo);
		else{
		/*Si la pila contiene algo*/
			if(length(PILA)>0){
			/*Mientras el operador sea < al que se encuentra al tope de la pila*/
				while(Priority(Simbolo,PILA[TOPE])<0){
					/*Agregar lo que hay en el tope de la pila*/
					Append(EPRE,PILA[TOPE]);
					/*Eliminamos lo que hay en el tope de la pila*/
					PILA[TOPE]='\0';
					TOPE-=1;
					if(TOPE<0)
						break;
				}
			}
			TOPE+=1;
			/*Agregamos el s¡mbolo al tope de la pila*/
			PILA[TOPE]=Simbolo;
		}
	}
	/*Agregamos lo que qued¢ en la pila*/
	while(TOPE>=0){
		Append(EPRE,PILA[TOPE]);
		TOPE-=1;
	}
}

/*Elimina el primer elemento*/
void Rec_Exp_Pos(char Text[]){
	int i,n;
	n=length(Text);
	for(i=0;i<(n-1);i++)
		Text[i]=Text[i+1];
	Text[i]='\0';
}

/*Convierte una epresion EI (Infija) a una expresion EPOS (Postfija)*/
void Conv_Pos(char EI[],char EPOS[]){
	int TOPE,n;
	char Simbolo,PILA[50];
	Clear(PILA,50);
	/*Hacer TOPE <- -1*/
	TOPE=-1;
	n=length(EI);
	/*Repetir Mientras EI sea diferente a cadena vac¡a*/
	while(EI[0]!='\0'){
		/*Tomar el s¡mbolo m s a la izquierda de EI*/
		Simbolo=EI[0];
		/*Recortamos la Expresi¢n*/
		Rec_Exp_Pos(EI);
		n-=1;
		/*Si el s¡mbolo es par‚ntesis izquierdo*/
		if(Simbolo=='('){
			/*Poner s¡mbolo en la pila*/
			TOPE+=1;
			PILA[TOPE]=Simbolo;
		}
		/*Si el s¡mbolo es par‚ntesis derecho*/
		else if(Simbolo==')'){
			while(PILA[TOPE]!='('){
				/*Agregamos lo que hay en el tope de la pila*/
				Append(EPOS,PILA[TOPE]);
				PILA[TOPE]='\0';
				TOPE-=1;
			}
			/*Sacamos el par‚ntesis izquierdo de la pila*/
			PILA[TOPE]='\0';
			TOPE-=1;
		}
		/*Si es operando*/
		else if(IfSimb(Simbolo)==False){
			/*Agregar contenido de Simbolo a EPOS*/
			Append(EPOS,Simbolo);
		}
		else{
			/*Si la Pila contiene algo*/
			if(length(PILA)>0){
			/*Mientras el operador sea <= al que se encuentra al tope de la pila*/
				while(Priority(Simbolo,PILA[TOPE])<=0){
					/*Agregar lo que hay al tope de la pila*/
					Append(EPOS,PILA[TOPE]);
					/*Borramos lo que hay al tope de la pila*/
					PILA[TOPE]='\0';
					TOPE-=1;
					if(TOPE<0)
						break;
				}
			}
			/*Agregamos el s¡mbolo al tope de la pila*/
			TOPE+=1;
			PILA[TOPE]=Simbolo;
		}
	}
	/*Agregamos lo que qued¢ en la pila*/
	while(TOPE>=0){
		Append(EPOS,PILA[TOPE]);
		TOPE-=1;
	}
}
