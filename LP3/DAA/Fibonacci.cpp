#include<bits/stdc++.h>
using namespace std;

//fibonacciRecusrive
int fibonacciRecursive(int n, int& count){
    if(n == 0 || n == 1){
        return n;
    }
    count++;
    return fibonacciRecursive(n-1, count) + fibonacciRecursive(n-2, count);
}

//fibonacciIterative
int fibonacciIterative(int n, int &count){
    int a = 0, b = 1;
    int num;
    for(int i = 2; i <= n; i++){
        num = a + b;
        a = b;
        b = num;
        count++;
    }
    return num;
}

int main(){
    int n = 10;
    int count1 = 0, count2 = 0;
    cout << "Fibonacci Number for N = " << n << ": " << fibonacciRecursive(n,count1) << endl;
    cout << "Fibonacci Number for N = " << n << ": " << fibonacciIterative(n,count2) << endl;

    cout << "Steps for recusrive for N = "  << n << ": " << count1 << endl;
    cout << "Steps for iterative for N = " << n << ": " << count2 << endl;
}