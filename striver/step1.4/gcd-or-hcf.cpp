#include<iostream>
using namespace std;


// Euclidean Algorithm best approach
// gcd(a,b) = gcd(a -b , b) -> a > b
// gcd(a,b) = gcd(a % b, b) -> a > b 
// a should be greater then b

int calcGCD(int n, int m){

    while(n > 0 && m > 0) {
        if(n > m) {
            n = n % m;
        }else {
            m = m % n;
        }
    }

   if(n == 0) return m;
   return n;
}

int main() {
    cout << calcGCD(12, 9) << endl;
    return 0;
}