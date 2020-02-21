#pragma once
/*
Author:  Peng Zheng
Last modified date: 2/21/2020

Description:

Implementation of Matrix class with operator overloads

*/

#include "PZ_Matrix.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class PZ_Matrix
{
	vector<vector<double>> matrix;
public:
	// default constructor
	PZ_Matrix() {}
	// Three constructors
	PZ_Matrix(const unsigned int& a, const double& b) :matrix(a, vector<double>(a, b)) {}
	PZ_Matrix(const unsigned int& a, const unsigned int& b, const double& c) : matrix(a, vector<double>(b, c)) {}
	PZ_Matrix(const string&);

	//copy constructor
	PZ_Matrix(PZ_Matrix const& in) : matrix(in.matrix) {}

	// stream insertion operator
	friend ostream& operator<<(ostream& os, const PZ_Matrix& M)
	{
		for (unsigned int i = 0; i < M.matrix.size(); ++i)
		{
			for (unsigned int j = 0; j < M.matrix[0].size(); ++j)
			{
				os << scientific << setw(12) << setprecision(3) << M.matrix[i][j];
			}
			os << endl;
		}
		return os;
	}

	////////////////
	//operators

	//Assignment
	PZ_Matrix& operator=(PZ_Matrix const&);
	//Addition of PZ_Matrix and double
	PZ_Matrix operator+(const double& val) const;
	//Addition of two PZ_Matrix
	PZ_Matrix operator+(PZ_Matrix const& val) const;
	//Addition of double and PZ_Matrix
	friend PZ_Matrix operator+(double const&, const PZ_Matrix&);
	//PZ_Matrix minus double
	PZ_Matrix operator-(const double& val) const;
	//PZ_Matrix minus PZ_Matrix
	PZ_Matrix operator-(PZ_Matrix const& val) const;
	//Double minus PZ_Matrix
	friend PZ_Matrix operator-(double const&, const PZ_Matrix&);
	//PZ_Matrix multiplies double
	PZ_Matrix operator*(const double& val) const;
	//PZ_Matrix multiplies PZ_Matrix
	PZ_Matrix operator*(const PZ_Matrix& M) const;
	//Double multiplies PZ_Matrix
	friend PZ_Matrix operator*(double const&, const PZ_Matrix&);
	//PZ_Matrix divided by double
	PZ_Matrix operator/(const double& val) const;
	//Addition assignment
	PZ_Matrix& operator+=(const PZ_Matrix& val);
	//Substration assignment
	PZ_Matrix& operator-=(const PZ_Matrix& val);
	//Transpose Funcition
	PZ_Matrix transpose() const;
};