#include <iostream>

using namespace std;

const int N = 5;

void fillMatrix( int mtrx[N][N], const int N);
void displayMatrix( int mtrx[N][N], const int);
void rotate90DegRight( int mtrx[N][N], const int);

int main() {
  int mtrx[N][N];

  cout << "Before rotation" << endl;

  fillMatrix( mtrx, N);
  displayMatrix( mtrx, N);

  cout << "After rotation" << endl;
  rotate90DegRight( mtrx, N);
  displayMatrix( mtrx, N);

  return 0;
}

void fillMatrix( int mtrx[N][N], const int N) {
  int k = 1;
  for( int i =0; i < N; i++)
    for( int j =0; j<N; j++)
      mtrx[i][j] = k++;
};

void displayMatrix( int mtrx[N][N], const int N) {
  for( int i=0; i<N; i++) {
    for( int j=0; j<N; j++) {
      cout << mtrx[i][j] << "\t";
    }
    cout << endl;
  }
}

void rotate90DegRight( int mtrx[N][N], const int N) {
  int lowBound = 0;
  for( int i=lowBound; i< N-1-lowBound; i++) {
    for( int j=lowBound; j< N-1-lowBound; j++) {
      cout << " i=" << i << ", j=" << j << endl;
      // int tmp = mtrx[i][j];
      // mtrx[i][j] = mtrx[N-j-1][i];
      // mtrx[N-j-1][i] = mtrx[N-i-1][N-j-1];
      // mtrx[j][N-i-1] = tmp;
      int tmp = mtrx[N-1-j][i];
      mtrx[N-1-j][i] = mtrx[N-1-i][N-1-j];
      mtrx[N-1-i][N-1-j] = mtrx[j][N-1-i];
      mtrx[j][N-1-i] = mtrx[i][j];
      mtrx[i][j] = tmp;
    }
    lowBound++;
  }
}
