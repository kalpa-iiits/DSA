// Find array of nearest smaller to right
#include <bits/stdc++.h>

using namespace std;

int rain_water_tapping(int arr[], int n){

  int max_left[n], max_right[n];
  max_left[0] = arr[0];
  max_right[n-1] = arr[n-1];

  for(int i = 1; i< n; i++){
      max_left[i] = max(max_left[i-1], arr[i]);
  }

  for(int i = n-2; i>= 0; i--){
      max_right[i] = max(max_right[i+1], arr[i]);
  }

  int sum = 0;

  for(int i = 0; i<n;i++){
      int water_level = min(max_left[i], max_right[i]);
      sum += (water_level - arr[i]);
  }
  
  return sum;
}

int main(){
  int arr[] = {3,0,0,2,0,4};
  int n = sizeof(arr)/sizeof(arr[0]);

  int res =  rain_water_tapping(arr,n);
  cout << res << " ";
  return 0;
}