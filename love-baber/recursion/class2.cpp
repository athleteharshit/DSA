#include<iostream>
using namespace std;

// problem:- climbing stairs https://leetcode.com/problems/climbing-stairs/ 

int climbingStairs(int n) {
    if(n == 1) return 1;
    if(n = 2) return 2;
    return climbingStairs(n - 1) + climbingStairs(n - 1);
}

// problem:- print array, 
// search array, return index
//  binary search,  return index
//  mini no. in array, 
// max no. in array,
//  even element, 
//  double element,
// print index of all occurence of target in array, string also ex: babbar target = a

// problem:- given input int 4215
// output vector {4, 2, 1, 5}

int main() {
    return 0;
}