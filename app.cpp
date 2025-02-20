#include <iostream>
#include <cmath>
#include <cstdlib>

void userMemoryAllocation(int arr[]) { 
    int address = 2000;
    int currentProcess = 1;
    int totalPages = 100;
    int pagesUsed = 0;
    int startIndex = 0;
    
    // Stop when all pages are used
    while (pagesUsed < totalPages){
        // Initialize random int from 1-30
        int randomNum = (rand() % 30) + 1;

        // Process size is number of pages * 80
        int processSize = randomNum * 80;

        // Required pages is the ceiling of the processSize / 160. 
        int requiredPages = ceil( (double) processSize / 160);

        // Update pagesUsed with the requiredPages needed for the current process.
        pagesUsed += requiredPages;

        // Calculate unusedSpace. 
        int unusedSpace = (requiredPages*160) - processSize;

        // Fill array with process id
        for(int i = startIndex; i < (startIndex + requiredPages) && i < totalPages; i++){
            arr[i] = currentProcess;
        }
        
        printf("%-15d %-25d %-30d %-10d\n", currentProcess, address, processSize, unusedSpace);
        
        startIndex += requiredPages;
        currentProcess += 1;
        address += requiredPages * 160;
    }
    
}

int main() {
    // Create time seed for random integer. 
    srand(time(NULL));

    // Declare an array of 100 integers. 
    int emptyArr[100] = {0};
    
    std::cout << "\033[4mProcess ID: | Starting Memory Address: | Size of the Process MB  | Unused Space MB\033[0m" << std::endl;

    userMemoryAllocation(emptyArr);

    return 0;
}