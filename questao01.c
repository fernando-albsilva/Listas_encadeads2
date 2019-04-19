#include <stdio.h>
#include <stdlib.h>

struct lista
{
    float info;
    struct lista *prox;
};
typedef struct lista Lista;

void tamanho_remove(int*);
Lista *preenche_lista();
void busca(Lista *);
Lista * retira(Lista*,int);
void imprime_lista(Lista *);
int main()
{
    int n;
    

    Lista *l;

    l = NULL;
    tamanho_remove(&n);
    l = preenche_lista();
    imprime_lista(l);
    l=retira(l,n);
    imprime_lista(l);
    busca(l);
        return 0;
}

void tamanho_remove(int *p_n)
{
    printf("\n Digite quantos elementos deseja remover da lista:\n");
    scanf("%d",&*p_n);
}

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
    int cont=1;
    if (l == NULL)
    {
        printf("\n Lista vazia\n");
    }
    else
    {
        printf("\n------------INICIO-------------------\n");
        for (;;)
        {
            printf("\nno = %d elemento info = %.0f\n",cont, l->info);
            cont++;
            if (l->prox == NULL)
            {
                break;
            }
            l = l->prox;
        }

        printf("\n---------------FIM-------------------\n");
    }
}

Lista * retira(Lista* l,int n)
{
    Lista * aux;
    int cont=1;

    
    while( l->prox != NULL && cont<= n)
    {
        aux=l->prox;
        free(l);
        l=aux;      
        cont++;
    }
    return l;
}

void busca(Lista *l)
{
    float busca;
    int cont=0,teste=0;
    printf("\n Digite o dado a ser buscado na lista \n");
    scanf("%f",&busca);

    while (l->prox != NULL)
    {
        cont ++;
        if (l->info == busca)
        {
            printf("\n o valor buscado esta no no : %d \n",cont);
            teste=1;
            break;
            
        }
        l=l->prox;

    }
    if (teste == 0)
    {
        printf(" \nvalor  nao se encontra na lista\n");
    }
    
}