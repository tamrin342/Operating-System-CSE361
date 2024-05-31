#include<bits/stdc++.h>
using namespace std;

bool compare(const pair<int, int>&i, const pair<int, int>&j)
{
    return i.second < j.second;
}

int main()
{
    int process, val ;
    vector<int> waitingTime,turnAroundTime,cpuTime;
    vector<pair<int,int>> arrivalTime;

    cout << "Enter the Number of  Process : " ;
    cin >> process ;
    cout << "Enter the CPU times : " << endl ;
    for(int i=0; i<process; i++)
    {
        cin >> val;
        cpuTime.push_back(val);
    }
    cout << "Enter the Arrival times : " << endl ;
    for(int i=0; i<process; i++)
    {
        cin >> val;
        arrivalTime.push_back({val,i});
    }
    int finishTime[process];
    sort(arrivalTime.begin(), arrivalTime.end());
    val =0;
    for(int i=0; i<process; i++)
    {
       while(true){
        if(arrivalTime[i].first>val)
            val++;
        else break;
       }
        val = val+cpuTime[arrivalTime[i].second];
        finishTime[arrivalTime[i].second] = val;
    }
    sort(arrivalTime.begin(),arrivalTime.end(),compare);
    for(int i=0; i<process; i++)
    {
      turnAroundTime.push_back(finishTime[i]-arrivalTime[i].first);
      waitingTime.push_back(turnAroundTime[i]-cpuTime[i]);
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


