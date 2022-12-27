/*#include <stdio.h>
#include <stdlib.h>
int* input(int* num)
{
    int i,n;
    printf("Input number of elements: ");
    scanf("%d",&n);
    int * a = malloc(n*sizeof(int));
    for(i = 0; i < n; i++)
    {
        printf("a[%d] = ",i);
        scanf("%d", &a[i]);
    }
    *num = n;
    return a;
}

void output(int *a, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("a[%d] = %d\n",i, a[i]);
    }
}
void process(int** a, int* n) {
    if ((*n)!=0){
        for(int i=0;i<(*n);i++){
            if ((*a)[i] < 0){
                (*n) -=1;
                for (int k=i; k<(*n);k++){
                    (*a)[k] = (*a)[k+1];
                }
            }
            if ((*a)[i] > 0){
                (*n)++;
                for (int k=i; k<(*n*2-1);k++){
                    (*a)[k+1] = (*a)[k];
                }

            }
            (*a)=realloc(*a,(*n)*sizeof(int));
            i--;
            }

        }
}


int main() {
    int n;
    int * a = input(&n);
    printf("Printed mass: ");
    process(&a,&n);
    output(a,n);
    free(a);
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
int* input(int* num)
{
    int i,n;
    printf("Input number of elements: ");
    scanf("%d",&n);
    int * a = malloc(n*sizeof(int));
    for(i = 0; i < n; i++)
    {
        printf("a[%d] = ",i);
        scanf("%d", &a[i]);
    }
    *num = n;
    return a;
}

void output(int *a, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("a[%d] = %d\n",i, a[i]);
    }
}
void process(int** a, int* n) {
    if ((*n)!=0){
        for(int i=0;i<(*n);i++){
            if ((*a)[i] >0){
                (*n) =(*n)+1;
                for (int k=i; k<(*n);k++){
                    (*a)[k] = (*a)[k-1];
                }
                (*a)=realloc(*a,(*n)*sizeof(int));
                i++;
            }

        }
    }
}

int main() {
    int n;
    int * a = input(&n);
    printf("Printed mass: ");
    process(&a,&n);
    output(a,n);
    free(a);
    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>
#include "process.h"
int* input(int* num)
{
    int i,n;
    printf("Input number of elements: ");
    scanf("%d",&n);
    int * a = malloc(n*sizeof(int));
    for(i = 0; i < n; i++)
    {
        printf("a[%d] = ",i);
        scanf("%d", &a[i]);
    }
    *num = n;
    return a;
}

void output(int *a, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("a[%d] = %d\n",i, a[i]);
    }
}
void process(int **array, int *size) {
    int col = *size;
    if (col != 0) {
        for (int i = 0; i < col; i++) {
            if ((*array)[i] < 0) {
                col--;
                for (int k = i; k < col; k++) {
                    (*array)[k] = (*array)[k + 1];
                }
                (*array) = realloc(*array, (col) * sizeof(int));
                i--;
            }
            if ((*array)[i] > 0){
                col ++;
                for (int k = col-1; k > i+1; k--){
                    (*array)[k] = (*array)[k - 1];
                }
                (*array) = realloc(*array, (col) * sizeof(int));
                (*array)[i+1] = (*array)[i];
                i++;
            }
        }
    }
    *size = col;
}

int main() {
    int size;
    int flag = 0;
    int *array = input(&size);
    //printf("Printed number func: ");
    printf("Printed mass: \n");
    process(&array, &size);
    output(array, size);
    free(array);
    return 0;
}