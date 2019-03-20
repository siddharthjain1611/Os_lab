#include <iostream>
#include <queue>
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
    char level;
};

int main()
{
  //input N
    int N;
    cin>>N;
    //time quantum for RR queue
    int q=2;
    
    queue<node> fore_processes; 
    queue<node> back_processes;
    for(int i=0;i<N;i++){
        struct node process;
        cin>>process.pid;
        cin>>process.running_time;
        cin>>process.priority;
        cin>>process.level;
        if(process.level=='F')
            fore_processes.push(process);
        else
            back_processes.push(process);
    }

    int timer = q;
    int timer1 = 4; //for level 1 RR queue
    int timer2 = 1; //for level 2 FCFS queue
    int current_process_left = fore_processes.front().running_time;
    
    while(!fore_processes.empty() || !back_processes.empty()) {
        
        while(timer1 && !fore_processes.empty()) {
            struct node process = fore_processes.front();
            
            if(current_process_left==0) {
                cout<<process.pid<<"\n";
                fore_processes.pop();
                timer = q;
                current_process_left = fore_processes.front().running_time;  
            }
            else if(timer==0) {
                cout<<process.pid<<"\n";
                process = fore_processes.front();
                fore_processes.pop();
                process.running_time = current_process_left;
                fore_processes.push(process);
                timer = q;
                current_process_left = fore_processes.front().running_time;  
            }
            else if(timer1==1 && current_process_left>1) {
                cout<<process.pid<<"\n";
                timer--;
                current_process_left--;
            }
            else {
                timer--;
                current_process_left--;
            }

            timer1--;
            //cout<<timer<<" "<<timer1<<" "<<current_process_left<<"\n";
        }

        while(timer2>0 && !back_processes.empty()) {
            struct node process = back_processes.front();
            cout<<process.pid<<"\n";
            timer2-=process.running_time;
            back_processes.pop();
        }

        timer1 = 4;
        timer2 = 1;
        timer = q;
        current_process_left = fore_processes.front().running_time;
    }
    
  return 0;
}