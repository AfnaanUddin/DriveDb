#include "../include/headerA3.h"

// Function to remove a car from the linked list at a specified position
void oneLessCar(a3Car **headLL, int whichOne)
{
    // Step 1: Check if the list is empty
    if (*headLL == NULL)
    {
        printf("No Cars Found To Remove.\n"); // If the list is empty, display a message and return
        return;
    }

    // Step 2: Count the total number of cars in the list
    int count = countCars(*headLL); // Call the countCars function to get the total number of cars

    // Step 3: Check if the specified position is valid
    if (whichOne < 1 || whichOne > count)
    {
        printf("Invalid Position. Please Enter A Value Between 1 and %d.\n", count); // Display an error if the position is out of range
        return;
    }

    // Step 4: Handle the case where the first car is to be removed
    if (whichOne == 1)
    {
        struct car *temp = *headLL;                        // Create a temporary pointer to hold the current head (first car)
        *headLL = (*headLL)->nextCar;                      // Move the head pointer to the next car in the list
        free(temp);                                        // Free the memory occupied by the removed car (previous head)
        printf("Car At Position %d Removed.\n", whichOne); // Notify the user that the first car has been removed
        return;
    }

    // Step 5: Handle the case where the car to be removed is not the first one
    struct car *currentCar = *headLL; // Initialize currentCar to point to the head of the list
    struct car *prevCar = NULL;       // Initialize prevCar to NULL (will point to the previous car during traversal)
    int currentPosition = 1;          // Initialize the position counter to 1 (starting from the head)

    // Step 6: Traverse the list to find the car at the specified position
    while (currentCar != NULL && currentPosition != whichOne)
    {
        prevCar = currentCar;             // Update prevCar to the current car (previous node in the list)
        currentCar = currentCar->nextCar; // Move to the next car in the list
        currentPosition++;                // Increment the position counter
    }

    // Step 7: If no car is found at the specified position, display an error message
    if (currentCar == NULL)
    {
        printf("No Car Found At Position %d.\n", whichOne); // Notify the user if the position is invalid
        return;
    }

    // Step 8: Remove the car from the list by updating pointers and freeing memory
    prevCar->nextCar = currentCar->nextCar;            // Update the previous car's next pointer to skip the current car
    free(currentCar);                                  // Free the memory occupied by the current car (the one being removed)
    printf("Car At Position %d Removed.\n", whichOne); // Notify the user that the car has been removed
}