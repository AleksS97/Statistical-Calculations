//The final grades for a Physics exam taken by a large group of students
//have a mean of 70 and a standard deviation of 10. If we can approximate
//the distribution of these grades by a normal distribution, what percentage of the students:

//Scored higher than 80 (i.e., have a grade > 80)?
//Passed the test (i.e., have a grade >= 60)?
//Failed the test (i.e., have a grade < 60)?
//Find and print the answer to each question on a new line, rounded to a scale of 2 decimal places.

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
    double mean, stdDev, num1, num2;
    cin>>mean>>stdDev>>num1>>num2;
    //less than 80
    double numLE=calcPhi(80,mean,stdDev);
    numLE=1.00000-numLE;
    numLE*=100.00;
    cout<<fixed<<setprecision(2)<<numLE<<endl;
    //less than 60
    double numLS=calcPhi(60,mean,stdDev);
    numLS*=100.00;
    double numGS=100.000-numLS;
    cout<<numGS<<endl;
    cout<<numLS<<endl;
    

}