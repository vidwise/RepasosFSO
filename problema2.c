#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <pthread.h>
#include "semafor.h"
#define N 10

int escrits;
int * mat;
pthread_t tid[N];
pthread_sem sincro;
int n;

void fill(int tid)
{
    boolean filled = false;
    boolean isNotZero = true;
    int i = rand() % n, j = rand() % n;
    int num_escrits = 0;

    while (! filled)
    {
        wait(sincro);
        i = rand() % n;
        j = rand() % n;

        if (mat[i][j] == 0)
        {
            mat[i][j] = rand() + 1;
            num_escrits++;
        }

        // cada thread mira si la matriz esta llena ya
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                isNotZero = isNotZero && mat[j][k] != 0;
            }
        }
        if (isNotZero)
        {
            signal(sincro);
            return(num_escrits);
        }

        signal(sincro);

    }
}


int main(int n_args, char * ll_args[])
{
    int n = atoi(ll_args[1]);

    mat = malloc(n * n * sizeof(int));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) mat[i][j] = 0;


    sincro = ini_sem(1);

    for (int i = 0; i < n; i++)
    {
        if (pthread_create(&tid[i], NULL, & fill, i) != 0)
        {
            // Eliminar estructuras memoria / sicnronismo
            // matar threads (p_kill)
            exit(1);
        }
    }

    int * ret;
    for (int i = 0; i < n; i++)
    {
        pthread_join(tid[i], (void *) ret);
        printf("El proces %d ha escrit %d dades", tid[i],  *ret);
    }


    // thread principal

    elim_sem(sincro);




}


























int escrits;
int mat[N][N];
pthread_t tid[N];
int sincro;
int nn;
void surt_amb_error(int p)
{
//
}
void *genera(void* i_thr)
{
    [4] unsigned int id = (intptr_t) i_thr;
    unsigned int s = id;
    long alea;
    int jo_escrits=0;
    int i,j;
    [2] waitS(sincro);
    [7] while(escrits != nn*nn){
        alea = rand_r(&s);
        if (alea) {
            j = alea %nn;
            i = (alea / nn)%nn;
            printf("%d: provo %d,%d; hi ha %d\n",id,i,j,mat[i][j]);
            [5] if ( !mat[i][j]) {
                mat[i][j] = alea;
                [6] escrits ++ ;
                [6] jo_escrits ++;
            }
        }
        [2] signalS(sincro);
//sleep(1);
        [2] waitS(sincro);
    }
    printf("%d: surto i he escrit %d\n",id,jo_escrits);
    [2] signalS(sincro);
    [9] return((void *) (intptr_t) jo_escrits); /* retorna numero lletres
escrites pel fil */
}
int main(int n_args, char * ll_args[])
{
    int i,j,p;
    int a;
    [4]
    assert(n_args == 2);
    nn=atoi(ll_args[1]);
    assert(nn>=3 && nn<=10);
    [4] for (i=0; i < nn; i++)
        for (j=0; j < nn; j++) mat[i][j]=0;
    escrits = 0;
    [1] sincro = ini_sem(1);
    assert(sincro);
    p = 0;
    for (i=0; i<nn; i++) {
        [3] if (pthread_create(&tid[p],NULL,genera,(void *) (intptr_t)i) == 0) p++;
        [3] else surt_amb_error(p);
    }
    printf("main: s'han creat %d processos\n",p);
    for (i=0; i<p; i++) {
        [8][9] pthread_join(tid[i], (void **)&a);
        [10] printf("%d: ha escrit %d dades\n",i,a);
    }
    [11] elim_sem(sincro);
    [12] return(0);