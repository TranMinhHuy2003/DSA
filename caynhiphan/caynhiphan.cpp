#include <iostream>
using namespace std;

struct Node
{
    int key;
    struct Node* pleft;
    struct Node* pright;
};
typedef struct Node NODE;
typedef NODE* TREE;

void NLR (TREE t)
{
    if (t != NULL)
    {
        cout << t->key << "\t";
        NLR (t->pleft);
        NLR (t->pright);
    }
}

void LNR (TREE t)
{
    if (t != NULL)
    {
        LNR (t->pleft);
        cout << t->key << "\t";
        LNR (t->pright);
    }
}

void LRN (TREE t)
{
    if (t != NULL)
    {
        LRN (t->pleft);
        LRN (t->pright);
        cout << t->key << "\t";
    }
}

int main ()
{
    system ("pause");
    system ("cls");
    return 0;
}