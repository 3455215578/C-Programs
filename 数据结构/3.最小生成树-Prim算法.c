#include <stdio.h>
#include <stdlib.h>

typedef char VertexType; // 顶点类型
typedef int EdgeType;   // 边类型

#define MAXSIZE 100
#define INF 0x7fffffff

/** 邻接矩阵结构体 **/
typedef struct
{
	int vertex_num; // 顶点数
	int edge_num;  // 边数

	VertexType vertex[MAXSIZE];       // 顶点数组
	EdgeType edge[MAXSIZE][MAXSIZE];  // 边数组

}MatGraph;

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

void Prim(MatGraph* graph)
{
	// weight和vex_index的关系：若vex_index[1] = 0, 则weight[1]表示从vertex[0]到vertex[1]的权值
	int vex_index[MAXSIZE];	// 值代表起点，下标代表终点
	int weight[MAXSIZE];	// 存储待选边的权值	

	// 存储选出来的权值最小边的权值
	int min;

	// 存储权值最小的节点的下标
	int min_index;

	// 初始化A点
	vex_index[0] = 0;
	weight[0] = 0;

	// 初始化weight和vex_index
	for (int i = 1; i < graph->vertex_num; i++)
	{
		// 将节点A的待选边权值添加到weight中
		weight[i] = graph->edge[0][i];

		// 从A点指向其他节点
		vex_index[i] = 0;
	}

	// 大循环
	for (int i = 1; i < graph->vertex_num; i++)
	{
		// 每一次循环前重置min
		min = INF;

		for(int j = 0; j < graph->vertex_num; j ++)
		{
			if ((weight[j] != 0) && ((weight[j] < min)))
			{
				min = weight[j];
				min_index = j;
			}
		}

		printf("(%c->%c)\n", graph->vertex[vex_index[min_index]], graph->vertex[min_index]);

		// 连接权值最小的节点后，将其与起始节点的权值设为0
		weight[1] = 0;

		// 3.找新加入的节点的待选边(更新vex_index和weight)
		for (int k = 0; k < graph->vertex_num; k++)
		{
			// 排除已连接的边
			if ((graph->edge[min_index][k] < weight[k]) && (weight[k] != 0))
			{
				// ☆直接用权值更小的覆盖
				weight[k] = graph->edge[min_index][k];
				vex_index[k] = min_index;
			}
		}
	}

}

int main(void)
{
	MatGraph graph;
	Create_Graph(&graph);

	Prim(&graph);

	return 0;
}
