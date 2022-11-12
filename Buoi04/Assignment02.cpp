#include <iostream>
using namespace std;

struct CongNhan {
    char macongnhan[50];
    char tencongnhan[100];
    int namsinh;
    int sosanpham;
};
typedef struct CongNhan CONGNHAN;

struct Node {
    CONGNHAN data;
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

NODE* CreateNode (CONGNHAN a) {
    NODE* p=new NODE;
    if (p==NULL) {
        return NULL;
    } 
    p->data=a;
    p->pnext=NULL;
    p->ppre=NULL;
    return p;
}

void Nhap1CongNhan (CONGNHAN &a) {
    cin.ignore();
    cout <<"\nNhap ma cong nhan: ";
    cin.getline(a.macongnhan,50);
    cout <<"\nNhap ten cong nhan: ";
    cin.getline(a.tencongnhan,100);
    cout <<"\nNhap nam sinh: ";
    cin >>a.namsinh;
    cout <<"\nNhap so san pham may: ";
    cin>>a.sosanpham;
}

void Xuat1CongNhan (CONGNHAN a) {
    cout <<"\nMa so cong nhan: "<<a.macongnhan;
    cout <<"\nTen cong nhan: "<<a.tencongnhan;
    cout <<"\nNam sinh: "<<a.namsinh;
    cout <<"\nSo san pham may: "<<a.sosanpham;
}

void AddHead (LIST &l, NODE* p) {
    if (l.phead==NULL) {
        l.phead=p;
        l.ptail=p;
    } else {
        p->pnext=l.phead;
        l.phead->ppre=p;
        l.phead=p;
    }
}

void AddTail (LIST &l, NODE* p) {
    if (l.phead==NULL) {
        l.phead=p;
        l.ptail=p;
    } else {
        l.ptail->pnext=p;
        p->ppre=l.ptail;
        l.ptail=p;
    }
}

void AddNodeToList (LIST &l, int n) {
    for (int i=0; i<n; i++) {
        CONGNHAN a;
        cout <<"\n\t\tNHAP CONG NHAN THU "<<i+1<<endl;
        Nhap1CongNhan(a);
        AddTail(l,CreateNode(a));
    }
}

void PrintList (LIST l) {
    int i=1;
    for (NODE* k=l.phead; k!=NULL; k=k->pnext) {
        cout <<"\n\t\tTHONG TIN CONG NHAN THU "<<i;
        Xuat1CongNhan(k->data);
        i++;
    }
}

void InThongTinCongNhanCoSanPhamMayNhieuNhat (LIST l) {
    NODE* max=l.phead;
    for (NODE* k=l.phead->pnext; k!=NULL; k=k->pnext) {
        if (k->data.sosanpham>max->data.sosanpham) {
            max=k;
        }
    }
    Xuat1CongNhan(max->data);
}

int TinhTuoi (int x) {
    return 2022-x;
}

int ThongKeDuoi30 (LIST l) {
    int dem=0;
    for (NODE* k=l.phead; k!=NULL; k=k->pnext) {
        if (TinhTuoi(k->data.namsinh)<30) {
            dem++;
        }
    }
    return dem;
}

int ThongKeTu30Den50 (LIST l) {
    int dem=0;
    for (NODE* k=l.phead; k!=NULL; k=k->pnext) {
        if (TinhTuoi(k->data.namsinh)>=30&&TinhTuoi(k->data.namsinh)<=50) {
            dem++;
        }
    }
    return dem;
}

void HoanVi (CONGNHAN &a, CONGNHAN &b) {
    CONGNHAN t=a;
    a=b;
    b=t;
}

void SapXepDanhSachGiamDanTheoSoSanPhamMay (LIST &l) {
    for (NODE* i=l.phead; i!=l.ptail; i=i->pnext) {
        for (NODE* j=i->pnext; j!=NULL; j=j->pnext) {
            if (j->data.sosanpham>i->data.sosanpham) {
                HoanVi(i->data,j->data);
            }
        }
    }
}

int main () {
    LIST l;
    CreateList(l);
    int n;
    cout <<"\nNhap so luong cong nhan: ";
    cin >>n;
    AddNodeToList(l,n);
    cout <<"-----------------------------------------------------------";
    PrintList(l);
    cout <<"\n\t\tTHONG TIN CONG NHAN CO SO SAN PHAM MAY NHIEU NHAT";
    InThongTinCongNhanCoSanPhamMayNhieuNhat(l);
    cout <<"\n\t\tTHONG KE SO LUONG CONG NHAN THEO DO TUOI\n";
    cout <<"\n1. Duoi 30 tuoi: "<<ThongKeDuoi30(l)<<" cong nhan";
    cout <<"\n2. Tu 30 den 50 tuoi: "<<ThongKeTu30Den50(l)<<" cong nhan";
    cout <<"\n3. Tren 50 tuoi: "<<n-ThongKeDuoi30(l)-ThongKeTu30Den50(l)<<" cong nhan";
    cout <<"\n\t\tDANH SACH CONG NHAN GIAM DAN THEO SO SAN PHAM MAY\n";
    SapXepDanhSachGiamDanTheoSoSanPhamMay(l);
    PrintList(l);
    system("pause");
    system("cls");
    return 0;
}