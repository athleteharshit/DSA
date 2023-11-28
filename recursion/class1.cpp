#include<iostream>
using namespace std;

// Problem:- power of 2 nth term
// base case n == 0 -> 1;
int pow(int n) {
    if(n == 0) return 1;
    return 2 * pow(n -1);
}

// Problem:- fibnacci series problem
// base case n == 0 -> 0, n == 1 -> 1;

int fib(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}
// iterative approach

// Problem:- sum of n to 1
// base case n == 1 -> 1;
int sum(int n) {
    if(n == 1) return 1;
    return n + sum(n -1);
}

int main() {
    cout << "hello" << sum(5) << endl;
    return 0;
}