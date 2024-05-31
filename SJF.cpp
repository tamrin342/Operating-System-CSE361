#include<bits/stdc++.h>
using namespace std;
bool compare(const pair<int, int>&i, const pair<int, int>&j)
{
    return i.second < j.second;
}
int main()
{
    int process,val;
    cout << "Enter the Number of  Process : " ;
    cin>>process;
    int cpuTime[process],finishTime[process],turnAroundTime[process],waitingTime[process];
    vector<pair<int,int>> arrivalTime;
    vector<int> processOrder;

    cout << "Enter the CPU Times : " << endl ;
    for(int i=0; i<process; i++)
        cin >> cpuTime[i] ;

    cout << "Enter the Arrival times : " << endl ;
    for(int i=0; i<process; i++)
    {
        cin >> val;
        arrivalTime.push_back({val,i});
    }
    sort(arrivalTime.begin(), arrivalTime.end());

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({cpuTime[arrivalTime[0].second],arrivalTime[0].first,arrivalTime[0].second});
    int i=1;
    int current_time=0;

    while(!pq.empty()){
        int burst_time = pq.top()[0];
        int id = pq.top()[2];
        pq.pop();
        processOrder.push_back(id);
        current_time= current_time+burst_time;

        while(true){
            if(i<process && arrivalTime[i].first<=current_time){
                pq.push({cpuTime[arrivalTime[i].second],arrivalTime[i].first,arrivalTime[i].second});
                i++;
            }
            else break;
        }
    }

    int time =0;
    for(int i=0; i<process; i++)
    {
        time = time+cpuTime[processOrder[i]];
        finishTime[processOrder[i]] = time;
    }
    sort(arrivalTime.begin(),arrivalTime.end(),compare);

    for(int i=0; i<process; i++)
    {
      turnAroundTime[i] = (finishTime[i]-arrivalTime[i].first);
      waitingTime[i] = (turnAroundTime[i]-cpuTime[i]);
    }
    for(int i=0; i<process; i++)
    {
      cout<<"Process "<<i+1<<": Waiting Time: "<<waitingTime[i]<<" Turnaround Time: "<<turnAroundTime[i]<<endl;
    }
    float totalWT,totalTT=0;
    for(int i=0; i<process; i++)
    {
        totalWT = totalWT+waitingTime[i];
        totalTT = totalTT+turnAroundTime[i];
    }
    cout<<"Average Waiting Time : "<<(totalWT/process)<<endl;
    cout<<"Average Turnaround Time : "<<(totalTT/process);
}

