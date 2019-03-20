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
    int q0=8, q1=16;

    queue<node> queue_0, queue_1, queue_2;
    for(int i=0;i<N;i++){
        struct node process;
        cin>>process.pid;
        cin>>process.running_time;
        cin>>process.priority;
        queue_0.push(process);
    }

    int timer = q0;
    int current_process_left = queue_0.front().running_time;

    while(!queue_0.empty()) {
        struct node process = queue_0.front();

        if(current_process_left==0) {
                cout<<process.pid<<"\n";
                queue_0.pop();
                timer = q0;
                current_process_left = queue_0.front().running_time;
            }
        else if(timer==0) {
            cout<<process.pid<<"\n";
            process = queue_0.front();
            queue_0.pop();
            process.running_time = current_process_left;
            queue_1.push(process);
            timer = q0;
            current_process_left = queue_0.front().running_time;
        }
        else {
            timer--;
            current_process_left--;
        }
    }

    timer = q1;
    while(!queue_1.empty()) {
        struct node process = queue_1.front();

        if(current_process_left==0) {
                cout<<process.pid<<"\n";
                queue_1.pop();
                timer = q1;
                current_process_left = queue_1.front().running_time;
            }
        else if(timer==0) {
            cout<<process.pid<<"\n";
            process = queue_1.front();
            queue_1.pop();
            process.running_time = current_process_left;
            queue_2.push(process);
            timer = q1;
            current_process_left = queue_1.front().running_time;
        }
        else {
            timer--;
            current_process_left--;
        }
    }

    while(!queue_2.empty()) {
        struct node process = queue_2.front();
        cout<<process.pid<<"\n";
        queue_2.pop();
    }
    return 0;
}
