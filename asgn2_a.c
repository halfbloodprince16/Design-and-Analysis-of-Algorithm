#include"stdio.h"
#include"stdlib.h"

void merge(int x[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
  
    int L[n1], R[n2]; 
  
  
    for (i = 0; i < n1; i++) 
        L[i] = x[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = x[m + 1+ j]; 
  
   
    i = 0;
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            x[k] = L[i]; 
            i++; 
        } 
        else
        { 
            x[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        x[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        x[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void mergeSort(int x[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
        mergeSort(x, l, m); 
        mergeSort(x, m+1, r); 

        merge(x, l, m, r); 
    } 
}

struct jobs
{
    int id;
    int size;
    char name[20];
    double rt;
};

void mrt(int x[],int n,int t)
{
	

	return;
}

int main(int argc, char const *argv[])
{
	int n,i,j,k,t;
	printf("Enter No. of Tapes:");
	scanf("%d",&t);

    printf("Enter No. of Programs:");
    scanf("%d",&n);
    struct jobs *j;

    j = (jobs *)malloc(n*sizeof(jobs));

    for(i=0;i<n;i++)
    {
        j[i].id = i+1;
        printf("Enter Job Name:");
        scanf("%[^\n]%*c", j[i].name);
        printf("\nEnter Job Size:"); 
        scanf("%d",&j[i].size);
    }

    for(i=0;i<n;i++)
    {
        printf("%d "j[i].id);
        printf("%s ",j[i].name);
        printf("%d ",j[i].size);
        printf("\n");
    }
    //mrt(x,n,t);
	return 0;
}