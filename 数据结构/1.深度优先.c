#include <stdio.h>
#include <stdlib.h>

typedef char VertexType; // ��������
typedef int EdgeType;   // ������

#define MAXSIZE 100

/** �ڽӾ���ṹ�� **/
typedef struct
{
	int vertex_num; // ������
	int edge_num;  // ����

	VertexType vertex[MAXSIZE];       // ��������
	EdgeType edge[MAXSIZE][MAXSIZE];  // ������

}MatGraph;

/** �鿴�����Ƿ��ѱ����� **/
int visited[MAXSIZE];

/** ����ͼ **/
void Create_Graph(MatGraph* graph)
{
	graph->vertex_num = 9;
	graph->edge_num = 15;

	// ��ʼ����������
	graph->vertex[0] = 'A';
	graph->vertex[1] = 'B';
	graph->vertex[2] = 'C';
	graph->vertex[3] = 'D';
	graph->vertex[4] = 'E';
	graph->vertex[5] = 'F';
	graph->vertex[6] = 'G';
	graph->vertex[7] = 'H';
	graph->vertex[8] = 'I';

	// ��ʼ��������
	for (int i = 0; i < graph->vertex_num; i++)
	{
		for (int j = 0; j < graph->vertex_num; j++)
		{
			graph->edge[i][j] = 0;
		}
	}

	// �����鸳ֵ
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

	// �ԶԽ���Ϊ�ᣬΪ�°벿�ָ�ֵ
	for (int i = 0; i < graph->vertex_num; i++)
	{
		for (int j = 0; j < graph->vertex_num; j++)
		{
			graph->edge[j][i] = graph->edge[i][j];
		}
	}

}

// ������ȣ�Depth First Search
void DFS(MatGraph graph, int vertex_index)
{
	// ���ʶ���
	visited[vertex_index] = 1;
	printf("%c\n", graph.vertex[vertex_index]);

	// Ѱ���뵱ǰ������������δ�����ʵĶ���
	for (int j = 0; j < graph.vertex_num; j++)
	{
		if ((graph.edge[vertex_index][j] == 1) && (visited[j] == 0))
		{
			DFS(graph, j);
		}
	}
}

/** ���������� **/
void Travel_Edge(MatGraph graph)
{
	// ����������
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

	DFS(graph, 0);

	return 0;
}
