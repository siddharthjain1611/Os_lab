#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct node{
    int pid;
    int timestamp;
    int running_time;
    int waiting_time;
    int priority;
    int order;
};

int main()
{
	//input N
    int N;
    cin>>N;
    //input time quantum
    int q;
    cin>>q;
    
    queue<node> processes; 
    for(int i=0;i<N;i++){
        struct node process;
        cin>>process.pid;
        cin>>process.running_time;
        cin>>process.priority;
        processes.push(process);
    }

    //int ctr=20;
    int timer = q;
    int current_process_left = processes.front().running_time;
    while(!processes.empty()) {
        
        struct node process = processes.front();
        
        if(current_process_left==0) {
            cout<<process.pid<<"\n";
            if(processes.size()==1)
                break;
            processes.pop();
            timer = q;
            current_process_left = processes.front().running_time;  
        }
        else if(timer==0) {
            cout<<process.pid<<"\n";
            if(processes.size()==1)
                break;
            process = processes.front();
            processes.pop();
            process.running_time = current_process_left;
            processes.push(process);
            timer = q;
            current_process_left = processes.front().running_time;  
        }
        else {
            timer--;
            current_process_left--;
        }
    }
    
	return 0;
}