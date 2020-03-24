//The number of tickets purchased by each student for the University X vs. University Y football game
//follows a distribution that has a mean of 2.4 and a standard deviation of 2.0.
//A few hours before the game starts, 100 eager students line up to purchase last-minute tickets.
//If there are only 250 tickets left, what is the probability that all 100 students will be able to purchase tickets?

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

double cdf(double tickets, double students, double sampleMean, double stddev){

    return 0.5 * (1+erf((tickets - sampleMean * students)/(stddev *  sqrt(2))));
}

int main() {
    
    double tickets, students , sampleMean, sampleStddev;

    cin >> tickets >> students >> sampleMean >> sampleStddev;

    double stddev = sampleStddev * sqrt(students);

    double prob = cdf(tickets, students, sampleMean, stddev);
    cout << fixed << setprecision(4) << prob << endl;
    return 0;

}
