#include <iostream>
#include <vector>
#include <queue>
#include <functional>
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

//comparator    
class compare {
    public:
        bool operator() (node const& lhs, node const& rhs) const {
        if (lhs.priority != rhs.priority)
            return lhs.priority > rhs.priority;
        return lhs.pid > rhs.pid;
    }
};

int main()
{
    //input N
    int N;
    cin>>N;
    
    //to store the ids according to resultant order
    priority_queue<node, vector<node>, compare > processes; 
    for(int i=0;i<N;i++){
        struct node process;
        cin>>process.pid;
        cin>>process.running_time;
        cin>>process.priority;
        processes.push(process);
    }
    
    int timer = 0;
    for(int i=0;i<N;i++) {
        struct node process;
        process = processes.top();
        process.order = i+1;
        process.waiting_time = timer;
        timer+=process.running_time;
        process.turnaround_time = process.waiting_time + process.running_time;
        processes.pop();
        cout<<process.pid<<"\n";
    }
 
    return 0;
}
