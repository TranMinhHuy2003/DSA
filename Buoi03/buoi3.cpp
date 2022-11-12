#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

struct node {
    int data;
    struct node* pnext;
};
typedef struct node NODE;

struct list {
    NODE* phead;
    NODE* ptail; 
};
typedef struct list List;

void CreateList (List &l) {
    l.phead=NULL;
    l.ptail=NULL;
}

NODE* CreateNode (int x) {
    NODE* p=new NODE;
    if (p==NULL) {
        exit(1);
    }
    p->data=x;
    p->pnext=NULL;
    return p;
}

void AddHead (List &l, NODE* p) {
    if (l.phead==NULL) {
        l.phead=p;
        l.ptail=p;
    } else {
        p->pnext=l.phead;
        l.phead=p;
    }
}

void AddTail (List &l, NODE* p) {
    if (l.phead==NULL) {
        l.phead=p;
        l.ptail=p;
    } else {
        l.ptail->pnext=p;
        l.ptail=p;
    }
}

bool KTSNT(int n)
{
    if (n < 2)    
        return false;

    for (int i = 2; i <= sqrt(n); i ++)
    {
        if (n%i==0)
        {
            return false;
        }
    }
    return true;
}

int DemNodeSoNguyenTo (List l) {
    int dem=0;
    for (NODE* k=l.phead; k!=NULL; k=k->pnext) {
        if (KTSNT(k->data)==true) {
            dem++;
        }
    }
    return dem;
}

int TinhTongNodeChan (List l) {
    int sum=0;
    for (NODE* k=l.phead; k!=NULL; k=k->pnext) {
        if (k->data%2==0) {
            sum+=k->data;
        }
    }
    return sum;
}

int KiemTraSoTang (int n) {
    int t=n%10;
    n=n/10;
    int k;
    while (n!=0) {
        if (t>n%10) {
            t=n%10;
            n=n/10;
            k=1;
        } else {
            k=0;
            break;
        }
    }
    return k;
}

void LietKeCacNodeTang (List l) {
    int dem=1;
    for (NODE* k=l.phead; k!=NULL; k=k->pnext) {
        if (KiemTraSoTang(k->data)==1) {
            cout <<dem<<"  ";
            dem++;
        }
    }
}

void hoanvi(int &a,int &b) {
    int t=a; 
    a=b; 
    b=t; 
}

void SapXepTangDan (List &l) {
    NODE *i,*j; 

    for(i=l.phead;i!=l.ptail;i=i->pnext) {

         for(j=i->pnext;j!=NULL;j=j->pnext) {

            if(i->data>j->data) {

                hoanvi(i->data,j->data); 
            }
         }
    }

}

/*void AddAfterQ(LIST &L, NODE* p, NODE* Q) {
    if (Q != NULL) {
        p->pNext = Q->pNext;
        Q->pNext = p;
        if (L.pTail == Q)
            L.pTail = p;
    } else
        AddHead(L, p); 
}

NODE* SearchNode(LIST L, int x) {
    NODE* p = L.pHead;
    while (p != NULL && p->info != x)
        p = p->pNext;
    return p;
}

bool RemoveHead(LIST &L, int &x) {
    NODE *p;
    if (L.pHead !=NULL) {
        x = L.pHead->info;
        p = L.pHead;
        L.pHead = L.pHead->pNext;
        if (L.pHead == NULL)
            L.pTail = NULL;
        delete p;
        return 1; 
    }
    return 0;
} 

int RemoveTail (List &l) {
    NODE* p;
    if (l.phead!=NULL) {
        for (NODE* k=l.phead; k!=NULL; k=k->pnext) {
            if (k->pnext==l.ptail) {
                delete l.ptail;
                k.pnext=NULL;
                l.ptail=k;
                return 1;
            }
        }
    }
    return 0;
}

bool RemoveAfterQ(LIST &l, NODE *Q, int &x) {
    NODE *p;
    if (Q != NULL) {
        p = Q->pNext; 
        if (p != NULL) { 
            if (p == l.pTail) 
                l.pTail = Q; 
            Q->pNext = p->pNext;
            x = p->info;
            delete p;
        }
        return 1;
    }
    return 0;
}

bool RemoveX(LIST &L, int x) {
    NODE *Q, *p;
    Q = NULL;
    p = L.pHead;
    while (p!=NULL && p->info!=x) {
        Q = p;
        p = p->pNext;
    }
    if (p == NULL) return 0; 
    if (Q != NULL) RemoveAfterQ(L, Q, x);
    else RemoveHead(L, x);
    return 1;
}

void RemoveList(LIST &L) {
    NODE * p;
    while (L.pHead != NULL) {
        p = L.pHead;
        L.pHead = p->pNext;
    delete p;
    }
    L.pTail = NULL;
}*/

void PrintList (List l) {
    for (NODE* k=l.phead; k!=NULL; k=k->pnext) {
        cout <<k->data<<" ";
    }
}


int main() {
    List l;
    CreateList(l); 
    int n;
    cout <<"\nNhap so luong node can them: ";
    cin>>n;
    for (int i=1; i<=n; i++) {
        int x;
        cout <<"\nNhap info: ";
        cin>>x;
        NODE* p=CreateNode(x);
        AddTail(l,p);
    }
    cout <<"\nCo "<< DemNodeSoNguyenTo (l)<<" node co info la so nguyen to";
    cout <<"\nTong cac node co info la so chan: "<<TinhTongNodeChan(l);
    cout <<"\nGia su cac node co chi so bat dau tu 1, cac node co gia tri la so tang nam o cac vi tri: ";
    LietKeCacNodeTang(l);
    SapXepTangDan(l);
    cout <<"\n\t\tDanh sach tang dan";
    PrintList(l);
    system("pause");
    system("cls");
    return 0;
}

