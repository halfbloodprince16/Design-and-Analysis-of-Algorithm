#include <stdio.h>
#include<stdlib.h>
void minmax (int* a, int i, int j, int* min, int* max) 
{
    int lmin, lmax, rmin, rmax, mid;
    if (i == j) 
    {
        *min = a[i];
        *max = a[j];
    } 
    else if (j == i + 1) 
    {
        if (a[i] > a[j]) 
        {
            *min = a[j];
            *max = a[i];
        } 
        else 
        {
            *min = a[i];
            *max = a[j];
        }
    } 
    else 
    {
        mid = (i + j) / 2;
        minmax(a, i, mid, &lmin, &lmax);
        minmax(a, mid + 1, j, &rmin, &rmax);
        *min = (lmin > rmin) ? rmin : lmin;
        *max = (lmax > rmax) ? lmax : rmax;
    }
}

int main () 
{
    int n,i;
    scanf("%d",&n);
    int *a;
    a = (int *)malloc(n*sizeof(int));

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    int min, max;
    minmax (a, 0, n-1, &min, &max);

    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

    printf("\n");
    printf ("Min : %d, Max: %d\n", min, max);

    free(a);

    return 0;
}