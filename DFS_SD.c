#include<stdio.h>
#define maxnodes  100
void addEdge(int x, int y, int adjMatrix[maxnodes][maxnodes])
{
    adjMatrix[x][y] = 1;
    adjMatrix[y][x] = -1;
}
void displayMatrix(int node, int adjMatrix[maxnodes][maxnodes])
{
 int i, j;
    printf("Adjacency Matrix:\n");
    for (i = 0; i < node; i++)
    {
        for (j = 0; j < node; j++)
            printf("%3d ", adjMatrix[i][j]);
        printf("\n");
    }
}

void DFS(int startnode ,int node,int adjMatrix[maxnodes][maxnodes])
{
	int stack[maxnodes];
	int visited[maxnodes]={0};
	int i;
	int top=-1;
	stack[++top]=startnode;
	visited[startnode]=1;
	printf("\nDFS traversal starting from node %d: ",startnode+1);
	while(top!=-1)
	{
	  int current=stack[top--];
	  printf("%d",current+1);
	  for( i=0;i<node;i++){
	  	if(adjMatrix[current][i]==1 && visited[i]==0)
	  	{
	  		stack[++top]=i;
	  		visited[i]=1;
		  }
	  }	
	}
	
}
int main()
{
    int i, node, edge, x, y;
    static int adjMatrix[maxnodes][maxnodes];
    printf("Enter number of nodes in the graph: ");
    scanf("%d", &node);
	printf("Enter number of edges in the graph: ");
    scanf("%d", &edge);
    printf("Enter the edges (format: from_node to_node):\n");
    for (i = 0; i < edge; i++)
    {
        scanf("%d %d", &x, &y);
        addEdge(x-1, y-1, adjMatrix);
    }
    displayMatrix(node, adjMatrix);
    printf("Enter the starting node for DFS traversal: ");
    scanf("%d", &x);
    
    DFS(x-1,node,adjMatrix);
    return 0;
}

