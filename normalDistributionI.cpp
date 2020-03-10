//In a certain plant, the time taken to assemble a car is a random variable, X, 
//having a normal distribution with a mean of 20 hours and a standard deviation of 2 hours.
//What is the probability that a car can be assembled at this plant in:
//Less than 19.5 hours?
//Between 20 and 22 hours?

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

const double e=2.71828;

double erf(double z){
        double t = 1.0 / (1.0 + 0.5 * abs(z));

        // use Horner's method
        double ans = 1 - t * pow(e,( -z*z   -   1.26551223 +
                                            t * ( 1.00002368 +
                                            t * ( 0.37409196 +
                                            t * ( 0.09678418 +
                                            t * (-0.18628806 +
                                            t * ( 0.27886807 +
                                            t * (-1.13520398 +
                                            t * ( 1.48851587 +
                                            t * (-0.82215223 +
                                            t * ( 0.17087277)))))))))));
        if (z >= 0) return  ans;
        else        return -ans;
}

double calcPhi(double x, double mean, double stdDev){
    //find erf 
    double erfResNum=x-mean;
    double erfResDenom=stdDev*(sqrt(2));
    double inParends=erfResNum/erfResDenom;
    double finalVal=erf(inParends);
    finalVal+=1;
    finalVal/=2;
    return finalVal;
}




int main(){
    double mean, stdDev;
    double test1, rng1, rng2;
    cin>>mean>>stdDev>>test1>>rng1>>rng2;
    double norLess=calcPhi(test1,mean,stdDev);
    cout<<norLess<<endl;
    //find <20 and <22
    double diff=calcPhi(rng2,mean,stdDev)-calcPhi(rng1,mean,stdDev);
    cout<<diff<<endl;
    
}
