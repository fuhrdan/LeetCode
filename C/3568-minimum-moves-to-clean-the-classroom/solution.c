//*****************************************************************************
//** 3568. Minimum Moves to Clean the Classroom                     leetcode **
//*****************************************************************************

int minMoves(char** classroom, int classroomSize, int energy)
{
    int rows = classroomSize;
    int cols = (int)strlen(classroom[0]);
    int litterCount = 0;
    int startRow = 0;
    int startCol = 0;

    int litterIndex[20][20];

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            litterIndex[r][c] = -1;

            if (classroom[r][c] == 'S')
            {
                startRow = r;
                startCol = c;
            }
            else if (classroom[r][c] == 'L')
            {
                litterIndex[r][c] = litterCount;
                litterCount++;
            }
        }
    }

    if (litterCount == 0)
    {
        return 0;
    }

    int maskCount = 1 << litterCount;
    int fullMask = maskCount - 1;
    int cellCount = rows * cols;
    int stateCount = cellCount * maskCount;

    /*
     * bestEnergy[position, mask] stores the greatest amount of
     * energy with which we have reached that state.
     *
     * -1 means the state has never been reached.
     */
    int* bestEnergy = (int*)malloc(sizeof(int) * stateCount);

    if (bestEnergy == NULL)
    {
        return -1;
    }

    for (int i = 0; i < stateCount; i++)
    {
        bestEnergy[i] = -1;
    }

    /*
     * Queue entries:
     * position = r * cols + c
     * mask     = litter collected
     * power    = remaining energy
     *
     * A state can be revisited whenever it arrives with more energy.
     * Allocate dynamically and grow the queue when needed.
     */
    typedef struct
    {
        int position;
        int mask;
        int power;
    } State;

    int queueCapacity = stateCount;

    if (queueCapacity < 1024)
    {
        queueCapacity = 1024;
    }

    State* queue = (State*)malloc(sizeof(State) * queueCapacity);

    if (queue == NULL)
    {
        free(bestEnergy);
        return -1;
    }

    int head = 0;
    int tail = 0;

    int startPosition = startRow * cols + startCol;
    int startIndex = startPosition * maskCount;

    bestEnergy[startIndex] = energy;

    queue[tail].position = startPosition;
    queue[tail].mask = 0;
    queue[tail].power = energy;
    tail++;

    int moves = 0;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    while (head < tail)
    {
        /*
         * Process one entire BFS level.
         * Every state currently in [head, levelEnd) was reached
         * using exactly 'moves' moves.
         */
        int levelEnd = tail;

        while (head < levelEnd)
        {
            State current = queue[head];
            head++;

            int r = current.position / cols;
            int c = current.position % cols;

            /*
             * This queue entry may have been superseded by another
             * route to the same state with more energy.
             */
            int currentIndex =
                current.position * maskCount + current.mask;

            if (current.power < bestEnergy[currentIndex])
            {
                continue;
            }

            for (int d = 0; d < 4; d++)
            {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 0 || nr >= rows ||
                    nc < 0 || nc >= cols)
                {
                    continue;
                }

                if (classroom[nr][nc] == 'X')
                {
                    continue;
                }

                /*
                 * We need at least one energy unit to make the move.
                 */
                if (current.power == 0)
                {
                    continue;
                }

                int nextPower = current.power - 1;
                int nextMask = current.mask;

                if (classroom[nr][nc] == 'L')
                {
                    int bit = litterIndex[nr][nc];
                    nextMask |= 1 << bit;
                }

                /*
                 * If this move collected the final litter,
                 * we are done even if energy just reached zero.
                 */
                if (nextMask == fullMask)
                {
                    free(queue);
                    free(bestEnergy);
                    return moves + 1;
                }

                /*
                 * Reset areas restore energy immediately after
                 * entering the cell.
                 */
                if (classroom[nr][nc] == 'R')
                {
                    nextPower = energy;
                }

                /*
                 * Zero energy on a non-reset square cannot lead
                 * anywhere, and we already know all litter has
                 * not been collected.
                 */
                if (nextPower == 0)
                {
                    continue;
                }

                int nextPosition = nr * cols + nc;
                int nextIndex =
                    nextPosition * maskCount + nextMask;

                /*
                 * Dominance:
                 *
                 * BFS guarantees this previous state was reached
                 * in no more moves than the current route.
                 *
                 * Therefore, if it already had at least this much
                 * energy, the new state cannot improve anything.
                 */
                if (bestEnergy[nextIndex] >= nextPower)
                {
                    continue;
                }

                bestEnergy[nextIndex] = nextPower;

                if (tail >= queueCapacity)
                {
                    int newCapacity = queueCapacity * 2;

                    State* newQueue =
                        (State*)realloc(
                            queue,
                            sizeof(State) * newCapacity
                        );

                    if (newQueue == NULL)
                    {
                        free(queue);
                        free(bestEnergy);
                        return -1;
                    }

                    queue = newQueue;
                    queueCapacity = newCapacity;
                }

                queue[tail].position = nextPosition;
                queue[tail].mask = nextMask;
                queue[tail].power = nextPower;
                tail++;
            }
        }

        moves++;
    }

    free(queue);
    free(bestEnergy);

    return -1;
}