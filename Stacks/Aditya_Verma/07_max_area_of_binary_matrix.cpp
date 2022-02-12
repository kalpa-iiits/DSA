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

int max_area_of_binary_rectangle(int arr[][4], int m, int n) {
        int result=0;
        int histogram[n];

        memset(histogram, 0, sizeof(histogram));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(arr[i][j]==1)
                    histogram[j]+=1;
                else
                    histogram[j]=0;
            }
            result = max(result, max_area_of_histogram(histogram, n));
        }
        return result;
}

int main(){
    int rows=4,cols = 4;
    int arr[][4] = {
        { 0, 1, 1, 0 },
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 },
        { 1, 1, 0, 0 },
    };

  int area =  max_area_of_binary_rectangle(arr,rows, cols);
  cout << area;

  return 0;
}