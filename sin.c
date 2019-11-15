#include <stdio.h>
	
void sinx(int N, int terms, float* x, float* result){
    for(int i=0; i<N; i++){
        float value = x[i];
        float numer = x[i] * x[i] * x[i];
        int denom = 6; // 3!
        int sign = -1;
        
        for (int j=1; j<=terms; j++){
            value += sign * numer / denom;
            numer *= x[i] * x[i];
            denom *= (2*j+2) * (2*j+3);
            sign *= -1;
        }

        result[i] = value;
    }	
}


int main(){

    int N = 30;
    int terms = 10;
    float x[N], result[N];
    for(int i=0; i< N; i++){
       x[i] = i;
       result[i] = 0;
    }

    sinx(N, terms, &x, &result);
    for(int i; i<N; i++)
        printf("%.10f\n", result[i]);

    return 0;
}
