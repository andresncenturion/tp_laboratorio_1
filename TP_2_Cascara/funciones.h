typedef struct
{
    char nombre[50];
    int edad;
    int estado;
    long int dni;
}EPersona;

void inicializarEmpleados (EPersona[], int);
int menu (void);
void agregarPersona (EPersona[], int);
int buscarLibre(EPersona[], int);
int buscarPersona (EPersona[], int, long int);
void borrarPersona (EPersona[], int);
void ordenarPorNombre(EPersona[], int);
void mostrarPersonas(EPersona[], int);
void mostrarPersona (EPersona[], int);
void imprimirGrafico (EPersona[], int);
