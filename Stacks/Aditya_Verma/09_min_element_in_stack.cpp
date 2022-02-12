// Find array of nearest smaller to right
#include <bits/stdc++.h>

using namespace std;

void push(int a){
    s.push(a);
    if(ss.size() == 0 || ss.top() >= a)
        ss.push(a);
}


int pop(){
    if(s.size() == 0) return -1;
    int ans = s.top();
    s.pop();
    if(ans == ss.top()) ss.pop()
    return ans;
}

int getMin(){
    if(ss.size() == 0) return -1;
    return ss.top();
}

int main(){
  int arr[] = {18,19,29,15,16};
  int n = sizeof(arr)/sizeof(arr[0]);

  
  return 0;
}