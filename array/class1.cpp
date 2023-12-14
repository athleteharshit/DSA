#include<iostream>
#include<vector>
using namespace std;

//problem: Reverse a array
vector<int> reverse(vector <int> arr) {
    int start = 0;
    int end = arr.size() - 1;

    while(start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    return arr;
}

// problem: Extream print a array
void extreamPrint(vector<int> arr) {
    int start = 0;
    int end = arr.size() -1;

    while(start <= end) {
        if(start == end) {
             cout << arr[start] << endl;
        }else{
            cout << arr[start] << endl;
            cout << arr[end] << endl;
        }
        start++;
        end--;
    }
}

int main() {
    // vector<int> arr = {1,2,3,4,5};
    // extreamPrint(arr);
    // vector<int> rev = reverse(arr);
    // for(int i = 0; i < rev.size(); i++) {
    //     cout << rev[i] << endl;
    // }
    // cout << "hello !" << endl;
    return 0;
}