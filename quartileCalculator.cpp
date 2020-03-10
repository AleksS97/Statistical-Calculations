#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void vectorMaker(vector<int>& x, int n){
    int input;
    for (int i=0; i<n; i++){
        cin>>input;
        if  ((input>0)&&(input<100)){
            x.push_back(input);
        }
    }
};

void swapMembers(int *i, int* j){
    int temp=*i;
    *i=*j;
    *j=temp;
};

void orderVector(vector<int>& x, int n){
    for (int i=1; i<n; i++){
        for (int j=0; j<n-i; j++){
            if (x[j]>x[j+1]){
                swapMembers(&(x[j]), &(x[j+1]));
            }
        }
    }
};

void printVector(vector<int> x, int n){
    cout<<endl;
    cout<<"n is "<<n<<endl;
    for (int i=0; i<n; i++){
        cout<<x[i]<<" ";
    }
}

int median(vector<int> x, int n){
    int med=0;
    if (n%2==0){
        med+=x[n/2];
        med+=x[(n-2)/2];
        med=med/2;
    }
    else if (n%2==1){
        med+=x[(n-1)/2];
    }

    return med;
};

int calcQ1(vector<int>x, int n){
    int q=0;
    if (n%2==1){
        q+=x[(n-1)/4];
        q+=x[((n-1)/4)-1];
        q=q/2;
    }
    else if (n%2==0){
        q+=x[n/4];
    }

    return q;
};


int calcQ3(vector<int>x, int n){
    int q3=0;
    if (n%2==0){
        if ((n/2)%2==1){
            q3+=x[(n*0.75)];
        }
        else {
            q3+=x[n*0.75];
            q3+=x[(n*0.75)-1];
            q3=q3/2;
        }
    }
    else if (n%2==1){
        q3+=x[((n-1)+((n+1)/2))/2];
        q3+=x[(((n-1)+((n+1)/2))/2)+1];
        q3=q3/2;
    }

    return q3;
};



int main() {
    int n;
    cin>>n;
    if ((n<5)||(n>50)){
        cerr<<"Wrong array size.";
        cin>>n;
    }
    vector<int> arr;
    vectorMaker(arr,n);
   
    orderVector(arr,n);
    
    int med=median(arr,n);
    int q1=calcQ1(arr,n);
    int q3=calcQ3(arr,n);

    cout<<q1<<endl;
    cout<<med<<endl;
    cout<<q3<<endl;
 

    return 0;
}
