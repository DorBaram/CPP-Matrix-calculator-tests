/**
 * Matrix Calculator Exercise
 * 
 * Author: Dor Baram
 * Since : 2022-04
 */

#include "matrix.hpp"
using namespace zich;


namespace zich{

        Matrix::Matrix(vector<double> mat, int inrow, int incol){
            if (inrow <1 || incol <1)
            {
                throw invalid_argument("matrix size must be positive");
            }
            if (mat.size() != inrow * incol)
            {
                throw invalid_argument("vector size must be the size of the mult of two sizes");
            }
            
            this->row = inrow;
            this->col = incol;
            for (int i = 0; i < inrow; i++){
                for (int j = 0; j < incol; j++){
                    this->matrix[i][j] = mat[(double)(j+i*(incol))];
                }
            }
        }

         /*input validators*/
        void validator(const Matrix &m1, const Matrix &m2){      //check if the two matrix are same nXm size
            if (m1.matrix.size() != m2.matrix.size() || m1.col != m2.col || m1.row != m2.row)
            {
                throw invalid_argument("mat sizes must be identical");
            }
            
        }
        void checkMul(const Matrix &m1, const Matrix &m2){       //check if the matrixs are nXm and mXk size
                   if (m1.col !=m2.row)
                   {
                       throw invalid_argument("mat mult must be nXm and mXk size");
                   }
                   
        }

        /*Input Output*/
        ostream &operator<<(ostream &out, const Matrix &m){
            //need to implement
            return out;
        }
        istream &operator>>(istream &in, Matrix &m){
            //need to implement
            return in;
        }

        /*Arithmetic*/
        Matrix operator+(const Matrix &m1, const Matrix &m2){    //addetive
        validator(m1,m2);
        return Matrix({1},1,1);
        }
        Matrix operator+=(Matrix &m1, const Matrix &m2){         //add equal
        validator(m1,m2);
        return Matrix({1},1,1);
        }
        Matrix operator+(const Matrix &m){                       //unari add
        return Matrix({1},1,1);
        }
        Matrix operator-(const Matrix &m1, const Matrix &m2){    //subtract
        validator(m1,m2);
        return Matrix({1},1,1);
        }
        Matrix operator-=(Matrix &m1, const Matrix &m2){         //sub equal
        validator(m1,m2);
        return Matrix({1},1,1);
        }
        Matrix operator-(const Matrix &m){                       //unari sub
        return Matrix({1},1,1);
        }

        /*Compare*/
        bool operator>(const Matrix &m1, const Matrix &m2){      //grater
        return true;
        }
        bool operator>=(const Matrix &m1, const Matrix &m2){     //grater equal
        return true;
        }
        bool operator<(const Matrix &m1, const Matrix &m2){      //lesser
        return true;
        }
        bool operator<=(const Matrix &m1, const Matrix &m2){     //lesser equal
        return true;
        }
        bool operator==(const Matrix &m1, const Matrix &m2){     //equal
        return true;
        }
        bool operator!=(const Matrix &m1, const Matrix &m2){     //not equal
        return true;
        }
        bool equal(const Matrix &m1, const Matrix &m2){          //same as equal?
        return true;
        }

        /*Increment Decrement*/
        Matrix operator++(Matrix &m){            //increments
        return Matrix({1},1,1);
        }
        Matrix operator--(Matrix &m){            //decrements
        return Matrix({1},1,1);
        }

        /*Mult*/
        Matrix operator*(double scalar, Matrix& m){      //scalar mult
        return Matrix({1},1,1);
        }
        Matrix operator*=(Matrix& matrix, double scalar){//scalar mult equal
        return Matrix({1},1,1);
        }
        Matrix operator*(Matrix& m1, Matrix& m2){        //matrix mult
        checkMul(m1,m2);
        return Matrix({1},1,1);
        }
        Matrix operator*=(Matrix& m1, Matrix& m2){       //matrix mult equal
        checkMul(m1,m2);
        return Matrix({1},1,1);
        }
    
}

