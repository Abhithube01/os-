#include<iostream>
using namespace std;

const int MAX_PROCESSES = 10;
const int MAX_RESOURCES = 10;
int seq[MAX_PROCESSES];

int is_safe(int allo[][MAX_RESOURCES], int need[][MAX_RESOURCES], int available[], int n, int m) {
    int work[MAX_RESOURCES];
    bool finish[MAX_PROCESSES] = {false};

    for(int i = 0; i < m; ++i)
        work[i] = available[i];

    for(int c = 0; c < n; ++c) {
        int found = 0;
        for(int i = 0; i < n; ++i) {
            if(!finish[i]) {
                int flag = 0;
                for(int j = 0; j < m; ++j) {
                    if(need[i][j] > work[j]) {
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0) {
                    for(int j = 0; j < m; ++j)
                        work[j] += allo[i][j];
                    finish[i] = true;
                    seq[c] = i;
                    found = 1;
                    break;
                }
            }
        }
        if(found == 0)
            return 0;
    }
    return 1;
}

void display_safe_state(int n) {
    cout << "The system is in a safe state.\n";
    cout << "Safe sequence: ";
    for(int i = 0; i < n; ++i)
        cout << seq[i] << " ";
    cout << endl;
}

void process_request(int allo[][MAX_RESOURCES], int need[][MAX_RESOURCES], int available[], int id,
                     int req[], int n, int m) {
    int f = 1;
    for(int i = 0; i < m; ++i) {
        if(req[i] > need[id][i] || req[i] > available[i]) {
            f = 0;
            break;
        }
    }
    if(f == 1) {
        cout << "The requested resources are within the process's need and available resources." << endl;
        for(int i = 0; i < m; ++i) {
            available[i] -= req[i];
            allo[id][i] += req[i];
            need[id][i] -= req[i];
        }
        if(is_safe(allo, need, available, n, m)) {
            display_safe_state(n);
            cout << "Request Granted" << endl;
        }
        else {
            cout << "System not in safe state. Process must wait\n";
            for(int i = 0; i < m; ++i) {
                available[i] += req[i];
                allo[id][i] -= req[i];
                need[id][i] += req[i];
            }
        }
    }
    else
        cout << "Request not granted\n";
}

int main() {
    int n, m;
    cout << "Enter no. of processes: ";
    cin >> n;
    cout << "Enter no. of resource types: ";
    cin >> m;

    int available[MAX_RESOURCES], req[MAX_RESOURCES];
    int allo[MAX_PROCESSES][MAX_RESOURCES], max[MAX_PROCESSES][MAX_RESOURCES],
    need[MAX_PROCESSES][MAX_RESOURCES];

    cout << "Enter Allocated matrix: ";
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> allo[i][j];

    cout << "Enter Max matrix: ";
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> max[i][j];

    cout << "Enter Available matrix: ";
    for(int i = 0; i < m; ++i)
        cin >> available[i];

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            need[i][j] = max[i][j] - allo[i][j];

    int ch, id;
    do {
        cout << "\nMenu: \n1.Check for safe state\n2.Request for process\n3.Exit\n";
        cout << "\nEnter Your Choice: ";
        cin >> ch;

        switch(ch) {
            case 1:
                if(is_safe(allo, need, available, n, m))
                    display_safe_state(n);
                else
                    cout << "System is not in safe state\n";
                break;
            case 2:
                cout << "Enter process no. for request: ";
                cin >> id;
                cout << "Enter request for process: ";
                for(int i = 0; i < m; ++i)
                    cin >> req[i];
                cout << endl;
                process_request(allo, need, available, id, req, n, m);
                break;
        }
    } while(ch != 3);

    return 0;
}
