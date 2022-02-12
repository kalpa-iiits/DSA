// Find array of nearest smaller to right
#include <bits/stdc++.h>

using namespace std;

vector<int> NSL(int arr[], int n){

  vector<int> res;
  stack<int> s;

  for(int i = 0; i < n; i++){   //step 1: check for conditions
    if(s.size() == 0) res.push_back(-1);   //condition 1

    else if(s.size() > 0 && s.top() < arr[i]){    //condition 2
      res.push_back(s.top());
    }
    else if(s.size() > 0 && s.top() >= arr[i]){   // condition 3
      
      while(s.size() > 0 && s.top() >= arr[i])
        s.pop();
      
      if(s.size() == 0) res.push_back(-1);
      else res.push_back(s.top());
      
    }
    s.push(arr[i]);    //step 2: push into stack
  }
  return res;
}

int main(){
  int arr[] = {2,3,1,4};
  int n = sizeof(arr)/sizeof(arr[0]);

  vector<int> res =  NSL(arr,n);
  for(int i = 0; i< res.size(); i++){
    cout << res[i] << " ";
  }
  return 0;
}