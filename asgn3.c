#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

struct edges
{
	int u,v,w;
};

int distance(int a,int b,int e,struct edges *ed)
{
	int i,j;
	for(i=0;i<e;i++)
	{
		if(ed[i].u == a && ed[i].v == b)
		{
			return ed[i].w;
		}
	}
}

int bellmanford(struct edges *ed,int g[][2],int v,int e)
{
	int cost[v],i,j;
	int flg=0;

	for(i=1;i<=v;i++)
	{
		cost[i] = INT_MAX;
	}

	int head;
	printf("Enter Head :");
	scanf("%d",&head);
	cost[head] = 0;

	int a,b,c;
	for(i=0;i<v-1;i++)
	{
		for(j=0;j<e;j++)
		{
			a = g[j][0]; b = g[j][1];
			int wt = distance(a,b,e,ed);
			//printf("i%d j%d weight%d\n",a,b,wt);
			if(cost[a]+wt < cost[b])
			{
				cost[b] = cost[a]+wt;
			}
		}
	}

	for(i=0;i<e;i++)
	{
		a = g[i][0]; b = g[i][1];
		int wt = distance(a,b,e,ed);
		if(cost[a]+wt < cost[b])
		{
			flg=1;
			break;
		}
	}

	if(flg!=1)
	{
		for(i=1;i<=v;i++)
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
	int graph[e][3];

	for(i=0;i<e;i++)
	{
		printf("Enter Vertices(u,v) and weights :");
		scanf("%d %d %d",&graph[i][0],&graph[i][1],&graph[i][2]);
	}
	//handling duplicate edges
	int count=0;
	for(i=0;i<e-1;i++)
	{
		for(j=i+1;j<e;j++)
		{
			if(graph[i][0] == graph[j][0] && graph[i][1]==graph[j][1])
			{
				int w;
				if(graph[i][2] < graph[j][2])
				{
					w = graph[i][2];
				}
				else
				{
					w = graph[j][2];
				}
				graph[i][2] = w;
				graph[j][0] = -1;
				graph[j][1] = -1;
				count++;
			}

		}
	}

	int g[e-count][2];
	int a,b,c;

	struct edges *ed;
	ed = (struct edges*)malloc((e-count)*sizeof(struct edges));
	j=0;
	for(i=0;i<e;i++)
	{
		if(graph[i][0]!=-1)
		{
			ed[j].u = graph[i][0];
			ed[j].v = graph[i][1];
			ed[j].w = graph[i][2];

			g[j][0] = graph[i][0];
			g[j][1] = graph[i][1];
			j = j+1;
		}
	}

	int flg;
	e = e-count;
	flg = bellmanford(ed,g,v,e);
	if(flg==0){return printf("\nNo Negative Cycle"),0;}
	printf("\nNegative Cycle Present");
	return 0;
}