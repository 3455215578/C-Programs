#include <stdio.h>
#include <stdlib.h>

typedef char VertexType; // 顶点类型
typedef int EdgeType;   // 边类型

#define MAXSIZE 100

/** 邻接矩阵结构体 **/
typedef struct
{
	int vertex_num; // 顶点数
	int edge_num;  // 边数

	VertexType vertex[MAXSIZE];       // 顶点数组
	EdgeType edge[MAXSIZE][MAXSIZE];  // 边数组

}MatGraph;

/** 查看顶点是否已被访问 **/
int visited[MAXSIZE];

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
			graph->edge[i][j] = 0;
		}
	}

	// 边数组赋值
	// A-B  A-F
	graph->edge[0][1] = 1;
	graph->edge[0][5] = 1;

	// B-C B-G B-I
	graph->edge[1][2] = 1;
	graph->edge[1][6] = 1;
	graph->edge[1][8] = 1;

	// C-D C-I
	graph->edge[2][3] = 1;
	graph->edge[2][8] = 1;

	// D-E D-G D-H D-I
	graph->edge[3][4] = 1;
	graph->edge[3][6] = 1;
	graph->edge[3][7] = 1;
	graph->edge[3][8] = 1;

	// E-F E-H
	graph->edge[4][5] = 1;
	graph->edge[4][7] = 1;

	// F-G
	graph->edge[5][6] = 1;

	// G-H
	graph->edge[6][7] = 1;

	// 以对角线为轴，为下半部分赋值
	for (int i = 0; i < graph->vertex_num; i++)
	{
		for (int j = 0; j < graph->vertex_num; j++)
		{
			graph->edge[j][i] = graph->edge[i][j];
		}
	}

}

//广度优先：Breadth First Search
void BFS(MatGraph graph)
{
	// 定义"队列"
	VertexType queue[MAXSIZE];
	int front = 0;
	int rear = 0;

	visited[rear] = 1;
	printf("%c\n", graph.vertex[rear]);

	queue[rear] = graph.vertex[rear];
	rear++;

	while (front != rear)
	{
		int count = rear - front;

		while (count > 0)
		{
			int curr = queue[front] - 'A';
			front++;

			for (int j = 0; j < graph.vertex_num; j++)
			{
				if ((graph.edge[curr][j] == 1) && (visited[j] == 0))
				{
					visited[j] = 1;
					printf("%c\n", graph.vertex[j]);

					queue[rear] = graph.vertex[j];
					rear++;

				}
			}

			count--;
		}
	}
}

/** 遍历边数组 **/
void Travel_Edge(MatGraph graph)
{
	// 遍历边数组
	for (int i = 0; i < graph.vertex_num; i++)
	{
		for (int j = 0; j < graph.vertex_num; j++)
		{
			printf("%d ", graph.edge[i][j]);
		}

		printf("\n");
	}
}

int main(void)
{
	MatGraph graph;
	Create_Graph(&graph);

	for (int i = 0; i < graph.vertex_num; i++)
	{
		visited[i] = 0;
	}

	BFS(graph);

	return 0;
}
