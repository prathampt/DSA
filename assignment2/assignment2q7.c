#include <stdio.h>

int gcd(int a, int b);
int lcm(int a, int b);

int main(){
    int a, b;

    printf("Enter a: ");
    scanf("%d", &a);

    printf("Enter b: ");
    scanf("%d", &b);

    int g = gcd(a,b);
    int l = lcm(a,b);

    printf("The GCD of above numbers is: %d and their LCM is: %d\n", g, l);

    return 0;
}

int gcd(int a, int b){
    if (a<b){
        return gcd(b,a);
    }
    else if (b == 0)
    {
        return a;
    }
    else{
        return gcd(b, a % b);
    }
    
}

int lcm(int a, int b){
    return a*b/gcd(a,b);
}