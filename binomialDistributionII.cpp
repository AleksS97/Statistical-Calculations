//A manufacturer of metal pistons finds that, on average, 12% of the pistons they manufacture
//are rejected because they are incorrectly sized. What is the probability that a batch of  pistons will contain:
//No more than 2 rejects?
//At least 2 rejects?

#include <iostream>
#include <vector>
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

    num=factorial(n);
    denom=(factorial(x))*(factorial(n-x));
    comb=(double)num/(double)denom;

    return comb;
};
//p is 0.12, the prob success for one trial
double probSuc(double p, int numSuc){
    double suc=1.0;
    for (int i=0; i<numSuc; i++){
        suc*=p;
    }
    return suc;
};
//q is prob failure (0.88), n is 10, numSuc is whatever num you want
double probFail(double q, int n, int x){
    double fail=1.0;
    int exp=n-x;
    for (int i=0; i<exp; i++){
        fail*=q;
    }
    return fail;
};

double binomDist(int n, int x, double p, double q){
    double binomDist=0.0;
    int com=combination(n,x);
    double pass=probSuc(p,x);
    double fail=probFail(q,n,x);

    binomDist=com*pass*fail;

    return binomDist;
};
//n stays same, i changes for each val(so do for all ns), p and q are const
void pushInVect(int n, double p, double q, vector<double>& dists){
    double distAtx;
    for (int i=0; i<n; i++){
        distAtx=binomDist(n,i,p,q);
        dists.push_back(distAtx);
    }
};

double findProbBtw2Pnts(vector<double> dists, int beg, int fin){
    double prob=0.0;
    for (int i=beg;i<=fin; i++){
        prob+=dists[i];
    }
    return prob;
};

int main(){
    int numTrials;
    int numSuc;
    int numFail;
    double rateSuc;
    double rateFail;
    cin>>rateSuc>>numTrials;
    rateSuc=rateSuc/100;
    rateFail=1-rateSuc;
    numSuc=2;
    vector<double> distribution;
    pushInVect(numTrials,rateSuc,rateFail,distribution);
    //first between 0 and numSuc then numSuc and numTrials
    double p1=findProbBtw2Pnts(distribution,0,numSuc);
    double p2=findProbBtw2Pnts(distribution,numSuc,numTrials);
    cout<<fixed<<setprecision(3)<<p1<<endl;
    cout<<fixed<<setprecision(3)<<p2<<endl;

}
