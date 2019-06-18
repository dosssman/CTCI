#include <iostream>
#include <random>
#include <time.h>
#include <stdlib.h>

using namespace std;

const int M=5;
const int N=5;

void fillMatrix( int mtrx[N][N], const int M, const int N) {
  int k = 1;
  for( int i =0; i < M; i++)
    for( int j =0; j < N; j++)
      mtrx[i][j] = k++;
};

void displayMatrix( int mtrx[N][N], const int M, const int N) {
  for( int i=0; i<M; i++) {
    for( int j=0; j<N; j++) {
      cout << mtrx[i][j] << "\t";
    }
    cout << endl;
  }
}

void zerofyRowCol( int m[M][N], const int , const int);

int main() {

  srand (time(NULL));

  int m[M][N];

  cout << "Before zerofy" << endl;

  fillMatrix( m, M, N);
  displayMatrix( m, M, N);

  // Insert zero at random position then zerofy

  int zeroi = rand() % M, zeroj = rand() % N;
  m[zeroi][zeroj] = 0;

  bool zerofied = false;
  for( int i=0; i<M; i++) {
    for( int j=0; j<N; j++) {
        if( m[i][j] == 0) {
          zerofyRowCol( m, i, j);
          zerofied = true;
        }
        if( zerofied) break;
    }
    if( zerofied) break;
  }

  cout << "After zerofied" << endl;
  displayMatrix( m, M,N);
  
  return 0;
}

void  zerofyRowCol( int m[M][N], const int row, const int col) {
  for( int i=0; i<M; i++)
    m[i][col] = 0;
  for( int j=0; j<N; j++)
    m[row][j] = 0;
}
