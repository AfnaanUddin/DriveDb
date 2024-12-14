#include "../include/headerA3.h"

// Function to remove all car data from the linked list
void noMoreCars(a3Car **headLL)
{
    char option;

    // Step 1: Prompt the user for confirmation to remove all car data
    do
    {
        // Ask the user to confirm if they want to remove all car data
        printf("Are You Sure You Want To Remove All Car Data (enter y for yes, n for no): ");
        scanf(" %c", &option); // Read the user input for their choice (y or n)

        // Step 2: Handle invalid input
        if (option != 'y' && option != 'n')
        {
            printf("Invalid Input. Please Enter y or n.\n"); // Display error message for invalid input
        }

    } while (option != 'y' && option != 'n'); // Keep asking until the user provides a valid input ('y' or 'n')

    // Step 3: If the user confirms (option == 'y'), proceed with deleting the car data
    if (option == 'y')
    {
        // Step 4: Free memory for all cars in the linked list
        a3Car *currentCar = *headLL; // Initialize currentCar to point to the head of the list

        // Step 5: Traverse the list and free memory for each car node
        while (currentCar != NULL) // Continue until the end of the list (currentCar becomes NULL)
        {
            a3Car *nextCar = currentCar->nextCar; // Store the pointer to the next car node
            free(currentCar);                     // Free the memory occupied by the current car node
            currentCar = nextCar;                 // Move to the next car in the list
        }

        // Step 6: Set the head pointer to NULL, indicating that the list is now empty
        *headLL = NULL; // Make the head pointer NULL, effectively removing all cars from the list
    }
}