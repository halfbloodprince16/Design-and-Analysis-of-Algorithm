#include"stdio.h"
#include"stdlib.h"
#include"string.h"

struct jobs
{
    int id;
    int size;
    char name[20];
    double rt;
};

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

void heapify(int arr[], int n, int i,struct jobs *jb) 
{ 
    int largest = i; 
    int l = 2*i + 1; 
    int r = 2*i + 2; 

    if (l < n && jb[arr[l]].size > jb[arr[largest]].size) 
        largest = l; 
  
    if (r < n && jb[arr[r]].size > jb[arr[largest]].size) 
        largest = r; 
  
    if (largest != i) 
    { 
        swap(&arr[i], &arr[largest]); 

        heapify(arr, n, largest,jb); 
    } 
} 

void heapSort(int arr[], int n,struct jobs *jb) 
{ 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i,jb); 
  
    for (int i=n-1; i>=0; i--) 
    { 
        swap(&arr[0], &arr[i]); 
        heapify(arr, i, 0,jb); 
    } 
} 

void sort(struct jobs *jb,int n,int t)
{
	int *x,i,j;
	x = (int *)malloc(n*sizeof(int));

    for(i=0;i<n;i++)
    {
    	x[i] = jb[i].id;
    }

   /* for(i=0;i<n;i++)
    {
    	printf("%d ",x[i]);
    }

    printf("\nSorting\n");*/

    heapSort(x,n,jb);
    /*int t1=0;
    for(i=0;i<n-1;i++)
    {
    	for(j=i+1;j<n;j++)
    	{
    		if(jb[x[i]].size >jb[x[j]].size)
    		{
    			t1 = x[i];
	    		x[i] = x[j];
	    		x[j] = t1;
    		}
    		
    	}
    }*/
    /*for(i=0;i<n;i++)
    {
    	printf("%d ",x[i]);
    }*/

    //multi tape soln begins

    int row = t,col=0;
    if(n%t == 0)
    {
    	col = n/t;
    }
    else
    {
    	col = (n/t)+1;
    }

    int mat[row][col];
    for(i=0;i<row;i++)
    {
    	for(j=0;j<col;j++)
    	{
    		mat[i][j]=-1;
    	}
    }

    int k =0;
    for(i=0;i<col;i++)
    {
    	for(j=0;j<row;j++)
    	{
    		mat[j][i] = x[k++];
    		if(k == n)
	    	{
	    		break;
	    	}
    	}
    	if(k == n)
    	{
    		break;
    	}
    }
  /*  printf("\n");
    for(i=0;i<row;i++)
    {
    	for(j=0;j<col;j++)
    	{
    		printf("%d ",mat[i][j]);
    	}
    	printf("\n");
    }*/

    int time[row];
    int sum=0;
    double ans;
    for(i=0;i<row;i++)
    {
    	for(j=0;j<col;j++)
    	{
    		if(mat[i][j]!= -1)
    		{
    			sum += jb[mat[i][j]].size;
    			jb[mat[i][j]].rt = sum;
    		}	
    	}
    	time[i] = sum;
    	ans += sum;
    	sum=0;
    }
    printf("\n");
    printf("ID\tName\tSize\tRetrieval Time\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%s\t%d\t%f\n",jb[i].id,jb[i].name,jb[i].size,jb[i].rt);
    }

    printf("Minimum Retrieval Time : %f",ans/n);
    
    free(x);
    return ;
}

void mrt(struct jobs *jb,int n,int t)
{
	int i;
    /*for(i=0;i<n;i++)
    {
        printf("%d %d\n",jb[i].id,jb[i].size);
    }*/
    sort(jb,n,t);
	return;
}

int main(int argc, char const *argv[])
{
	int n,i,j,k,t;
	printf("Enter No. of Tapes:");
	scanf("%d",&t);

    printf("Enter No. of Programs:");
    scanf("%d",&n);

    struct jobs *jb;
    jb = (struct jobs *)malloc(n*sizeof(struct jobs));

    for(i=0;i<n;i++)
    {
        jb[i].id = i;
        printf("Enter Job Size:");
        scanf("%d",&jb[i].size);
        printf("Enter Job Name:");
        scanf("%s",jb[i].name);
    }
    mrt(jb,n,t);
    free(jb);

	return 0;
}