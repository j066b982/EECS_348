/*
EECS 348 lab 6
matrix manipulation
date created 10-20-2023
Jeff Burns
*/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
const int maxsize=100;

void readmatrix(int mat1[maxsize][maxsize], int mat2[maxsize][maxsize], int &size, const std::string &filename); 
void submatrix(int mat1[maxsize][maxsize], int mat2[maxsize][maxsize], int size);
void addmatrix(int mat1[maxsize][maxsize], int mat2[maxsize][maxsize], int size); 
void multiplymatrix(int mat1[maxsize][maxsize], int mat2[maxsize][maxsize], int size);
void printmatrix(int mat1[maxsize][maxsize], int size);



int main()
{
int mat1[maxsize][maxsize];
int mat2[maxsize][maxsize];
int mat3[maxsize][maxsize];
int size;
string filename;
cout<< "Enter input file ";
cin>> filename;
cout<< "Jeff Burns\n"<<"matrix manipulation\n";
readmatrix(mat1, mat2, size, filename);
cout<< "matrix A\n";
printmatrix(mat1, size);
cout<< "matrix B\n";
printmatrix(mat2, size);
cout<< "matrix A + B\n";
addmatrix(mat1, mat2, size);
cout<< "matrix A * B\n";
multiplymatrix(mat1, mat2, size);
cout<< "matrix A - B\n";
submatrix(mat1, mat2, size);

    
    return 0;
}

void readmatrix(int mat1[maxsize][maxsize], int mat2[maxsize][maxsize], int &size, const std::string &filename){
    std::ifstream myfile(filename);
    if (!myfile) {
        std::cerr << "Error opening file:" << filename;
        exit(1);
        }
    myfile >> size; //read first character

    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++i){
            myfile >> mat1[i][j];
        }
    }

    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++i){
            myfile >> mat2[i][j];
        }
    }
  myfile.close();
}


void submatrix(int mat1[maxsize][maxsize], int mat2[maxsize][maxsize], int size) {
 // subtract the two matrices using for loops.
 int mat3[maxsize][maxsize];
   for (int i = 0; i < size; i++)
   {
      for (int j = 0; j < size; j++)
      {
         mat3[i][j] = mat1[i][j] - mat2[i][j];
      }
   }
   // Making a line break.
   cout << endl;

   // Printing the 2D array 
   for (int i = 0; i < size; i++)
   {
      for (int j = 0; j < size; j++)
      {
         cout << mat3[i][j] << "  ";
      }
      cout << "\n";
   }
}

void addmatrix(int mat1[maxsize][maxsize], int mat2[maxsize][maxsize], int size) {
 // Adding the two matrices using for loops.
 int mat3[maxsize][maxsize];
   for (int i = 0; i < size; i++)
   {
      for (int j = 0; j < size; j++)
      {
         mat3[i][j] = mat1[i][j] + mat2[i][j];
      }
   }

   // Making a line break.
   cout << endl;

   // Printing the 2D array for visualization.
   for (int i = 0; i < size; i++)
   {
      for (int j = 0; j < size; j++)
      {
         cout << mat3[i][j] << "  ";
      }
      cout << endl;
   }
   
}

void multiplymatrix(int mat1[maxsize][maxsize], int mat2[maxsize][maxsize], int size) {
    int mat3[maxsize][maxsize];
    int k = 0;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            int mat3[i][j] = {{0}};
            for (int k = 0; k < size; k++) { 
                mat3[i][j] += mat1[i][k] * mat2[k][j];
            } 
        }
    }
       // Printing the 2D array for visualization.
   for (int i = 0; i < size; i++)
   {
      for (int j = 0; j < size; j++)
      {
         cout << mat3[i][j] << "  ";
      }
      cout << endl;
   }
}

void printmatrix(int mat1[maxsize][maxsize], int size){
    for (int i = 0; i < size; i++)
   {
      for (int j = 0; j < size; j++)
      {
         cout << mat1[i][j] << "  ";
      }
      cout << endl;
   }
}

