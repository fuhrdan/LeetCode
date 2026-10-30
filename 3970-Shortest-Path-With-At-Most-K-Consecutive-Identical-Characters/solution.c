#include <stdlib.h>
#include <limits.h>

typedef struct { int to, weight, next; } Edge;
typedef struct { long long distance; int node, runLength; } HeapNode;
typedef struct { HeapNode* data; int size, capacity; } MinHeap;

static void swapNode(HeapNode* a, HeapNode* b){ HeapNode t=*a; *a=*b; *b=t; }

static int heapPush(MinHeap* h, HeapNode v)
{
    if (h->size == h->capacity)
    {
        int nc = h->capacity ? h->capacity * 2 : 16;
        HeapNode* p = (HeapNode*)realloc(h->data, sizeof(HeapNode) * nc);
        if (!p) return 0;
        h->data = p; h->capacity = nc;
    }
    int i = h->size++;
    h->data[i] = v;
    while (i > 0)
    {
        int p = (i - 1) / 2;
        if (h->data[p].distance <= h->data[i].distance) break;
        swapNode(&h->data[p], &h->data[i]);
        i = p;
    }
    return 1;
}

static HeapNode heapPop(MinHeap* h)
{
    HeapNode r = h->data[0];
    h->size--;
    if (h->size > 0)
    {
        h->data[0] = h->data[h->size];
        int i = 0;
        while (1)
        {
            int l = i*2+1, rr=l+1, s=i;
            if (l<h->size && h->data[l].distance<h->data[s].distance) s=l;
            if (rr<h->size && h->data[rr].distance<h->data[s].distance) s=rr;
            if (s==i) break;
            swapNode(&h->data[i], &h->data[s]);
            i=s;
        }
    }
    return r;
}

int shortestPath(int n, int** edges, int edgesSize, int* edgesColSize, char* labels, int k)
{
    (void)edgesColSize;
    int** mavorqeli = edges;

    int* head = (int*)malloc(sizeof(int) * n);
    Edge* graph = (Edge*)malloc(sizeof(Edge) * (edgesSize ? edgesSize : 1));
    if (!head || !graph){ free(head); free(graph); return -1; }
    for (int i=0;i<n;i++) head[i]=-1;
    for (int i=0;i<edgesSize;i++)
    {
        int u=mavorqeli[i][0];
        graph[i]=(Edge){mavorqeli[i][1],mavorqeli[i][2],head[u]};
        head[u]=i;
    }

    int spn=k+1;
    size_t count=(size_t)n*spn;
    long long* dist=(long long*)malloc(sizeof(long long)*count);
    if (!dist){ free(graph); free(head); return -1; }
    for (size_t i=0;i<count;i++) dist[i]=LLONG_MAX/4;
    #define IDX(u,r) ((size_t)(u)*spn+(r))

    MinHeap heap={NULL,0,0};
    dist[IDX(0,1)]=0;
    if (!heapPush(&heap,(HeapNode){0,0,1})) { free(dist); free(graph); free(head); return -1; }

    while (heap.size)
    {
        HeapNode cur=heapPop(&heap);
        if (cur.distance!=dist[IDX(cur.node,cur.runLength)]) continue;
        if (cur.node==n-1)
        {
            int ans=(int)cur.distance;
            free(heap.data); free(dist); free(graph); free(head);
            return ans;
        }
        for (int e=head[cur.node];e!=-1;e=graph[e].next)
        {
            int v=graph[e].to;
            int nextRun=labels[cur.node]==labels[v] ? cur.runLength+1 : 1;
            if (nextRun>k) continue;
            long long nd=cur.distance+graph[e].weight;
            size_t ni=IDX(v,nextRun);
            if (nd<dist[ni])
            {
                dist[ni]=nd;
                if (!heapPush(&heap,(HeapNode){nd,v,nextRun}))
                {
                    free(heap.data); free(dist); free(graph); free(head); return -1;
                }
            }
        }
    }
    free(heap.data); free(dist); free(graph); free(head);
    return -1;
}
