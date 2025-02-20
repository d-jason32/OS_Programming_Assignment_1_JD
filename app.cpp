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
    int endIndex = 0;
    // Number of pages randomly generated (Size of proccess)
    while (pagesUsed < totalPages){
        int randomNum = (rand() % 30) + 1;
        int processSize = randomNum * 80;
        int requiredPages = ceil(processSize / 160);
        pagesUsed += requiredPages;

        for(int i = startIndex; i < (startIndex + requiredPages) && i < 100; i++){
            arr[i] = currentProcess;
        }
        startIndex += requiredPages;
        currentProcess += 1;
        
        
    }
    for(int i = 0; i < 100; i++){
        printf("%d\n",arr[i]);
    }
    
    
}



int main() {
    // Create time seed for random integer. 
    srand(time(NULL));

    // Declare an array of 100 integers. 
    int emptyArr[100];

    userMemoryAllocation(emptyArr);

    return 0;
}