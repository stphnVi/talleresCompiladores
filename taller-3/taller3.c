#include <stdio.h>
#include <stdlib.h>


void kiloMilla();
void centFaren();
void contT(int num);
void contP(int num);
int auxT(int num, int cont);
int auxP(int num, int cont);
int strcmp(char *s, char *p);
void Strcat(char *dest, char *src);
void contTxt();
void ordTxt();

int main() {
    char strS[20] = "comida";
    char strP[] = "food";


    //kiloMilla();                                                                  //1. De km a millas en un rango de [1-10].
    //centFaren();                                                                  //2. De centigrados a farenheit con un valor de entrada.
    //contT(212387050);                                                             //3. cantidad de digitos de un numero entero.
    //contP(212387050);                                                             //4. cantidad de digitos pares en un numero entero.
    //strcmp(strS, strP);
    //printf("El resultado de la comparación es: %d\n", strcmp(strS, strP));        //5. compara largo de string
    //Strcat(strS, strP);                                                           //6. La función pega al final del string dest el valor del string src
    contTxt();                                                                      //7. # de linea en que aparecen palabras. Elimina palabras como el, la, los, y, etc
    ordTxt();                                                                       //8.imprime las distintas palabras ordenadas en forma descendente de acuerdo con su frecuencia de ocurrencia
    
    return 0;
}

//..........................................................................................1

void kiloMilla(){
    int i= 1;
    float x;
    while (i <= 10){
        x = i* 0.6214;
        i++;
        printf("%f\n", x);
    }
}

//..........................................................................................2

void centFaren(){
    float centi;
    float f;
    printf("Ingresa un valor en grados centigrados: ");
    scanf("%f", &centi);
    f =  (9.0/5.0) * centi + 32;
    printf("El equivalente en Fahrenheit es: %f\n", f);
}

//..........................................................................................3

void contT(int num){
    auxT(num, 0); 
}


int auxT(int num, int cont){
    int newNum;
    newNum = num/10;
    cont++;
    if (newNum == 0){
        printf(" la cantidad de digitos es: %d\n", cont);
        return cont;
    }else{
        return auxT(newNum, cont);
    }
}

//..........................................................................................4

void contP(int num){
    auxP(num, 0);
}


int auxP(int num, int cont){
    int newNum;
    newNum = num/10;
    if (newNum == 0){
        if(newNum % 2 == 0 ){
            cont++;
            printf(" la cantidad de digitos pares es: %d\n", cont);
            return cont;
        }
            printf(" la cantidad de digitos pares es: %d\n", cont);
            return cont;
    }else{
        if(newNum % 2 == 0 ){
            cont++;
            return auxP(newNum, cont);
        }
        return auxP(newNum, cont);
    }
}

//..........................................................................................5

int strcmp(char *s, char *p){
        while (*s != '\0' && *p != '\0') {
        if (*s != *p) {
            return (*s > *p) ? 1 : -1;
        }
        s++;
        p++;
    }
        if(*s == '\0' && *p == '\0'){
            
            return 0;
        }else if(*s == '\0'){
            
            return -1;
        }else {
            
            return 1;
        }
}

//..........................................................................................6

void Strcat(char *dest, char *src){
    char *initialDest = dest;
    while(1){
        if(*dest != '\0'){
            dest++;
        }else if(*src != '\0'){
            *dest = *src;
            src++;
            dest++;
        }else{
            printf("Valor final de dest: %s\n", initialDest);
            break;
        }
    }
}

//..........................................................................................7

void contTxt(){
    FILE *archivo;
    char palabra[50];
    int cont;
    char linea[MAX_LONGITUD_LINEA]; 

    archivo = fopen("test.txt", "r");
    char caracter;

    

    while (fgets(linea, MAX_LONGITUD_LINEA, archivo) != NULL) {
        printf("%s", linea);
        while(fscanf(linea, "%s", palabra) == 1){
            printf("%s\n", palabra);
        }
        
    }

    fclose(archivo);

    
}

void LeerA(){

}


//..........................................................................................8

void ordTxt(){

}