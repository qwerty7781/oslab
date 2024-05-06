#include <stdio.h>

#define MEMORY_SIZE 100

// Function to initialize memory blocks as free
void initializeMemory(int memory[], int size) {
    for (int i = 0; i < size; i++) {
        memory[i] = -1; // -1 represents free memory
    }
}

// Function to allocate memory using Best Fit algorithm
int allocateMemoryBestFit(int memory[], int size, int processSize) {
    int minSize = MEMORY_SIZE + 1;
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (memory[i] == -1) {
            int blockSize = 0;
            int j = i;
            while (j < size && memory[j] == -1) {
                blockSize++;
                j++;
            }
            if (blockSize >= processSize && blockSize < minSize) {
                minSize = blockSize;
                index = i;
            }
            i = j; // Move the index to the next free memory block
        }
    }

    // If a suitable block is found, allocate memory
    if (index != -1) {
        for (int i = index; i < index + processSize; i++) {
            memory[i] = processSize;
        }
    }
    return index;
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

        int allocatedIndex = allocateMemoryBestFit(memory, MEMORY_SIZE, processSize);
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
