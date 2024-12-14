#include "../include/headerA3.h"

// Function to search for a car based on both model and type and return its position in the linked list
int lookForCarModelType(struct car *headLL, char key[100])
{
    int position = 1;                // Initialize the position counter to 1 since linked lists are 1-indexed
    struct car *currentCar = headLL; // Pointer used to traverse the list, starting from the head of the linked list
    char model[MAX_LENGTH];          // Buffer to store the model part of the extracted key
    char type[MAX_LENGTH];           // Buffer to store the type part of the extracted key

    // Step 1: Extract the model and type from the key parameter using sscanf
    sscanf(key, "%s %s", model, type); // Parse the key to extract both model and type (space-separated)

    // Step 2: Loop through the linked list to check each car's model and type
    while (currentCar != NULL) // The loop continues until the currentCar pointer is NULL (end of the list)
    {
        // Step 3: Compare the model and type of the current car with the extracted model and type from key
        if (strcmp(currentCar->model, model) == 0 && strcmp(currentCar->type, type) == 0)
        {
            return position; // If both model and type match, return the current position of the car in the list
        }
        // Step 4: Move to the next car in the list
        currentCar = currentCar->nextCar; // Update currentCar to point to the next car in the linked list
        position++;                       // Increment the position counter since we moved to the next car in the list
    }

    // Step 5: If no matching car is found, return -1 to indicate that no car with the given model and type was found
    return -1; // Return -1 to signal that no match was found after traversing the entire list
}