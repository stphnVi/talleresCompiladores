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
void eliminar(const char *archOri, char *archTemp);
int buscarPalabra(char *pal);
void auxcontTxt(char *pal, int valor);
void imprimirOcurrencias();
void imprimirDiccionario();

int main()
{
    char strS[20] = "comida";
    char strP[] = "food";
    // kiloMilla(); // 1. De km a millas en un rango de [1-10].
    // centFaren(); // 2. De centigrados a farenheit con un valor de entrada.
    //  contT(212387050);                                                             //3. cantidad de digitos de un numero entero.
    //  contP(212387050);                                                             //4. cantidad de digitos pares en un numero entero.
    //  printf("El resultado de la comparación es: %d\n", Strcmp(strP, strS));        //5. compara largo de string
    //  Strcat(strS, strP);                                                           //6. La función pega al final del string dest el valor del string src
    //  contTxt();                                                                    //7. # de linea en que aparecen palabras. Elimina palabras como el, la, los, y, etc
    //  ordTxt();                                                                     //8.imprime las distintas palabras ordenadas en forma descendente de acuerdo con su frecuencia de ocurrencia
    return 0;
}

//..........................................................................................1

void kiloMilla()
{
    int i = 1;
    float x;
    while (i <= 10)
    {
        x = i * 0.6214;
        i++;
        printf("%f\n", x);
    }
}

//..........................................................................................2

void centFaren()
{
    float centi;
    float f;
    printf("Ingresa un valor en grados centigrados: ");
    scanf("%f", &centi);
    f = (9.0 / 5.0) * centi + 32;
    printf("El equivalente en Fahrenheit es: %f\n", f);
}

//..........................................................................................3

void contT(int num)
{
    auxT(num, 0);
}

int auxT(int num, int cont)
{
    int newNum;
    newNum = num / 10;
    cont++;
    if (newNum == 0)
    {
        printf(" la cantidad de digitos es: %d\n", cont);
        return cont;
    }
    else
    {
        return auxT(newNum, cont);
    }
}

//..........................................................................................4

void contP(int num)
{
    auxP(num, 0);
}

int auxP(int num, int cont)
{
    int newNum;
    newNum = num / 10;
    if (newNum == 0)
    {
        if (newNum % 2 == 0)
        {
            cont++;
            printf(" la cantidad de digitos pares es: %d\n", cont);
            return cont;
        }
        printf(" la cantidad de digitos pares es: %d\n", cont);
        return cont;
    }
    else
    {
        if (newNum % 2 == 0)
        {
            cont++;
            return auxP(newNum, cont);
        }
        return auxP(newNum, cont);
    }
}

//..........................................................................................5

int Strcmp(char *s, char *p)
{
    while (*s != '\0' && *p != '\0')
    {
        if (*s != *p)
        {
            if (*s == '\0' && *p == '\0')
            {

                return 0;
            }
            else if (*s > *p)
            {

                return -1;
            }
            else
            {

                return 1;
            }
        }
        s++;
        p++;
    }
}

//..........................................................................................6

void Strcat(char *dest, char *src)
{
    char *initialDest = dest;
    while (1)
    {
        if (*dest != '\0')
        {
            dest++;
        }
        else if (*src != '\0')
        {
            *dest = *src;
            src++;
            dest++;
        }
        else
        {
            printf("Valor final de dest: %s\n", initialDest);
            break;
        }
    }
}

//..........................................................................................7

/* para usar esta funcion probar el texto con test.txt o bien cambiarlo en la funcion contTxt en la linea
166 para poder eliminar las palabras solicitadas*/

typedef struct
{
    char palabra[50];
    int aparicionPorLinea[50];
    int conteoAparicion[50];
} diccionario;

diccionario palabras[500];

int globalOccur = 1;

// función que procesa el nuevo archivo para armar el diccionario
void contTxt()
{
    int valor = -1; // Inicializar el valor en -1
    char archivoTemporal[50];
    eliminar("test.txt", archivoTemporal);
    FILE *archivo;
    char linea[1000];
    char *token1;

    archivo = fopen("temp.txt", "r");
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    char x[1024];
    /* asume que una palabra no exceda un largo de 1023 */
    while (fscanf(archivo, " %1023s", x) == 1)
    {
        // Procesar cada palabra
        int indice = buscarPalabra(x);
        if (indice == -1)
        {
            valor++;
            strcpy(palabras[valor].palabra, x); // Agregar la palabra al diccionario
            auxcontTxt(x, valor);
        }
        else
        {
            auxcontTxt(x, indice); // Actualizar la aparición de la palabra existente
        }
        // printf("Palabra: %s\n", x);
    }
    if (globalOccur == 1)
    {
        imprimirOcurrencias();
    }

    fclose(archivo);
}

// función auxiliar de conTxt que actualiza el diccionario si la palabra no es repetida
void auxcontTxt(char *pal, int valor)
{
    int contOcur = 0;
    int contLi = 0;
    int indiceAparicion = 0;

    FILE *archivo;
    char linea[1000];
    char *token1;
    char *saveptr;

    archivo = fopen("temp.txt", "r");
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    while (fgets(linea, sizeof(linea), archivo) != NULL)
    {
        contLi++;
        token1 = strtok_r(linea, " \n", &saveptr);
        while (token1 != NULL)
        {
            if (strcmp(pal, token1) == 0)
            {
                contOcur++;
                palabras[valor].conteoAparicion[0] = contOcur;
                palabras[valor].aparicionPorLinea[contOcur - 1] = contLi;
            }
            token1 = strtok_r(NULL, " \n", &saveptr);
        }
    }
    palabras[valor].conteoAparicion[0] = contOcur; // Actualizar el conteo total de apariciones

    fclose(archivo);
}
int tDiccionario = 0;
// busca palabras en el diccionario para asegurar que no se repitan
int buscarPalabra(char *pal)
{
    for (int i = 0; i < 200; i++)
    {
        if (strcmp(palabras[i].palabra, pal) == 0)
        {
            return i;
        }
    }
    tDiccionario++;
    return -1; // La palabra no se encuentra en el diccionario
}

// elimina las palabras el, la, los, y, etc del texto de test.txt y lo reescribe en temp.txt para evaluar
void eliminar(const char *archivo, char *archivoTemporal)
{
    FILE *archivoOriginal = fopen(archivo, "r");
    FILE *temporal;
    if (archivoOriginal == NULL)
    {
        printf("No se puede abrir el archivo.\n");
        return;
    }
    char archivoTemporalUnico[50];
    int i = 1;
    while (1)
    {
        sprintf(archivoTemporalUnico, "temp.txt", i);
        temporal = fopen(archivoTemporalUnico, "w");
        if (temporal != NULL)
        {
            break;
        }
        i++;
    }
    char linea[1000];

    while (fgets(linea, sizeof(linea), archivoOriginal) != NULL)
    {
        char *palabra;
        char *token = strtok(linea, " ");

        while (token != NULL)
        {
            if (strcmp(token, "el") != 0 && strcmp(token, "la") != 0 && strcmp(token, "los") != 0 && strcmp(token, "y") != 0 && strcmp(token, "etc") != 0)
            {
                fprintf(temporal, "%s ", token);
            }
            token = strtok(NULL, " ");
        }
    }

    fclose(archivoOriginal);
    fclose(temporal);
    strcpy(archivoTemporal, archivoTemporalUnico);
}

// imprime ocurrencias en cada oracion del tecto de una palabra.

void imprimirOcurrencias()
{
    int i, j;
    for (i = 0; i < 200; i++)
    {
        if (palabras[i].palabra[0] != '\0')
        {
            printf("%s: ", palabras[i].palabra);
            int numOcurrencias = palabras[i].conteoAparicion[0]; // Obtener el número de ocurrencias
            for (j = 0; j < numOcurrencias; j++)
            {
                printf("%d", palabras[i].aparicionPorLinea[j]);
                if (j < numOcurrencias - 1)
                { // Comparar j con numOcurrencias
                    printf(", ");
                }
            }
            printf("\n");
        }
    }
}

//..........................................................................................8

void ordTxt()
{
    globalOccur = 0;
    contTxt();

    printf("Diccionario ordenado por conteo de apariciones:\n");
    // ordenado con buble
    for (int i = 0; i < tDiccionario - 1; i++)
    {
        for (int j = 0; j < tDiccionario - i - 1; j++)
        {
            if (palabras[j].conteoAparicion[0] < palabras[j + 1].conteoAparicion[0])
            {
                diccionario tmp = palabras[j];
                palabras[j] = palabras[j + 1];
                palabras[j + 1] = tmp;
            }
        }
    }

    // Imprimir el diccionario ordenado
    for (int i = 0; i < tDiccionario; i++)
    {
        if (palabras[i].palabra[0] != '\0')
        {
            printf("%s: ", palabras[i].palabra);
            printf("%d ", palabras[i].conteoAparicion[0]);
            printf("\n");
        }
    }
    globalOccur = 1;
}
