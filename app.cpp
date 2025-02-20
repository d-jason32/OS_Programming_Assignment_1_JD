/*
16 GB of memory total 
Divided into 100 Pages
Each page has 160 MB. 
*/

#include <iostream>
#include <cmath>
#include <cstdlib>

void userMemoryAllocation(int x[]) { 
    int y = x[1];
    // Number of pages randomly generated (Size of proccess)
    int randomNum = (rand() % 30) + 1;
    
    int processSize = randomNum * 80;

    int requiredPages = ceil(processSize / 160);
}

void printReport(){

}

int main() {
    // Create time seed for random integer. 
    srand(time(NULL));

    // Declare an array of 100 integers. 
    int arr[100];


    



    return 0;
}