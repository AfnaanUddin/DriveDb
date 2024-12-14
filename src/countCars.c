#include "../include/headerA3.h"

// Function to count the total number of cars in the linked list
int countCars(a3Car *headLL)
{
    // Step 1: Initialize a counter to keep track of the number of cars in the linked list
    int count = 0; // This variable will store the total count of cars in the linked list

    // Step 2: Create a pointer to traverse the linked list starting from the head
    a3Car *currentCar = headLL; // 'currentCar' will be used to move through each node (car) in the list

    // Step 3: Loop through each car in the linked list
    while (currentCar != NULL) // Continue looping as long as 'currentCar' is not NULL (i.e., end of list not reached)
    {
        count++; // Increment the counter to count the current car (each iteration represents one car)

        // Step 4: Move the pointer to the next car in the linked list
        currentCar = currentCar->nextCar; // Update 'currentCar' to point to the next car in the list
    }

    // Step 5: Return the total count of cars in the linked list
    return count; // Return the final count of the total number of cars
}