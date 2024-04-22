#include <iostream>
using namespace std;

void gantt_chart(int processes, int at[], int bt[], int iterator)
{
    int ct[processes] = {0};
    int pro[10] = {0};
    int l = 0;
    int temp_bt[processes];

    for(int i = 0; i < processes; i++)
    {
        temp_bt[i] = bt[i];
    }

    for(int arrival = 0; arrival < iterator; arrival++)
    {
        int process = -1;
        int min_bt = 1e7;
        int min_at = 1e7;

        for(int j = 0; j < processes; j++)
        {
            if(at[j] <= arrival && bt[j] != 0 && bt[j] < min_bt)
            {
                min_bt = bt[j];
                min_at = at[j];
                process = j;
            }
        }

        if(process != -1)
        {
            bt[process] -= min_bt;
            arrival += min_bt - 1;

            if(bt[process] == 0)
            {
                ct[process] = arrival + 1;
            }

            pro[l] = process + 1;
            l++;
        }
        else
        {
            pro[l] = -1;
            l++;
        }
    }

    cout << "\n";

    int tat[processes], wt[processes], avg_tat = 0, avg_wt = 0;

    for(int i = 0; i < processes; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - temp_bt[i];
        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    cout << "\nAverage TAT = " << (float)avg_tat / (float)processes << endl;
    cout << "Average WT = " << (float)avg_wt / (float)processes << endl;
}

int main()
{
    int processes;
    cout << "Enter the number of process: ";
    cin >> processes;

    int arrival_times[processes];
    int burst_times[processes];
    int iterator = 0;

    for(int i = 0; i < processes; i++)
    {
        cout << "Enter arrival time for process " << i + 1 << ": ";
        cin >> arrival_times[i];
    }

    for(int i = 0; i < processes; i++)
    {
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> burst_times[i];
        iterator += burst_times[i];
    }

    cout << endl;
    gantt_chart(processes, arrival_times, burst_times, iterator);

    return 0;
}
