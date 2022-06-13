#import <stdio.h>
#import <stdlib.h>
#import <assert.h>

int pid[2 * n + 1];
typedef struct
{
    int id;
    int valor;
    int num;
} retorn;

int fill_column(int id, int *own_matrix)
{
    int i = 0;
    int pos = id % n;
    int num = 0;

    while (! own_matrix[i][pos] && i < n)
    {
        wait(sem);
        // esta parte esta protegida
        own_matrix[i][pos] = id;
        signal(sem);
        i++;
        num++;
    }

    ret[id].valor = id;
    ret[id].id = id;
    ret[id].num = num;

    exit(0);
}


int fill_rows(int id, int *own_matrix)
{
    int pos = id % n;
    wait(sem);
    // esta parte esta protegida

    int i = 0;
    int pos = id % n;

    int num = 0;
    while (! own_matrix[pos][i] && i < n)
    {
        wait(sem);
        // esta parte esta protegida
        own_matrix[pos][i] = id;
        signal(sem);
        i++;
        num++;
    }

    ret[id].valor = id;
    ret[id].id = id;
    ret[id].num = num;

    exit(0);
}


int main(int num_args, char[] *args)
{
    int useless;
    int own_pid;
    int *own_matrix;
    // Parse args
    int n = atoi(args[1]);
    assert(n <= 10 && n >= 3);

    // Iniciamos mem para retorno
    int *ret = ini_mem(sizeof(retorn) * 2 * n);

    // Initi semafor
    Semaforo sem = ini_sem(1);

    // Create shared memory zone
    int *matrix = ini_mem(sizeof(int) * n * n);

    // Init matrix with 0
    for (int i = 0; i < n * n; i++)
    {
      matrix[i] = 0;
    }

    // Process spawn
    int p = 0;
    for (int i = 0; i < 2 * n; i++)
    {
          own_pid = fork();
          // Error
          if (own_pid < 0)
          {
                for (int j = 0; j < 2 * n; j++)
                {
                      kill(pid[k]);
                      elim_mem(matrix);
                      exit(1);
                }
          }
          else if (own_pid == 0)
          {
              own_matrix = map_mem(matrix);
              own_ret = map_mem(ret);
              if (i < n)
              {
                  fill_column(p, own_matrix);
              }
              else
              {
                  fill_rows(p, own_matrix);
              }
          }
          else if (own_pid > 0)
          {
              pid[i] = own_pid;
              for (int j = 0; j < n * 2; j++)
              {
                if (waitpid(pid[j], &useless, NULL) != 0)
                {
                    exit(1);
                }
                printf("El proces %d ha escrit el numero %d %d cops", ret[j].id, ret[j].val, ret[j].num);
              }
              elim_mem(ret);
              elim_mem(pid);
              elim_mem(mat);
              elim_sem(sem);
              exit(1);
          }
    }

    //










}