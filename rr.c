#include <stdio.h>

struct process {
    int pid;
    int bt;
    int temp_bt;
    int tat;
    int wt;
} p[10];

int main() {
    int i, n, qt;
    printf("Enter the total number of processes:");
    scanf("%d", &n);
    printf("Enter the process ID and burst time of each process:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &p[i].pid, &p[i].bt);
        p[i].temp_bt = p[i].bt;
    }
    printf("Enter the quantum time:");
    scanf("%d", &qt);
    
    int x = 0; // FOR TIME
    int y = 0; // FOR PROCESS COMPLETION
    int z = 0; // TO DETERMINE THE CURRENT PROCESS

    while (y < n) {
        if (p[z].bt > 0) {
            if (p[z].bt > qt) {
                x = x + qt;
                p[z].bt = p[z].bt - qt;
            } else {
                x = x + p[z].bt;
                p[z].bt = 0;

                p[z].tat = x;
                p[z].wt = p[z].tat - p[z].temp_bt;

                y++;
            }
        }
        z = (z + 1) % n; // Circular increment to handle all processes

        if (y == n) break;
    }

    printf("PROCESS ID\tBURST TIME\tWAITING TIME\tTURN AROUND TIME\n");
    int sum = 0, wts = 0;
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].temp_bt, p[i].wt, p[i].tat);
        sum += p[i].tat;
        wts += p[i].wt;
    }

    printf("The average TAT is: %d\n", sum / n);
    printf("The average WT is: %d\n", wts / n);

    return 0;
}
