#include <stdio.h>

#define MEMORY_SIZE 100

// Function to initialize memory blocks as free
void initializeMemory(int memory[], int size) {
    for (int i = 0; i < size; i++) {
        memory[i] = -1; // -1 represents free memory
    }
}

// Function to allocate memory using First Fit algorithm
int allocateMemoryFirstFit(int memory[], int size, int processSize) {
    for (int i = 0; i < size; i++) {
        int j;
        // Find the first free memory block of sufficient size
        for (j = i; j < size && memory[j] != -1; j++) {
            if (memory[j] != -1 && memory[j] >= processSize) {
                // Allocate memory
                memory[j] = processSize;
                return j;
            }
        }
        i = j; // Move the index to the next free memory block
    }
    return -1; // No suitable block found
}

// Function to display memory status
void displayMemory(int memory[], int size) {
    printf("Memory Status:\n");
    for (int i = 0; i < size; i++) {
        if (memory[i] == -1) {
            printf("[ Free ] ");
        } else {
            printf("[ %d ] ", memory[i]);
        }
    }
    printf("\n");
}

int main() {
    int memory[MEMORY_SIZE];
    initializeMemory(memory, MEMORY_SIZE);

    int processSize;
    int processId = 1;
    char choice;

    do {
        printf("Enter the size of the process %d: ", processId);
        scanf("%d", &processSize);

        int allocatedIndex = allocateMemoryFirstFit(memory, MEMORY_SIZE, processSize);
        if (allocatedIndex != -1) {
            printf("Process %d allocated at memory block %d.\n", processId, allocatedIndex);
        } else {
            printf("Memory allocation failed for process %d. Not enough memory available.\n", processId);
        }

        displayMemory(memory, MEMORY_SIZE);

        printf("Do you want to allocate more processes? (y/n): ");
        scanf(" %c", &choice);

        processId++;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
