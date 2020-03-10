#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

void makeVector(vector<int>&nums, int n){
    int input;
    for (int i=0; i<n; i++){
        cin>>input;
        if (0<input<=100){
            nums.push_back(input);
        }
    }
};

void swapMembers(int *i, int* j){
    int temp=*i;
    *i=*j;
    *j=temp;
};

void orderVector(vector<int>& x, int n){

    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            if (x[i]>x[j]){
                swapMembers(&(x[i]), &(x[j]));
            }
        }
    }
};

void makeFrequencySet(vector<int>nums, vector<int>freq, vector<int>& set, int n){
    int repeats;
    int num;

    for (int i=0; i<n; i++){
        num=nums[i];
        repeats=freq[i];
        for (int j=0; j<repeats;j++){
            set.push_back(num);
        }
    }
};

void splitSet(vector<int>set1, vector<int>&lowSet, vector<int>& highSet){
    int num;
    if (set1.size()%2==0){
        for (int i=0; i<(set1.size()/2); i++){
                num=set1[i];
                lowSet.push_back(num);
        }
        for (int j=(set1.size()/2); j<set1.size(); j++){
                num=set1[j];
                highSet.push_back(num);
        }
    }
    else if (set1.size()%2==1){
        for (int k=0; k<(set1.size()/2); k++){
                num=set1[k];
                lowSet.push_back(num);
        }
        for (int l=(set1.size()/2)+1; l<set1.size(); l++){
                num=set1[l];
                highSet.push_back(num);
        }
    }
};

double findQ(vector<int> highOrLow){
    double q=0.0;
    if (highOrLow.size()%2==0){
        q+=(double)highOrLow[(highOrLow.size()/2)];
        q+=(double)highOrLow[(highOrLow.size()/2)-1];
        q=q/2;
    }
    else if (highOrLow.size()%2==1){
        q=(double)highOrLow[((highOrLow.size()-1)/2)];
    }
    return q;
};

void printVector(vector<int> x, int n){
    for (int i=0; i<n; i++){
        cout<<x[i]<<" ";
    }
}

int main() {
    int n;
    cin>>n;
    vector<int> nums;
    vector<int> freq;
    vector<int> set1;
    makeVector(nums, n);
    makeVector(freq, n);
    makeFrequencySet(nums,freq,set1,n);
  
    orderVector(set1,set1.size());
    vector<int> highSet;
    vector<int> lowSet;
    splitSet(set1,lowSet,highSet);
   
    double q1=findQ(lowSet);
    double q3=findQ(highSet);
    double rng=q3-q1;
    cout<<fixed<<setprecision(1)<<rng<<endl;
};

