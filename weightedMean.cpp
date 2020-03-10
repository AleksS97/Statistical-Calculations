#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

//this program makes in an array of integers and an array representing the weights of each element
//it prints the weighted mean to a precision of one decimal space

struct Weighted{
    int num;
    int weight;
};

void makeVector(vector<Weighted>& mean, int n){
        vector<int> nums;
        vector<int> weights;
        int a;
        int b;

        for (int i=0; i<n; i++){
            cin>>a;
            if (0<a<=100){
                nums.push_back(a);
            }
        }
        for (int j=0; j<n; j++){
            cin>>b;
            if (0<b<=100){
                weights.push_back(b);
            }
        }

        Weighted input;
        for (int k=0; k<n; k++){
            input.num=nums[k];
            input.weight=weights[k];
            mean.push_back(input);
        }
};

int numerator(vector<Weighted> mean, int n){
    int running=0;
    for (int i=0; i<n; i++){
        running+=((mean[i].num)*(mean[i].weight));
    }
    return running;
};

int denom(vector<Weighted> mean, int n){
    int sum=0;
    for (int i=0; i<n; i++){
        sum+=(mean[i].weight);
    }
    return sum;
};

double weightMean(int num, int denom){
    double mean;
    mean=(double)num/(double)denom;
    return mean;
};

int main() {
    int n;
    cin>>n;
    if ((n>50)||(n<5)){
        cerr<<"Too many or few numbers!"<<endl;
    }
    vector<Weighted> mean;
    makeVector(mean,n);
    int num=numerator(mean,n);
    int den=denom(mean, n);
    double wmean=weightMean(num, den);
    cout<<fixed<<setprecision(1)<<wmean<<endl;

    return 0;
}

