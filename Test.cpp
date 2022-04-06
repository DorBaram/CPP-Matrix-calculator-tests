/**
 * Matrix Calculator Exercise
 * 
 * Author: Dor Baram
 * Since : 2022-04
 */
#include "doctest.h"
using namespace doctest;
#include <iostream>
#include <stdexcept>
using namespace std;
#include "matrix.hpp"
using namespace zich;


TEST_CASE("arithmetic and constructors")
{
    vector<double> v1,v2;
    for (int i = 0; i < 50; i++){
        v1.push_back(i);
        v2.push_back(0);
    }
    Matrix m1(v1,5,10);
    Matrix m2(v1,50,1);
    Matrix m3(v1,10,5);
    Matrix mz1(v2,5,10);
    Matrix mz2(v2,50,1);
    Matrix mz3(v2,10,5);
    
    //wrong size or zero size matrix
    CHECK_THROWS(Matrix(v1,10,10));
    CHECK_THROWS(Matrix(v2,10,10));
    CHECK_THROWS(Matrix({},0,0));

    //arithmetics
    //not the same size mat
    CHECK_THROWS(m1+m2);
    CHECK_THROWS(m1+m3);
    CHECK_THROWS(m2+m3);
    CHECK_THROWS(mz1-m2);
    CHECK_THROWS(m1-m3);
    CHECK_THROWS(m2-mz3);
    CHECK_THROWS(m1+=m2);
    CHECK_THROWS(m1+=mz3);
    CHECK_THROWS(mz2+=m3);
    CHECK_THROWS(mz1-=m2);
    CHECK_THROWS(mz1-=mz3);
    CHECK_THROWS(m2-=m3);

    //same size mat
    CHECK_NOTHROW(m1+mz1);
    CHECK_NOTHROW(m2+mz2);
    CHECK_NOTHROW(m1+m1);
    CHECK_NOTHROW(m2+m2);

    //not the same size
    CHECK_THROWS(m1*m2);
    CHECK_THROWS(m1*mz1);
    CHECK_THROWS(m2*m3);
    CHECK_THROWS(mz3*m3);

    //should work, nXm,mXn
    CHECK_NOTHROW(m1*m3);
    CHECK_NOTHROW(mz1*mz3);  
    CHECK_NOTHROW(m1*mz3);
    CHECK_NOTHROW(mz1*m3); 
    CHECK_NOTHROW(m3*m1);
    CHECK_NOTHROW(mz3*mz1);  
    CHECK_NOTHROW(m3*mz1);
    CHECK_NOTHROW(mz3*m1); 
    
}
/*
m1:             m2:
[27 3 5]        [11 2 1 2 91]
[14 0 112]      [5 22 0 7 9]
[8 4 6]         [6 36 10 36 27]
[3 53 2]        
[22 22 1]       
*/
TEST_CASE("mult on two matrix and check inequalities"){
    //the test checks the multipication of four matrixes m1,m2,unit3,unit5
    //and we have two more matrixes that is the correct multipication of the other two
    //m1*m2=m3, m2*m1=m4
    Matrix m1({27,3,5,14,0,112,8,4,6,3,53,2,22,22,1},5,3);
    Matrix m2({11,2,1,2,91,5,22,0,7,9,6,36,10,36,27},3,5);
    Matrix m3({342,300,77,255,2619,826,4060,1134,4060,4298,114,320,68,260,926,310,1244,23,449,804,358,564,32,234,2227},5,5);
    Matrix m4({2341,2145,380,662,584,2512,1448,2560,4221},3,3);
    //m1*unit3=m1 ,m2*unit5=m2 ,unit5*m1=m1 ,unit3*m2=m2
    Matrix unit3({1,0,0,0,1,0,0,0,1},3,3);
    Matrix unit5({1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1},5,5);

    //equals
    CHECK(m1*m2 == m3);
    CHECK(m2*m1 == m4);
    CHECK(m1*unit3 == m1);
    CHECK(unit5*m1 == m1);
    CHECK(m2*unit5 == m2);
    CHECK(unit3*m2 == m2);
    CHECK(m3*unit5 == unit5*m3);
    CHECK(m4*unit3 == unit3*m4);
    CHECK(unit3*unit3 == unit3);
    CHECK(unit5*unit5 == unit5);

    //grater equals
    CHECK(m1*m2 >= m3);
    CHECK(m2*m1 >= m4);
    CHECK(m1*unit3 >= m1);
    CHECK(unit5*m1 >= m1);
    CHECK(m2*unit5 >= m2);
    CHECK(unit3*m2 >= m2);
    CHECK(m3*unit5 >= unit5*m3);
    CHECK(m4*unit3 >= unit3*m4);
    CHECK(unit3*unit3 >= unit3);
    CHECK(unit5*unit5 >= unit5);

    //lesser equals
    CHECK(m1*m2 <= m3);
    CHECK(m2*m1 <= m4);
    CHECK(m1*unit3 <= m1);
    CHECK(unit5*m1 <= m1);
    CHECK(m2*unit5 <= m2);
    CHECK(unit3*m2 <= m2);
    CHECK(m3*unit5 <= unit5*m3);
    CHECK(m4*unit3 <= unit3*m4);
    CHECK(unit3*unit3 <= unit3);
    CHECK(unit5*unit5 <= unit5);

    //grater
    CHECK_FALSE(m1*m2 > m3);
    CHECK_FALSE(m2*m1 > m4);
    CHECK_FALSE(m1*unit3 > m1);
    CHECK_FALSE(unit5*m1 > m1);
    CHECK_FALSE(m2*unit5 > m2);
    CHECK_FALSE(unit3*m2 > m2);
    CHECK_FALSE(m3*unit5 > unit5*m3);
    CHECK_FALSE(m4*unit3 > unit3*m4);
    CHECK_FALSE(unit3*unit3 > unit3);
    CHECK_FALSE(unit5*unit5 > unit5);

    //lesser
    CHECK_FALSE(m1*m2 < m3);
    CHECK_FALSE(m2*m1 < m4);
    CHECK_FALSE(m1*unit3 < m1);
    CHECK_FALSE(unit5*m1 < m1);
    CHECK_FALSE(m2*unit5 < m2);
    CHECK_FALSE(unit3*m2 < m2);
    CHECK_FALSE(m3*unit5 < unit5*m3);
    CHECK_FALSE(m4*unit3 < unit3*m4);
    CHECK_FALSE(unit3*unit3 < unit3);
    CHECK_FALSE(unit5*unit5 < unit5);

    //illigal mult
    CHECK_THROWS(unit3*unit5);
    CHECK_THROWS(unit5*unit3);
    CHECK_THROWS(m1*unit5);
    CHECK_THROWS(m2*unit3);
    CHECK_THROWS(m3*unit3);
    CHECK_THROWS(unit3*m3);
    CHECK_THROWS(m4*unit5);
    CHECK_THROWS(unit5*m4);
}

TEST_CASE("++,--,*=,* "){
    vector<double> v1,v2,v3;
    for (int i = 0; i < 100; i++){
        v1.push_back(i);        //v1 = {1,2,3,...}
        v2.push_back(0);        //v2 = {0,0,0,...}
        v3.push_back(1);        //v3 = {1,1,1,...}
    }
    Matrix m1(v1,10,10);
    Matrix m2(v2,10,10);
    Matrix m3(v3,10,10);

    CHECK(m1!=m2);
    CHECK(m2!=m3);
    CHECK(m1!=m3);

    CHECK_FALSE(m1==m2);
    CHECK_FALSE(m2==m3);
    CHECK_FALSE(m1==m3);

    ++m2;           //m2=1,1,1,...
    CHECK(m2==m3);
    CHECK_FALSE(m2!=m3);

    m2 = m2-m3;     //m2=0,0,0,...
    CHECK_FALSE(m2==m3);

    --m3;           //m3=0,0,0,...
    CHECK(m2==m3);
    CHECK_FALSE(m2!=m3);

    ++m2;
    ++m2;
    ++m2;           //m2=3,3,3,3,...

    ++m3;
    m3*=3;          //m3=3,3,3,3,...

    CHECK(m2==m3);
    CHECK_FALSE(m2!=m3);

    m3*=2;          //m3=6,6,6,6,...
    m2=2*m2;        //m2=6,6,6,6,...

    CHECK(m2==m3);
    CHECK_FALSE(m2!=m3);
}

TEST_CASE("constructor"){
    vector<double> v1,v2,v3;        //v3 is empty
    CHECK_THROWS(Matrix m(v1,0,0));
    CHECK_THROWS(Matrix m(v2,1,1));
    for (int i = 0; i < 100; i++){
        CHECK_THROWS(Matrix m(v1,1,i+1));
        CHECK_THROWS(Matrix m(v2,i+1,1));
        CHECK_THROWS(Matrix m(v3,1,i+1));
        CHECK_THROWS(Matrix m(v3,i+1,1));
        v1.push_back(0);                //v1 = {0,0,0,...}
        v2.push_back(1);                //v2 = {1,1,1,...}
        CHECK_NOTHROW(Matrix m(v1,1,i+1));
        CHECK_NOTHROW(Matrix m(v2,i+1,1));
    }

}
