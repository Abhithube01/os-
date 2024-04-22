#include <bits/stdc++.h>
using namespace std;

class Process
{
    public:
    string name;
    float at,bt,ct,tat,wt;
};

int main()
{
    //input code
    int n;
    cout<<"enter the number of process"<<endl;
    cin>>n;
    Process P[n];
    for(int i=0;i<n;i++)
    {
        cout<<"enter name of process"<<endl;
        cin>>P[i].name;

        cout<<"enter the arrival time"<<endl;
        cin>>P[i].at;

        cout<<"enter the burst time"<<endl;
        cin>>P[i].bt;
    }
    //sorting code
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(P[j+1].at < P[j].at)
            {
                swap(P[j],P[j+1]);
            }
        }
    }
    cout<<endl;
    int temp=P[0].at;
    float avg_tat=0,avg_wt=0;
    for(int i=0;i<n;i++)
    {
        P[i].ct = temp + P[i].bt;
        if(P[i+1].at < P[i].ct)
        {
            temp = P[i].ct;
        }
        else{
            temp = P[i+1].at;
        }
        P[i].tat = P[i].ct - P[i].at;
        P[i].wt = P[i].tat - P[i].bt;
        avg_tat = avg_tat + P[i].tat;
        avg_wt = avg_wt + P[i].wt;
    }

    cout<<"Average Turn Around Time is"<<avg_tat/n<<endl;
    cout<<"Average Waiting Time is"<<avg_wt/n<<endl;
}