#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>


#include "Matrix.hpp"
using namespace zich;


  TEST_CASE(" 4 mat operators: +, +=, -, -= ")
  {
    /**
     * We are checking the operators +, +=, -, -= of two different dimension matrix.
     * we can add and substruct a and b if and only if the two matrix have same rows and columns size.
     */

      // it is the same dimension.
      std::vector<double> arr = {1, 0, 0, 0, 1, 0, 0, 0, 1}; //3x3
      std::vector<double> arr0 = {3, 0, 0, 0, 3, 0, 0, 0, 3}; //3x3
      std::vector<double> arr1 = {4, 0, 0, 0, 4, 0, 0, 0, 4}; //3x3
      Matrix a{arr, 3, 3};
      Matrix b{arr0, 3, 3};
      Matrix c{arr1, 3, 3};

      CHECK((a+b) == c);
      CHECK((b+a) == c);
      CHECK((a+c) != b);
      CHECK((b+c) != a);
      CHECK_THROWS ((a+c)= b);
      CHECK_THROWS ((b+c)= a);

      CHECK_NOTHROW(a + b);
      CHECK_NOTHROW(b + a);
      CHECK_NOTHROW(a + c); 
      CHECK_NOTHROW(c + a);   
      CHECK_NOTHROW(c + b);
      CHECK_NOTHROW(b + c);

      CHECK_NOTHROW(a - b);
      CHECK_NOTHROW(b - a);
      CHECK_NOTHROW(a - c); 
      CHECK_NOTHROW(c - a);   
      CHECK_NOTHROW(c - b);
      CHECK_NOTHROW(b - c);

      CHECK_NOTHROW(a += b);
      CHECK_NOTHROW(b += a);
      CHECK_NOTHROW(a += c); 
      CHECK_NOTHROW(c += a);   
      CHECK_NOTHROW(c += b);
      CHECK_NOTHROW(b += c);

      CHECK_NOTHROW(a -= b);
      CHECK_NOTHROW(b -= a);
      CHECK_NOTHROW(a -= c); 
      CHECK_NOTHROW(c -= a);   
      CHECK_NOTHROW(c -= b);
      CHECK_NOTHROW(b -= c);
      
      //different dimension.
      std::vector<double> arr2 = {2, 1, 1, 1, 2, 1}; //3x2
      Matrix d{arr2, 3, 3};

      CHECK_THROWS(a + d);
      CHECK_THROWS(d + b);
      CHECK_THROWS(a - d);
      CHECK_THROWS(d - c);
      CHECK_THROWS(b += a);
      CHECK_THROWS(c += d);
      CHECK_THROWS(d -= a);
      CHECK_THROWS(d -= c);

  }


    TEST_CASE(" 6 comparison operators: ==, !=, <, >, <=, >= ")
    {
    /**
     * 2 matrices are equal if and only if all their terms are equall.
     * Matrix a > Matrix b if and only if : sum of matrix a terms > sum of matrix b terms
     */      

      //it is the same matrix
      std::vector<double> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
      std::vector<double> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
      Matrix a{arr,4,4};
      Matrix b{arr,4,4};

      CHECK_EQ(a == b, true);
      CHECK_EQ(a != b, false);
      CHECK_EQ(a < b, false);
      CHECK_EQ(a > b, false);
      CHECK_EQ(a <= b, true);
      CHECK_EQ(a >= b, true);


      //matrix c and matrix d have the same dimension, but matrix d is bigger.
      std::vector<double> arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
      std::vector<double> arr3 = {11, 12, 13, 14, 15, 16, 17, 18, 19, 110, 111, 112, 113, 114, 115, 116};
      Matrix c{arr2,4,4};
      Matrix d{arr3,4,4};

      CHECK_EQ(c == d, false);
      CHECK_EQ(c != d, true);
      CHECK_EQ(c < d, true);
      CHECK_EQ(c > d, false);
      CHECK_EQ(c <= d, true);
      CHECK_EQ(c >= d, false);  


      //matrix e and matrix f have the same dimension, but matrix e is bigger.
      std::vector<double> arr4 = {11, 12, 13, 14, 15, 16, 17, 18, 19, 110, 111, 112, 113, 114, 115, 116};      
      std::vector<double> arr5 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
      Matrix e{arr4,4,4};
      Matrix f{arr5,4,4};

      CHECK_EQ(e == f, false);
      CHECK_EQ(e != f, true);
      CHECK_EQ(e < f, false);
      CHECK_EQ(e > f, true);
      CHECK_EQ(e <= f, false);
      CHECK_EQ(e >= f, true);      

    }

    TEST_CASE(" multiplication: *, *= ")
    {
     /**
     * a and b can be multiply if and only if:
     * a is n*m matrix
     * b is m*k matrix
     */

    std::vector<double> arr0 = {-1, 0, 0, 0, -1, 0, 0, 0, -1};
    std::vector<double> arr1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> arr2 = {0, 1, 1, 1, 0, 1, 1, 1,0};
    std::vector<double> arr3 = {2, 1, 1, 1, 2, 1, 1, 1, 2};
    Matrix a{arr0, 5, 5};
    Matrix b{arr1, 7, 4};
    Matrix c{arr2, 7, 6};
    Matrix d{arr3, 6, 5};
    
    CHECK_NOTHROW(a * a);
    CHECK_THROWS(a * b);
    CHECK_THROWS(a * c);
    CHECK_THROWS(a * d);

    CHECK_NOTHROW(a *= a);
    CHECK_THROWS(a *= b);
    CHECK_THROWS(a *= c);
    CHECK_THROWS(a *= d);



    CHECK_THROWS(b * a);
    CHECK_THROWS(b * b);
    CHECK_THROWS(b * c);
    CHECK_THROWS(b * d);

    CHECK_THROWS(b *= a);
    CHECK_THROWS(b *= b);
    CHECK_THROWS(b *= c);
    CHECK_THROWS(b *= d);



    CHECK_THROWS(c * a);
    CHECK_THROWS(c * b);
    CHECK_THROWS(c * c);
    CHECK_NOTHROW(c * d);

    CHECK_THROWS(c *= a);
    CHECK_THROWS(c *= b);
    CHECK_THROWS(c *= c);
    CHECK_NOTHROW(c *= d);



    CHECK_NOTHROW(d * a);
    CHECK_THROWS(d * b);
    CHECK_THROWS(d * c);
    CHECK_THROWS(d * d);

    CHECK_NOTHROW(d *= a);
    CHECK_THROWS(d *= b);
    CHECK_THROWS(d *= c);
    CHECK_THROWS(d *= d);
}

TEST_CASE(" prefix ++ --  postfix ++ ---")
{
    std::vector<double> arr0 = {-1, 0, 0, 0, -1, 0, 0, 0, -1};
    std::vector<double> arr1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> arr2 = {0, 1, 1, 1, 0, 1, 1, 1,0};
    std::vector<double> arr3 = {2, 1, 1, 1, 2, 1, 1, 1, 2};
    Matrix a{arr0,3,3};
    Matrix b{arr1,3,3};
    Matrix c{arr2,3,3};
    Matrix d{arr3,3,3};

   //"function ++ before"
    ++a;
    ++b;
    CHECK(c == a);
    CHECK(b == d);

   //"function ++ after"
    a++;
    b++;
    CHECK(c == a);
    CHECK(b == d);

    //function -- before
    --c;
    --d;
    CHECK(c == a);
    CHECK(b == d);

    //function -- after
    --c;
    --d;
    CHECK(c == a);
    CHECK(b == d);
    
}



  

  