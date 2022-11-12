#include <iostream>
#include <cmath>
using namespace std;

struct node {
    int info;
    struct node* pnext;
};
typedef struct node NODE;

struct list {
    NODE* phead;
    NODE* ptail;
};
typedef struct list List;

void TaoDanhSach (List &l) {
    l.phead=NULL;
    l.ptail=NULL;
}

NODE* TaoNode (int x) {
    NODE* p=new NODE;
    if (p==NULL) {
        exit(1);
    }
    p->info=x;
    p->pnext=NULL;
    return p;
}

void ThemDau (List &l, NODE* p) {
    if (l.phead==NULL) {
        l.phead=p;
        l.ptail=p;
    } else {
        p->pnext=l.phead;
        l.phead=p;
    }
}

void ThemCuoi (List &l, NODE* p) {
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
        if (KTSNT(k->info)==true) {
            dem++;
        }
    }
    return dem;
}

void InGiaTriNodeOViTriLe (List l) {
    int dem=1;
    for (NODE* k=l.phead; k!=NULL; k=k->pnext) {
        if (dem%2!=0) {
            cout<<k->info<<" ";
        }
        dem++;
    }
}

void InGiaTriNodeXuatHienDung1Lan (List l) {
    NODE* i,*j;
    int k;
    for (i=l.phead; i!=NULL; i=i->pnext) {
        for (j=l.phead; j!=NULL; j=j->pnext) {
            if (i->info==j->info&&i!=j) {
                k=0;
                break;
            } else {
                k=1;
            }
        }
        if (k==1) {
            cout <<i->info<<" ";
        }
    }
}

bool KiemTraSoChan (List l) {
    for (NODE* k=l.phead; k!=NULL; k=k->pnext) {
        if (k->info%2!=0) {
            return false;
        }
    }
    return true;
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

int KiemTraDanhSachDoiXung (List l, List a) {
    int c=0;
    for (NODE* i=l.phead; i!=NULL; i=i->pnext) {
        int b=0;
        c++;
        for (NODE* j=a.phead; j!=NULL; j=j->pnext) {
            b++;
            if (c==b) {
                if (i->info!=j->info) {
                    return 0;
                }
            }
        }
    }
    return 1;   
}

void TimNodeLaSoTang (List l) {
    for (NODE* k=l.phead; k!=NULL; k=k->pnext) {
        if (KiemTraSoTang(k->info)==1) {
            cout <<k->info<<" ";
        }
    }
}

int TimNodeLonNhat (List l) {
    int max=l.phead->info;
    for (NODE* k=l.phead->pnext; k!=NULL; k=k->pnext) {
        if (k->info>max) {
            max=k->info;
        }
    }
    return max;
}

int TimNodeNhoNhat (List l) {
    int min=l.phead->info;
    for (NODE* k=l.phead->pnext; k!=NULL; k=k->pnext) {
        if (k->info<min) {
            min=k->info;
        }
    }
    return min;
}

void XoaNodeCoInfoLaX(List &l, int x) {
    NODE* p=l.phead;
    NODE* q=l.phead;
    while (p!=NULL) {
        if (p->info==x) {
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

void PrintList (List l) {
    for (NODE* k=l.phead; k!=NULL; k=k->pnext) {
        cout <<k->info<<" ";
    }
}

int main () {
    List l;
    List a;
    int n;
    cout <<"\nNhap so luong can them: ";
    cin>>n;
    TaoDanhSach(l);
    TaoDanhSach(a);
    for (int i=1; i<=n; i++) {
        int x;
        cout <<"\nNhap info NODE "<<i<<": ";
        cin>>x;
        NODE* p=TaoNode(x);
        NODE* q=TaoNode(x);
        ThemCuoi (l,p);
        ThemDau (a,q);
    }
    cout <<"\nCo "<<DemNodeSoNguyenTo(l)<<" NODE co info la so nguyen to";
    cout <<"\nGia tri info cac NODE o vi tri le trong danh sach la: ";
    InGiaTriNodeOViTriLe (l);
    cout <<"\nGia tri info cac NODE xuat hien dung 1 lan: ";
    InGiaTriNodeXuatHienDung1Lan(l);
    if (KiemTraSoChan(l)) {
        cout <<"\nDanh sach L chua toan so chan";
    } else {
        cout <<"\nDanh sach L khong chua toan so chan";
    }
    if (KiemTraDanhSachDoiXung(l,a)==1) {
        cout <<"\nDanh sach tren la danh sach doi xung";
    } else {
        cout <<"\nDanh sach tren khong la danh sach doi xung";
    }
    cout <<"\nCac NODE co gia tri info la so tang la: ";
    TimNodeLaSoTang(l);
    cout <<"\nCac NODE co gia tri info lon nhat la: "<<TimNodeLonNhat(l);
    cout <<"\nCac NODE co gia tri info nho nhat la: "<<TimNodeNhoNhat(l);
    int x;
    cout <<"\nNhap gia tri info NODE muon xoa: ";
    cin >>x;
    XoaNodeCoInfoLaX(l,x);
    cout <<"\n\t\tDanh sach sau khi xoa\n";
    PrintList(l);
    system("pause");
    system("cls");
    return 0;
} 