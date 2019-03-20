#include <iostream>
#include <string>

using namespace std;

int main() {

  int N; // no of resources
  cin>>N;
  int available[N]; 
  for(int i=0;i<N;i++)
    cin>>available[i];
  
  int P; // no of processes
  cin>>P;
  
  int allocation[P][N];
  int max_req[P][N];
  int need[P][N];

  for(int i=0;i<P;i++) {
    for(int j=0;j<N;j++)
      cin>>allocation[i][j];
  }
  for(int i=0;i<P;i++) {
    for(int j=0;j<N;j++)
      cin>>max_req[i][j];
  }

  for(int i=0;i<P;i++) {
    for(int j=0;j<N;j++)
      need[i][j] = max_req[i][j] - allocation[i][j];
  }

  bool flag = false;
  string result = "SAFE";
  for(int i=0;i<P;i++) {
    for(int j=0;j<N;j++) {
      available[j] -= need[i][j];
      //check if possible
      if(available[j]<0) {
        result = "UNSAFE";
        flag = true;
        break;
      }
    }
    if(flag)
      break;
    //free the resources of this process
    for(int j=0;j<N;j++) {
      available[j]+=max_req[i][j];
    }
  }

  cout<<result;
  return 0;

}