#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[]){
    double sumA = 0,sumS = 0,sumG = 1,sumH = 0,max = A[0],min=A[0];
    for (int i = 0; i < N; i++){
        sumA += A[i];
    }
    B[0] = sumA/N;
    for (int i = 0; i < N; i++){
        sumS += pow(A[i] - B[0],2);
    }
    B[1] = sqrt(sumS/N);
    for (int i = 0; i < N; i++){
        sumG *= A[i];
    }
    B[2] = pow(sumG,(1/(double)N));
    for (int i = 0; i < N; i++){
        sumH += 1/A[i];
    }
    B[3] = N/sumH;
    for (int i = 0; i < N; i++){
        if (A[i] > max)
            max = A[i];    
    }
    B[4] = max;
    for (int i = 0; i < N; i++){
        if (A[i] < min)
            min = A[i];    
    }
    B[5] = min;
}