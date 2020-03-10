//The ratio of boys to girls for babies born in Russia is 1.09.
//If there is 1 child born per birth, what proportion of Russian
//families with exactly 6 children will have at least 3 boys?

#include <iostream>
#include <iomanip>
using namespace std;

int factorial(int x){
    int prod=1;
    for (int i=x; i>0; i--){
        prod*=i;
    }
    return prod;
};

//find binomial distribution

//n is numTrials, x is numBoys
double findComb(int n, int x){
    double comb;
    int num=1;
    int denom=1;

    num=factorial(n);
    denom=factorial(x)*factorial(n-x);
    comb=((double)num)/((double)denom);

    return comb;
};

double findProbSuccess(double pBoy, int x){
    double suc=(pBoy)/(pBoy+1);
    double probSuc=1;

    for (int i=0; i<x;i++){
        probSuc*=suc;
    }

    return probSuc;
};

double findProbFail(double pBoy, int n, int x){
    double q=1-(pBoy/(pBoy+1));
    double probFail=1.0;
    int reps=n-x;

    for (int i=0; i<reps; i++){
        probFail*=q;
    }
    return probFail;
};

double calcBinomDist(double comb, double probSuc, double probFail){
    double dist=1.0;
    dist=comb*probSuc*probFail;

    return dist;
};

double findSumBinomDist(int x, int n, double probBoy){
    double sum=0.0;
    double comb, suc, fail, binom;

    for (int i=x; i<=n; i++){
            comb=findComb(n,i);
            suc=findProbSuccess(probBoy,i);
            fail=findProbFail(probBoy,n,i);
            binom=calcBinomDist(comb,suc,fail);
            sum+=binom;
    }
    return sum;

};

int main(){
    double probBoy;
    double probGirl;
    int n=6;
    //how many boys
    int x=3;
    cin>>probBoy>>probGirl;
    double binomDist=findSumBinomDist(x,n,probBoy);


    cout<<fixed<<setprecision(3)<<binomDist<<endl;

};