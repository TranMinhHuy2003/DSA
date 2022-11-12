#include <iostream>
#include <math.h>
using namespace std;
                    //BÀI TẬP ÁP DỤNG DANH SÁCH LIÊN KẾT ĐƠN
/* Tạo cấu trúc dữ liệu cho danh sách liên kết đơn */
struct Node
{
    int x;
    int i;
    Node* pNext;
};
struct List
{
    Node* pHead;
    Node* pTail;
};
/* Khởi tạo cho pHead và pTail */
void CreatList(List& l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}
/* Tạo Node */
Node* CreateNode(int x, int i)
{
    Node* p = new Node;
    if (p == NULL)
    {
        cout << "Loi cap phat bo nho";
        exit(0);
    }
    p->i = i;
    p->x = x;
    p->pNext = NULL;
    return p;
}
/* insertlast */
void InsertLast(List& l, int x, int i)
{
    Node* p = CreateNode(x, i);
    if (l.pTail == NULL)
        l.pHead = l.pTail = p;
    else
    {
        l.pTail->pNext = p;
       l.pTail = p;
    }
}
/*printlist*/
void PrintList(List& l)
{
    Node* tam = l.pHead;
    while (tam != NULL)
    {
        if (tam->pNext != NULL)
            cout << tam->x << "^" << tam->i << "+";
        else
            cout << tam->x << "^" << tam->i;
        tam = tam->pNext;
    }
}
/* Hàm tính tổng */
double SumOfList(List& l)
{
    double sum = 0;
    for (Node* tam = l.pHead; tam != NULL; tam = tam->pNext)
    {
        double value = pow(tam->x, tam->i);
        sum += value;
    }
    return sum;
}

                    //BÀI TẬP ÁP DỤNG DANH SÁCH LIÊN KẾT KÉP

struct  hocsinh
{
    char hoten [30];
    float namsinh;
};

struct NODE
{
    hocsinh info ;
    NODE* next ;
    NODE* prev;   
};

struct LIST
{
    NODE* head;
    NODE* tail;
};

void CreateEmptyList(LIST &l)
{
    l.head = NULL;
    l.tail = NULL;
}
NODE* CreateNode(hocsinh x)
{
    NODE* p = new NODE;
    if(p == NULL) exit(1);
    p->info = x;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

// Nhập thông tin cho 1 phần tử
NODE* _input ()
{
    NODE* q = new  NODE;
    cout << "\nHo ten : ";
    
  cin>>q->info.hoten;
   cout<< "Nhap nam sinh : ";
  cin>> q->info.namsinh;
    q->next = q->prev = NULL ;
    return q;
}

//  Bổ sung 1 phần tử vào cuối danh sách 
void AddTail(LIST &l) 
{
    NODE *new_else = _input () ;  // Nhập thông tin 1 ptu mới 
    if ( l.head == NULL ) // Kiểm tra DS rỗng
    {
    //Nếu rỗng thì
    //head = new_ele;
    //tail = head;
        l.head = l.tail = new_else; 
    }
    else
    {
        //Ngược lại
        //tail = new_ele->prev;
        //tail->next = new_ele;
        //tail = new_ele;
        new_else->prev = l.tail ;
        l.tail->next = new_else;                 
        l.tail = new_else;
    }
}

// In ra danh sách học sinh có nam sinh từ 1980 trở về dây 
void Process(LIST l)
{
    NODE* p = l.head; // con trỏ trỏ tới ptu đầu tiên của danh sách
    if(l.head == NULL) //Kiểm tra DS rỗng
        cout << "\nDanh sach rong !!! " ;
    cout <<"\n\n============================================\n";
    cout << "\nDanh sach nhung nguoi sinh sau nam 1980 : \n  " ;
    while(p->next != NULL)
    {
        if (p->info.namsinh > 1980)
        //Trong khi (p!=NULL)& ( p -> info.ns > 1980 ) 
        //Th?c hi?n:
        //Xu?t ra thông tin p
        //p = p->next;
        {
            cout << "\nHo ten : " << p->info.hoten;
            cout << "\nNam sinh :" << p->info.namsinh;
            cout << "\n";
        }
        p = p->next;
    }
}

//Xóa  thông tin học sinh cuối danh sách
void DeleteTail(LIST  &l)
{
    NODE* p;
    if(l.tail != NULL) // Nếu danh sách khác rỗng
    {
        l.tail = p; //p là phần tử cần hủy
        //Tách p ra khỏi xâu
        l.tail = l.tail->prev ;
        l.tail->next = NULL ;
        delete  p ; //Hủy biến do p trỏ đến
        if (l.head == NULL )
            //Nếu nút dầu là rỗng thì nút cuối rỗng
            l.tail = NULL ;
        else
        //nguợc lại head->prev = NULL;
            l.head -> prev = NULL ;
    }
}

int main() {
    //BÀI TẬP ÁP DỤNG DANH SÁCH LIÊN KẾT ĐƠN
    List l;
    CreatList(l);
    int n, x;
    cout << "Nhap n:";
    cin >> n;
    cout << "Nhap x:";
    cin >> x;
    for (int i = 1; i <= n; i++)
    {
        InsertLast(l, x, i);
    }
    cout << "Danh sach lien ket don: \n";
    PrintList(l);
    double sum = SumOfList(l);
    cout << "\nTong cac phan tu trong danh sach: " << sum;

    cout << "\n----------------------------\n";

    //BÀI TẬP ÁP DỤNG DANH SÁCH LIÊN KẾT KÉP
    LIST a;
    CreateEmptyList(a);
    int  z = 1;
    cout << "\nThem 1 phan tu vao cuoi danh sach ";
    while (z == 1)
    {
        AddTail(a) ;
        cout << "Tiep tuc nhap ? ( 1 / 0 ) : " ;
        cin >> z ;
    }
    Process(a) ;
    return 0;
}