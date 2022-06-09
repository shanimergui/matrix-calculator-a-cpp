#include "Matrix.hpp"
#include <iostream>

using namespace std;
namespace zich
{
      Matrix::Matrix(vector<double> vec,int sizeCol, int sizeRow )
      {
          this->vec=vec;
          this->sizeCol=sizeCol;
          this->sizeRow=sizeRow;
      }  
  
    // + , - , += , -= , (+) ,(-)

       //+
      Matrix Matrix::operator+( Matrix const & b){
          return *this;
      }

      //(+)
      Matrix Matrix::operator+() const{
          return *this;
      }

      // -
      Matrix Matrix::operator-(Matrix const & b )
      {
          return *this;

      }

      // (-)
      Matrix Matrix::operator-() const{
          return *this;
      }

      //  +=
      // this = a
      Matrix & Matrix::operator+=(Matrix const & b ){
          return *this;
      }

      // -=
      Matrix & Matrix::operator-=(Matrix const & b ){return *this;}





      // > >= < <= != ==

      //==
      bool operator==( Matrix const & a, Matrix const & b ){return false;}

      //!=
      bool operator!=( Matrix const & a, Matrix const & b ){return false;}

      //<
      bool operator<( Matrix const & a, Matrix const & b ){return false;}

      //<=
      bool operator<=( Matrix const & a, Matrix const & b ){return false;}

      //>
      bool operator>( Matrix const & a, Matrix const & b ){
          return false;
      }

      //>=
      bool operator>=( Matrix const & a, Matrix const & b ){return false;}




      // prefix ++ --  postfix ++ ---

      //prefix
      Matrix & Matrix::operator++(){
          return *this;
      }

      //postfix
      Matrix Matrix::operator++(int x){
          return *this;
      }

      //prefix
      Matrix & Matrix::operator--(){return *this;}

      //postfix
      Matrix Matrix::operator--(int x){return *this;}



      //*
      Matrix operator*(const Matrix & a,double x){return a;}

      Matrix operator*(double x,const Matrix & a){return a;}
      Matrix Matrix::operator*(const Matrix & b) const{return *this;}

      //*=
      Matrix & Matrix::operator*=(double x){return *this;}
      Matrix & Matrix::operator*=(Matrix const & x){return *this;

      }


      // << >>
      ostream & operator<<(ostream& os,const Matrix & a){
          return os;
      }
      istream & operator>>(istream& is,Matrix & a){
          return is;
      }


      //compute sum of matrix
        double Matrix::sum() const{
            double sum = 0;
            for(size_t i = 0; i<sizeRow*sizeCol; i++){
                    sum+=this->vec[i];
        } 
        return sum;     

}
}     