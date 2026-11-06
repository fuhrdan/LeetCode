#include <stdlib.h>

typedef struct
{
    int server;
    int time;
} LogEntry;

typedef struct
{
    int time;
    int index;
} QueryEntry;

static int compareLogs(const void* a, const void* b)
{
    const LogEntry* x = (const LogEntry*)a;
    const LogEntry* y = (const LogEntry*)b;

    return (x->time > y->time) - (x->time < y->time);
}

static int compareQueries(const void* a, const void* b)
{
    const QueryEntry* x = (const QueryEntry*)a;
    const QueryEntry* y = (const QueryEntry*)b;

    return (x->time > y->time) - (x->time < y->time);
}

int* countServers(
    int n,
    int** logs,
    int logsSize,
    int* logsColSize,
    int x,
    int* queries,
    int queriesSize,
    int* returnSize)
{
    (void)logsColSize;

    LogEntry* sortedLogs =
        (LogEntry*)malloc(sizeof(LogEntry) * logsSize);

    QueryEntry* sortedQueries =
        (QueryEntry*)malloc(sizeof(QueryEntry) * queriesSize);

    int* frequency =
        (int*)calloc(n + 1, sizeof(int));

    int* answer =
        (int*)malloc(sizeof(int) * queriesSize);

    for (int i = 0; i < logsSize; i++)
    {
        sortedLogs[i].server = logs[i][0];
        sortedLogs[i].time = logs[i][1];
    }

    for (int i = 0; i < queriesSize; i++)
    {
        sortedQueries[i].time = queries[i];
        sortedQueries[i].index = i;
    }

    qsort(sortedLogs, logsSize, sizeof(LogEntry), compareLogs);
    qsort(sortedQueries, queriesSize, sizeof(QueryEntry), compareQueries);

    int left = 0;
    int right = 0;
    int activeServers = 0;

    for (int qi = 0; qi < queriesSize; qi++)
    {
        int currentTime = sortedQueries[qi].time;

        while (right < logsSize && sortedLogs[right].time <= currentTime)
        {
            int server = sortedLogs[right].server;

            if (frequency[server] == 0)
            {
                activeServers++;
            }

            frequency[server]++;
            right++;
        }

        int minimumTime = currentTime - x;

        while (left < right && sortedLogs[left].time < minimumTime)
        {
            int server = sortedLogs[left].server;

            frequency[server]--;

            if (frequency[server] == 0)
            {
                activeServers--;
            }

            left++;
        }

        answer[sortedQueries[qi].index] = n - activeServers;
    }

    free(sortedLogs);
    free(sortedQueries);
    free(frequency);

    *returnSize = queriesSize;
    return answer;
}
