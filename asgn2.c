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

void sort(struct jobs *jb,int n,int t)
{
    int *x,i,j;
    x = (int *)malloc(n*sizeof(int));

    for(i=0;i<n;i++)
    {
        x[i] = jb[i].id;
    }

    for(i=0;i<n;i++)
    {
        printf("%d ",x[i]);
    }

    printf("\nSorting\n");
    int t1=0;
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
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",x[i]);
    }

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
    printf("\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }

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
    for(i=0;i<n;i++)
    {
        printf("%d %d %f\n",jb[i].id,jb[i].size,jb[i].rt);
    }

    printf("%f",ans/t);
    

}

void mrt(struct jobs *jb,int n,int t)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d %d\n",jb[i].id,jb[i].size);
    }
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
        scanf("%s",&jb[i].name);
    }
    mrt(jb,n,t);
    free(jb);

    return 0;
}