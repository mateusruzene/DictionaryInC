#include <stdio.h>
#include <stdlib.h>

#define TAM_PLACA 8
#define MAX_CHAR 31
#define TAM_DICT 100

struct carro{
    char modelo[MAX_CHAR];
    unsigned short int ano;
    char placa[TAM_PLACA];
};

struct dicionario_carro{
    struct carro *carros[TAM_DICT];
    unsigned long numItens;
};

void criaCarro(struct dicionario_carro *dict){
    dict->numItens = 0;
}

void inicializar(struct dicionario_carro *dict){
    dict->numItens = 0;
}

struct carro *buscar(char *chave, struct dicionario_carro *dict){

    for (int i = 0; i < dict->numItens; i++){
        int isEqual = strcmp(chave, dict->carros[i]->placa);
        if (isEqual == 0)
            return dict->carros[i];
    }

    return NULL;
}

int inserir(struct carro *carro, struct dicionario_carro *dict){

    dict->carros[dict->numItens] = carro;
    dict->numItens += 1;

    return 0;
}

struct carro *remover(char *chave, struct dicionario_carro *dict){
    struct carro * carroRemovido;

    for (int i = 0; i < dict->numItens; i++){
        int isEqual = strcmp(chave, dict->carros[i]->placa);
        if (isEqual == 0){
            carroRemovido = dict->carros[i];
            free(dict->carros[i]);
            dict->carros[i] = dict->carros[dict->numItens];
            dict->numItens -= 1;
            return carroRemovido;
        }
    }

    return NULL;
}

void imprime(struct carro *carro){
    printf ("Placa: %s\n Modelo: %s \n Ano: %d", carro->placa, carro->modelo, carro->ano);
    printf("\n");
}

int main(){
    struct dicionario_carro *dict;
    struct carro *carro1;
    struct carro *carro2;
    struct carro *carro3;
    struct carro *carro4;
    struct carro *busca;
    struct carro *removido;
    
    inicializar(dict);

    inserir(carro1, dict);
    inserir(carro2, dict);
    inserir(carro3, dict);
    inserir(carro4, dict);

    busca = buscar("AAA1111", dict);
    printf("BUSCA");
    imprime(busca);

    busca = buscar("BBB2222", dict);
    printf("BUSCA");
    imprime(busca);

    removido = remover("CCC3333", dict);
    printf("REMOVIDO");
    imprime(removido);


    return 0;
}