#include <iostream>
#define max 30

struct pessoa{
    int valor;
    struct pessoa *prox;
};

struct fila{
    struct pessoa *inicio, *pessoa, *aux, *pont;
};

fila novaFila(){
    fila fila;
    fila.inicio = 0;
    return fila;
}

bool filaVazia(fila f){
    return (f.inicio != 0 ? false : true);
}

void inserir(fila *f, int valor){
    f->pessoa = new (pessoa);
    f->pessoa->valor = valor;
    f->pessoa->prox = f->inicio;
    f->inicio = f->pessoa;
}

void remover(fila *f, int valor){
    if (f->inicio == 0)
	    printf ("\n Lista vazia");
    else {
        f->pont = f->inicio;
       	f->aux  = f->inicio;
    while (f->pont->valor != valor){
        f->aux = f->pont;
		f->pont = f->pont->prox;
    }
    f->aux->prox = f->pont->prox;
    }
}
void exibirFila(fila fila){
	fila.pont = fila.inicio;
    std::cout << "\nEndereco de memoria do primeiro elemento da lista: "<< fila.inicio;
	std::cout << "\nEndereco\tValor\tProximo\n";
	while (fila.pont != 0) {
        std::cout << "\n" << fila.pont << "\t"<< fila.pont->valor << "\t"<< fila.pont->prox;
	    fila.pont = fila.pont->prox;
    }
    std::cout  << "\n";
}
int main(){
    using namespace std;
    fila fila;
    fila = novaFila();
    inserir(&fila, 50);
    exibirFila(fila);
    inserir(&fila, 75);
    exibirFila(fila);
    inserir(&fila, 88);
    exibirFila(fila);
    remover(&fila, 75);
    exibirFila(fila);
    return 0;
}