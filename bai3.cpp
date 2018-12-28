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
void DocFile(int a[10][10],int n)
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		fi>>a[i][j];
		fi.close();
}

void XuatDt(int a[10][10],int n){

		for(int i = 0; i < n; i++)
		  {
		  for(int j = 0; j < n; j++)
		  cout<<a[i][j]<<" ";
		  cout<<endl;
		  }
}
void TaoMoi(int a[10][10],int &n){
	cout<<"nhap n..";
	cin>>n;
	fi.open("duongdi.txt",ios::out);
	fi<<n<<endl;
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

