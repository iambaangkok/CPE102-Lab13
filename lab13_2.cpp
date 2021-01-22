#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}


void inputMatrix(double mat[][N]){
    for(int i = 0 ; i < N; ++i){
		cout << "Row " << i+1 << ": ";
        for(int j = 0 ; j < N; ++j){
            cin >> mat[i][j];
        }
    }
    return;
}

void findLocalMax(const double mat[][N], bool localMax[][N]){
    for(int i = 0 ; i < N; ++i){
        for(int j = 0 ; j < N; ++j){        
			localMax[i][j] = 0;
			if(i != 0 and j != 0 and i != N-1 and j != N-1){
				double x = mat[i][j];
				if(x >= mat[i][j] and x >= mat[i+1][j] and x >= mat[i][j+1] and x >= mat[i-1][j] and x >= mat[i][j-1]){
					localMax[i][j] = 1;
				}
			}
			
        }
    }
    return;
}

void showMatrix(const bool mat[][N]){
    for(int i = 0 ; i < N; ++i){
        for(int j = 0 ; j < N; ++j){
            cout << ((mat[i][j])? 1:0) << " ";
        }cout << endl;
    }cout << endl;

    return;
}