#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double factorial(double n){
 	double retval = 1;
 	for (int i = n; i > 1; --i)
 		retval *= i;
 	return retval;
}

int main(int argc, char** argv){
    double r = 0;
    int MAX = 42;
    if (argc == 2) MAX = atoi(argv[1]);
    for(int i = 0; i < MAX; i++)
        r += factorial(4 * i)*(1103 + 26390 * i) / (pow(factorial(i), 4) * pow(396, 4 * i));
    r *= 2*sqrt(2)/9801;
    printf("%.48f\n" ,1.0 / r);
    return 0;
}
