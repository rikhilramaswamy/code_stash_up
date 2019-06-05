#include <iostream>
#include <vector>
using namespace std;
typedef vector<float> vf;
typedef vector< vf > v2f;

class DenseMatrix{
  private:
    v2f myMatrix;
    int num_rows;
    int num_cols;
  
  bool invalid_dimensions(int r , int c) {
    if( r < 0 || r >=num_rows || c <0 || c >=num_cols)
      return true;
    
    return false;
  }
  
  
  public:
   
  DenseMatrix() { 
    num_rows =0; 
    num_cols =0;
  }
  
  DenseMatrix ( int max_rows, int max_cols) {
    num_rows = max_rows;
    num_cols = max_cols;
    myMatrix.resize(max_rows);
    
    // iterate through the rows and resize the vectors internally

    for(int i =0; i < num_rows; i++) {
      myMatrix[i].resize(num_cols, 0);
    }
  }
  
  const int get_max_rows() { return num_rows;}
  
  const int get_max_cols() { return num_cols;}
  

  const float get_cell(int r, int c) {
    // do validation for row and col to be in the range
      if(invalid_dimensions(r,c)) 
        return -1;
    
    return myMatrix[r][c];
  }
  
  int set_cell(int r , int c, float val ) {
        // do validation for row and col to be in the range
        if(invalid_dimensions(r,c)) 
          return -1;
        myMatrix [r][c] = val;
          return 0; // success value updated 
  }
  
  void print_vector() {
   cout<<"\n printing the complete matrix\n";
    
    for(int i =0; i < num_rows; i++){
      for(int j =0; j < num_cols; j++) {
          cout<<"\t "<< myMatrix[i][j];
      }
      cout<<"\n";
   }
  }

};



// To execute C++, please define "int main()"
int main() {
  
  DenseMatrix dMatrix(2,2);
  dMatrix.print_vector();
  dMatrix.set_cell(1,1, 1);
  dMatrix.print_vector();
  
  float res = dMatrix.get_cell(1,1);
  cout<<"\n res: "<<res;
  
  res = dMatrix.get_cell(1,0);
  cout<<"\n res: "<<res;
  
  int max_rows = dMatrix.get_max_rows();
  int max_cols = dMatrix.get_max_cols();
  cout<<"\nmax_rows : "<<max_rows;
  cout<<"\n max_cols: "<<max_cols;


  return 0;
}

// DENSE matrix 2D doubles:
// default construct
// parameterised construct
// get dimernsion: row, column
// access eleemnt (i, j)
// modify element (i,j) const
// print functionality 









Hi Darren, Thanks for the response! 

I am a generalist software engineer looking for backend position;
Distributed Systems work similar to CM team in Netapp would be ideal!

Thanks
Nikhil
