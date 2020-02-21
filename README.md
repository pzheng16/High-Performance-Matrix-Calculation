# High-Performance-Matrix-Calculation

﻿# Peng Zheng's High-Performance Matrix Library

This is designed for **Matrix Multiplication and Transposition**. Matrix is stored in **vectors** and calculation is processed with **operator overloads and multi-threads (OpenMP).**


## Compile

Please ensure you have main.cpp, PZ_Matrix.h, PZ_Matrix.cpp, data.txt(if you want to input matrix from a file) in the same directory.

 - [ ] ***main.cpp***
 - [ ] ***PZ_Matrix.h***
 - [ ] ***PZ_Matrix.cpp***
 - [ ] ***data.txt(optional)***

```bash
module load gcc/7.3.0
g++ PZ_Matrix.cpp main.cpp -o matrix -fopenmp
```
***or***

```bash
g++ PZ_Matrix.cpp main.cpp -std=c++11 -o matrix -fopenmp
```
***Then Run:***
```bash
./matrix
```

## Functions in cpp

### How to generate matrix in the *main function*

```C++
const PZ_Matrix M1(3, 5.0);  // Construct 3 x 3 array set all elements to 5.0
const PZ_Matrix M2(5, 5, 200.0); // Construct 5 x 5 array, setting all element to 200.0
const PZ_Matrix M3("./data.txt"); // Construct matrix from file
```
### How to do multiplication
```C++
const PZ_Matrix ans= M1*M2; // Two Matrix Multiplys
```
### How to do **transposition**
```C++
const PZ_Matrix ans = M.transpose();
```
### How to print the matrix (overloaded <<)
```C++
std::cout << "Result: " << std::endl << ans << std::endl;
```
### How to catch errors 
```C++
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
```
## Usage

 ### How to generate the Matrix in the command Line ?
 
 1. **From files**
 **Format of data.txt:**
 NumOfRows(m) NumOfColumns(n)
 num(0,0), ..... num(0,n-1)
 ...................................
 num(m-1,0),...num(m-1,n-1)
**example:**
 10 5
08 02 22 97 38
49 49 99 40 17
81 49 31 73 55
52 70 95 23 04
22 31 16 71 51
24 47 32 60 99
32 98 81 28 64
67 26 20 68 02
24 55 58 05 66
21 36 23 09 75

 2. **Generate automatically with the same value** 
 **Format:** NumOfRows NumOfCols value
 **Example:** **3 3 2.3**
 It will generat a matrix with 3 rows, 2 columns, and every   	item has the same value: 2.3


### Calculation Example:

Tranpose (enter 1) one matrix or Multiply (enter 2) two matrixs?
***Input： 2***

Please input one Matrix (choose one way):
1. from files
2. generate automatically with the same value (NumOfRows NumOfCols value)
***Input： 2***

Please input as the format of (NumOfRows NumOfCols value):
***Input： 3 2 3.3***

Please input one Matrix (choose one way):
1. from files
2. generate automatically with the same value (NumOfRows NumOfCols value)
***Input： 2***

Please input as the format of (NumOfRows NumOfCols value):
***Input： 2 3 3.0***

Choose to output to the screen (enter 1) or the file (enter 2, default):
***Input： 1***

**Ans: M1*M2
   2.178e+01   2.178e+01   2.178e+01
   2.178e+01   2.178e+01   2.178e+01**

## Other functions

I have also implemented some other calculations of matrix, please refer to cpp files. **Value refers to the double format**.

 - **Value * Matrix**
 - **Matrix * Value**
 - **Matrix +/- Matrix**
 - **Matirx +/- Value**
 - **Value +/- Matrix**
 - **Matrix / Value**

```C++
	const PZ_Matrix M1(3, 5.0);  // Construct 3 x 3 array set all elements to 5.0
	const PZ_Matrix M2(5, 5, 200.0); // Construct 5 x 5 array, setting all element to 200.0
	const PZ_Matrix M3("./data_Problem1.txt"); // Construct matrix from file

	// std::cout << "M3: " << std::endl << M3 << std::endl;

	// Doing some simple matrix math
	const PZ_Matrix M4 = M1 - 5.0 + M2;
	const PZ_Matrix M5 = M3 - M2 + 8.0;
	const PZ_Matrix M6 = 10.0 * M1 + M2;
	const PZ_Matrix M7 = M3.transpose();   // Function should not Modify M3 directly
											// but just return the transpose of the matrix

	const PZ_Matrix M9 = M1 * 8.0;
	const PZ_Matrix M10 = M1 / 8.0;        // Check for divide by zero. Set all elements equal 0 for that case

	PZ_Matrix M11; // Default constructor size 0 x 0
	M11 += M1;
	PZ_Matrix M12;
	M12 -= M1;

	const PZ_Matrix M13 = M1 + 8.0;
	const PZ_Matrix M14 = M1 - 8.0;

	const PZ_Matrix M15 = 8.0 * M1;
	const PZ_Matrix M17 = 8.0 + M1;
	const PZ_Matrix M18 = 8.0 - M1;


```

## Contributor

## ***Peng Zheng***

Master in Electrical and Computer Engineering

Georgia Institute of Technology


**Phone:**  470-437-0264

**Linkin:**  [linkedin.com/in/peng-zheng-609702191/](https://www.linkedin.com/in/peng-zheng-609702191/)

**Email:**  peng_zheng@gatech.edu

1000 Northside Dr NW, Atlanta, Georgia


> If you have any questions, please do not heasitate to contact me through my email or phone numbers.

