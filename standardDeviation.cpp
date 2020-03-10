#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

void makeVector(vector<int>& nums, int n){
    int num;
    for (int i=0; i<n; i++){
        cin>>num;
        if (0<num<=100000){
            nums.push_back(num);
        }
    }
};

double mean(vector<int>& nums, int n){
    double sum=0.0;
    double mean=0.0;
    for (int i=0; i<n; i++){
        sum+=nums[i];
    }
    mean=sum/n;
    
    return mean;
};

void calcStdDev(vector<int>& nums, int n, double mean, vector<double>& stdDev){
    double stdDevi;
    for (int i=0; i<n; i++){
        stdDevi=((nums[i])-(mean))*((nums[i]-mean));
        stdDev.push_back(stdDevi);
    }
};

double doSummationAvg(vector<double> stdDev, int n){
    double sumt=0.0;
    double stand=0.0;
    for (int i=0; i<n; i++){
        sumt+=stdDev[i];
    }
    stand=sumt/n;
      
    return stand;
};


int main() {
    int n;
    cin>>n;
    if ((n<5)||(n>100)){
        cerr<<"Error with nsize"<<endl;
        exit;
    }
    vector<int> nums;
    vector<double> stds;
    
    makeVector(nums,n);
    double mean1=mean(nums,n);
    calcStdDev(nums, n, mean1, stds);
    double stdDev=doSummationAvg(stds,n);
    stdDev=sqrt(stdDev);
    cout<<fixed<<setprecision(1)<<stdDev<<endl;
    return 0;
}
