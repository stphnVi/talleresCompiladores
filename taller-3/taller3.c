#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void kiloMilla();
void centFaren();
void contT(int num);
void contP(int num);
int auxT(int num, int cont);
int auxP(int num, int cont);
int Strcmp(char *s, char *p);
void Strcat(char *dest, char *src);
void contTxt();
void ordTxt();
void eliminar(const char *archOri, char* archTemp);

int main() {
    char strS[20] = "comida";
    char strP[] = "food";


    //kiloMilla();                                                                  //1. De km a millas en un rango de [1-10].
    //centFaren();                                                                  //2. De centigrados a farenheit con un valor de entrada.
    //contT(212387050);                                                             //3. cantidad de digitos de un numero entero.
    //contP(212387050);                                                             //4. cantidad de digitos pares en un numero entero.
    //strcmp(strS, strP);
    //printf("El resultado de la comparación es: %d\n", Strcmp(strP, strS));        //5. compara largo de string
    //Strcat(strS, strP);                                                           //6. La función pega al final del string dest el valor del string src
    contTxt();                                                                      //7. # de linea en que aparecen palabras. Elimina palabras como el, la, los, y, etc
    //ordTxt();    
                                                                       //8.imprime las distintas palabras ordenadas en forma descendente de acuerdo con su frecuencia de ocurrencia
    
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

int Strcmp(char *s, char *p){
        while (*s != '\0' && *p != '\0') {
        if (*s != *p) {
            if(*s == '\0' && *p == '\0'){
            
            return 0;
            }else if(*s > *p){
            
                return -1;
            }else {
            
                return 1;
            }
        }
        s++;
        p++;
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

/* para usar esta funcion probar el texto en test.txt o bien cambiarlo en la funcion
para poder eliminar las palabras solicitadas*/


typedef struct{
    char palabra[50];
    int aparicionPorLinea[50];
    int conteoAparicion[50];
}diccionario;

void contTxt() {
    char archivoTemporal[50];
    eliminar("test.txt", archivoTemporal);
    FILE *archivo;
    char linea[1000];
    char* token;
    int contAp;

    archivo = fopen("temp.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        
    }

    // Leer línea por línea
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        // Procesar cada línea
        printf("Línea: %s", linea);

        // Leer palabra por palabra
        token = strtok(linea, " ");
        while (token != NULL) {
            // Procesar cada palabra
            printf("Palabra: %s\n", token);
            token = strtok(NULL, " ");
        }
    }

    fclose(archivo);
}

// elimina las palabras el, la, los, y, etc del texto de test.txt y lo reescribe en temp.txt para evaluar

void eliminar(const char* archivo, char* archivoTemporal) {
    FILE* archivoOriginal = fopen(archivo, "r");
    FILE* temporal;

    if (archivoOriginal == NULL) {
        printf("No se puede abrir el archivo.\n");
        return;
    }

    char archivoTemporalUnico[50];
    int i = 1;
    while (1) {
        sprintf(archivoTemporalUnico, "temp.txt", i);
        temporal = fopen(archivoTemporalUnico, "w");
        if (temporal != NULL) {
            break;
        }
        i++;
    }

    char linea[1000];
    while (fgets(linea, sizeof(linea), archivoOriginal) != NULL) {
        char* palabra;
        char* token = strtok(linea, " ");

        while (token != NULL) {
            if (strcmp(token, "el") != 0 && strcmp(token, "la") != 0 && strcmp(token, "los") != 0 && strcmp(token, "y") != 0 && strcmp(token, "etc") != 0) {
                fprintf(temporal, "%s ", token);
            }
            token = strtok(NULL, " ");
        }
    }

    fclose(archivoOriginal);
    fclose(temporal);
    strcpy(archivoTemporal, archivoTemporalUnico);
}




void LeerA(){

}


//..........................................................................................8

/*void ordTxt(){

}*/