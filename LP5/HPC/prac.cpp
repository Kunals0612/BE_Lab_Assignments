#include<bits/stdc++.h>
#include<omp.h>
using namespace std;

int min_seq(vector<int>& arr){
    int n = arr.size();
    int mini = INT_MAX;

    for(int i = 0; i < n; i++){
        mini = min(mini, arr[i]);
    }

    return mini;
}

int min_par(vector<int>& arr){
    int n = arr.size();
    int mini = INT_MAX;

    #pragma omp parallel for reduction(min: mini)
    for(int i = 0; i < n; i++){
        mini = min(mini, arr[i]);
    }

    return mini;
}

int max_seq(vector<int>& arr){
    int n = arr.size();
    int maxi = INT_MIN;

    for(int i = 0; i < n; i++){
        maxi = max(maxi, arr[i]);
    }

    return maxi;
}

int max_par(vector<int>& arr){
    int n = arr.size();
    int maxi = INT_MIN;

    #pragma omp parallel for reduction(max: maxi)
    for(int i = 0; i < n; i++){
        maxi = max(maxi, arr[i]);
    }

    return maxi;
}

long long sum_seq(vector<int>& arr){
    int n = arr.size();
    long long sum = 0;

    for(int i = 0; i < n; i++){
        sum += arr[i];
    }

    return sum;
}

long long sum_par(vector<int>& arr){
    int n = arr.size();
    long long sum = 0;
    
    #pragma omp parallel for reduction(+:sum)
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }

    return sum;
}

int main(){
    int n = 1e7;
    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        arr[i] = rand() % 100000;
    }

    double t1, t2;
    
    t1 = omp_get_wtime();
    int miniVal1 = min_seq(arr);
    t2 = omp_get_wtime();
    cout << "Minimum value for sequential: " << miniVal1 << " & time consumed: " << t2 - t1 << endl;

    t1 = omp_get_wtime();
    int miniVal2 = min_par(arr);
    t2 = omp_get_wtime();
    cout << "Minimum value for parallel: " << miniVal2 << " & time consumed: " << t2 - t1 << endl;

    t1 = omp_get_wtime();
    int miniVal3 = max_seq(arr);
    t2 = omp_get_wtime();
    cout << "Maximum value for sequential: " << miniVal3 << " & time consumed: " << t2 - t1 << endl;

    t1 = omp_get_wtime();
    int miniVal4 = max_par(arr);
    t2 = omp_get_wtime();
    cout << "Maximum value for parallel: " << miniVal4 << " & time consumed: " << t2 - t1 << endl;

    t1 = omp_get_wtime();
    int sum1 = sum_seq(arr);
    t2 = omp_get_wtime();
    cout << "Sum value for sequential: " << sum1 << " & time consumed: " << t2 - t1 << endl;

    t1 = omp_get_wtime();
    int sum2 = sum_par(arr);
    t2 = omp_get_wtime();
    cout << "Sum value for parallel: " << sum2 << " & time consumed: " << t2 - t1 << endl;
}