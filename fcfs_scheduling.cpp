#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;

struct node {
    int pid;
    int timestamp;
    int running_time;
    int waiting_time;
    int turnaround_time;
    int priority;
    int order;
};

int main()
{
    //input N
    int N;
    cin>>N;
    
    //to store the ids according to resultant order
    vector<node> processes; 
    for(int i=0;i<N;i++){
        struct node process;
        cin>>process.pid;
        cin>>process.running_time;
        cin>>process.priority;
        processes.push_back(process);
    }
    
    int timer = 0;
    for(int i=0;i<N;i++) {
        struct node process;
        process = processes[i];
        process.order = i+1;
        process.waiting_time = timer;
        timer+=process.running_time;
        process.turnaround_time = process.waiting_time + process.running_time;
        cout<<process.pid<<"\n";
    }
 
    return 0;
}
