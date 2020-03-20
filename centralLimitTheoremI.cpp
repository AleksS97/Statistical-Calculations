//A large elevator can transport a maximum of 9800 pounds.
//Suppose a load of cargo containing 49 boxes must be transported via the elevator.
//The box weight of this type of cargo follows a distribution with a mean of 205 pounds
//and a standard deviation of 15 pounds. Based on this information, what is the probability that all 
//boxes can be safely loaded into the freight elevator and transported?

//the following is a calculator which can determine the probability
//that a given number of inputs, each following a probability distribution
//described by the input mean and standard deviation,
//has a cumulative sum under the given amount

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

//cululative distribution function
double cdf(int weight, int mean, int stddev){
    //calculate z score
    double z = (double)(weight - mean)/stddev;
    //calculate probability that the sum of normally distributed
    //weights will fall under the limit
    return 0.5*(1+erf(z/sqrt(2)));
}

int main() {


    int weight, numBoxes, mean, stddev;
    cin >> weight >> numBoxes >> mean >> stddev;

    int sumOfMeans = numBoxes * mean;
    int sumOfStddevs = sqrt(numBoxes) * stddev;

    double prob = cdf(weight, sumOfMeans, sumOfStddevs);
    cout<<fixed<<setprecision(4)<<prob<<endl;

    return 0;
}
