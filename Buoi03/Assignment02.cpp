#include <iostream>
using namespace std;

struct Phongks {
    int sophong;
    char loaiphong;
    int tinhtrang;
};
typedef struct Phongks PHONGKS;

struct node {
    PHONGKS info;
    struct node* pnext;
};
typedef struct node NODE;

struct List {
    NODE* phead;
    NODE* ptail;
};
typedef struct List LIST;

void TaoList (LIST &l) {
    l.phead=NULL;
    l.ptail=NULL;
}

void Nhap1PhongKS (PHONGKS &ks) {
    cout <<"\nNhap so phong: ";
    cin >>ks.sophong;
    do {
        cout <<"\nNhap loai phong: ";
        cin >>ks.loaiphong;
        if (ks.loaiphong!='A'&&ks.loaiphong!='B') {
            cout <<"\nLoai phong chi duoc nhap A hoac B, vui long nhap lai!";
        }
    } while (ks.loaiphong!='A'&&ks.loaiphong!='B');
    do {
        cout <<"\nNhap tinh trang phong: ";
        cin >>ks.tinhtrang;
        if (ks.tinhtrang!=1&&ks.tinhtrang!=0) {
            cout <<"\nTinh trang phong chi duoc nhap 0 hoac 1, vui long nhap lai!";
        }
    } while (ks.tinhtrang!=1&&ks.tinhtrang!=0);
}

NODE* TaoNode (PHONGKS x) {
    NODE* p=new NODE;
    if (p==NULL) {
        exit (1);
    }
    p->info=x;
    p->pnext=NULL;
    return p;
}

void ThemCuoi (LIST &l, NODE* p) {
    if (l.phead==NULL) {
        l.phead=p;
        l.ptail=p;
    } else {
        l.ptail->pnext=p;
        l.ptail=p;
    }
}

void PrintList (LIST l, PHONGKS ks) {
        for (NODE* k=l.phead; k!=NULL ; k=k->pnext) {
            cout <<"\nSo phong: "<<k->info.sophong;
            if (k->info.tinhtrang==1) {
                cout <<"\nTinh trang: Da co khach";
            } else {
                cout <<"\nTinh trang: Con trong";
            }
            if (k->info.loaiphong=='A') {
                cout <<"\nLoai phong: phong don";
            } else {
                cout <<"\nLoai phong: phong doi";
            }
            cout <<endl;
        }
}

int ThongKeTinhTrang (LIST l) {
    int dacokhach;
    for (NODE*k =l.phead; k!=NULL; k=k->pnext) {
        if (k->info.tinhtrang==1) {
            dacokhach++;
        }
    }
    return dacokhach;
}

int ThongKeLoaiPhong (LIST l) {
    int phongdon;
    for (NODE*k =l.phead; k!=NULL; k=k->pnext) {
        if (k->info.loaiphong=='A') {
            phongdon++;
        }
    }
    return phongdon;
}

int TinhDoanhThu (LIST l) {
    int sum=0;
    for (NODE* k=l.phead; k!=NULL; k=k->pnext) {
        if (k->info.tinhtrang==1) {
            if (k->info.loaiphong=='A') {
                sum+=200;
            } else {
                sum+=350;
            }
        }
    }
    return sum;
}

void RemoveHead(LIST &l) {
    NODE *p;
    if (l.phead !=NULL) {
        p = l.phead;
        l.phead = l.phead->pnext;
        if (l.phead == NULL)
            l.ptail = NULL;
        delete p;
    }
} 

void RemoveAfterQ(LIST &l, NODE *Q) {
    NODE *p;
    if (Q != NULL) {
        p = Q->pnext; 
        if (p != NULL) { 
            if (p == l.ptail) 
                l.ptail = Q; 
            Q->pnext = p->pnext;
            delete p;
        }
    }
}

void RemoveX(LIST &l, int x) {
    NODE *Q, *p;
    Q = NULL;
    p = l.phead;
    while (p!=NULL && p->info.sophong!=x) {
        Q = p;
        p = p->pnext;
    }
    if (p == NULL) return; 
    if (Q != NULL) RemoveAfterQ(l, Q);
    else RemoveHead(l);
    return;
}



int main () {
    LIST l;
    PHONGKS ks;
    int n;
    cout <<"\nNhap so luong phong khach san: ";
    cin >>n;
    TaoList(l);
    for (int i=1; i<=n; i++) {
        cout <<"\n\t\tNHAP PHONG THU "<<i<<endl;
        Nhap1PhongKS(ks);
        NODE* p=TaoNode(ks);
        ThemCuoi(l,p);
    }
    cout <<"\n\t\tTHONG TIN CAC PHONG\n";
    PrintList(l,ks);
    cout <<"\nCo "<<ThongKeTinhTrang(l)<<" phong da co khach";
    cout <<"\nCo "<<n-ThongKeTinhTrang(l)<<" phong con trong";
    cout <<"\nCo "<<ThongKeLoaiPhong(l)<<" phong don";
    cout <<"\nCo "<<n-ThongKeLoaiPhong(l)<<" phong doi";
    cout <<"\nDoanh thu cua khach san trong 1 ngay la: "<<TinhDoanhThu(l)<<"(d)";
    int x;
    cout <<"\nNhap so phong cua phong can xoa: ";
    cin >>x;
    RemoveX(l,x);
    cout <<"\n\t\tTHONG TIN CAC PHONG SAU KHI XOA\n";
    PrintList(l,ks);
    system("pause");
    system("cls");
    return 0;
}