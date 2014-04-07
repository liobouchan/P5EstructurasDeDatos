#ifndef POFFIJ_H
#define POSFIJ_H

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef enum {False,True} bool; //declara variable bool, con valores false and true//
typedef enum {izq,igual,der,none} Par;

void Clear(char [],int ),
Add(char [],char []),
Append(char [],char ),
Rec_Exp_Pos(char []),
Conv_Pos(char [],char []),
Invertir(char []),
Rec_Exp_Pre(char []),
Input(char []), //gets,scanf//
Conv_Pre(char [],char []);

int Priority(char,char),
length(char []);

Par Ver_Cad(char []);
bool IfSimb(char);
	
#endif
