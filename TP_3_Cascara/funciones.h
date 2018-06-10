typedef struct
{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkDeImagen[50];
    int estado;
}eMovie;

eMovie* newArrayMovies (int);
void mostrarPeliculas (char*, eMovie*, int);
void mostrarPelicula(eMovie*);
void inicializarArray (eMovie*, int);
int menu(void);
eMovie* new_movie();
int buscarLibre (eMovie*, int);
void agregarPelicula(char*, eMovie*, int);
void fileToArray (char*, eMovie*);
void arrayToFile (char*, eMovie*, int);
int findString(char*, eMovie*, int);
void borrarPelicula(char*, eMovie*, int);
