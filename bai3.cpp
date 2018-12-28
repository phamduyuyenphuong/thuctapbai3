//To chuc du lieu va giai bai toan tim duong di ngan nhat cua mot do thi vo huong
//tao moi do thi , luu do thi vao file
//mo do thi tu file da co
//tim duong di ngan nhat, ket qua tim duoc luu vao mot file
//xuat lan luot qua trinh tim ra duong di lon nhat 
#include<iostream>
#include<fstream>
using namespace std;
int n;
//tao moi do thi , luu do thi vao file
fstream fi;
void TaoMoi(int a[10][10],int &n);

void DocFile(int a[10][10],int n);

void XuatDt(int a[10][10],int n);


int main()
{
	fflush(stdin);
	int n;
	int a[10][10];
	TaoMoi(a,n);
	fi.open("duongdi.txt",ios::in);
	fi>>n;
	DocFile(a,n);
	XuatDt(a,n);
	

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
//tao mot vector luu lai cac dinh da qua
// gan 1 dinh dau tien A 
// tim duong di tuw A den cac dinh khac
//so sanh de tim duong di ngan nhat tu A den x
//tong1 =0
//tim trong vector cac dinh chua duoc goi
