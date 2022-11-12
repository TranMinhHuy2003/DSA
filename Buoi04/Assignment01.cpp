#include <iostream>
using namespace std;
#define Max 100

struct Node {
    char data;
    struct Node* pnext;
    struct Node* ppre;
};
typedef struct Node NODE;

struct List {
    NODE* phead;
    NODE* ptail;
};
typedef struct List LIST;

void CreateList (LIST &l) {
    l.phead=NULL;
    l.ptail=NULL;
}

NODE* CreateNode (char x) {
    NODE* p=new NODE;
    if (p==NULL) {
        return NULL;
    } else {
        p->data=x;
        p->pnext=NULL;
        p->ppre=NULL;
    }
    return p;
}

void AddHead (LIST &l, NODE* p) {
    if (l.phead==NULL) {
        l.phead=l.ptail=p;
    } else {
        p->pnext=l.phead;
        l.phead->ppre=p;
        l.phead=p;
    }
}

void AddTail (LIST &l, NODE* p) {
    if (l.phead==NULL) {
        l.phead=l.ptail=p;
    } else {
        l.ptail->pnext=p;
        p->ppre=l.ptail;
        l.ptail=p;
    }
}

void AddNodeToList (LIST &l, LIST &m,int n) {
    for (int i=0; i<n; i++) {
        cout <<"\n\t\tNHAP NODE THU "<<i+1<<endl;
        char x;
        cout <<"\nNhap data: ";
        cin >>x;
        AddHead(l,CreateNode(x));
        AddTail(m,CreateNode(x));
    }
}

void PrintList (LIST l) {
    for (NODE* k=l.phead; k!=NULL; k=k->pnext) {
        cout <<k->data<<"\t";
    }
}

void DemTatCaCacNodeXuatHienNhieuNhat (LIST l) {
    char a[2][Max];
    int j=0;
    int n=0;
    for (NODE* i=l.phead; i!=NULL; i=i->pnext) {
        n++;
        char c=i->data;
        int dem=0;
        for (NODE* k=l.phead; k!=NULL; k=k->pnext) {
            if (c==k->data) {
                dem++;
            }
        }
        a[0][j]=dem;
        a[1][j]=i->data;
        j++;
    }
    int h;
    int max=a[0][0];
    for (int g=1; g<n; g++) {
        if (a[0][g]>max) {
            max=a[0][g];
            h=g;
        }
    }
    for (int g=0; g<1; g++) {
        for (int f=0; f<n; f++) {
            if (max==a[g][f]) {
                if (h!=f) {
                    if (a[1][f]!=a[1][f+1]) {
                        cout <<a[1][f]<<"\t";
                    }
                }
            }
        }
    }
}

int KiemTraDanhSachDoiXung (List l, List a) {
    int c=0;
    for (NODE* i=l.phead; i!=NULL; i=i->pnext) {
        int b=0;
        c++;
        for (NODE* j=a.phead; j!=NULL; j=j->pnext) {
            b++;
            if (c==b) {
                if (i->data!=j->data) {
                    return 0;
                }
            }
        }
    }
    return 1;   
}

void HoanVi (char &x, char &y) {
    char t=x;
    x=y; 
    y=t;
}

void SapXepTangDan (LIST &l) {
    for (NODE* i=l.phead; i!=l.ptail; i=i->pnext) {
        for (NODE* j=i->pnext; j!=NULL; j=j->pnext) {
            if (i->data>j->data) {
                HoanVi(i->data,j->data);
            }
        }
    }     
}

int TimViTriCanThem (LIST l, char x) {
    int dem=1;
    for (NODE* k=l.phead; k!=NULL; k=k->pnext) {
        if (k==l.ptail) {
            return dem+1;
        } else if (k==l.phead) {
            if (x<=k->data) {
                return dem;
            }
        } else {
            if (k->data<=x&&k->pnext->data>=x) {
                break;
            } else if (k->data>x&&k->ppre->data<x) {
                return dem;
            }
        }
        dem++;
    }
    return dem+1;
}

int TimMax (LIST l) {
    char max=l.phead->data;
    for (NODE* k=l.phead->pnext; k!=NULL; k=k->pnext) {
        if (k->data>max) {
            max=k->data;
        }
    }
    return max;
}

int TimMin (LIST l) {
    char min=l.phead->data;
    for (NODE* k=l.phead->pnext; k!=NULL; k=k->pnext) {
        if (k->data<min) {
            min=k->data;
        }
    }
    return min;
}

void XoaNodeCoGiaTriLonNhat (LIST &l) {
    if (l.phead==NULL) {
        return;
    }
    NODE* p=l.phead;
    NODE* q=l.phead;
    int d=TimMax(l);
    while (p!=NULL) {
        if (p->data==d) {
            NODE* r=p;
            if (p==l.phead) {
                l.phead=l.phead->pnext;
                p=l.phead;
                q=l.phead;
            } else {
                q->pnext=p->pnext;
                p=p->pnext;
            }
            delete r;
            continue;
        }
        q=p;
        p=p->pnext;
    }
}

void XoaNodeCoGiaTriNhoNhat (LIST &l) {
    if (l.phead==NULL) {
        return;
    }
    NODE* p=l.phead;
    NODE* q=l.phead;
    int d=TimMin(l);
    while (p!=NULL) {
        if (p->data==d) {
            NODE* r=p;
            if (p==l.phead) {
                l.phead=l.phead->pnext;
                p=l.phead;
                q=l.phead;
            } else {
                q->pnext=p->pnext;
                p=p->pnext;
            }
            delete r;
            continue;
        }
        q=p;
        p=p->pnext;
    }
}

int main () {
    LIST l,m;
    CreateList(l);
    CreateList(m);
    int n;
    cout <<"\nNhap so node: ";
    cin >>n;
    AddNodeToList(l,m,n);
    cout <<endl;
    cout <<"\nCac node xuat hien nhieu nhat trong danh sach: ";
    DemTatCaCacNodeXuatHienNhieuNhat(l);
    if (KiemTraDanhSachDoiXung(l,m)==1) {
        cout <<"\nDanh sach tren la danh sach doi xung";
    } else {
        cout <<"\nDanh sach tren khong la danh sach doi xung";
    }
    SapXepTangDan(l);
    cout <<"\n\t\tDANH SACH TANG DAN THEO ALPHABET  \n";
    PrintList(l);
    char x;
    cout <<"\nNhap gia tri node can them: ";
    cin >>x;
    cout <<"\nVi tri can them 1 node sao cho danh sach van co thu tu tang dan theo alphabet: "<<TimViTriCanThem(l,x);
    XoaNodeCoGiaTriLonNhat(l);
    XoaNodeCoGiaTriNhoNhat(l);
    cout <<"\n\tDANH SACH SAU KHI XOA CAC NODE CO GIA TRI INFO LON NHAT VA NHO NHAT\n";
    PrintList(l);
    cout <<endl;
    system("pause");
    system("cls");
    return 0;
}