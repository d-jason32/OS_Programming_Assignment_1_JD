/*
16 GB of memory total 
Divided into 100 Pages
Each page has 160 MB. 
*/

#include <iostream>
#include <cmath>
#include <cstdlib>

void userMemoryAllocation(int arr[]) { 
    int address = 2000;
    int currentProcess = 1;
    int totalPages = 100;
    int pagesUsed = 0;
    int startIndex = 0;
    
    // Number of pages randomly generated (Size of proccess)
    while (pagesUsed < totalPages){
        int randomNum = (rand() % 30) + 1;
        int processSize = randomNum * 80;
        int requiredPages = ceil( (double) processSize / 160);
        pagesUsed += requiredPages;
        int unusedSpace = (requiredPages*160) - processSize;

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