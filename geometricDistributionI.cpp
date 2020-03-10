//The probability that a machine produces a defective product is 1/3.
//What is the probability that the 1st defect is found during the 5th inspection?

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

//calc prob that 1st defect in 3rd prob
//n is numTrials, p is probSuc
double findGeomDist(int n, double p){
    double dist=0.0;
    double rateFail=1.0-p;
    double t1=1.0;
    for (int i=0; i<n-1; i++){
        t1*=rateFail;
    }
    dist=t1*p;
    
    return dist;
};
                       
int main(){             
    int num, denom, trials;
    cin>>num>>denom;
    cin>>trials;
    double rateSuc=(double)num/(double)denom;
    double geomDist=findGeomDist(trials,rateSuc);
    cout<<fixed<<setprecision(3)<<geomDist<<endl;
}
