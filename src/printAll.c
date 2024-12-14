#include "../include/headerA3.h"

// Function to print details of all cars in the linked list
void printAll(struct car *headLL)
{
    // Step 1: Check if the linked list is empty
    if (headLL == NULL)
    {
        printf("No Cars Found.\n"); // Inform the user if the list is empty
        return;                     // Exit the function if the list is empty
    }

    // Step 2: Initialize a pointer to traverse the linked list
    struct car *currentCar = headLL; // Pointer to traverse through each car in the list
    int count = 0;                   // Variable to keep track of the number of cars printed

    // Step 3: Loop through the linked list until the end is reached
    while (currentCar != NULL)
    {
        count++; // Increment the count for each car in the list

        // Step 4: Print details of the current car
        printf("Car # %d:\n", count);                          // Print the car number (position in the list)
        printf("Car Id: %d\n", currentCar->carId);             // Print the car's ID
        printf("Model: %s\n", currentCar->model);              // Print the car's model
        printf("Type: %s\n", currentCar->type);                // Print the car's type
        printf("Price: CDN $%.2lf\n", currentCar->price);      // Print the car's price in CAD
        printf("Year Of Manufacture: %d\n", currentCar->year); // Print the car's manufacturing year
        printf("\n");                                          // Print a newline for readability

        // Step 5: Move to the next car in the list
        currentCar = currentCar->nextCar; // Move the pointer to the next car node
    }

    // Step 6: After printing details of all cars, print the total count
    printf("Currently, There are %d cars.\n", count); // Display the total number of cars printed
}