#include <stdio.h>
#include <stdlib.h>

typedef char VertexType; // 顶点类型
typedef int EdgeType;   // 边类型

#define MAXSIZE 100
#define EDGE_MAXSIZE 200
#define INF 0x7fffffff

/** 邻接矩阵结构体 **/
typedef struct
{
	int vertex_num; // 顶点数
	int edge_num;  // 边数

	VertexType vertex[MAXSIZE];       // 顶点数组
	EdgeType edge[MAXSIZE][MAXSIZE];  // 边数组

}MatGraph;

typedef struct
{
	// 存储起点和终点的下标
	int begin;
	int end;

	int weight;
}Edge;

/** 创建图 **/
void Create_Graph(MatGraph* graph)
{
	graph->vertex_num = 9;
	graph->edge_num = 15;

	// 初始化顶点数组
	graph->vertex[0] = 'A';
	graph->vertex[1] = 'B';
	graph->vertex[2] = 'C';
	graph->vertex[3] = 'D';
	graph->vertex[4] = 'E';
	graph->vertex[5] = 'F';
	graph->vertex[6] = 'G';
	graph->vertex[7] = 'H';
	graph->vertex[8] = 'I';

	// 初始化边数组
	for (int i = 0; i < graph->vertex_num; i++)
	{
		for (int j = 0; j < graph->vertex_num; j++)
		{
			if (i == j)
			{
				graph->edge[i][j] = 0;
			}
			else
			{
				graph->edge[i][j] = INF;
			}
		}
	}

	// 边数组赋值
	// A-B  A-F
	graph->edge[0][1] = 10;
	graph->edge[0][5] = 11;

	// B-C B-G B-I
	graph->edge[1][2] = 18;
	graph->edge[1][6] = 16;
	graph->edge[1][8] = 12;

	// C-D C-I
	graph->edge[2][3] = 22;
	graph->edge[2][8] = 8;

	// D-E D-G D-H D-I
	graph->edge[3][4] = 20;
	graph->edge[3][6] = 24;
	graph->edge[3][7] = 16;
	graph->edge[3][8] = 21;

	// E-F E-H
	graph->edge[4][5] = 26;
	graph->edge[4][7] = 7;

	// F-G
	graph->edge[5][6] = 17;

	// G-H
	graph->edge[6][7] = 19;

	// 以对角线为轴，为下半部分赋值
	for (int i = 0; i < graph->vertex_num; i++)
	{
		for (int j = 0; j < graph->vertex_num; j++)
		{
			graph->edge[j][i] = graph->edge[i][j];
		}
	}

}

/**
在C语言中，数组名本身就是一个指针，指向数组的第一个元素, 当你将数组作为参数传递给函数时，你实际上是传递了这个指针。
因此，函数内部对数组的任何修改都会反映到原始数组上。
**/ 
void Create_Edges(MatGraph graph, Edge* edges)
{
	int index = 0;

	// 只处理对角线上半部分
	for (int i = 0; i < graph.vertex_num; i++)
	{
		for (int j = i + 1; j < graph.vertex_num; j++)
		{
			if (graph.edge[i][j] != INF)
			{
				edges[index].begin = i;
				edges[index].end = j;
				edges[index].weight = graph.edge[i][j];

				index++;
			}
		}
	}
}

/** 用于排序时交换前后两条边 **/
void Swap(Edge* edge1, Edge* edge2)
{
	int temp;

	// begin
	temp = edge2->begin;
	edge2->begin = edge1->begin;
	edge1->begin = temp;

	// end
	temp = edge2->end;
	edge2->end = edge1->end;
	edge1->end = temp;

	// weight
	temp = edge2->weight;
	edge2->weight = edge1->weight;
	edge1->weight = temp;
}

/** 根据权值将边从小到大排序 **/ 
void Sort(Edge edges[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if(edges[j].weight > edges[j + 1].weight)
			{
				Swap(&edges[j], &edges[j + 1]);
			}
		}

	}
}

int Find(int* parent, int index)
{
	while (parent[index] > 0)
	{
		index = parent[index];
	}

	return index;
}

void Kruskal(MatGraph* graph)
{
	Edge edges[EDGE_MAXSIZE];
	Create_Edges(*graph, edges);

	Sort(edges, graph->edge_num);

	int parent[MAXSIZE];

	for (int i = 0; i < graph->vertex_num; i++)
	{
		parent[i] = 0;
	}

	int begin, end;
	
	for (int i = 0; i < graph->edge_num; i++)
	{
		begin = Find(parent, edges[i].begin);
		end = Find(parent, edges[i].end);

		if (begin != end)
		{
			parent[begin] = end;
			printf("(%c->%c)\n", graph->vertex[edges[i].begin], graph->vertex[edges[i].end]);
		}
	}

}

int main(void)
{
	MatGraph graph;
	Create_Graph(&graph);

	Kruskal(&graph);

	return 0;
}
