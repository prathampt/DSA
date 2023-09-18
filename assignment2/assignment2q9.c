#include <stdio.h>
#include <math.h>

double exponential(double x);
double sin(double x);
double cos(double x);

int main(){
    double x;

    printf("Enter x: ");
    scanf("%lf", &x);

    printf("sin x = %lf\n", sin(x));

    printf("cos x = %lf\n", cos(x));

    printf("e^x = %lf\n", exponential(x));

    return 0;
}

double exponential(double x){

    int n = 21;
    double ans = 1;
    for (int i = n; i > 0; i--)
    {
        ans = 1 + x * ans / i;
    }

    return ans;
    
}
double sin(double x){
    int n = 21;
    x = (double) x * 3.142159 / 180;
    double ans = x - x * x * x / ((2 * n + 1) * (2 * n));

    for (int i = 2 * n - 1; i > 1; i = i - 2)
    {
        ans = x - x * x * ans / (i * (i - 1));
        
    }

    return ans;
}
double cos(double x){
    int n = 21;
    x = (double) x * 3.142159 / 180;
    double ans = 1 - x * x/ ((2 * n) * (2 * n -1));

    for (int i = 2 * n - 2; i > 1; i = i - 2)
    {
        ans = 1 - x * x * ans / (i * (i - 1));
        
    }

    return ans;
}