/*
The span Si of the stocks price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.

Example 1:

Input: 
N = 7, price[] = [100 80 60 70 60 75 85]
Output:
1 1 1 2 1 4 6
Explanation:
Traversing the given input span for 100 
will be 1, 80 is smaller than 100 so the 
span is 1, 60 is smaller than 80 so the 
span is 1, 70 is greater than 60 so the 
span is 2 and so on
*/

// Find array of nearest smaller to right
#include <bits/stdc++.h>

using namespace std;

vector<int> ngl_index(int arr[], int n){

  vector<int> res;
  stack<pair<int,int> > s;

  for(int i = 0; i < n; i++){   //step 1: check for conditions
    if(s.size() == 0) res.push_back(-1);   //condition 1

    else if(s.size() > 0 && s.top().first > arr[i])   //condition 2
      res.push_back(s.top().second);
    
    else if(s.size() > 0 && s.top().first <= arr[i]){   // condition 3
      
      while(s.size() > 0 && s.top().first <= arr[i])
        s.pop();
      
      if(s.size() == 0) res.push_back(-1);
      else res.push_back(s.top().second);
    }
   s.push({arr[i],i});
  }

  for (int i=0;i < res.size();i++)
    {
       res[i]=i-res[i]; // subtract normal index from the vector index v[i]
    }
    return res;
}

int main(){
  int arr[] = {100, 80, 60, 70, 60, 75, 85};
  int n = sizeof(arr)/sizeof(arr[0]);

  vector<int> res =  ngl_index(arr,n);
  for(int i = 0; i< res.size(); i++){
    cout << res[i] << " ";
  }
  return 0;
}