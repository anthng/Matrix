//@IDE: Codelite
//@Date: 24/05/2019
//@Author: An Nguyen

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <bits/stdc++.h> 

using namespace std;

template <class T>
class Matrix
{
private:
	size_t rows;
	size_t cols;
	vector< vector<T> > mat;
public:
	//ctor
	Matrix();
	Matrix(size_t _rows, size_t _cols);
	Matrix(size_t _rows, size_t _cols, const T &_init);
	Matrix(vector< vector<T> > const &_mat);
	//cp ctor;
	Matrix(const Matrix<T> &rhs);
	
	//assign
	Matrix<T>& operator=(const Matrix<T> &rhs);
	T& operator()(const size_t &_rows, const size_t &_cols);
	const T& operator()(const size_t &_rows, const size_t &_cols) const;
																					
	//This is operators between matrix and matrix;                                        
	Matrix<T> operator+(const Matrix<T> &rhs);
	Matrix<T>& operator+=(const Matrix<T> &rhs);
	
	Matrix<T> operator-(const Matrix<T> &rhs);
	Matrix<T>& operator-=(const Matrix<T> &rhs);
	
	Matrix<T> operator*(const Matrix<T> &rhs);
	Matrix<T>& operator*=(const Matrix<T> &rhs);
	
	//This is operators between matrix and scalar
	Matrix<T> operator+(const T& rhs);
	Matrix<T> operator-(const T &rhs);
	Matrix<T> operator*(const T &rhs);
	Matrix<T> operator/(const T &rhs);

	//Mutiply a matrix with a vector
	vector<T> operator*(const vector<T> &rhs);
	
	//Find the maximum position in this matrix;
	void Maximum();
 
	void fill(const T& val);
	void input(size_t _rows, size_t _cols);
	void print() const;
	size_t getRows() const;
	size_t getCols() const;
	
	//dtor
	virtual ~Matrix();


};

#endif // MATRIX_H
