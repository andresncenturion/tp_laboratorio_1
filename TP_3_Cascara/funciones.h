typedef struct
{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[250];
    int puntaje;
    char linkDeImagen[200];
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
void generarPaginaWeb(eMovie*, int*);
