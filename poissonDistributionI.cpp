//A random variable, X, follows Poisson distribution with mean of 2.5.
//Find the probability with which the random variable X is equal to 5.

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int factorial(int x){
    int fact=1;
    for (int i=x; i>0; i--){
        fact*=i;
    }

    return fact;
};

double avgToK(int k, double avg){
    double total=1.0;
    for (int i=0; i<k; i++){
        total*=avg;
    }
    return total;
};

double euler(double avg){
    double total;
    double e=2.71828;
    double num=1.0;
    double denom=1.0;
    
    for (int i=0; i<5; i++){
        denom*=sqrt(e);
    }
    total=num/denom;
    
    return total;
};
    
    
    

double poissonDist(int k, double avg){
    double total=0.0;
    double num, denom;
    num=avgToK(k,avg);
    num*=euler(avg);
    denom=factorial(k);
    total=num/denom;
    
    return total;
};

int main() {
    double avg;
    int findProbOf;
    cin>>avg;
    cin>>findProbOf;
    double poisson=poissonDist(findProbOf,avg);
    cout<<fixed<<setprecision(3)<<poisson<<endl;
    return 0;
}
