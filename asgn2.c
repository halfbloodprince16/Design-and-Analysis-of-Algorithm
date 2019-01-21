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

void mrt(int x[],int n,int t)
{
	mergeSort(x,0,n-1);

	printf("Optimal order in which programs are to be stored is:");

	int i;
	double mrt=x[0];

	for(i=0;i<n;i++)
	{
		printf("%d ",x[i]);
	}
	printf("\n");
	for(i=1;i<n;i++)
	{
		x[i] += x[i-1];
		mrt += x[i];
	}	
	mrt /=n;
	printf("Minimum Retrieval Time of this order is : %f",mrt);

	return;
}

int main(int argc, char const *argv[])
{
	int n,i,j,k,t;
	printf("Enter No. of Programs:");
	scanf("%d",&n);
	printf("Enter No. of Tapes:");
	scanf("%d",&t);

	int *x;
    x = (int *)malloc(n*sizeof(int));

    for(i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }

    mrt(x,n,t);
	return 0;
}