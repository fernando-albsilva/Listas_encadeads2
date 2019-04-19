#include <stdio.h>
#include <stdlib.h>

struct lista
{
    float info;
    struct lista *prox;
};
typedef struct lista Lista;

//void tamanho_remove(int*);
Lista *preenche_lista();

//Lista * retira(Lista*,int);
void imprime_lista(Lista *);
int main()
{
    int n;

    Lista *l;

    l = NULL;
    //tamanho_remove(&n);
    l = preenche_lista();
    imprime_lista(l);
    printf("ok");
    return 0;
}

// void tamanho_remove(int *p_n)
// {
//     printf("\n Digite quantos elementos deseja remover da lista:\n");
//     scanf("%d",&*p_n);

// }

Lista * preenche_lista()
{
    int cont = 1;
    Lista * l;
    Lista *inicio;
    
    Lista *aux;
    l= (Lista *)malloc(sizeof(Lista));
    inicio=l;
    

    l->info = (float)cont;
    l->prox = NULL;
    
    cont++;
    while (cont <= 10)
    {
        aux = (Lista *)malloc(sizeof(Lista));

        aux->info = (float)cont;
        l->prox = aux;
        l = l->prox;


        cont++;
    }
    
    return inicio;
}

void imprime_lista(Lista *l)
{

    if (l == NULL)
    {
        printf("\n Lista vazia\n");
    }
    else
    {
        printf("\n------------INICIO-------------------\n");
        for (;;)
        {
            printf("\nelemento info = %.0f\n", l->info);
            if (l->prox == NULL)
            {
                break;
            }
            l = l->prox;
        }

        printf("\n---------------FIM-------------------\n");
    }
}
