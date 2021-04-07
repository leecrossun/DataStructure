#include <stdio.h>
#include <string.h>
#include <limits.h>

#define TRUE	1
#define FALSE	0
#define MAX_VERTICES	100		/* ����� �� */
#define INF 	9999		/* ���� ��(������ ���� ���) */

int distance[MAX_VERTICES];	/* ���۳��κ����� �ִܰ�� �Ÿ� */
int previous[MAX_VERTICES];	/* ���� ���  */
int found[MAX_VERTICES];	/* �湮�� ��� ǥ�� */

typedef struct GraphType {
	int n;					// ������ ����
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

// ����ö���� 
typedef struct station 
{
	char name[INF];
}STATION;
// �׷��� �ʱ�ȭ 
void graph_init(GraphType *g)
{
	int r,c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = INF;

     for (r = 0; r < MAX_VERTICES; r++) // pak �߰�, �ڱ��ڽſ����� �Ÿ��� 0����
          g->adj_mat[r][r] = 0;
}

/*  */
void read_graph(GraphType *g, char *filename)
{
	int n, u, v;
	FILE *fp = fopen(filename, "r");
	if (fp == NULL) { 
		fprintf(stderr, "���� %s�� �� �� ����!\n", filename); return;  
	}
	fscanf(fp, "%d\n", &n);
	g->n = n;
	while (fscanf(fp, "%d %d", &u, &v) != EOF) {
		fscanf(fp, "%d\n", &g->adj_mat[u][v]);
		g->adj_mat[v][u] = g->adj_mat[u][v];
	}
	fclose(fp);
}

int choose(int distance[], int n, int found[])
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i=0; i < n; i++)
		if (distance[i] < min && ! found[i]) {
			min = distance[i];
			minpos=i;
		}
	return minpos;
}

void print_path(STATION *s, int start, int end) // ���� ����� ���ְ� ����
{  
	if (start == end) 
		printf("%s", s[start].name);
	else {
		print_path(s, start, previous[end]);
		printf("-> %s ", s[end].name);
	}
}

void shortest_path(STATION *s, GraphType *g, int start, int end)
{  
	int i, u, w;
	for(i=0; i<g->n; i++) /* �ʱ�ȭ */
	{
		distance[i] = g->adj_mat[start][i];
		found[i] = FALSE;
        previous[i] = start;
	}

	found[start] = TRUE;    /* ���۳�� �湮 ǥ�� */
	distance[start] = 0;	
     
     for(i = 0; i < (g->n)-1; i++) {
		u = choose(distance, g->n, found); 
		found[u] = TRUE;
    
		for(w=0; w<g->n; w++) {
			if(!found[w])
				if( distance[u] + g->adj_mat[u][w] < distance[w] ) {
					distance[w] = distance[u] + g->adj_mat[u][w];	
					previous[w] = u;		/* ������� ���� */
                    }
		}
		// ������ ���� �� �������� 
		if (u==end)
			break;
	 }
	// ��ο� �Ÿ� ��� 
	print_path(s, start, end);
    printf(" (%d)\n", distance[end]);
}

void main()
{
	GraphType g;		// �Է� �׷���
	char start[50], dest[50];
    int i, sIndex, dIndex;
    char sName[10], dName[10];
	STATION st [12] = {"����","���빮","����3��","��û","���￪","������3��","�湫��","���빮����","���","û��","�Ŵ�","����"};
    graph_init(&g);
     
	read_graph(&g, "input.txt");
	
     printf("������:");
     scanf("%s", sName);
     
    for(i = 0; i < 12; i++)
    {
    	if (strcmp(st[i].name, sName) == 0)
    		sIndex = i;
	}
	 
    printf("������:");
    scanf("%s", dName);
     
    for(i = 0; i < 12; i++)
    {
    	if (strcmp(st[i].name, dName) == 0)
    		dIndex = i;
	}
	shortest_path(st, &g, sIndex, dIndex);
}
