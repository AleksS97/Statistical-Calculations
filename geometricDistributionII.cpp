//The probability that a machine produces a defective product is 1/3.
//What is the probability that the 1st defect is found during the first 5 inspections?

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

//finds the number of combinations
//of n total trials and x broken trials
double combination(int n, int x){
    double comb=1.0;
    int num, denom;
    int newN=n-1;
    int newX=x-1;
    
    num=factorial(newN);
    denom=(factorial(newX))*(factorial(newN-newX));
    comb=(double)num/(double)denom;

    return comb;
};
//p is , the prob success for one trial
double probSuc(double p, int numSuc){
    double suc=1.0;
    for (int i=0; i<numSuc; i++){
        suc*=p;
    }
    return suc;
};
//q is prob failure 2/3, n is num trials, x is numSuccesses
double probFail(double q, int n, int x){
    double fail=1.0;
    int exp=n-x;
    for (int i=0; i<exp; i++){
        fail*=q;
    }
    return fail;
};

double binomDist(int n, int x, double p, double q){
    double binomD=0.0;
    int com=combination(n,x);
    double pass=probSuc(p,x);
    double fail=probFail(q,n,x);

    binomD=com*pass*fail;

    return binomD;
};

double negBinomDist(int n, int x, double p, double q){
    double prob=0.0;
    for (int i=n;i>0; i--){
        prob+=binomDist(i,1,p,q);
    }
    return prob;
}

int main() {
    int num,denom,trials;
    cin>>num>>denom;
    cin>>trials;
    double prop=(double)num/(double)denom;
    double propF=1-prop;
    double neg=negBinomDist(trials,1,prop,propF);
    
    cout<<fixed<<setprecision(3)<<neg<<endl;
    
    return 0;
}
