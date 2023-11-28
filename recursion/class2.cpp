#include<iostream>
using namespace std;

// problem:- climbing stairs https://leetcode.com/problems/climbing-stairs/ 

int climbingStairs(int n) {
    if(n == 1) return 1;
    if(n = 2) return 2;
    return climbingStairs(n - 1) + climbingStairs(n - 1);
}

int main() {
    return 0;
}