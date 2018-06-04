typedef struct
{
    int idMovie;
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkDeImagen[50];
    int estado;
}eMovie;

eMovie* newArrayMovies (int);
void mostrarPeliculas (eMovie*, int);
void mostrarPelicula(eMovie*);
void inicializarArray (eMovie*, int);
int menu(void);
eMovie* new_movie();
int buscarLibre (eMovie*, int);
void guardarMovies (eMovie*, int, char*);
void agregarPelicula(eMovie*, int);
void leerMovies(eMovie*, int, char*);
void borrarPelicula(eMovie*, int, char*);
