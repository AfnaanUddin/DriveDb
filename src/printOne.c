#include "../include/headerA3.h"

// Function to print the details of a single car based on its position in the list
void printOne(struct car *headLL, int whichOne)
{
    // Step 1: Check if the linked list is empty
    if (headLL == NULL)
    {
        printf("No cars found.\n"); // Inform the user if the list is empty
        return;                     // Exit the function if the list is empty
    }

    int count = 0;                   // Counter to keep track of the current position in the list
    struct car *currentCar = headLL; // Pointer to traverse the list

    // Step 2: Loop through the list to find the car at the specified position
    while (currentCar != NULL)
    {
        count++; // Increment the position counter for each car in the list

        // Step 3: Check if the current position matches the requested one
        if (count == whichOne)
        {
            // Step 4: If the position matches, print the details of the car at this position
            printf("Car # %d:\n", whichOne);                       // Print the position of the car
            printf("Car Id: %d\n", currentCar->carId);             // Print the car's ID
            printf("Model: %s\n", currentCar->model);              // Print the car's model
            printf("Type: %s\n", currentCar->type);                // Print the car's type
            printf("Price: CDN $%.2lf\n", currentCar->price);      // Print the car's price in CAD
            printf("Year of Manufacture: %d\n", currentCar->year); // Print the car's year of manufacture
            return;                                                // Exit the function after printing the details of the car
        }

        // Step 5: Move to the next car in the list
        currentCar = currentCar->nextCar;
    }

    // Step 6: If the loop completes without finding a car at the specified position
    printf("No car found at position %d.\n", whichOne); // Inform the user if no car exists at the requested position
}