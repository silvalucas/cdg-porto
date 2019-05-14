#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int unidadeTempo;
int maxNavio = 300;
int transpTravessa;
int quantNavios;
int quantNaviosDentro;
int instante1;
int instante2;
float mediaEspera;

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
    NO2 *inicio;
} Pilha;

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
    int tam;
    NO *inicio;
    NO *fim;
} Fila;

// ############# FUNÇÕES ##################

//Criação de pilha com cabeça
void criaPilhaVazia(Pilha *pilha) {
    pilha->inicio = malloc(sizeof(NO2));
    pilha->tam = 0;
    pilha->inicio->proximo = NULL;
}

//Criação de fila com cabeça
void criaFilaVazia(Fila *fila) {
    fila->inicio = malloc(sizeof(NO));
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
        unidadeTempo++;
    } else {
        NO *aux = fila->inicio->proximo;
        NO *aux2 = aux->proximo;
        fila->inicio->proximo = aux2;
        fila->tam = fila->tam - 1;
        unidadeTempo++;
        free(aux);
    }
    quantNaviosDentro = quantNaviosDentro - 1;
}

//Veículo retira travessas para armazem após atingirem o limite máximo;
int retiraTravessas(Pilha *pilha1, Pilha *pilha2, Pilha *pilha3, Pilha *pilha4, Pilha *pilha5) {
    if (pilha1->tam == 5) {
        NO2 *aux = pilha1->inicio;
        pilha1->inicio->proximo = NULL;
        pilha1->inicio = aux;
        pilha1->tam = 0;
        unidadeTempo++;
        unidadeTempo++;
        transpTravessa = transpTravessa + 1;
        printf("Travessa 1 transportada para o armazem!\n");
    }
    if (pilha2->tam == 5) {
        NO2 *aux = pilha2->inicio;
        pilha2->inicio->proximo = NULL;
        pilha2->inicio = aux;
        pilha2->tam = 0;
        unidadeTempo++;
        unidadeTempo++;
        transpTravessa = transpTravessa + 1;
        printf("Travessa 2 transportada para o armazem!\n");
    }
    if (pilha3->tam == 5) {
        NO2 *aux = pilha3->inicio;
        pilha3->inicio->proximo = NULL;
        pilha3->inicio = aux;
        pilha3->tam = 0;
        unidadeTempo++;
        unidadeTempo++;
        transpTravessa = transpTravessa + 1;
        printf("Travessa 3 transportada para o armazem!\n");
    }
    if (pilha4->tam == 5) {
        NO2 *aux = pilha4->inicio;
        pilha4->inicio->proximo = NULL;
        pilha4->inicio = aux;
        pilha4->tam = 0;
        unidadeTempo++;
        unidadeTempo++;
        transpTravessa = transpTravessa + 1;
        printf("Travessa 4 transportada para o armazem!\n");
    }
    if (pilha5->tam == 5) {
        NO2 *aux = pilha5->inicio;
        pilha5->inicio->proximo = NULL;
        pilha5->inicio = aux;
        pilha5->tam = 0;
        unidadeTempo++;
        unidadeTempo++;
        transpTravessa = transpTravessa + 1;
        printf("Travessa 5 transportada para o armazem!\n");
    }
}

//Retira 1 a 1 os conteiners do navio
int retiraConteinerNavio(Fila *fila, Pilha *pilha1, Pilha *pilha2, Pilha *pilha3, Pilha *pilha4, Pilha *pilha5) {
    NO *aux = fila->inicio->proximo;

    if (fila->tam == 0) {
        printf("Fila do atracadouro abaixo esta vazia!");
        return 0;
    }

    //Verifica se o navio atual não possui conteiners a serem descarregados.
    if (aux->navio.quantConteiners == 0) {
        retiraNavio(fila);
        return 0;
    }

    printf("Descarregando...\n");

    while (aux->navio.quantConteiners > 0) {
        int cabem1 = 5 - pilha1->tam;
        if (cabem1 > 0 && aux->navio.quantConteiners > 0) {
            NO2 *novo = malloc(sizeof(NO2));
            pilha1->inicio->proximo = novo;
            NO2 *aux2 = pilha1->inicio->proximo;
            novo->proximo = aux2;
            pilha1->tam = pilha1->tam + 1;
            aux->navio.quantConteiners = aux->navio.quantConteiners - 1;
            unidadeTempo++;
        }
        int cabem2 = 5 - pilha2->tam;
        if (cabem2 > 0 && aux->navio.quantConteiners > 0) {
            NO2 *novo = malloc(sizeof(NO2));
            pilha2->inicio->proximo = novo;
            NO2 *aux2 = pilha2->inicio->proximo;
            novo->proximo = aux2;
            pilha2->tam = pilha2->tam + 1;
            aux->navio.quantConteiners = aux->navio.quantConteiners - 1;
            unidadeTempo++;
        }
        int cabem3 = 5 - pilha3->tam;
        if (cabem3 > 0 && aux->navio.quantConteiners > 0) {
            NO2 *novo = malloc(sizeof(NO2));
            pilha3->inicio->proximo = novo;
            NO2 *aux2 = pilha3->inicio->proximo;
            novo->proximo = aux2;
            pilha3->tam = pilha3->tam + 1;
            aux->navio.quantConteiners = aux->navio.quantConteiners - 1;
            unidadeTempo++;
        }
        int cabem4 = 5 - pilha4->tam;
        if (cabem4 > 0 && aux->navio.quantConteiners > 0) {
            NO2 *novo = malloc(sizeof(NO2));
            pilha4->inicio->proximo = novo;
            NO2 *aux2 = pilha4->inicio->proximo;
            novo->proximo = aux2;
            pilha4->tam = pilha4->tam + 1;
            aux->navio.quantConteiners = aux->navio.quantConteiners - 1;
            unidadeTempo++;
        }
        int cabem5 = 5 - pilha5->tam;
        if (cabem5 > 0 && aux->navio.quantConteiners > 0) {
            NO2 *novo = malloc(sizeof(NO2));
            pilha5->inicio->proximo = novo;
            NO2 *aux2 = pilha5->inicio->proximo;
            novo->proximo = aux2;
            pilha5->tam = pilha5->tam + 1;
            aux->navio.quantConteiners = aux->navio.quantConteiners - 1;
            unidadeTempo++;
        }

        int lotado = 0;
        lotado = pilha1->tam + pilha2->tam + pilha3->tam + pilha4->tam + pilha5->tam;
        if (lotado == 25) {
            retiraTravessas(pilha1, pilha2, pilha3, pilha4, pilha5);
        }
    }
    //Retira o navio atual após o descarregamento
    if (aux->navio.quantConteiners == 0) {
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
    if(aux == NULL){
        printf("Fila acima vazia!\n");
        return;
    }
    printf("Fila de navios atual: \n");
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

    quantNavios = 0, instante1 = 0, instante2 = 0;

    //Funções que iniciam as filas nas 4 áreas de atracamento
    Fila fila1;
    criaFilaVazia(&fila1);
    Fila fila2;
    criaFilaVazia(&fila2);
    Fila fila3;
    criaFilaVazia(&fila3);
    Fila fila4;
    criaFilaVazia(&fila4);

    //Área de descarregamento de 5x5 existem 5 pilhas com limite de 5 contêiners em cada
    //Funções que iniciam as pilhas da área de descarregamento

    //5 travessas do atracadouro 1
    Pilha pilha1Atrac1;
    criaPilhaVazia(&pilha1Atrac1);
    Pilha pilha2Atrac1;
    criaPilhaVazia(&pilha2Atrac1);
    Pilha pilha3Atrac1;
    criaPilhaVazia(&pilha3Atrac1);
    Pilha pilha4Atrac1;
    criaPilhaVazia(&pilha4Atrac1);
    Pilha pilha5Atrac1;
    criaPilhaVazia(&pilha5Atrac1);
    //5 travessas do atracadouro 2
    Pilha pilha1Atrac2;
    criaPilhaVazia(&pilha1Atrac2);
    Pilha pilha2Atrac2;
    criaPilhaVazia(&pilha2Atrac2);
    Pilha pilha3Atrac2;
    criaPilhaVazia(&pilha3Atrac2);
    Pilha pilha4Atrac2;
    criaPilhaVazia(&pilha4Atrac2);
    Pilha pilha5Atrac2;
    criaPilhaVazia(&pilha5Atrac2);
    //5 travessas do atracadouro 3
    Pilha pilha1Atrac3;
    criaPilhaVazia(&pilha1Atrac3);
    Pilha pilha2Atrac3;
    criaPilhaVazia(&pilha2Atrac3);
    Pilha pilha3Atrac3;
    criaPilhaVazia(&pilha3Atrac3);
    Pilha pilha4Atrac3;
    criaPilhaVazia(&pilha4Atrac3);
    Pilha pilha5Atrac3;
    criaPilhaVazia(&pilha5Atrac3);
    //5 travessas do atracadouro 4
    Pilha pilha1Atrac4;
    criaPilhaVazia(&pilha1Atrac4);
    Pilha pilha2Atrac4;
    criaPilhaVazia(&pilha2Atrac4);
    Pilha pilha3Atrac4;
    criaPilhaVazia(&pilha3Atrac4);
    Pilha pilha4Atrac4;
    criaPilhaVazia(&pilha4Atrac4);
    Pilha pilha5Atrac4;
    criaPilhaVazia(&pilha5Atrac4);

    Navio navio;
    criaPilhaVazia(&navio.pilha1);
    criaPilhaVazia(&navio.pilha2);
    criaPilhaVazia(&navio.pilha3);
    criaPilhaVazia(&navio.pilha4);

    do {
            int quantChega = rand() % 4;
            for (int i = 0; i < quantChega; i++) {
                //Função que cria um navio e preenche com uma quantidade aleatória de conteiners em cada pilha;
                quantNavios = quantNavios + 1;
                navio.id = quantNavios;
                navio.unidTempo = unidadeTempo;
                navio.quantConteiners = 0;
                preencheNavio(&navio);


            int random = 1 + (rand() % 3);
            switch (random) {
                case 1:
                    printf("Chegou no atracadouro 1!\n");
                    insereNavio(&fila1, &navio);
                    imprimeFila(&fila1);
                    break;
                case 2:
                    printf("Chegou no atracadouro 2!\n");
                    insereNavio(&fila2, &navio);
                    imprimeFila(&fila2);
                    break;
                case 3:
                    printf("Chegou no atracadouro 3!\n");
                    insereNavio(&fila3, &navio);
                    imprimeFila(&fila3);
                    break;
                case 4:
                    printf("Chegou no atracadouro 4!\n");
                    insereNavio(&fila4, &navio);
                    imprimeFila(&fila4);
                    break;
                default:
                    printf("Fila inexistente!\n");
                    break;
            }
        }


        retiraConteinerNavio(&fila1, &pilha1Atrac1, &pilha2Atrac1, &pilha3Atrac1, &pilha4Atrac1, &pilha5Atrac1);
        printf("\nStatus travessas do Atracadouro 1:\n");
        printf("%d \t", pilha1Atrac1.tam);
        printf("%d \t", pilha2Atrac1.tam);
        printf("%d \t", pilha3Atrac1.tam);
        printf("%d \t", pilha4Atrac1.tam);
        printf("%d \t\n\n", pilha5Atrac1.tam);
        if (fila1.tam == 0) {
            imprimeFila(&fila1);
        }

        retiraConteinerNavio(&fila2, &pilha1Atrac2, &pilha2Atrac2, &pilha3Atrac2, &pilha4Atrac2, &pilha5Atrac2);
        printf("\nStatus travessas do Atracadouro 2:\n");
        printf("%d \t", pilha1Atrac2.tam);
        printf("%d \t", pilha2Atrac2.tam);
        printf("%d \t", pilha3Atrac2.tam);
        printf("%d \t", pilha4Atrac2.tam);
        printf("%d \t\n\n", pilha5Atrac2.tam);
        if (fila2.tam == 0) {
            imprimeFila(&fila2);
        }

        retiraConteinerNavio(&fila3, &pilha1Atrac3, &pilha2Atrac3, &pilha3Atrac3, &pilha4Atrac3, &pilha5Atrac3);
        printf("\nStatus travessas do Atracadouro 3:\n");
        printf("%d \t", pilha1Atrac3.tam);
        printf("%d \t", pilha2Atrac3.tam);
        printf("%d \t", pilha3Atrac3.tam);
        printf("%d \t", pilha4Atrac3.tam);
        printf("%d \t\n\n", pilha5Atrac3.tam);
        if (fila3.tam == 0) {
            imprimeFila(&fila3);
        }

        retiraConteinerNavio(&fila4, &pilha1Atrac4, &pilha2Atrac4, &pilha3Atrac4, &pilha4Atrac4, &pilha5Atrac4);
        printf("\nStatus travessas do Atracadouro 4:\n");
        printf("%d \t", pilha1Atrac4.tam);
        printf("%d \t", pilha2Atrac4.tam);
        printf("%d \t", pilha3Atrac4.tam);
        printf("%d \t", pilha4Atrac4.tam);
        printf("%d \t\n\n", pilha5Atrac4.tam);
        if (fila4.tam == 0) {
            imprimeFila(&fila4);
        }
    } while (quantNavios < maxNavio);


    printf("Contador: %d\n", unidadeTempo);
    printf("Travessa transportadas: %d", transpTravessa);

    return 0;
}