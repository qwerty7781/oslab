#include <stdio.h>

struct Process {
    int pid; // Process ID
    int arrival_time; // Arrival time of the process
    int burst_time; // Burst time of the process
    int completion_time; // Completion time of the process
    int turnaround_time; // Turnaround time of the process
    int waiting_time; // Waiting time of the process
};

void calculateCompletionTime(struct Process processes[], int n) {
    int current_time = 0;
    int completed = 0;
    while (completed < n) {
        int shortest_job = -1;
        int shortest_burst = 999999; // Initialize with a large value
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].completion_time == -1) {
                if (processes[i].burst_time < shortest_burst) {
                    shortest_burst = processes[i].burst_time;
                    shortest_job = i;
                }
            }
        }
        if (shortest_job != -1) {
            processes[shortest_job].completion_time = current_time + processes[shortest_job].burst_time;
            current_time = processes[shortest_job].completion_time;
            completed++;
        } else {
            current_time++;
        }
    }
}

void calculateTurnaroundTime(struct Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
    }
}

void calculateWaitingTime(struct Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }
}

void printProcessDetails(struct Process processes[], int n) {
    printf("Process\t Arrival Time\t Burst Time\t Completion Time\t Turnaround Time\t Waiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\t\t %d\n", processes[i].pid, processes[i].arrival_time,
               processes[i].burst_time, processes[i].completion_time, processes[i].turnaround_time,
               processes[i].waiting_time);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    // Input process details
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].completion_time = -1; // Initialize completion time to -1
    }

    // Calculate completion time
    calculateCompletionTime(processes, n);

    // Calculate turnaround time
    calculateTurnaroundTime(processes, n);

    // Calculate waiting time
    calculateWaitingTime(processes, n);

    // Print process details
    printProcessDetails(processes, n);

    return 0;
}
