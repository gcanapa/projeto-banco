//Fila não prioritaria
struct fila{
    int inicio;
    int fim;
    int cap;
    int *valores;
    int total;
};

void criafila(struct fila *f, int cap);
void inserir_elemento(struct fila *f, int elemento);
int retirar_elemento(struct fila *f);
int isEmpty(struct fila *f);
int isFull(struct fila *f);
void mostra_elementos(struct fila *f);
int inverteFila(struct fila *f, struct fila *filaCopia);

