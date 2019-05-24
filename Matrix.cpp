//@IDE: Codelite
//@Date: 24/05/2019
//@Author: An Nguyen

#include <Matrix.h>

template <class T>
Matrix<T>::Matrix(){
    this->rows = 0;
    this->cols = 0;
}

template <class T>
Matrix<T>::Matrix(size_t _rows, size_t _cols){
    this->rows = _rows;
    this->cols = _cols;
	this->mat.resize(_rows);
	for(size_t i = 0; i<mat.size(); i++) {
		this->mat[i].resize(_cols, 0.0);
	}
}

template <class T>
Matrix<T>::Matrix(size_t _rows, size_t _cols, const T & _init ) {
	this->rows = _rows;
	this->cols = _cols;
	
	this->mat.resize(_rows);
	for(size_t i = 0; i<mat.size(); i++) {
		this->mat[i].resize(_cols, _init);
	}
}

template <class T>
Matrix<T>::Matrix(vector< vector<T> > const &_mat) {
	if(_mat.size() <= 0) {
		throw invalid_argument("Size of matrix must be greater than zero");
	}
	this->rows = _mat.size();
	this->cols = _mat[0].size();
	this->mat = _mat;
}

template <class T>
Matrix<T>::Matrix(const Matrix &rhs)
{
	this->rows = rhs.getRows();
    this->cols = rhs.getCols();
	this->mat = rhs.mat;
	cout << "This is a copy constructor" << endl;
}

template <class T>
void Matrix<T>::fill(const T& val){
    for(size_t i=0 ; i<this->rows ; i++){
        for(size_t j=0 ; j<this->cols ; j++){
            mat[i][j] = val	;
        }
    }
}

template <class T>
size_t Matrix<T>::getRows() const {
    return this->rows;
}

template <class T>
size_t Matrix<T>::getCols() const {
    return this->cols;
}

template <class T>
void Matrix<T>::input(size_t _rows, size_t _cols) {
	this->cols = _cols;
	this->rows = _rows;
	for(size_t i = 0; i < _rows; i++) {
		for(size_t j = 0; j < _cols; j++) {
			cout << "a[" << i << "]" <<"[" << j << "]: ";
			cin >> this->mat[i][j];
		}
	}
}

template <class T>
void Matrix<T>::print() const {
    cout << "Matrix: " << endl;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            cout << "[" << this->mat[i][j] << "] ";
        }
        cout << endl;
    }
}
//====================================End_Utils==========================================//


//===================================Operator_overloading===================================//
template<class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs) {
	if(&rhs == this)
		return *this;

	size_t newRows = rhs.getRows();
	size_t newCols = rhs.getCols();
	this->rows = newRows;
	this->cols = newCols;

	this->mat.resize(newRows);
	for(size_t i=0; i<mat.size(); i++) {
		this->mat[i].resize(newCols);
	}
	
	for(size_t i=0; i < newRows; i++) {
		for(size_t j=0; j < newCols; j++) {
			this->mat[i][j] = rhs(i, j);
		}
	}


	return *this;
}

template<class T>
T& Matrix<T>::operator()(const size_t &_rows, const size_t &_cols) {
  return this->mat[_rows][_cols];
}

// Access the individual elements (const)  
                                            
template<class T>
const T& Matrix<T>::operator()(const size_t &_rows, const size_t &_cols) const {
  return this->mat[_rows][_cols];
}


template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs) {
	Matrix res(this->rows, this->cols, 0.0);
	for(size_t i = 0; i < rows; i++) {
		for(size_t j = 0; j < cols; j++) {
			res(i,j) = this->mat[i][j] + rhs(i,j);
		}
	}
	return res;
}

template<class T>
Matrix<T>& Matrix<T>::operator +=(const Matrix<T>& rhs) {
	for(size_t i = 0; i < rhs.getRows(); i++) {
		for(size_t j = 0; j < rhs.getCols(); j++) {
			this->mat[i][j] = this->mat[i][j] + rhs(i,j);
		}
	}
	return *this;
}

template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& rhs) {
	Matrix res(this->rows, this->cols, 0.0);
	for(size_t i = 0; i < this.rows; i++) {
		for(size_t j = 0; j<this.cols; j++) {
			res(i,j) = this->mat[i][j] - rhs(i,j);
		}
	}
	return res;
}

template<class T>
Matrix<T>& Matrix<T>::operator -=(const Matrix<T>&rhs) {
	for(size_t i = 0; i<rhs.getRows(); i++) {
		for(size_t j = 0; j < rhs.getCols(); j++) {
			this->mat[i][j] -=rhs(i,j);
		}
	}
	return *this;
}

template<class T>
Matrix<T> Matrix<T>::operator *(const Matrix<T>& rhs) {
	Matrix res(this->rows, this->cols, 0.0);
	for(size_t i = 0; i<this->rows; i++) {
		for(size_t j = 0; j< this->cols; j++) {
			for(size_t k = 0; k < this->rows; k++) {
				res(i,j) += (this->mat[i][k] * rhs(i,j));
			}
		}
	}
	return res;
}

template<class T>
Matrix<T>& Matrix<T>::operator *=(const Matrix<T> &rhs) {
	Matrix res = *this * rhs;
	
	return res;
}
//===================================End_Operator_overloading===============================//


//=============================Operator_with_scalar===================================//
template<class T>
Matrix<T> Matrix<T>::operator +(const T &rhs) {
	Matrix res(this->cols, this->rows, 0.0);
	for(size_t i = 0; i<this->rows; i++) {
		for(size_t j = 0; j<this->cols; j++) {
			res(i,j) = this->mat[i][j] + rhs;
		}
	}
	return res;
}

template<class T>
Matrix<T> Matrix<T>::operator -(const T &rhs) {
	Matrix res(this->cols, this->rows, 0.0);
	for(size_t i = 0; i<this->rows; i++) {
		for(size_t j = 0; j<this->cols; j++) {
			res(i,j) = this->mat[i][j] - rhs;
		}
	}
	return res;
}

template<class T>
Matrix<T> Matrix<T>::operator *(const T &rhs) {
	Matrix res(this->cols, this->rows, 0.0);
	for(size_t i = 0; i<this->rows; i++) {
		for(size_t j = 0; j<this->cols; j++) {
			res(i,j) = this->mat[i][j] * rhs;
		}
	}
	return res;
}

template<class T>
Matrix<T> Matrix<T>::operator /(const T &rhs) {
	Matrix res(this->cols, this->rows, 0.0);
	for(size_t i = 0; i<this->rows; i++) {
		for(size_t j = 0; j<this->cols; j++) {
			res(i,j) = this->mat[i][j] / rhs;
		}
	}
	return res;
}
//=============================End_Operator_with_scalar===============================//


//=============================Operator_with_vector===============================//
template<class T>
vector<T> Matrix<T>::operator *(const vector<T> &rhs) {
	vector<T> res(rhs.size(),0.0);
	for(size_t i = 0; i<this->rows; i++) {
		for(size_t j = 0; j<this->cols; j++) {
			res[i] = this->mat[i][j] * rhs[j];
		}
	}
	return res;
}
//=============================End_Operator_with_vector===============================//
template<class T>
void Matrix<T>::Maximum() {
	T max = INT_MIN;
	int pos_i, pos_j;
	for(size_t i = 0; i<this->rows; i++) {
		for(size_t j = 0; j<this->cols; j++) {
			if(this->mat[i][j]>max) {
				max = this->mat[i][j];
				pos_i = i;
				pos_j = j;
			}
		}
	}
	cout << "\n- The maximum element: " << max;
	cout << "\n- The position: (" << pos_i << " ," << pos_j <<")\n";
}

template <class T>
Matrix<T>::~Matrix() {}
