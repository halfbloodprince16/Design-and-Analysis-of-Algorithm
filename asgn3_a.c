#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

struct edges
{
	int u,v,w;
};

int bellmanford(struct edges *ed,int v,int e)
{
	int *cost,i,j;
	int flg=0;

	cost = (int *)malloc(v*sizeof(int));
	for(i=0;i<v;i++)
	{
		cost[i] = INT_MAX;
	}

	int head;
	printf("Enter Head :");
	scanf("%d",&head);
	cost[head] = 0;
	int a,b,c,nochange=0;
	for(i=0;i<v-1;i++)
	{
		for(j=0;j<e;j++)
		{
			a = ed[j].u;
			b = ed[j].v;
			c = ed[j].w;
			if(cost[a] == INT_MAX)
			{
				continue;
			}
			else if(cost[a]+c < cost[b])
			{
				cost[b] = cost[a]+c;
				nochange=1;
			}
		}
		printf("\n");
		/*for(int k=0;k<v;k++)
		{
			printf("%d ",cost[k]);
		}*/
		if(nochange==0)
		{
			for(int k=0;k<v;k++)
			{
				printf("Cost to travel from %d to %d is->%d\n",head,k,cost[k]);
			}
			return 0;
		}
		nochange = 0;
	}

	for(i=0;i<e;i++)
	{
		a = ed[i].u;
		b = ed[i].v;
		c = ed[i].w;
		if(cost[a]+c < cost[b])
		{
			flg=1;
			break;
		}
	}

	if(flg!=1)
	{
		for(i=0;i<v;i++)
		{
			printf("Cost to travel from %d to %d is->%d\n",head,i,cost[i]);
		}
	}

	return flg;

}

int main(int argc, char const *argv[])
{
	int v,e,i,j;

	printf("Enter No. of Vertices :");
	scanf("%d",&v);
	printf("Enter No. of Edges :");
	scanf("%d",&e);

	struct edges *ed;
	ed = (struct edges *)malloc(e*sizeof(struct edges));

	int a,b,c,flg=0;

	printf("As per the input you can enter Vertices b/w 0 to %d\n",v-1);
	for(i=0;i<e;)
	{
		printf("Enter Vertices(u,v) and weights :");
		scanf("%d %d %d",&a,&b,&c);
		if(a >= v || a < 0 || b >= v || b<0)
		{
			printf("Error Invalid Vertices\n");
		}
		else 
		{
			for(j=0;j<i;j++)
			{
				if(a == ed[j].u && b == ed[j].v)
				{
					flg=1;
					printf("Error Duplicate Edge Found->Insert Again\n");
					break;
				}
			}
			if(flg!=1)
			{
				ed[i].u = a;
				ed[i].v = b;
				ed[i].w = c;
				i++;
			}
			
		}
		flg=0;
	}
/*	for(i=0;i<e;i++)
	{
		printf("%d\n",ed[i].w);
	}*/

	int fl = bellmanford(ed,v,e);
	if(fl==0)
	{
		return printf("\nNo Negative Cycle"),0;
	}
	printf("\nNegative Cycle Present");
	return 0;
}