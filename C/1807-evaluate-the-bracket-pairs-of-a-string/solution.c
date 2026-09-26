//*****************************************************************************
//** 1807. Evaluate the Bracket Pairs of a String                   leetcode **
//*****************************************************************************

#define HASH_SIZE 262147

typedef struct HashNode
{
    char *key;
    char *value;
    struct HashNode *next;
} HashNode;

static unsigned int hashKey(const char *key)
{
    unsigned int hash = 5381;

    while (*key != '\0')
    {
        hash = ((hash << 5) + hash) + (unsigned char)(*key);
        key++;
    }

    return hash % HASH_SIZE;
}

static void insertHash(HashNode **table, char *key, char *value)
{
    unsigned int index = hashKey(key);

    HashNode *node = malloc(sizeof(HashNode));

    node->key = key;
    node->value = value;
    node->next = table[index];

    table[index] = node;
}

static char *findHash(HashNode **table, const char *key)
{
    unsigned int index = hashKey(key);

    HashNode *node = table[index];

    while (node != NULL)
    {
        if (strcmp(node->key, key) == 0)
        {
            return node->value;
        }

        node = node->next;
    }

    return NULL;
}

static void freeHash(HashNode **table)
{
    for (int i = 0; i < HASH_SIZE; i++)
    {
        HashNode *node = table[i];

        while (node != NULL)
        {
            HashNode *next = node->next;

            free(node);
            node = next;
        }
    }

    free(table);
}

char* evaluate(char* s, char*** knowledge, int knowledgeSize,
               int* knowledgeColSize)
{
    (void)knowledgeColSize;

    HashNode **table = calloc(HASH_SIZE, sizeof(HashNode *));

    for (int i = 0; i < knowledgeSize; i++)
    {
        insertHash(table, knowledge[i][0], knowledge[i][1]);
    }

    int sLength = (int)strlen(s);
    int capacity = sLength * 10 + 1;

    char *retVal = malloc(capacity);
    int outputIndex = 0;

    for (int i = 0; i < sLength;)
    {
        if (s[i] != '(')
        {
            retVal[outputIndex++] = s[i++];
            continue;
        }


        char key[11];
        int keyLength = 0;

        i++;

        while (i < sLength && s[i] != ')')
        {
            key[keyLength++] = s[i++];
        }

        key[keyLength] = '\0';

        i++; 

        char *value = findHash(table, key);

        if (value == NULL)
        {
            retVal[outputIndex++] = '?';
        }
        else
        {
            int valueLength = (int)strlen(value);

            memcpy(retVal + outputIndex, value, valueLength);
            outputIndex += valueLength;
        }
    }

    retVal[outputIndex] = '\0';

    freeHash(table);

    return retVal;
}