#include <stdlib.h>

typedef struct
{
    int weight;
    int index;
} FreeServer;

typedef struct
{
    long long freeTime;
    int weight;
    int index;
} BusyServer;

static int freeLess(FreeServer a, FreeServer b)
{
    if (a.weight != b.weight)
        return a.weight < b.weight;

    return a.index < b.index;
}

static int busyLess(BusyServer a, BusyServer b)
{
    if (a.freeTime != b.freeTime)
        return a.freeTime < b.freeTime;

    if (a.weight != b.weight)
        return a.weight < b.weight;

    return a.index < b.index;
}

static void freeSwap(FreeServer* a, FreeServer* b)
{
    FreeServer t = *a;
    *a = *b;
    *b = t;
}

static void busySwap(BusyServer* a, BusyServer* b)
{
    BusyServer t = *a;
    *a = *b;
    *b = t;
}

static void freePush(FreeServer* heap, int* size, FreeServer value)
{
    int i = (*size)++;
    heap[i] = value;

    while (i > 0)
    {
        int p = (i - 1) / 2;

        if (freeLess(heap[p], heap[i]))
            break;

        freeSwap(&heap[p], &heap[i]);
        i = p;
    }
}

static FreeServer freePop(FreeServer* heap, int* size)
{
    FreeServer result = heap[0];
    (*size)--;

    if (*size > 0)
    {
        heap[0] = heap[*size];
        int i = 0;

        while (1)
        {
            int left = i * 2 + 1;
            int right = left + 1;
            int smallest = i;

            if (left < *size && freeLess(heap[left], heap[smallest]))
                smallest = left;

            if (right < *size && freeLess(heap[right], heap[smallest]))
                smallest = right;

            if (smallest == i)
                break;

            freeSwap(&heap[i], &heap[smallest]);
            i = smallest;
        }
    }

    return result;
}

static void busyPush(BusyServer* heap, int* size, BusyServer value)
{
    int i = (*size)++;
    heap[i] = value;

    while (i > 0)
    {
        int p = (i - 1) / 2;

        if (busyLess(heap[p], heap[i]))
            break;

        busySwap(&heap[p], &heap[i]);
        i = p;
    }
}

static BusyServer busyPop(BusyServer* heap, int* size)
{
    BusyServer result = heap[0];
    (*size)--;

    if (*size > 0)
    {
        heap[0] = heap[*size];
        int i = 0;

        while (1)
        {
            int left = i * 2 + 1;
            int right = left + 1;
            int smallest = i;

            if (left < *size && busyLess(heap[left], heap[smallest]))
                smallest = left;

            if (right < *size && busyLess(heap[right], heap[smallest]))
                smallest = right;

            if (smallest == i)
                break;

            busySwap(&heap[i], &heap[smallest]);
            i = smallest;
        }
    }

    return result;
}

int* assignTasks(
    int* servers,
    int serversSize,
    int* tasks,
    int tasksSize,
    int* returnSize)
{
    FreeServer* freeHeap =
        (FreeServer*)malloc(sizeof(FreeServer) * serversSize);

    BusyServer* busyHeap =
        (BusyServer*)malloc(sizeof(BusyServer) * serversSize);

    int* ans =
        (int*)malloc(sizeof(int) * tasksSize);

    if (freeHeap == NULL || busyHeap == NULL || ans == NULL)
    {
        free(freeHeap);
        free(busyHeap);
        free(ans);
        *returnSize = 0;
        return NULL;
    }

    int freeSize = 0;
    int busySize = 0;

    for (int i = 0; i < serversSize; i++)
    {
        freePush(
            freeHeap,
            &freeSize,
            (FreeServer){servers[i], i});
    }

    long long time = 0;

    for (int i = 0; i < tasksSize; i++)
    {
        if (time < i)
            time = i;

        while (busySize > 0 && busyHeap[0].freeTime <= time)
        {
            BusyServer s = busyPop(busyHeap, &busySize);

            freePush(
                freeHeap,
                &freeSize,
                (FreeServer){s.weight, s.index});
        }

        if (freeSize == 0)
        {
            time = busyHeap[0].freeTime;

            while (busySize > 0 && busyHeap[0].freeTime <= time)
            {
                BusyServer s = busyPop(busyHeap, &busySize);

                freePush(
                    freeHeap,
                    &freeSize,
                    (FreeServer){s.weight, s.index});
            }
        }

        FreeServer s = freePop(freeHeap, &freeSize);
        ans[i] = s.index;

        busyPush(
            busyHeap,
            &busySize,
            (BusyServer){
                time + tasks[i],
                s.weight,
                s.index
            });
    }

    free(freeHeap);
    free(busyHeap);

    *returnSize = tasksSize;
    return ans;
}
