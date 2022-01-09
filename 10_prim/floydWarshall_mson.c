#include "linkedgraph.h"
const int INF = 1e9;
void floydWarshall(LinkedGraph *lg) {
    // 결과 그래프를 초기화합니다.
    int **ans;
    ans = (int **)calloc(lg->maxVertexCount, sizeof(int *));
    if (!ans)
        return ;
    for (int i = 0; i < lg->maxVertexCount; i++) {
        ans[i] = (int *)calloc(lg->maxVertexCount, sizeof(int));
        if (!ans[i]) {
            for (int j = 0; j < i; j++)
                free(ans[j]);
            return free(ans);
        }
        for (int j = 0; j < lg->maxVertexCount; j++) {
            if (i != j)
                ans[i][j] = INF;
        }
    }
    for (int i = 0; i < lg->maxVertexCount; i++) {
        ListNode *node;
        node = lg->ppAdjEdge[i]->headerNode.pLink;
        while (node) {
            ans[i][node->vertexID] = node->weight;
            node = node->pLink;
        }
    }
    // k == 경유 노드
    for (int k = 0; k < lg->maxVertexCount; k++) {
        for (int i = 0; i < lg->maxVertexCount; i++) {
            for (int j = 0; j < lg->maxVertexCount; j++) {
                if (ans[i][k] + ans[k][j] < ans[i][j]) {
                    ans[i][j] = ans[i][k] + ans[k][j];
                }
            }
        }
    }
    for (int i = 0; i < lg->maxVertexCount; i++) {
            if (!checkVertexValid(lg, i))
                continue ;
            printf("%d : ", i);
        for (int j = 0; j < lg->maxVertexCount; j++) {
            if (ans[i][j] == INF) {
                printf("INF ");
                continue;
            }
            printf("%3d ", ans[i][j]);
        }
        printf("\n");
    }
}
int main() {
    LinkedGraph *lg;
    int max_count;
    printf("graph max size : ");
    scanf("%d", &max_count);
    lg = createLinkedGraph(max_count);
    while (1) {
        int n;
        int to;
        int from;
        int x;
        printf("1.vertex insert\n2.edge insert(no weight)\n3.edge insert(weight)\n4.remove vertex\n5.remove edge\n6.empty\n7.display\n8.floydwhashall\n9.delete\n");
        printf("input : ");
        scanf(" %d", &n);
        switch(n) {
            case 1:
                printf("Vertex input : ");
                scanf(" %d", &n);
                addVertexLG(lg, n);
                break;
            case 2:
                printf("add edge(from, to) : ");
                scanf("%d %d", &from, &to);
                if (addEdgeLG(lg, from, to) == FAIL)
                    fprintf(stderr, "edge connect failed.\n");
                break;
            case 3:
                printf("add edge(from, to) : ");
                scanf(" %d %d", &from, &to);
                printf("weight : ");
                scanf(" %d", &x);
                if (!addEdgewithWeightLG(lg, from, to, x))
                    fprintf(stderr, "edge connect failed.\n");
                break;
            case 4:
                printf("remove vertex : ");
                scanf(" %d", &n);
                if (removeVertexLG(lg, n) == FAIL)
                    fprintf(stderr, "vertex remove failed.\n");
                break;
            case 5:
                printf("remove edge(from, to) : ");
                scanf(" %d %d", &from, &to);
                if(removeEdgeLG(lg, from, to) == FAIL)
                    fprintf(stderr, "edge remove failed.\n");
                break;
            case 6:
                printf("%s\n", isEmptyLG(lg) ? "TRUE" : "FALSE");
                break;
            case 7:
                displayLinkedGraph(lg);
                break;
            case 8:
                floydWarshall(lg);
                break;
            case 9:
                deleteLinkedGraph(lg);
                break;
            default:
                break;
        }
        if (n == 9)
            break ;
    }
}