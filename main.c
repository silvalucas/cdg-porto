#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int unidadeTempo, transpTravessa;
int quantNavios, quantNaviosDentro;
int instantesf1, instantesf2, instantesf3, instantesf4;
int quant1, quant2, quant3, quant4;
float media1, media2, media3, media4;

//Data: 30/04/2019
//Nome: Lucas Oliveira Silva
//Disciplica: Estrutura de Dados I

// ############# ESTRUTURAS ##################


typedef struct Conteiner {
    int id;
} Conteiner;

typedef struct NO2 {
    Conteiner conteiner;
    struct NO2 *proximo;
} NO2;

typedef struct {
    int tam;
    int id;
    int status;
    NO2 *inicio;
} Pilha;

typedef struct Carro {
    int instante;
} Carro;

typedef struct Navio {
    int id;
    int unidTempo;
    int quantConteiners;
    Pilha pilha1;
    Pilha pilha2;
    Pilha pilha3;
    Pilha pilha4;
} Navio;

typedef struct NO {
    Navio navio;
    struct NO *proximo;
} NO;

typedef struct {
    int id;
    int tam;
    Carro carro;
    NO *inicio;
    NO *fim;
} Fila;

// ############# FUNÇÕES ##################

//Criação de pilha com cabeça
void criaPilhaVazia(Pilha *pilha, int x) {
    pilha->inicio = malloc(sizeof(NO2));
    pilha->tam = 0;
    pilha->inicio->proximo = NULL;
    pilha->status = 0;
    pilha->id = x;
}

//Criação de fila com cabeça
void criaFilaVazia(Fila *fila, int x) {
    fila->inicio = malloc(sizeof(NO));
    fila->id = x;
    fila->fim = fila->inicio;
    fila->fim->proximo = NULL;
    fila->tam = 0;
}

//Retirada do navio da fila após finalizar o descarregamento dos conteiners
int retiraNavio(Fila *fila) {
    if (fila->tam == 1) {
        NO *aux = fila->inicio;
        aux->proximo = NULL;
        fila->fim = aux;
        fila->fim->proximo = NULL;
        fila->tam = 0;
        return 0;
    } else {
        NO *aux = fila->inicio->proximo;
        NO *aux2 = aux->proximo;
        fila->inicio->proximo = aux2;
        fila->tam = fila->tam - 1;
        free(aux);
        return 0;
    }
}

//Veículo retira travessa para armazem após atingir o limite máximo;
int retiraTravessas(Pilha *pilha, int x, Fila *fila) {
    NO2 *aux = pilha->inicio;
    pilha->inicio->proximo = NULL;
    pilha->inicio = aux;
    pilha->tam = 0;
    transpTravessa = transpTravessa + 1;
    pilha->status = 2;
    fila->carro.instante = 2;
    printf("Travessa %d transportada para o armazem!\n", x);
    printf("Tempo: %d\n", unidadeTempo);
}

//Retira 1 a 1 os conteiners do navio
int retiraConteinerNavio(Fila *fila, Pilha *pilha1, Pilha *pilha2, Pilha *pilha3, Pilha *pilha4, Pilha *pilha5) {
    NO *aux = fila->inicio->proximo;

    if (aux == NULL) {
        printf("Atracadouro %d esta vazio!\n", fila->id);
        return 1;
    } else {
        printf("Descarregando no atracadouro %d...\n", fila->id);
    }

    int cabem1 = 5 - pilha1->tam;
    if (cabem1 == 0) {
        retiraTravessas(pilha1, 1, fila);
        if(pilha1->status == 2){
            pilha1->status = pilha1->status - 1;
        } else{
            pilha1->status = 0;
        }
        fila->carro.instante = fila->carro.instante - 1;
    } else if (cabem1 > 0 && aux->navio.quantConteiners > 0) {
        NO2 *novo = malloc(sizeof(NO2));
        if (aux->navio.pilha1.tam > 0 && pilha1->status == 0) {
            NO2 *aux2 = pilha1->inicio->proximo;
            pilha1->inicio = novo;
            novo->proximo = aux2;
            pilha1->tam = pilha1->tam + 1;
            aux->navio.quantConteiners = aux->navio.quantConteiners - 1;
            aux->navio.pilha1.tam = aux->navio.pilha1.tam - 1;
            return 0;
        } else if (aux->navio.pilha2.tam > 0 && fila->carro.instante == 0) {
            NO2 *aux2 = pilha1->inicio->proximo;
            pilha1->inicio = novo;
            novo->proximo = aux2;
            pilha1->tam = pilha1->tam + 1;
            aux->navio.quantConteiners = aux->navio.quantConteiners - 1;
            aux->navio.pilha2.tam = aux->navio.pilha2.tam - 1;
            return 0;
        } else if (aux->navio.pilha3.tam > 0 && fila->carro.instante == 0) {
            NO2 *aux2 = pilha1->inicio->proximo;
            pilha1->inicio = novo;
            novo->proximo = aux2;
            pilha1->tam = pilha1->tam + 1;
            aux->navio.quantConteiners = aux->navio.quantConteiners - 1;
            aux->navio.pilha3.tam = aux->navio.pilha3.tam - 1;
            return 0;
        } else if (aux->navio.pilha4.tam > 0 && fila->carro.instante == 0) {
            NO2 *aux2 = pilha1->inicio->proximo;
            pilha1->inicio = novo;
            novo->proximo = aux2;
            pilha1->tam = pilha1->tam + 1;
            aux->navio.quantConteiners = aux->navio.quantConteiners - 1;
            aux->navio.pilha4.tam = aux->navio.pilha4.tam - 1;
            return 0;
        }
    }
    int cabem2 = 5 - pilha2->tam;
    if (cabem2 == 0) {
        retiraTravessas(pilha2, 2, fila);
        if(pilha1->status == 2){
            pilha1->status = pilha1->status - 1;
        } else{
            pilha1->status = 0;
        }
        fila->carro.instante = fila->carro.instante - 1;
    } else if (cabem2 > 0 && aux->navio.quantConteiners > 0) {
        NO2 *novo = malloc(sizeof(NO2));
        if (aux->navio.pilha1.tam > 0 && pilha2->status == 0) {
            NO2 *aux2 = pilha2->inicio->proximo;
            pilha2->inicio = novo;
            novo->proximo = aux2;
            pilha2->tam = pilha2->tam + 1;
            aux->navio.quantConteiners = aux->navio.quantConteiners - 1;
            aux->navio.pilha1.tam = aux->navio.pilha1.tam - 1;
            return 0;
        } else if (aux->navio.pilha2.tam > 0 && fila->carro.instante == 0) {
            NO2 *aux2 = pilha2->inicio->proximo;
            pilha2->inicio = novo;
            novo->proximo = aux2;
            pilha2->tam = pilha2->tam + 1;
            aux->navio.quantConteiners = aux->navio.quantConteiners - 1;
            aux->navio.pilha2.tam = aux->navio.pilha2.tam - 1;
            return 0;
        } else if (aux->navio.pilha3.tam > 0 && fila->carro.instante == 0) {
            NO2 *aux2 = pilha2->inicio->proximo;
            pilha2->inicio = novo;
            novo->proximo = aux2;
            pilha2->tam = pilha2->tam + 1;
            aux->navio.quantConteiners = aux->navio.quantConteiners - 1;
            aux->navio.pilha3.tam = aux->navio.pilha3.tam - 1;
            return 0;
        } else if (aux->navio.pilha4.tam > 0 && fila->carro.instante == 0) {
            NO2 *aux2 = pilha2->inicio->proximo;
            pilha2->inicio = novo;
            novo->proximo = aux2;
            pilha2->tam = pilha2->tam + 1;
            aux->navio.quantConteiners = aux->navio.quantConteiners - 1;
            aux->navio.pilha4.tam = aux->navio.pilha4.tam - 1;
            return 0;
        }
    }
    int cabem3 = 5 - pilha3->tam;
    if (cabem3 == 0) {
        retiraTravessas(pilha3, 3, fila);
        if(pilha1->status == 2){
            pilha1->status = pilha1->status - 1;
        } else{
            pilha1->status = 0;
        }
        fila->carro.instante = fila->carro.instante - 1;
    } else if (cabem3 > 0 && aux->navio.quantConteiners > 0) {
        NO2 *novo = malloc(sizeof(NO2));
        if (aux->navio.pilha1.tam > 0 && pilha3->status == 0) {
            NO2 *aux2 = pilha3->inicio->proximo;
            pilha3->inicio = novo;
            novo->proximo = aux2;
            pilha3->tam = pilha3->tam + 1;
            aux->navio.quantConteiners = aux->navio.quantConteiners - 1;
            aux->navio.pilha1.tam = aux->navio.pilha1.tam - 1;
            return 0;
        } else if (aux->navio.pilha2.tam > 0 && fila->carro.instante == 0) {
            NO2 *aux2 = pilha3->inicio->proximo;
            pilha3->inicio = novo;
            novo->proximo = aux2;
            pilha3->tam = pilha3->tam + 1;
            aux->navio.quantConteiners = aux->navio.quantConteiners - 1;
            aux->navio.pilha2.tam = aux->navio.pilha2.tam - 1;
            return 0;
        } else if (aux->navio.pilha3.tam > 0 && fila->carro.instante == 0) {
            NO2 *aux2 = pilha3->inicio->proximo;
            pilha3->inicio = novo;
            novo->proximo = aux2;
            pilha3->tam = pilha3->tam + 1;
            aux->navio.quantConteiners = aux->navio.quantConteiners - 1;
            aux->navio.pilha3.tam = aux->navio.pilha3.tam - 1;
            return 0;
        } else if (aux->navio.pilha4.tam > 0 && fila->carro.instante == 0) {
            NO2 *aux2 = pilha3->inicio->proximo;
            pilha3->inicio = novo;
            novo->proximo = aux2;
            pilha3->tam = pilha3->tam + 1;
            aux->navio.quantConteiners = aux->navio.quantConteiners - 1;
            aux->navio.pilha4.tam = aux->navio.pilha4.tam - 1;
            return 0;
        }
    }
    int cabem4 = 5 - pilha4->tam;
    if (cabem4 == 0) {
        retiraTravessas(pilha4, 4, fila);
        if(pilha1->status == 2){
            pilha1->status = pilha1->status - 1;
        } else{
            pilha1->status = 0;
        }
        fila->carro.instante = fila->carro.instante - 1;
    } else if (cabem4 > 0 && aux->navio.quantConteiners > 0) {
        NO2 *novo = malloc(sizeof(NO2));
        if (aux->navio.pilha1.tam > 0 && pilha2->status == 0) {
            NO2 *aux2 = pilha4->inicio->proximo;
            pilha4->inicio = novo;
            novo->proximo = aux2;
            pilha4->tam = pilha4->tam + 1;
            aux->navio.quantConteiners = aux->navio.quantConteiners - 1;
            aux->navio.pilha1.tam = aux->navio.pilha1.tam - 1;
            return 0;
        } else if (aux->navio.pilha2.tam > 0 && fila->carro.instante == 0) {
            NO2 *aux2 = pilha4->inicio->proximo;
            pilha4->inicio = novo;
            novo->proximo = aux2;
            pilha4->tam = pilha4->tam + 1;
            aux->navio.quantConteiners = aux->navio.quantConteiners - 1;
            aux->navio.pilha2.tam = aux->navio.pilha2.tam - 1;
            return 0;
        } else if (aux->navio.pilha3.tam > 0 && fila->carro.instante == 0) {
            NO2 *aux2 = pilha4->inicio->proximo;
            pilha4->inicio = novo;
            novo->proximo = aux2;
            pilha4->tam = pilha4->tam + 1;
            aux->navio.quantConteiners = aux->navio.quantConteiners - 1;
            aux->navio.pilha3.tam = aux->navio.pilha3.tam - 1;
            return 0;
        } else if (aux->navio.pilha4.tam > 0 && fila->carro.instante == 0) {
            NO2 *aux2 = pilha4->inicio->proximo;
            pilha4->inicio = novo;
            novo->proximo = aux2;
            pilha4->tam = pilha4->tam + 1;
            aux->navio.quantConteiners = aux->navio.quantConteiners - 1;
            aux->navio.pilha4.tam = aux->navio.pilha4.tam - 1;
            return 0;
        }
    }
    int cabem5 = 5 - pilha5->tam;
    if (cabem5 == 0) {
        retiraTravessas(pilha5, 5, fila);
        if(pilha1->status == 2){
            pilha1->status = pilha1->status - 1;
        } else{
            pilha1->status = 0;
        }
        fila->carro.instante = fila->carro.instante - 1;
    } else if (cabem5 > 0 && aux->navio.quantConteiners > 0) {
        NO2 *novo = malloc(sizeof(NO2));
        if (aux->navio.pilha1.tam > 0 && pilha2->status == 0) {
            NO2 *aux2 = pilha5->inicio->proximo;
            pilha5->inicio = novo;
            novo->proximo = aux2;
            pilha5->tam = pilha5->tam + 1;
            aux->navio.quantConteiners = aux->navio.quantConteiners - 1;
            aux->navio.pilha1.tam = aux->navio.pilha1.tam - 1;
            return 0;
        } else if (aux->navio.pilha2.tam > 0 && fila->carro.instante == 0) {
            NO2 *aux2 = pilha5->inicio->proximo;
            pilha5->inicio = novo;
            novo->proximo = aux2;
            pilha5->tam = pilha5->tam + 1;
            aux->navio.quantConteiners = aux->navio.quantConteiners - 1;
            aux->navio.pilha2.tam = aux->navio.pilha2.tam - 1;
            return 0;
        } else if (aux->navio.pilha3.tam > 0 && fila->carro.instante == 0) {
            NO2 *aux2 = pilha5->inicio->proximo;
            pilha5->inicio = novo;
            novo->proximo = aux2;
            pilha5->tam = pilha5->tam + 1;
            aux->navio.quantConteiners = aux->navio.quantConteiners - 1;
            aux->navio.pilha3.tam = aux->navio.pilha3.tam - 1;
            return 0;
        } else if (aux->navio.pilha4.tam > 0 && fila->carro.instante == 0) {
            NO2 *aux2 = pilha5->inicio->proximo;
            pilha5->inicio = novo;
            novo->proximo = aux2;
            pilha5->tam = pilha5->tam + 1;
            aux->navio.quantConteiners = aux->navio.quantConteiners - 1;
            aux->navio.pilha4.tam = aux->navio.pilha4.tam - 1;
            return 0;
        }
    }

    //Calcula o tempo que o navio ficou no atracadouro até ser descarregado;
    if (fila->id == 1 && aux->navio.quantConteiners == 0) {
        instantesf1 = instantesf1 + (unidadeTempo - aux->navio.unidTempo);
        media1 = instantesf1 / quant1;
        printf("Media de espera do atracadouro 1: %.2f\n", media1);
    }
    if (fila->id == 2 && aux->navio.quantConteiners == 0) {
        instantesf2 = instantesf2 + (unidadeTempo - aux->navio.unidTempo);
        media2 = instantesf2 / quant2;
        printf("Media de espera do atracadouro 2: %.2f\n", media2);
    }
    if (fila->id == 3 && aux->navio.quantConteiners == 0) {
        instantesf3 = instantesf3 + (unidadeTempo - aux->navio.unidTempo);
        media3 = instantesf3 / quant3;
        printf("Media de espera do atracadouro 3: %.2f\n", media3);
    }
    if (fila->id == 4 && aux->navio.quantConteiners == 0) {
        instantesf4 = instantesf4 + (unidadeTempo - aux->navio.unidTempo);
        media4 = instantesf4 / quant4;
        printf("Media de espera do atracadouro 4: %.2f\n", media4);
    }

    //Retira o navio atual após o descarregamento
    if(aux->navio.quantConteiners == 0){
        retiraNavio(fila);
    }
}

//Inserir navio no final da Fila do atracadouro
void insereNavio(Fila *fila, Navio *navio) {
    NO *aux = malloc(sizeof(NO));
    aux->navio = *navio;
    quantNaviosDentro = quantNaviosDentro + 1;

    if (fila->tam == 0) {
        fila->tam = fila->tam + 1;
        fila->inicio->proximo = aux;
        fila->fim = aux;
        fila->fim->proximo = NULL;
    } else {
        fila->tam = fila->tam + 1;
        fila->fim->proximo = aux;
        aux->proximo = NULL;
        fila->fim = aux;
    }
}

//Função de imprimir a Fila de navios atracados
void imprimeFila(Fila *fila) {
    NO *aux = fila->inicio->proximo;
    if (aux == NULL) {
        printf("\nFila do atracadouro %d esta vazia!\n", fila->id);
        return;
    }
    printf("\nFila de navios atual do atracadouro %d: \n", fila->id);
    while (aux != NULL) {
        printf("Navio: %d\n", aux->navio.id);
        printf("Unidade Tempo: %d\n", aux->navio.unidTempo);
        printf("Quantidade de conteiners: %d\n", aux->navio.quantConteiners);
        aux = aux->proximo;
    }
}

void preencheNavio(Navio *navio) {
    int random = 1 + rand() % 3;
    navio->quantConteiners = navio->quantConteiners + random;
    for (int i = 0; i < random; i++) {
        NO2 *aux = malloc(sizeof(NO2));
        navio->pilha1.tam = navio->pilha1.tam + 1;
        if (i == 0) {
            navio->pilha1.inicio->proximo = aux;
            aux->proximo = NULL;
        } else {
            NO2 *aux2 = navio->pilha1.inicio->proximo;
            navio->pilha1.inicio->proximo = aux;
            aux->proximo = aux2;
        }
    }
    random = 1 + rand() % 3;
    navio->quantConteiners = navio->quantConteiners + random;
    for (int i = 0; i < random; i++) {
        NO2 *aux = malloc(sizeof(NO2));
        navio->pilha2.tam = navio->pilha2.tam + 1;
        if (i == 0) {
            navio->pilha2.inicio->proximo = aux;
            aux->proximo = NULL;
        } else {
            NO2 *aux2 = navio->pilha2.inicio->proximo;
            navio->pilha2.inicio->proximo = aux;
            aux->proximo = aux2;
        }
    }
    random = 1 + rand() % 3;
    navio->quantConteiners = navio->quantConteiners + random;
    for (int i = 0; i < random; i++) {
        NO2 *aux = malloc(sizeof(NO2));
        navio->pilha3.tam = navio->pilha3.tam + 1;
        if (i == 0) {
            navio->pilha3.inicio->proximo = aux;
            aux->proximo = NULL;
        } else {
            NO2 *aux2 = navio->pilha3.inicio->proximo;
            navio->pilha3.inicio->proximo = aux;
            aux->proximo = aux2;
        }
    }
    random = 1 + rand() % 3;
    navio->quantConteiners = navio->quantConteiners + random;
    for (int i = 0; i < random; i++) {
        NO2 *aux = malloc(sizeof(NO2));
        navio->pilha4.tam = navio->pilha4.tam + 1;
        if (i == 0) {
            navio->pilha4.inicio->proximo = aux;
            aux->proximo = NULL;
        } else {
            NO2 *aux2 = navio->pilha4.inicio->proximo;
            navio->pilha4.inicio->proximo = aux;
            aux->proximo = aux2;
        }
    }
}

int main() {

    quantNavios = 0, instantesf1 = 0, instantesf2 = 0, instantesf3 = 0, instantesf4 = 0;
    quant1 = 0, quant2 = 0, quant3 = 0, quant4 = 0;
    int sair = 0;

    //Funções que iniciam as filas nas 4 áreas de atracamento
    Fila fila1;
    criaFilaVazia(&fila1, 1);
    Fila fila2;
    criaFilaVazia(&fila2, 2);
    Fila fila3;
    criaFilaVazia(&fila3, 3);
    Fila fila4;
    criaFilaVazia(&fila4, 4);

    //Área de descarregamento de 5x5 existem 5 pilhas com limite de 5 contêiners em cada
    //Funções que iniciam as pilhas da área de descarregamento

    //5 travessas do atracadouro 1
    Pilha pilha1Atrac1;
    criaPilhaVazia(&pilha1Atrac1, 11);
    Pilha pilha2Atrac1;
    criaPilhaVazia(&pilha2Atrac1, 21);
    Pilha pilha3Atrac1;
    criaPilhaVazia(&pilha3Atrac1, 31);
    Pilha pilha4Atrac1;
    criaPilhaVazia(&pilha4Atrac1, 41);
    Pilha pilha5Atrac1;
    criaPilhaVazia(&pilha5Atrac1, 51);
    //5 travessas do atracadouro 2
    Pilha pilha1Atrac2;
    criaPilhaVazia(&pilha1Atrac2, 12);
    Pilha pilha2Atrac2;
    criaPilhaVazia(&pilha2Atrac2, 22);
    Pilha pilha3Atrac2;
    criaPilhaVazia(&pilha3Atrac2, 32);
    Pilha pilha4Atrac2;
    criaPilhaVazia(&pilha4Atrac2, 42);
    Pilha pilha5Atrac2;
    criaPilhaVazia(&pilha5Atrac2, 52);
    //5 travessas do atracadouro 3
    Pilha pilha1Atrac3;
    criaPilhaVazia(&pilha1Atrac3, 13);
    Pilha pilha2Atrac3;
    criaPilhaVazia(&pilha2Atrac3, 23);
    Pilha pilha3Atrac3;
    criaPilhaVazia(&pilha3Atrac3, 33);
    Pilha pilha4Atrac3;
    criaPilhaVazia(&pilha4Atrac3, 43);
    Pilha pilha5Atrac3;
    criaPilhaVazia(&pilha5Atrac3, 53);
    //5 travessas do atracadouro 4
    Pilha pilha1Atrac4;
    criaPilhaVazia(&pilha1Atrac4, 14);
    Pilha pilha2Atrac4;
    criaPilhaVazia(&pilha2Atrac4, 24);
    Pilha pilha3Atrac4;
    criaPilhaVazia(&pilha3Atrac4, 34);
    Pilha pilha4Atrac4;
    criaPilhaVazia(&pilha4Atrac4, 44);
    Pilha pilha5Atrac4;
    criaPilhaVazia(&pilha5Atrac4, 54);

    Navio navio;
    criaPilhaVazia(&navio.pilha1, 1);
    criaPilhaVazia(&navio.pilha2, 2);
    criaPilhaVazia(&navio.pilha3, 3);
    criaPilhaVazia(&navio.pilha4, 4);

    do {
        int quantChega = rand() % 4;
        for (int i = 0; i < quantChega; i++) {
            //Função que cria um navio e preenche com uma quantidade aleatória de conteiners em cada pilha;
            quantNavios = quantNavios + 1;
            navio.id = quantNavios;
            navio.unidTempo = unidadeTempo;
            navio.quantConteiners = 0;
            preencheNavio(&navio);

            int random = 1 + (rand() % 4);
            switch (random) {
                case 1:
                    printf("Chegou no atracadouro 1!\n");
                    insereNavio(&fila1, &navio);
                    quant1++;
                    imprimeFila(&fila1);
                    break;
                case 2:
                    printf("Chegou no atracadouro 2!\n");
                    insereNavio(&fila2, &navio);
                    quant2++;
                    imprimeFila(&fila2);
                    break;
                case 3:
                    printf("Chegou no atracadouro 3!\n");
                    insereNavio(&fila3, &navio);
                    quant3++;
                    imprimeFila(&fila3);
                    break;
                case 4:
                    printf("Chegou no atracadouro 4!\n");
                    insereNavio(&fila4, &navio);
                    quant4++;
                    imprimeFila(&fila4);
                    break;
                default:
                    printf("Fila inexistente!\n");
                    break;
            }
        }

        retiraConteinerNavio(&fila1, &pilha1Atrac1, &pilha2Atrac1, &pilha3Atrac1, &pilha4Atrac1, &pilha5Atrac1);
        printf("Status travessas do Atracadouro 1:\n");
        printf("%d \t", pilha1Atrac1.tam);
        printf("%d \t", pilha2Atrac1.tam);
        printf("%d \t", pilha3Atrac1.tam);
        printf("%d \t", pilha4Atrac1.tam);
        printf("%d \n", pilha5Atrac1.tam);
        if (fila1.tam == 0) {
            imprimeFila(&fila1);
        }

        retiraConteinerNavio(&fila2, &pilha1Atrac2, &pilha2Atrac2, &pilha3Atrac2, &pilha4Atrac2, &pilha5Atrac2);
        printf("Status travessas do Atracadouro 2:\n");
        printf("%d \t", pilha1Atrac2.tam);
        printf("%d \t", pilha2Atrac2.tam);
        printf("%d \t", pilha3Atrac2.tam);
        printf("%d \t", pilha4Atrac2.tam);
        printf("%d \n", pilha5Atrac2.tam);
        if (fila2.tam == 0) {
            imprimeFila(&fila2);
        }

        retiraConteinerNavio(&fila3, &pilha1Atrac3, &pilha2Atrac3, &pilha3Atrac3, &pilha4Atrac3, &pilha5Atrac3);
        printf("Status travessas do Atracadouro 3:\n");
        printf("%d \t", pilha1Atrac3.tam);
        printf("%d \t", pilha2Atrac3.tam);
        printf("%d \t", pilha3Atrac3.tam);
        printf("%d \t", pilha4Atrac3.tam);
        printf("%d \n", pilha5Atrac3.tam);
        if (fila3.tam == 0) {
            imprimeFila(&fila3);
        }

        retiraConteinerNavio(&fila4, &pilha1Atrac4, &pilha2Atrac4, &pilha3Atrac4, &pilha4Atrac4, &pilha5Atrac4);
        printf("Status travessas do Atracadouro 4:\n");
        printf("%d \t", pilha1Atrac4.tam);
        printf("%d \t", pilha2Atrac4.tam);
        printf("%d \t", pilha3Atrac4.tam);
        printf("%d \t", pilha4Atrac4.tam);
        printf("%d \n", pilha5Atrac4.tam);
        if (fila4.tam == 0) {
            imprimeFila(&fila4);
        }

        printf("Digite 1 para sair: ");
        scanf("%d", &sair);
        unidadeTempo++;
    } while (sair != 1);

    printf("Travessa transportadas: %d\n", transpTravessa);

    return 0;
}