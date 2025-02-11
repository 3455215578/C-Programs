#include <stdio.h>
#include <stdlib.h>

typedef char VertexType; // ��������
typedef int EdgeType;   // ������

#define MAXSIZE 100
#define INF 0x7fffffff

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

void Prim(MatGraph* graph)
{
	// weight��vex_index�Ĺ�ϵ����vex_index[1] = 0, ��weight[1]��ʾ��vertex[0]��vertex[1]��Ȩֵ
	int vex_index[MAXSIZE];	// ֵ������㣬�±�����յ�
	int weight[MAXSIZE];	// �洢��ѡ�ߵ�Ȩֵ	

	// �洢ѡ������Ȩֵ��С�ߵ�Ȩֵ
	int min;

	// �洢Ȩֵ��С�Ľڵ���±�
	int min_index;

	// ��ʼ��A��
	vex_index[0] = 0;
	weight[0] = 0;

	// ��ʼ��weight��vex_index
	for (int i = 1; i < graph->vertex_num; i++)
	{
		// ���ڵ�A�Ĵ�ѡ��Ȩֵ��ӵ�weight��
		weight[i] = graph->edge[0][i];

		// ��A��ָ�������ڵ�
		vex_index[i] = 0;
	}

	// ��ѭ��
	for (int i = 1; i < graph->vertex_num; i++)
	{
		// ÿһ��ѭ��ǰ����min
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

		// ����Ȩֵ��С�Ľڵ�󣬽�������ʼ�ڵ��Ȩֵ��Ϊ0
		weight[1] = 0;

		// 3.���¼���Ľڵ�Ĵ�ѡ��(����vex_index��weight)
		for (int k = 0; k < graph->vertex_num; k++)
		{
			// �ų������ӵı�
			if ((graph->edge[min_index][k] < weight[k]) && (weight[k] != 0))
			{
				// ��ֱ����Ȩֵ��С�ĸ���
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
