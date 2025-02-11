#include <stdio.h>
#include <stdlib.h>

typedef char VertexType; // ��������
typedef int EdgeType;   // ������

#define MAXSIZE 100
#define EDGE_MAXSIZE 200
#define INF 0x7fffffff

/** �ڽӾ���ṹ�� **/
typedef struct
{
	int vertex_num; // ������
	int edge_num;  // ����

	VertexType vertex[MAXSIZE];       // ��������
	EdgeType edge[MAXSIZE][MAXSIZE];  // ������

}MatGraph;

typedef struct
{
	// �洢�����յ���±�
	int begin;
	int end;

	int weight;
}Edge;

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

	// �ԶԽ���Ϊ�ᣬΪ�°벿�ָ�ֵ
	for (int i = 0; i < graph->vertex_num; i++)
	{
		for (int j = 0; j < graph->vertex_num; j++)
		{
			graph->edge[j][i] = graph->edge[i][j];
		}
	}

}

/**
��C�����У��������������һ��ָ�룬ָ������ĵ�һ��Ԫ��, ���㽫������Ϊ�������ݸ�����ʱ����ʵ�����Ǵ��������ָ�롣
��ˣ������ڲ���������κ��޸Ķ��ᷴӳ��ԭʼ�����ϡ�
**/ 
void Create_Edges(MatGraph graph, Edge* edges)
{
	int index = 0;

	// ֻ����Խ����ϰ벿��
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

/** ��������ʱ����ǰ�������� **/
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

/** ����Ȩֵ���ߴ�С�������� **/ 
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
