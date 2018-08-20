#include <stdio.h>
#include <stdlib.h>

// structs
typedef struct TNode
{
    int value;
    struct LList *edges;
} TNode;

typedef struct Trie
{
    struct LList *edges;
} Trie;

typedef struct LLNode
{
    char key;
    struct TNode *value;
    struct LLNode *next;
} LLNode;

typedef struct LList
{
    struct LLNode *head;
} LList;

// TNode fns
TNode *TNode_New(int v)
{
    LList *ll = malloc(sizeof(LList));
    TNode *tn = malloc(sizeof(TNode));
    tn->value = v;
    tn->edges = ll;

    return tn;
}

// LLNode fns
LLNode *LLNode_Next(LLNode *lln)
{
    return lln->next;
}

void LList_Add(LList *ll, int k, int v)
{
    TNode *tn = TNode_New(v);
    LLNode *lln = malloc(sizeof(LLNode));
    lln->key = k;
    lln->value = tn;
    lln->next = NULL;

    if (ll->head != NULL)
    {
        lln->next = ll->head;
    }

    ll->head = lln;
}

LLNode *LList_Find(LList *ll, char k)
{
    LLNode *lln = ll->head;

    while (lln != NULL && lln->key != k)
    {
        lln = LLNode_Next(lln);
    }

    return lln;
}

// Trie fns
TNode *Trie_Find(Trie *t, char k[], int l)
{
    LList *e = t->edges;
    TNode *tn;

    int i = 0;
    while (i < l && tn != NULL)
    {
        LLNode *lln = LList_Find(e, k[i]);

        if (lln == NULL)
        {
            tn = NULL;
            break;
        }

        tn = lln->value;
        e = tn->edges;
        i++;
    }

    return tn;
}

void Trie_Add(Trie *t, char k[], int l, int v)
{
    int i = 1;
    LList *e = t->edges;
    LLNode *lln = LList_Find(e, k[0]);

    while (lln != NULL && i < l - 1)
    {
        TNode *tn = lln->value;

        if (tn == NULL)
        {
            break;
        }

        e = tn->edges;
        lln = LList_Find(e, k[0]);
    }

    if (lln == NULL)
    {
        LList_Add(e, k[l - 1], v);
        return;
    }

    LList_Add(lln->value->edges, k[l - 1], v);
}

int main()
{
    LList ll = {.head = NULL};

    Trie t = {.edges = &ll};
    Trie_Add(&t, "a", 1, 1);
    Trie_Add(&t, "ab", 2, 4);
    Trie_Add(&t, "b", 1, 2);

    TNode *ftn = Trie_Find(&t, "b", 1);

    printf("value: %i\n", ftn->value);
}