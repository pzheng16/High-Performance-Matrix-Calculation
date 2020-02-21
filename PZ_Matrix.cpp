/*
Author:  Peng Zheng
Last modified date: 2/21/2020

Description:

Implementation of Matrix class with operator overloads

*/

#include "PZ_Matrix.h"
#include <omp.h>

//String constructors
PZ_Matrix::PZ_Matrix(const string& a)
{
	ifstream inFile;
	inFile.open(a);
	if (!inFile) {
		cerr << "Unable to open file";
		exit(1);
	}
	unsigned int size;
	inFile >> size;
	unsigned int rows = size;
	inFile >> size;
	unsigned int columns = size;
	matrix = vector<vector<double>>(rows, vector<double>(columns, double(0)));
	double val;
	int index = 0;
	while (inFile >> val) {
		unsigned int r = index / columns;
		unsigned int c = index % columns;
		matrix[r][c] = val;
		++index;
	}
	inFile.close();
}

//////////Operators//////////

//Assignment
PZ_Matrix& PZ_Matrix::operator=(PZ_Matrix const& M)
{
	if (this == &M)
	{
		return *this;
	}

	this->matrix = M.matrix;
	return *this;
}

//Addition of PZ_Matrix and double
PZ_Matrix PZ_Matrix::operator+(const double& val) const
{
	PZ_Matrix newM(*this);
	for (auto& i : newM.matrix) {
		for (auto& j : i) {
			j += val;
		}
	}
	return newM;
}

//Addition of two PZ_Matrix
PZ_Matrix PZ_Matrix::operator+(PZ_Matrix const& M) const {
	unsigned int max_row;
	unsigned int max_column;
	if (this->matrix.empty())
	{
		max_row = M.matrix.size();
		max_column = M.matrix[0].size();
	}
	else {
		max_row = (this->matrix.size() >= M.matrix.size()) ? this->matrix.size() : M.matrix.size();
		max_column = (this->matrix[0].size() >= M.matrix[0].size()) ? this->matrix[0].size() : M.matrix[0].size();
	}
	PZ_Matrix M1(max_row, max_column, double(0));
	PZ_Matrix M2(M1);
	PZ_Matrix newM(M1);
	if (this->matrix.empty() == 0)
	{
		for (unsigned int i = 0; i < this->matrix.size(); ++i) {
			for (unsigned int j = 0; j < this->matrix[0].size(); ++j) {
				M1.matrix[i][j] = this->matrix[i][j];
			}
		}
	}
	if (this->matrix.empty() == 0)
	{
		for (unsigned int i = 0; i < M.matrix.size(); ++i) {
			for (unsigned int j = 0; j < M.matrix[0].size(); ++j) {
				M2.matrix[i][j] = M.matrix[i][j];
			}
		}
	}

	for (unsigned int i = 0; i < M1.matrix.size(); ++i) {
		for (unsigned int j = 0; j < M1.matrix[0].size(); ++j) {
			newM.matrix[i][j] = M1.matrix[i][j] + M2.matrix[i][j];
		}
	}
	return newM;
}

// Addition of double and PZ_Matrix
PZ_Matrix operator + (const double& val, PZ_Matrix const& M)
{
	PZ_Matrix newM(M);
	return (newM + val);
}

//PZ_Matrix minus double
PZ_Matrix PZ_Matrix::operator-(const double& val) const
{
	PZ_Matrix newM(*this);
	for (auto& i : newM.matrix) {
		for (auto& j : i) {
			j -= val;
		}
	}
	return newM;
}

//PZ_Matrix minus PZ_Matrix
PZ_Matrix PZ_Matrix::operator-(PZ_Matrix const& M) const {
	unsigned int max_row;
	unsigned int max_column;
	if (this->matrix.empty())
	{
		max_row = M.matrix.size();
		max_column = M.matrix[0].size();
	}
	else {
		max_row = (this->matrix.size() >= M.matrix.size()) ? this->matrix.size() : M.matrix.size();
		max_column = (this->matrix[0].size() >= M.matrix[0].size()) ? this->matrix[0].size() : M.matrix[0].size();
	}
	PZ_Matrix M1(max_row, max_column, double(0));
	PZ_Matrix M2(M1);
	PZ_Matrix newM(M1);
	if (this->matrix.empty() == 0)
	{
		for (unsigned int i = 0; i < this->matrix.size(); ++i) {
			for (unsigned int j = 0; j < this->matrix[0].size(); ++j) {
				M1.matrix[i][j] = this->matrix[i][j];
			}
		}
	}
	if (this->matrix.empty() == 0)
	{
		for (unsigned int i = 0; i < M.matrix.size(); ++i) {
			for (unsigned int j = 0; j < M.matrix[0].size(); ++j) {
				M2.matrix[i][j] = M.matrix[i][j];
			}
		}
	}

	for (unsigned int i = 0; i < M1.matrix.size(); ++i) {
		for (unsigned int j = 0; j < M1.matrix[0].size(); ++j) {
			newM.matrix[i][j] = M1.matrix[i][j] - M2.matrix[i][j];
		}
	}
	return newM;
}

// Double minus PZ_Matrix
PZ_Matrix operator-(double const& val, const PZ_Matrix& M) {
	PZ_Matrix newM(M.matrix.size(), M.matrix[0].size(),double(val));
	return newM - M;
}

//PZ_Matrix multiplies double
PZ_Matrix PZ_Matrix::operator*(const double& val) const
{
	PZ_Matrix newM(*this);
	for (auto& i : newM.matrix) {
		for (auto& j : i) {
			j *= val;
		}
	}
	return newM;
}

// Double multiplies PZ_Matrix;
PZ_Matrix operator * (const double& val, PZ_Matrix const& M)
{
	PZ_Matrix newM(M);
	return (newM * val);
}

//PZ_Matrix multiplies PZ_Matrix
PZ_Matrix PZ_Matrix::operator * (const PZ_Matrix& M) const
{
	if (this -> matrix.empty() || M.matrix.empty()){
		throw "One of the matrixs is empty!!!";
	}
	int col1 = this -> matrix[0].size();
	int row2 = M.matrix.size();
	if (col1 != row2) {
		throw "Multiply is not allowed due to mismatching between number of rows and number of columns!!";
	}
	int row = this -> matrix.size();
	int col = M.matrix[0].size();
	PZ_Matrix newM(row,col,double(0));// new Matrix = Matrix1 * Matrix2

	#pragma omp parallel for schedule(dynamic)
	for (int i = 0; i < row; ++i)// number of row numbers in the new Matrix
	{
		for (int j = 0; j < col; ++j)// number of column numbers in the new Matrix
		{			
			for (int k = 0; k < col1; ++k)// number of column numbers in the Matrix1
			{
				newM.matrix[i][j] += (this->matrix[i][k])*(M.matrix[k][j]);
			}
		}
	}

	return newM;
}

//PZ_Matrix divided by double
PZ_Matrix PZ_Matrix::operator/(const double& val) const
{
	PZ_Matrix newM(*this);
	if (val == double(0)) {
		for (auto& i : newM.matrix) {
			for (auto& j : i) {
				j = double(0);
			}
		}
	}
	else {
		for (auto& i : newM.matrix) {
			for (auto& j : i) {
				j /= val;
			}
		}
	}
	return newM;
}

//Addition assignment
PZ_Matrix& PZ_Matrix::operator+=(const PZ_Matrix& M) {
	PZ_Matrix newM(*this);
	*this = newM + M;
	return *this;
}

//Substration assignment
PZ_Matrix& PZ_Matrix::operator-=(const PZ_Matrix& M) {
	PZ_Matrix newM(*this);
	*this = newM - M;
	return *this;
}

//Transpose Funcition
PZ_Matrix PZ_Matrix::transpose() const
{
	if (this -> matrix.empty()){
		throw "The matrix is empty!!!";
	}
	PZ_Matrix newM(this->matrix[0].size(),this->matrix.size(),double(0));
	#pragma omp parallel for schedule(dynamic)
	for (unsigned int i = 0; i < newM.matrix.size(); ++i) {
		for (unsigned int j = 0; j < newM.matrix[0].size(); ++j) {
			newM.matrix[i][j] = this->matrix[j][i];
		}
	}
	return newM;
}











