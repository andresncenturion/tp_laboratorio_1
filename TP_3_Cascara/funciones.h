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

/** \brief Construye un array de estructuras eMovie
 *
 * \param
 * \return Puntero al array de peliculas
 *
 */

eMovie* newArrayMovies ();

/** \brief Muestra por consola todas las peliculas almacenadas
 *
 * \param Puntero al array de peliculas
 * \param Tamanio del array de peliculas
 * \return
 *
 */

void mostrarPeliculas (eMovie*, int);

/** \brief Muestra por consola una pelicula almacenada
 *
 * \param Puntero a la pelicula a mostrar
 * \return
 *
 */

void mostrarPelicula(eMovie*);

/** \brief Inicializa los flags de estado del array
 *
 * \param Puntero a array de peliculas
 * \param Tamano del array
 * \return
 *
 */

void inicializarArray (eMovie*, int);

/** \brief Muestra por consola el menu de opciones del programa
 *
 * \return Retorna la seleccion del usuario
 *
 */

int menu(void);

/** \brief Crea una nueva pelicula solicitando los datos al usuario
 *
 * \param
 * \return Retorna la direccion de memoria de la pelicula creada
 *
 */

eMovie* new_movie();

/** \brief Busca un espacio libre en el array.
 *
 * \param Puntero al array de peliculas
 * \param Tamanio del array de peliculas
 * \return Retorna el primer indice libre en el array
 *
 */

int buscarLibre (eMovie*, int);

/** \brief Lee del archivo los datos guardados y los carga en el array de peliculas
 *
 * \param Path al archivo que almacena los datos de las peliculas
 * \param Puntero al array de peliculas
 * \return
 *
 */

int fileToArray (char*, eMovie*);

/** \brief Escribe en el archivo los datos almacenados en el array de peliculas
 *
 * \param Path al archivo a escribir
 * \param Puntero al array de peliculas
 * \param Tamanio del array de peliculas
 * \return
 *
 */

int arrayToFile (char*, eMovie*);

/** \brief Agranda 5 lugares el array de peliculas
 *
 * \param Puntero al array de peliculas
 * \param Tamanio del array de peliculas
 * \return Puntero al array de peliculas redimensionado
 *
 */

eMovie* resizeArray (eMovie*, int);

/** \brief Agrega una pelicula al array de peliculas
 *
 * \param Path al archivo en el que se almacenan las peliculas
 * \param Puntero al array de peliculas
 * \param Tamanio del array de peliculas
 * \return
 *
 */

void agregarPelicula(char*, eMovie*);
void arrayToFile2(char* path, eMovie* arrayMovies, int tam);
void borrarPelicula(char*, eMovie*);
