#include "../include/headerA3.h"

// Function to load car data from a specified file into the linked list
void loadCarData(struct car **headLL, char fileName[MAX_LENGTH])
{
    // Step 1: Attempt to open the specified file for reading in text mode ("r" mode)
    FILE *file = fopen(fileName, "r");
    if (file == NULL) // Check if the file was successfully opened
    {
        printf("Failed To Open File.\n"); // If the file could not be opened, print an error message
        return;                           // Exit the function early, as there is no file to read data from
    }

    char buffer[100]; // Buffer to temporarily hold each line of text read from the file

    // Step 2: Read the file line by line using fgets()
    while (fgets(buffer, sizeof(buffer), file)) // Reads one line from the file and stores it in 'buffer'
    {
        // Step 3: Declare temporary variables to store the extracted data for each car
        int carId;              // Unique identifier for the car
        char model[MAX_LENGTH]; // Car model name (string)
        char type[MAX_LENGTH];  // Car type (string)
        int year;               // Year of manufacture of the car
        double price;           // Price of the car

        // Step 4: Extract the car details from the current line using sscanf()
        // Format of each line in the file: carId,model,type,year,price
        sscanf(buffer, "%d,%[^,],%[^,],%d,%lf", &carId, model, type, &year, &price);
        // sscanf() parses the string stored in 'buffer' and extracts the values into the respective variables
        // %d - carId (integer), %[^,] - reads a string until a comma is encountered, %lf - price (double)

        // Step 5: Dynamically allocate memory for a new 'car' node
        struct car *newCar = malloc(sizeof(struct car)); // Allocate memory for the new car structure
        if (newCar == NULL)                              // Check if the memory allocation was successful
        {
            printf("Memory Allocation Failed.\n"); // Print error message if memory allocation fails
            fclose(file);                          // Close the file to avoid resource leaks
            return;                                // Exit the function early, as the new car cannot be created
        }

        // Step 6: Assign the extracted data to the respective fields in the 'newCar' structure
        newCar->carId = carId;        // Assign the carId value to the car's carId field
        strcpy(newCar->model, model); // Copy the model string into the newCar's model field
        strcpy(newCar->type, type);   // Copy the type string into the newCar's type field
        newCar->year = year;          // Assign the year value to the newCar's year field
        newCar->price = price;        // Assign the price value to the newCar's price field

        // Step 7: Ensure that the carId of the new car is unique within the linked list
        struct car *temp = *headLL; // Pointer to traverse the linked list from the head
        while (temp != NULL)        // Loop through the linked list to check for carId conflicts
        {
            if (temp->carId == newCar->carId) // Check if the carId already exists in the list
            {
                // If the carId is not unique, modify it by adding a random number (1 to 999) to it
                newCar->carId += rand() % 999 + 1;
                temp = *headLL; // Restart the search from the head of the linked list to ensure uniqueness
                continue;       // Continue the loop to check if the new carId is unique
            }
            temp = temp->nextCar; // Move to the next car in the list
        }

        // Step 8: Insert the new car node into the linked list
        newCar->nextCar = NULL; // Set the 'nextCar' pointer of the new node to NULL (it's the last node)

        if (*headLL == NULL) // Check if the linked list is currently empty
        {
            // If the linked list is empty, make the new car the head of the list
            *headLL = newCar;
        }
        else
        {
            // If the linked list is not empty, traverse to the end of the list
            temp = *headLL;               // Start from the head of the list
            while (temp->nextCar != NULL) // Traverse until the last car (where temp->nextCar is NULL)
            {
                temp = temp->nextCar; // Move to the next car in the list
            }
            temp->nextCar = newCar; // Link the last car to the newly created car node
        }
    }

    // Step 9: Close the file after all the data has been read and processed
    fclose(file); // Close the file to free system resources

    // Step 10: Notify the user that the car data has been successfully loaded
    printf("Car Data Loaded Successfully From %s.\n", fileName); // Print a success message
}