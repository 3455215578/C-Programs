#include <stdio.h>
#include <stdlib.h>

typedef int VertexType; // ��������
typedef int EdgeType;   // ������

#define MAXSIZE 100
#define EDGE_MAXSIZE 200
#define INF 0x10000

/** �ڽӾ���ṹ�� **/
typedef struct
{
	int vertex_num; // ������
	int edge_num;  // ����

	VertexType vertex[MAXSIZE];       // ��������
	EdgeType edge[MAXSIZE][MAXSIZE];  // ������

}MatGraph;

/** ����ͼ **/
void Create_Graph(MatGraph* graph)
{
	graph->vertex_num = 9;
	graph->edge_num = 16;

	// ��ʼ����������
	for (int i = 0; i < graph->vertex_num; i++)
	{
		graph->vertex[i] = i;
	}

	// ��ʼ��������
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

	// �����鸳ֵ
	// V0-V1 V0-V2
	graph->edge[0][1] = 1;
	graph->edge[0][2] = 5;
		   
	// V1-V2 V1-V3 V1-V4
	graph->edge[1][2] = 3;
	graph->edge[1][3] = 7;
	graph->edge[1][4] = 5;
		  
	// V2-V4 V2-V5
	graph->edge[2][4] = 1;
	graph->edge[2][5] = 7;
		 
	// V3-V4 V3-V6
	graph->edge[3][4] = 2;
	graph->edge[3][6] = 3;
		
	// V4-V5 V4-V6 V4-V7
	graph->edge[4][5] = 3;
	graph->edge[4][6] = 6;
	graph->edge[4][7] = 9;
		
	// V5-V7
	graph->edge[5][7] = 5;
		   
	// V6-V7 V6-V8
	graph->edge[6][7] = 2;
	graph->edge[6][8] = 7;
		 
	// V7-V8
	graph->edge[7][8] = 4;

	// �ԶԽ���Ϊ�ᣬΪ�°벿�ָ�ֵ
	for (int i = 0; i < graph->vertex_num; i++)
	{
		for (int j = 0; j < graph->vertex_num; j++)
		{
			graph->edge[j][i] = graph->edge[i][j];
		}
	}

}

// Ѱ����һ��Ҫ�۲�Ķ���
int choose(int* distance, int* visited, int vertex_num)
{
	int min = INF;
	int min_pos = -1;

	for (int i = 0; i < vertex_num; i++)
	{
		if ((visited[i] == 0) && (distance[i] < min))
		{
			min = distance[i];
			min_pos = i;
		}
	}

	return min_pos;
}

void Dijkstra(MatGraph graph, int begin)
{
	// �����Ƿ��ѱ��߹�
	int visited[MAXSIZE];

	// begin�������������СȨֵ "distance[2]"��ʾ��begin��vertex[2]����̾���
	int distance[MAXSIZE];

	// �洢���·�� "path[0] = 1" ��ʾ��vertex[0]����Ľڵ���vertex[1]
	int path[MAXSIZE];

	// ��ʼ��
	for (int i = 0; i < graph.vertex_num; i++)
	{
		visited[i] = 0;
		distance[i] = graph.edge[begin][i];
		path[i] = -1;
	}

	visited[begin] = 1;
	distance[begin] = 0;

	// ��һ��Ҫ�۲�Ķ���
	int next;
	for (int i = 1; i < graph.vertex_num; i++)
	{
		next = choose(distance, visited, graph.vertex_num);

		// 
		visited[next] = 1;

		// ����begin�����ڵ����̾���(distance)
		for (int j = 0; j < graph.vertex_num; j++)
		{
			// ��ǰ����δ�����ʵĽڵ�
			if (visited[j] == 0)
			{
				if ((distance[next] + graph.edge[next][j]) < distance[j])
				{
					distance[j] = distance[next] + graph.edge[next][j];
					path[j] = next;
				}
			}

		}
	}

}

int main(void)
{
	MatGraph graph;
	Create_Graph(&graph);

	int begin = 0;
	Dijkstra(graph, begin);

	return 0;
}
