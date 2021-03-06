#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//this is a data structure which contains a variable representing a particular double, 
//as well as the number of repetitions of that variable

struct Instance{
    double num;
    int reps = 0;
};

//this function takes as input a reference to a vector of doubles and an integer representing the amount of array elements
//it takes in elements from the standard input stream and enters them into the vector container,
//adding each successive element to the stack of the vector data structure

void makeVector(vector<double>& nums){
    double num;
    while (cin>>num){
        nums.push_back(num);
    }
};

//this function takes in the vector of numbers and calculates its average,
//which is the sum divided by number of elements in the vector

double calcAvg(vector<double> nums){
    double avg;
    double total=0;
    for (int i=0; i<nums.size(); i++){
        total+=nums[i];
    }
    avg=total/nums.size();

    return avg;
}

//this function takes in a reference to the array of numbers
//and orders them from largest to smallest

void reOrder(vector<double>& nums){
    double temp;

    for (int i=0; i<nums.size()-1; i++){
        for (int j=0; j<nums.size()-1-i; j++){
            if (nums[j]<nums[j+1]){
                temp=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=temp;

            }
        }
    }
}


//this function prints every element within the vector container

void printVector(vector<double> nums){
    for (int i=0; i<nums.size(); i++){
        cout<<nums[i]<<endl;
    }
}

//this function calculates the median of the vector

double calcMedian(vector<double> nums){
    double median=0;


        median+=nums[nums.size()/2];
        median+=nums[(nums.size()/2)-1];
        median=median/2;

    return median;
}

//this function swaps two Instance data structures using pointers and temporary memory allocation

void swapInstances(Instance* one, Instance* two){
    Instance temp=*one;
    *one=*two;
    *two=temp;
};


//this function takes a reference to a vector of Instances
//and ranks them in terms of frequency
//starting with smallest, going to largest

void orderInstances(vector<Instance>& modes){

    Instance* one=NULL;
    Instance* two=NULL;
    for (int i=0; i<modes.size()-1; i++){
        for (int j=0; j<modes.size()-i-1; j++){
            if (modes[j].reps>modes[j+1].reps){
                one=&(modes[j]);
                two=&(modes[j+1]);
                swapInstances(one,two);
            }
        }
    }
};

//this functions calculates the mode of the vector, using the smallest number if there are multiple modes
double calcMode(vector<double> nums){
    vector<Instance> modes;
    Instance mode;
    bool seen=0;

    for (int i=0; i<nums.size(); i++){
        mode.num=nums[i];
        mode.reps=1;
        //check if it's in the vector already
        for (int j=0; j<modes.size(); j++){
            if ((mode.num)==modes[j].num){
                modes[j].reps++;
                seen=1;
            }
        }
        if (seen==0){
            modes.push_back(mode);
        }
        seen=0;
    }

    mode.reps=0;
    mode.num=0.0;

    orderInstances(modes);
    mode.num=modes[modes.size()-1].num;
    mode.reps=modes[modes.size()-1].reps;
    int r=modes.size()-2;

    while ((modes[r].reps==mode.reps)&&(mode.num<modes[r].num)){

        if (mode.num>(modes[r-1].num)){
            mode.reps=modes[r].reps;
            mode.num=modes[r].num;
            r--;
        }
        else {
            break;
        }
    }

    return mode.num;
}

int main() {

    //enter number of elements in array to be entered in subsequent line
    int size;
    cin>>size;

    //error checking to determine whether the number of elements is out of bounds
    if ((size<10)||(size>2500)){
        cerr<<"Wrong size! Try again"<<endl;
        exit (1);
    }

    //create vector using input from standard input stream
    vector<double> nums;
    makeVector(nums);

    //calculate and print the average on one line
    double average=calcAvg(nums);
    cout<<average<<endl;

    //sort array from largest to smallest
    reOrder(nums);
    
    //calculate median and print on second line
    double median=calcMedian(nums);
    cout<<median<<endl;
    
    //calculate mode and print on third line
    double mode=calcMode(nums);
    cout<<mode<<endl;

    return 0;
}
