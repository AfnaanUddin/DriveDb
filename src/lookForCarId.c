#include "../include/headerA3.h"

// Function to search for a car based on carId and return its position in the linked list
int lookForCarId(struct car *headLL, int carId)
{
    int position = 1;                // Initialize the position counter to 1 since linked lists are 1-indexed
    struct car *currentCar = headLL; // Pointer to traverse the list, starting from the head of the linked list

    // Step 1: Loop through the linked list until the end is reached (i.e., currentCar becomes NULL)
    while (currentCar != NULL) // The loop continues as long as there are more cars to check in the list
    {
        // Step 2: Check if the carId of the current node matches the target carId
        if (currentCar->carId == carId) // Compare the carId of the current car with the target carId
        {
            return position; // If a match is found, return the current position of the car in the list
        }

        // Step 3: Move to the next car in the list
        currentCar = currentCar->nextCar; // Update currentCar to point to the next car in the list

        // Step 4: Increment the position counter since we have moved to the next node
        position++; // Increase position to reflect the current car's position in the list
    }

    // Step 5: If the loop finishes without finding a matching carId, it means the carId does not exist in the list
    return -1; // Return -1 to indicate that the car with the given carId was not found in the list
}