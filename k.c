//Pilas
Es un tipo de dato abstracto lineal de elementos del mismo tipo, dónde cada
elemento se puede agregar o quitar únicamente por uno de sus extremos.

  En consecuencia, los elementos de la pila se eliminan en orfen inverso al que
  se insertaron, es decir , "el último elemento en entrar, es el primero en
  salir".
  
  Debido a esto, a una pila se le conoce como una estructura LIFO (Last-in , First-out).

  La pila se puede definir como una colección de datos a los cuales se puede
  acceder por un extremo llamado tope.

  //Representación de la pila
    Una pila se puede representar de dos formas:
      1) Estática.- Utilizando un arreglo
      2) Dinámica - Utilizando una lista.

  //Tope
    1; El lugar donde se va a insertar un elemento en la pila.
    2; El elemento que se va a eliminar de la pila.

  //Restricciones
    1; Para la pila estática, no se puede insertar un nuevo elemento en una
      pila llena, si ésta ocurre, se estaría provocando un desbordamiento.

    2; No se puede eliminar un elmento de una pila vacía, si ésto ocurre,
      se estaría provocando un subdesbordamiento.

  //Operaciones
    1; Insetar un elemento (push): Insetar un elemento en el tope de la pila.
    2; ELiminar un elemento (pop): Elimina el elemento que se encuentra en el
      tope de la pila, retornandolo.
    3; Retornar Elemento : Si se va a retomar el elemento que se encuentra en el
      tope de la pila, debemos conocer el valor nulo de ese elemento en caso de
      que la pila esté vacía.

  //Implementación
    Datos datoNULO; //Variable global para el pop
    typedef struct{
      Datos elementos[tamaño-maximo];
      int tope;
      char tipo[100];
      int contElems;
    }Pila;

    //Saberes
      // n es igual al tamaño máximo de la pila
      1; ¿Cuándo la pila está llena?
        tope = n-1 , contElems = n

      2; ¿Cuando la pila está vacía?
        tope = -1 , contElems = 0

      3; ¿Cuál es el índice dónde se va a insertar el nuevo elemento?
        tope + 1

      4; ¿Cuál es el índice dónde se va a eliminar el elemento?
        tope

      5; ¿Cuál es el valor inicial de tope?
        tope = -1

    //Crear Pila.- Cre la pila y la inicializa para su uso norma
      1) Pila p;
        void crearPila( Pila *p , char *tipo){
          p -> tope = -1;
          strcpy( p -> tipo , tipo );
          p -> contElems = 0;
        }

      2) Pila *p;
        void crearPila( Pila **p , char *tipo){
          *p = (Pila *)malloc(sizeof(Pila));
          (*p) -> tope = -1;
          strcpy( (*p) -> tipo , tipo );
          (*p) -> contElems = 0;
        }

    //Push
      int push( Pila * p , Datos nuevo ){
        if( p -> tope == tamaño-maximo-1 ){
          printf("%s\n", "Pila llena");
          return 0;
        }
        p -> elementos [ p -> tope +1 ] = nuevo;
        p -> tope += 1;
        p -> contElems += 1;
        return 1;
      }
    //Pop
      Datos pop( Pila *p ){
        if( p -> tope == -1){
          printf("%s\n", "Pila Vacia" );
          return datoNULO; //Declarada como variable global.
        }
        aux = p -> elementos[ p -> tope ];
        p -> tope -= 1;
        p -> contElems -=1;
        return aux;
      }
      //Otra Implementación de Pop
        int pop( Pila *p , Datos *aux ){
          if( p -> tope == -1 ){
            printf("%s\n", "Pila vacia \n");
            return -1;
          }
          *aux = p -> elementos[ p -> tope ];
          p -> tope -= 1;
          p -> contElems -=1;
          return 1;
        }
    //Mostrar Pila
      int mostrar_pila( Pila *p ){
        int topeAux = p -> tope;
        if ( topeAux == -1 ){
          printf("%s\n", "PIla vacia");
          return -1;
        }
        while( topeAux != -1 ){
          printf("%d\n", p -> elementos[topeAux].ALGUNDATO);
          topeAux --;
        }
        return 1;
      }