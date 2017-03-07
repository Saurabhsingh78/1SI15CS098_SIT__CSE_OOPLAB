#include<iostream>
using namespace std;

class matrix
{
	int a[20][20],row,col;
	public:
		matrix(){}
		matrix(int a,int b)
		{
			row=a;   col=b;
		}
		void read_mat();
		matrix operator+(matrix m2);
		matrix operator-(matrix m2);
		int operator==(matrix m2);
		friend ostream& operator<<(ostream &,matrix);
};
void matrix::read_mat()
{
	cout<<"enter the matrix elements"<<endl;
	for(int i=0;i<row;i++)
	for(int j=0;j<col;j++)
		cin>>a[i][j];
}
int matrix::operator==(matrix m2)	//m1==m2	m1.operator==(m2)
{
	if(row==m2.row && col==m2.col)	return 1;
	return 0;
}
matrix matrix::operator+(matrix m2)
{
	matrix m3(row,col);
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			m3.a[i][j]=a[i][j]+m2.a[i][j];
return m3;
}
matrix matrix::operator-(matrix m2)
{
	matrix m3(row,col);
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			m3.a[i][j]=a[i][j]-m2.a[i][j];
return m3;
}
ostream& operator<<(ostream& out,matrix m)	//cout << m1 << m2;	operator<<(cout,m1);
{
	for(int i=0;i<m.row;i++)
	{
		for(int j=0;j<m.col;j++)
			out<<m.a[i][j]<<"\t";
		out<<endl;
	}
return out;
}
int main(void)
{
	int m,n,p,q,x;
/*
	x = x << 1;
	cout << x;
	cout << m1;*/
	cout<<"enter the order of mat1"<<endl;
	cin>>m>>n;
	matrix m1(m,n);
	cout<<"enter the order of mat2"<<endl;
	cin>>p>>q;
	matrix m2(p,q);
	if(m1==m2)
	{
		m1.read_mat();
		m2.read_mat();

		matrix m3=m1+m2;
		cout<<"addition of "<<endl<<m1<<endl<<"and"<<endl<<m2<<
					       "______________"<<endl<<m3<<endl;
		matrix m4=m1-m2;
		cout<<"subtraction of "<<endl<< m1<<"and"<<endl<< m2<<
			"______________"<<endl<<m4<<endl;
	}
	else
		cout<<"matrices cannot be added/subtracted"<<endl;

    return 0;

}


