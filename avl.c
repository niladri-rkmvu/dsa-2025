#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    int height; // to track bal_factor
    struct Node *rchild;
}*root=NULL;

/*
int NodeHeight(struct Node *p)
{
    int hl = 0, hr = 0;
    if (p != NULL && p->lchild != NULL)
        hl = p->lchild->height;
    else
        hl = 0;
    if (p != NULL && p->rchild != NULL)
        hr = p->rchild->height;
    else
        hr = 0;
    if (hl > hr)
        return hl + 1;
    else
        return hr + 1;
}
*/

int NodeHeight(struct Node *p)
{
    int hl, hr;
    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;
    return (hl > hr ? hl+1 : hr+1);
}

int BalanceFactor(struct Node *p)
{
    int hl, hr;
    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    return hl-hr;
}

struct Node * LL_Rotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if(root == p)
        root = pl;

    return pl; // new root or node around
}

struct Node * LR_Rotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    // Defensive check
    if (!plr) return p;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    if (root == p)
        root = plr;

    return plr;
}


struct Node * RR_Rotation(struct Node *p)
{
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    if (root == p)
        root = pr;

    return pr;
}

struct Node * RL_Rotation(struct Node *p)
{
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

    if (!prl) return p;

    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;

    prl->rchild = pr;
    prl->lchild = p;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    prl->height = NodeHeight(prl);

    if (root == p)
        root = prl;

    return prl;
}

struct Node * RInsert(struct Node *p, int key)
{
    struct Node *t = NULL;
    if(p == NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->height = 1; // this is the change we are adding. We can make it 0 as well
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data)
        p->lchild = RInsert(p->lchild, key);
    else if (key > p->data)
        p->rchild = RInsert(p->rchild, key);
    else
    {
        printf("Key value already exists in the tree\n");
        return t; // at this time t should be NULL
    }

    p->height = NodeHeight(p);

    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
        return LL_Rotation(p);
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1 && p->lchild->rchild)
        return LR_Rotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
        return RR_Rotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1 && p->rchild->lchild)
        return RL_Rotation(p);
    
    return p;
}

int main(void)
{
    root = RInsert(root, 50);
    RInsert(root, 10);
    RInsert(root, 20);
    
    printf("Root = %d\n",root->data);
    printf("Root -> lchild = %d\n", root->lchild->data);
    printf("Root -> rchild = %d\n", root->rchild->data);
    return 0;
}
