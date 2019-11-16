#include <stdio.h>
	
void sinx(int N, int terms, float* x, float* result){
    for(int i=0; i<N; i++){
        float value = x[i];
        float numer = x[i] * x[i] * x[i];
        float denom = 6.0; // 3!
        int sign = -1;
        
        for (int j=1; j<=terms; j++){
            //printf("%.2f\n", numer / denom);
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
    int terms = 4;
    float x[N]; 
    float result[N];
    for(int i=0; i< N; i++){
       x[i] = i;
       result[i] = 0.0;
    }

    sinx(N, terms, &x, &result);
    for(int i; i<N; i++)
        printf("%.10f\n", result[i]);

    return 0;
}
