#include <stdlib.h>

typedef struct
{
    long long freeTime;
    int server;
} BusyServer;

typedef struct
{
    BusyServer* data;
    int size;
} MinHeap;

static int busyLess(BusyServer a, BusyServer b)
{
    if (a.freeTime != b.freeTime) return a.freeTime < b.freeTime;
    return a.server < b.server;
}

static void busySwap(BusyServer* a, BusyServer* b)
{
    BusyServer t = *a; *a = *b; *b = t;
}

static void heapPush(MinHeap* heap, BusyServer value)
{
    int i = heap->size++;
    heap->data[i] = value;
    while (i > 0)
    {
        int p = (i - 1) / 2;
        if (busyLess(heap->data[p], heap->data[i])) break;
        busySwap(&heap->data[p], &heap->data[i]);
        i = p;
    }
}

static BusyServer heapPop(MinHeap* heap)
{
    BusyServer result = heap->data[0];
    heap->size--;
    if (heap->size > 0)
    {
        heap->data[0] = heap->data[heap->size];
        int i = 0;
        while (1)
        {
            int left = i * 2 + 1, right = left + 1, smallest = i;
            if (left < heap->size && busyLess(heap->data[left], heap->data[smallest])) smallest = left;
            if (right < heap->size && busyLess(heap->data[right], heap->data[smallest])) smallest = right;
            if (smallest == i) break;
            busySwap(&heap->data[i], &heap->data[smallest]);
            i = smallest;
        }
    }
    return result;
}

static void fwAdd(int* bit, int n, int index, int delta)
{
    for (int i = index; i <= n; i += i & -i) bit[i] += delta;
}

static int fwSum(int* bit, int index)
{
    int result = 0;
    for (int i = index; i > 0; i -= i & -i) result += bit[i];
    return result;
}

static int fwKth(int* bit, int n, int k)
{
    int index = 0, step = 1;
    while ((step << 1) <= n) step <<= 1;
    for (; step > 0; step >>= 1)
    {
        int next = index + step;
        if (next <= n && bit[next] < k)
        {
            index = next;
            k -= bit[next];
        }
    }
    return index + 1;
}

int* busiestServers(
    int k,
    int* arrival,
    int arrivalSize,
    int* load,
    int loadSize,
    int* returnSize)
{
    (void)loadSize;

    int* bit = (int*)calloc(k + 1, sizeof(int));
    int* handled = (int*)calloc(k, sizeof(int));
    BusyServer* heapData = (BusyServer*)malloc(sizeof(BusyServer) * arrivalSize);

    if (bit == NULL || handled == NULL || heapData == NULL)
    {
        free(bit); free(handled); free(heapData);
        *returnSize = 0;
        return NULL;
    }

    for (int server = 0; server < k; server++) fwAdd(bit, k, server + 1, 1);

    MinHeap busy = {heapData, 0};

    for (int i = 0; i < arrivalSize; i++)
    {
        long long time = arrival[i];

        while (busy.size > 0 && busy.data[0].freeTime <= time)
        {
            BusyServer server = heapPop(&busy);
            fwAdd(bit, k, server.server + 1, 1);
        }

        int totalFree = fwSum(bit, k);
        if (totalFree == 0) continue;

        int start = i % k;
        int beforeStart = fwSum(bit, start);
        int targetOrder = (totalFree - beforeStart > 0) ? beforeStart + 1 : 1;
        int fenwickIndex = fwKth(bit, k, targetOrder);
        int server = fenwickIndex - 1;

        fwAdd(bit, k, fenwickIndex, -1);
        handled[server]++;
        heapPush(&busy, (BusyServer){time + load[i], server});
    }

    int best = 0;
    for (int server = 0; server < k; server++) if (handled[server] > best) best = handled[server];

    int count = 0;
    for (int server = 0; server < k; server++) if (handled[server] == best) count++;

    int* answer = (int*)malloc(sizeof(int) * count);
    int index = 0;
    for (int server = 0; server < k; server++) if (handled[server] == best) answer[index++] = server;

    free(heapData); free(handled); free(bit);
    *returnSize = count;
    return answer;
}
