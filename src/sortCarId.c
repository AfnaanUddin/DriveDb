#include "../include/headerA3.h"

// Function to sort the cars in the list based on carId
void sortCarId(struct car **headLL)
{
    // Step 1: Check if the list is empty or has only one node
    if (*headLL == NULL || (*headLL)->nextCar == NULL)
        return; // No need to sort if the list is empty or has only one car

    struct car *current, *newNode; // Pointers to traverse the list
    int temp;                      // Temporary variable for swapping carId values

    // Step 2: Traverse the list using two nested loops to compare and swap carId values
    for (current = *headLL; current != NULL; current = current->nextCar) // Outer loop to iterate through each car
    {
        for (newNode = current->nextCar; newNode != NULL; newNode = newNode->nextCar) // Inner loop to compare current node with the rest
        {
            // Step 3: Compare the carId values of the current and next nodes
            if (current->carId > newNode->carId) // If current car's carId is greater than next car's carId
            {
                // Step 4: Swap the carId values of the current and next nodes
                temp = current->carId;           // Store current car's carId in temp
                current->carId = newNode->carId; // Assign newNode's carId to current car
                newNode->carId = temp;           // Assign temp (old current car's carId) to newNode's carId
            }
        }
    }
}