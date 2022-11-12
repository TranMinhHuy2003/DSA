#include <bits/stdc++.h>
using namespace std;

                    //BALANCING ACT

// Khai báo node cho DSLK

struct Node
{
    int data;
    Node* link;
};

Node* top;

//Thêm 1 phần tử vào ngăn xếp
void push(int data)
{

    // Tạo 1 Node mới và cấp phát bộ nhớ
    Node* temp = new Node();

    // Kiểm tra xem Node có đầy hay không
    if (!temp)
    {
        cout << "\nStack Overflow";
        exit(1);
    }

    // Khởi tạo dữ liệu vào dữ liệu tạm thời
    temp->data = data;

    // Đặt tham chiếu con trỏ trên cùng vào liên kết tạm thời
    temp->link = top;

    // Tạo temp = top của Stack
    top = temp;
}

// Utility function to check if
// the stack is empty or not
int isEmpty()
{
    //Nếu top là NULL thì DS trống,không có phần tử nào trong DS
    return top == NULL;
}

// Trả về phần tử trên cùng của Stack
int peek()
{

    // Nếu Stack không rỗng, trả về phần tử trên cùng
    if (!isEmpty())
        return top->data;
    else
        exit(1);
}

// Utility function to pop top
// element from the stack
void pop()
{
    Node* temp;

    // Kiểm tra xem danh sách có rỗng hay không
    if (top == NULL)
    {
        cout << "\nStack Underflow" << endl;
        exit(1);
    }
    else
    {

        // Gán top cho biến tạm
        temp = top;

        // Gán node thứ 2 lên trên cùng
        top = top->link;

        // liên kết giữa nút đầu tiên và nút thứ hai

        // Giải phóng bộ nhớ của nút trên cùng
        free(temp);
    }
}

//Tạo ra 1 hàm xuất kết quả ra màn hình
void display()
{
    Node* temp;

    // Kiểm tra danh sách có trống hay không
    if (top == NULL)
    {
        cout << "\nStack Underflow";
        exit(1);
    }
    else
    {
        temp = top;
        while (temp != NULL)
        {

            // Xuát giá trị
            cout << temp->data << "-> ";

            // Gán địa chỉ cho biến tạm
            temp = temp->link;
        }
    }
}
void BalancingAct(string &s){
    cin>>s;
    int mo=0;
    int dong=0;
    int n=s.size()-1;
    for(int i=0; i<=n; ++i){
        if(s[i]=='(' || s[i]=='{' || s[i]=='[') mo++;
        if(s[i]==')' || s[i]=='}' || s[i]==']') dong++;
    }
    if(mo!=dong){
        cout<<"FALSE";
        exit(0);
    }
    for(int i=0; i<=n; ++i){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
        push(s[i]);
        }
        if(s[i]==')' && top->data=='(') pop();
        if(s[i]==']' && top->data=='[') pop();
        if(s[i]=='}' && top->data=='{') pop();
    }
    if(isEmpty()) cout<<"TRUE";
    else cout<<"FALSE";
}

                    //ĐẢO TỪ TRONG CHUỖI

struct SNode {
    string data;
    struct SNode* pnext;
};
typedef struct SNode SNODE;

struct SList {
    SNODE* phead;
    SNODE* ptail;
};
typedef struct SList SLIST;

void CreateSList (SLIST &sl) {
    sl.phead=sl.ptail=NULL;
}

SNODE* CreateSNode (string x) {
    SNODE* p=new SNODE;
    if (p==NULL) {
        return NULL;
    } else {
        p->data=x;
        p->pnext=NULL;
    }
    return p;
}

void spush (SLIST &sl, SNODE* p) {
    if (sl.phead==NULL) {
        sl.phead=sl.ptail=p;
    } else {
        p->pnext=sl.phead;
        sl.phead=p;
    }
}

int spop (SLIST &sl, string &x) {
    SNODE* p;
    if (sl.phead!=NULL) {
        x=sl.phead->data;
        p=sl.phead;
        sl.phead=sl.phead->pnext;
        if (sl.phead==NULL) {
            sl.ptail=NULL;
        }
        delete p;
        return 1;
    }
    return 0;
}

void reverseString(string x) //Đảo chuỗi: thực hiện đảo từ trong chuỗi
{
    SLIST stack;
    CreateSList(stack);
	string s,a[50];
    x+=" ";
    int k=0,length=x.length();
    for (int i=0; i<length; i++) {
        if(x[i]!=' ') {
            s.push_back(x[i]);
        }
        if (x[i]!=' '&&x[i+1]==' ') {
            spush(stack,CreateSNode(s));
            k++;
            s="";
        }
    }
    for (int i=0; i<k; i++) {
        string b;
        spop(stack,b);
        if (i==k-1) {
            cout <<b;
        } else {
            cout <<b<<" ";
        }
    }
}

                    //CHUYỂN ĐỔI HỆ THẬP PHÂN SANG NHỊ PHÂN

struct INode {
    int data;
    struct INode* pnext;
};
typedef struct INode INODE;

struct IList {
    INODE* phead;
    INODE* ptail;
};
typedef struct IList ILIST;

void CreateIList (ILIST &il) {
    il.phead=il.ptail=NULL;
}

INODE* CreateINode (int x) {
    INODE* p=new INODE;
    if (p==NULL) {
        return NULL;
    } else {
        p->data=x;
        p->pnext=NULL;
    }
    return p;
}

void ipush (ILIST &il, INODE* p) {
    if (il.phead==NULL) {
        il.phead=il.ptail=p;
    } else {
        p->pnext=il.phead;
        il.phead=p;
    }
}

int ipop (ILIST &il, int &x) {
    INODE* p;
    if (il.phead!=NULL) {
        x=il.phead->data;
        p=il.phead;
        il.phead=il.phead->pnext;
        if (il.phead==NULL) {
            il.ptail=NULL;
        }
        delete p;
        return 1;
    }
    return 0;
}

void ChuyenDoiCoSo (int n) {  //Chuyển đổi hệ 10 sang hệ nhị phân
    ILIST stack;
    int t,dem=0;
    while (n!=0)
    {
        t=n%2;
        n=n/2;
        ipush(stack,CreateINode(t));
        dem++;
    }
    for (int i=0; i<dem; i++) {
        int x;
        ipop(stack,x);
        cout <<x;
    }
}

int main()
{ 
    //BALANCING ACT
    string s;
    BalancingAct(s);


    //ĐẢO TỪ TRONG CHUỖI
    string b="Lan di hoc";
    cout <<"\n\t\t======DAO TU TRONG CHUOI======\n";
    reverseString(b);

    //CHUYỂN ĐỔI HỆ THẬP PHÂN SANG NHỊ PHÂN
    cout <<"\n\t\t=====CHUYEN HE THAP PHAN SANG NHI PHAN=====\n";
    ChuyenDoiCoSo(8);
    return 0;
}