
#include <bits/stdc++.h>
using namespace std;

int maxSum(int arr[], int n, int k){
    if(k > n)return -1;
    int sum  = 0;

    int i = 0, j=0, res = INT_MIN;

    while(j < n){
        sum += arr[j];
        if(j-i+1 < k){
            j++;
        }
        else if(j-i+1 == k){
            res = max(res, sum);
            sum -= arr[i];
            i++;
            j++;
        }
        
    }
    return res;
}

int main(){
    int arr[] = { 1, 4 ,2, 10, 2, 3, 1, 0 ,20};
    int k = 4;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << maxSum(arr, n, k);
    return 0;
}