#include <bits/stdc++.h>

using namespace std;

vector<int> nsl_index(int arr[], int n){

  vector<int> res;
  stack<pair<int,int> > s1;

  for(int i = 0; i < n; i++){   //step 1: check for conditions
    if(s1.size() == 0) res.push_back(-1);   //condition 1

    else if(s1.size() > 0 && s1.top().first < arr[i])   //condition 2
      res.push_back(s1.top().second);
    
    else if(s1.size() > 0 && s1.top().first >= arr[i]){   // condition 3
      
      while(s1.size() > 0 && s1.top().first >= arr[i])
        s1.pop();
      
      if(s1.size() == 0) res.push_back(-1);
      else res.push_back(s1.top().second);
    }
   s1.push({arr[i],i});
  }
  return res;
}

vector<int> nsr_index(int arr[], int n){

  vector<int> res;
  stack<pair<int,int> > s2;

  for(int i = n-1; i >= 0; i--){   //step 1: check for conditions
    if(s2.size() == 0) res.push_back(n);   //condition 1

    else if(s2.size() > 0 && s2.top().first < arr[i])   //condition 2
      res.push_back(s2.top().second);
    
    else if(s2.size() > 0 && s2.top().first >= arr[i]){   // condition 3
      
      while(s2.size() > 0 && s2.top().first >= arr[i])
        s2.pop();
      
      if(s2.size() == 0) res.push_back(n);
      else res.push_back(s2.top().second);
    }
   s2.push({arr[i],i});
  }
  reverse(res.begin(), res.end());
  return res;
}

int max_area_of_histogram(int arr[], int n){
  vector<int> left = nsl_index(arr, n);
  vector<int> right = nsr_index(arr, n);

  int max_area = INT_MIN;

  for(int i = 0; i<n; i++){
    max_area = max(max_area, (right[i] - left[i]-1)*arr[i] );
  }
  return max_area;
}

int main(){
  int arr[] = {6, 2, 5, 4, 5, 1, 6};
  int n = sizeof(arr)/sizeof(arr[0]);

  int area =  max_area_of_histogram(arr,n);
  cout << area;

  return 0;
}