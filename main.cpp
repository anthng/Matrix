//@IDE: Codelite
//@Date: 24/05/2019
//@Author: An Nguyen

#include <Matrix.h>
#include <Matrix.cpp>
#include <iostream>

using namespace std;

int main() {
	cout << "Enter row and column: ";
	int m,n; cin>>m>>n;
	Matrix<double> mat1(2,2,3.3);
	Matrix<double> mat2(2,2,0.7);
	Matrix<double> mat(m,n);

	cout << "Enter value: ";
	mat.input(m,n);
	//mat.fill(68.3);
	cout << "\n\n Show matrix\n";
	//mat1.plus(3);
	mat.print();
	cout << "\n\n Show matrix + 3\n";
	mat += mat2;	
	mat.print();

	return 0;
}
