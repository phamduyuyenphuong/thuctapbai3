/*To chuc du lieu va giai bai toan tim duong di ngan nhat cua mot do thi vo huong
tao moi do thi , luu do thi vao file
mo do thi tu file da co
tim duong di ngan nhat, ket qua tim duoc luu vao mot file
xuat lan luot qua trinh tim ra duong di lon nhat */
#include<iostream>
#include<fstream>
#include<vector>
#define MAX 50 
#define TRUE 1 
#define FALSE  0
#define VOCUNG 10000000
using namespace std;
int n;
//tao moi do thi , luu do thi vao file
fstream fi;
void TaoMoi(int a[10][10],int &n);

void DocFile(int a[10][10],int n);

void XuatDt(int a[10][10],int n);
 void TimDuong();
void Result();

int s;//dinh dau
int t;//dinh cuoi
char chon;
int truoc[MAX];//mang danh dau duong di
int d[MAX];//mang danh dau khoang cach
int c[MAX][MAX];//ma tran trong so
int chuaxet[MAX];//mang sanh dau dinhr da duoc gan nha dan
int main()
{
	fflush(stdin);
	int n;// so dinh cua do thi
	int a[10][10];
	TaoMoi(a,n);
	fi.open("duongdi.txt",ios::in);
	fi>>n;
	DocFile(a,n);
	XuatDt(a,n);
	 TimDuong();
 Result();
	

}
void DocFile(int a[10][10],int n)//doc file da luu
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		fi>>a[i][j];
		fi.close();
}

void XuatDt(int a[10][10],int n){// xuat file ra

		for(int i = 0; i < n; i++)
		  {
		  for(int j = 0; j < n; j++)
		  cout<<a[i][j]<<" ";
		  cout<<endl;
		  }
}
void TaoMoi(int a[10][10],int &n){// cap nhat do thi moi
	cout<<"nhap n..";// nhap dinh cua do thi
	cin>>n;
	fi.open("duongdi.txt",ios::out);// mo file duongdi.txt de ghi
	fi<<n<<endl; // in so dinh vao
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			{
			cout<<"trong so "<<i<<"den "<<j<<":";
			cin>>a[i][j];
			fi<<a[i][j]<<" ";
			}
		fi<<endl;
		}
	fi.close();
}
////tim duong di ngan nhat, ket qua tim duoc luu vao mot file
struct  cap{
	int Dinh;
	int tong;
};
/*tao struct cap{Dinh,Tong}
tao mot vector luu lai cac dinh da qua(de xet trong qua trinh xu li)
Tao mot bien char kieu cap
gan 1 dinh dau tien A vao char
so sanh de tim ra duong di ngan nhat tu A toi diem tiep theo chua duoc chon
xet cac dinh chua duoc chon
kiem tra xem co duong di tu dinh duoc chon toi cac dinh con lai
neu co duong di -> gan dinh dang xet
 cho tong =c.tong +a[i][c.dinh]
nguoc lai chon tong=0;
kiem tra lan luot cac phan tu trong vector
chon ra phan tu co tong nho nhat tru i=0 dua vao dschon*/
void Result(){
 cout<<"Duong di ngan nhat tu "<<(char)(s+'A'-1)<<" den "<<(char)(t + 'A' -1)<< " la"<<endl;
 cout<<(char)(t + 'A' - 1)<<"<=";//in dinh cuoi duoi (dang char)
 int i = truoc[t];
 while (i != s){
  cout<<(char)(i +'A' -1)<<"<=";//in in ra ket qua(dang char)
  i = truoc[i];
 }
 cout<<(char)(s+'A' -1);//in dinh dau (dang char).
 cout<<endl<<"Do dai duong di la : "<< d[t];
}
void TimDuong (){
 int u, minp;
 //khoi tao nhan dan tam thoi cho cac dinh
 for (int v = 1; v <= n; v++){
  d[v] = a[s][v];
  truoc[v] = s;
  chuaxet[v] = FALSE;
 }
 truoc[s] = 0;
 d[s] = 0;
 chuaxet[s] = TRUE;
 //buoc lap
 while (!chuaxet[t]) {
  minp = VOCUNG;
  //tìm dinh u sao cho d[u] nho nhat
  for (int v = 1; v <= n; v++){
   if ((!chuaxet[v]) && (minp > d[v])){
    u = v;
    minp = d[v];
   }
  }
  chuaxet[u] = TRUE;// u la dinh co nhan tam thoi nho nhat 
  if (!chuaxet[t]){
   //gan nhan lai cho cac dinh
   for (int v = 1; v <= n; v++){
    if ((!chuaxet[v]) && (d[u] + a[u][v] < d[v])){
     d[v] = d[u] + a[u][v];
     truoc[v] = u;
    }
   }
  }
 }
}


