/*
Author:  Peng Zheng
Last modified date: 2/21/2020

Description:

Implementation of Matrix class with operator overloads

*/

#include <iostream>
#include <fstream>
#include <limits>
#include "PZ_Matrix.h"
#include <chrono>
#include <string>

using namespace std;
using namespace std::chrono;

const PZ_Matrix inputFunction(void);

int main()
{
	
	/////// Other Calculations of Matrixs ////////////

	// const PZ_Matrix M1(3, 5.0);  // Construct 3 x 3 array set all elements to 5.0
	// const PZ_Matrix M2(5, 5, 200.0); // Construct 5 x 5 array, setting all element to 200.0
	// const PZ_Matrix M3("./data_Problem1.txt"); // Construct matrix from file

	// // std::cout << "M3: " << std::endl << M3 << std::endl;

	// // Doing some simple matrix math
	// const PZ_Matrix M4 = M1 - 5.0 + M2;
	// const PZ_Matrix M5 = M3 - M2 + 8.0;
	// const PZ_Matrix M6 = 10.0 * M1 + M2;
	// const PZ_Matrix M7 = M3.transpose();   // Function should not Modify M3 directly
	// 										// but just return the transpose of the matrix

	// const PZ_Matrix M9 = M1 * 8.0;
	// const PZ_Matrix M10 = M1 / 8.0;        // Check for divide by zero. Set all elements equal 0 for that case

	// PZ_Matrix M11; // Default constructor size 0 x 0
	// M11 += M1;
	// PZ_Matrix M12;
	// M12 -= M1;

	// const PZ_Matrix M13 = M1 + 8.0;
	// const PZ_Matrix M14 = M1 - 8.0;

	// const PZ_Matrix M15 = 8.0 * M1;
	// const PZ_Matrix M17 = 8.0 + M1;
	// const PZ_Matrix M18 = 8.0 - M1;
	


	/////// Matrix Multiplication and Transposition ////////////

	cout << "Tranpose (enter 1) one matrix or Multiply (enter 2) two matrixs? "<< endl;
	int calType = 0;
	cin >> calType;
	if (!calType)
	{
		return 0;
	}
	else if (calType == 1)// transpose
	{
		const PZ_Matrix M = inputFunction();
		try{
			const PZ_Matrix ans = M.transpose();
			cout << "Choose to output to the screen (enter 1) or the file (enter 2, default):" << endl;
			int outputType = 0;
			cin >> outputType;
			if (outputType == 1 ){
				cout << "Ans: M Transposed " << endl << ans << endl;
			}
			else{
				cout << "Please enter the output filename (e.g output.txt):"<< endl;
				string outputName;
				cin >> outputName;
				ofstream outfile (outputName);
				outfile << "Ans: M Transposed " << endl << ans << endl;
			}
			return 0;
		}
		catch (const char* msg){
			cout << msg << endl;
		}
		return 0;
	}
	else
	{
		const PZ_Matrix M1 = inputFunction();
		const PZ_Matrix M2 = inputFunction();
		try{
			const PZ_Matrix ans= M1*M2; // Two Matrix Multiplys
			cout << "Choose to output to the screen (enter 1) or the file (enter 2, default):" << endl;
			int outputType = 0;
			cin >> outputType;
			if (outputType == 1 ){
				cout << "Ans: M1*M2" << endl << ans << endl;
			}
			else{
				cout << "Please enter the output filename (e.g output.txt):"<< endl;
				string outputName;
				cin >> outputName;
				ofstream outfile (outputName);
				outfile << "Ans: M1*M2" << endl << ans << endl;
			}
			return 0;
		}
		catch (const char* msg)
		{
			cerr << msg << endl;
		}

	}


	/////// Output of Results ////////////

	// const PZ_Matrix M19(10000, 200, 4.0);  // Construct 3 x 3 array set all elements to 5.0
	// const PZ_Matrix M20(200, 10000, 4.0); // Construct 5 x 5 array, setting all element to 200.0
	// try{
	// 	const PZ_Matrix M21= M19*M20; // Two Matrix Multiplys
	// 	std::cout << "M21: M19*M20" << std::endl << M21 << std::endl;
	// }
	// catch (const char* msg)
	// {
	// 	std:cerr << msg << endl;
	// }


	// std::cout << "M4: (M1 - 5.0 + M2): " << std::endl << M4 << std::endl;
	// std::cout << "M5: (M3 - M2 + 8.0) " << std::endl << M5 << std::endl;
	// std::cout << "M6: (10.0 * M1 + M2) " << std::endl << M6 << std::endl;
	// std::cout << "M7: M3 Transposed " << std::endl << M7 << std::endl;
	// std::cout << "M9: (M1 * 8.0) " << std::endl << M9 << std::endl;
	// std::cout << "M10: (M1 / 8.0) " << std::endl << M10 << std::endl;
	// std::cout << "M13: (M1 + 8.0) " << std::endl << M13 << std::endl;
	// std::cout << "M14: (M1 - 8.0) " << std::endl << M14 << std::endl;
	// std::cout << "M15: (8.0 * M1) " << std::endl << M15 << std::endl;
	// std::cout << "M17: (8.0 + M1) " << std::endl << M17 << std::endl;
	// std::cout << "M18: (8.0 - M1) " << std::endl << M18 << std::endl;

	return 0;
}


const PZ_Matrix inputFunction(void)// Asking for input
{
	int inputType = 0;
	do
	{
		cout << "Please input one Matrix (choose one way):" << endl 
		<< "1. from files" << endl<< "2. generate automatically with the same value (NumOfRows NumOfCols value)" << endl;
		cin >> inputType;
	}while (inputType != 1 && inputType != 2);

	string filename;
	if (inputType == 1)
	{	
		cout << "Please enter the name of the file (e.g data.txt) and make sure it is in the same directory:" << endl;
		cin >> filename;
		const PZ_Matrix M1("./" + filename);
		return M1;
	}
	else
	{
		cout << "Please input as the format of (NumOfRows NumOfCols value):" << endl;
		int a, b;
		double c;
		cin >> a >> b >> c;
		const PZ_Matrix M1(a,b,c);
		return M1;
	}
	const PZ_Matrix M;
	return M;
}