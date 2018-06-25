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

eMovie* newArrayMovies (int*);
void inicializarArray (eMovie* arrayMovies, int* pTam);
void fileToArray (char*, eMovie*, int*);
void mostrarPelicula (eMovie*);
void mostrarPeliculas (eMovie*, int*);
int menu(void);
eMovie* new_movie(void);
int buscarLibre (eMovie*, int*);
eMovie* resizeArray (eMovie*, int*);
void arrayToFile (char*, eMovie*, int*);
void agregarPelicula(char*, eMovie*, int*);
void borrarPelicula(eMovie*, int*);
void modificarPelicula(eMovie*, int*);
