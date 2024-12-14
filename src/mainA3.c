#include "../include/headerA3.h" // Include the custom header file containing function prototypes and struct definitions

int main()
{
    printf("\n\n");
    // 🌟 Welcome message displayed when the program starts
    printf("WELCOME TO DRIVEDB:\n\n");

    // Pointer to the start of the linked list of cars, initially set to NULL
    // (since no cars exist in the system at the start)
    struct car *carList = NULL;

    // Filename from which car data will be loaded
    // This can be modified later if the program allows for file name input
    char fileName[MAX_LENGTH];
    strcpy(fileName, "inputFile.txt"); // Copies the name "inputFile.txt" into the fileName variable

    // Variables used for user inputs during various menu options
    int nth;             // Used to specify the nth car for certain operations (like printing, deleting)
    int searchCarId;     // Used to store the carId entered by the user for searching
    char modelType[100]; // Used to store the car model and type as a combined string for searching
    int whichOne;        // Used to specify the position of the car to remove

    // Variable to store the user's choice for menu options
    int choice;

    // 📜 Main program loop - Repeats until the user selects option 11 (Exit)
    do
    {
        // Display the menu of options available to the user
        printf("\nMenu Options:\n");
        printf("1. Add Data On A New Car:\n");
        printf("2. Load Data On Cars From A Given Text File:\n");
        printf("3. Print Data Of All Cars:\n");
        printf("4. Print Data Of The nth Car:\n");
        printf("5. Search Car Data Based On CarId:\n");
        printf("6. Search Car Data Based On Model And Type:\n");
        printf("7. Count The Total Number Of Cars In The List:\n");
        printf("8. Sort The Cars In The List Based On CarId:\n");
        printf("9. Remove Data Of The nth Car:\n");
        printf("10. Remove all car data:\n");
        printf("11. Exit:\n");
        printf("Please Enter Your Choice: ");
        scanf("%d", &choice); // User inputs their choice (integer) for the menu option

        // 🌟 Handle the user's menu selection using a switch statement
        switch (choice)
        {
        case 1:
            // 📥 Add a new car to the linked list
            addNewCar(&carList);
            break;

        case 2:
            // 📂 Load car data from an external file
            // (The file name is set to "inputFile.txt" earlier in the program)
            loadCarData(&carList, fileName);
            break;

        case 3:
            // 📃 Print the details of all cars currently in the linked list
            printAll(carList);
            break;

        case 4:
            // 📄 Print the details of the nth car in the linked list
            printf("Enter The Position Of The Car To Print: ");
            scanf("%d", &nth);      // Input the position of the car to print
            printOne(carList, nth); // Call the function to print the details of the specified car
            break;

        case 5:
            // 🔍 Search for a car using its carId
            printf("Enter A Car ID: ");
            scanf("%d", &searchCarId);                           // Input the carId to search for
            int positionId = lookForCarId(carList, searchCarId); // Call function to search for the carId
            if (positionId != -1)
            {
                // If the car is found, display its position and details
                printf("Car Found at position %d:\n", positionId);
                printOne(carList, positionId); // Print the details of the found car
            }
            else
            {
                // If the car is not found, inform the user
                printf("Car With Car ID %d Not Found.\n", searchCarId);
            }
            break;

        case 6:
            // 🔍 Search for a car using its model and type
            printf("Enter The Model And Type (separated by a space): ");
            getchar();                                                       // Clear the newline character left in the input stream after the previous scanf
            fgets(modelType, 100, stdin);                                    // Read the model and type input as a single string
            modelType[strlen(modelType) - 1] = '\0';                         // Remove the newline character from the string
            int positionModelType = lookForCarModelType(carList, modelType); // Search for the car with the given model and type
            if (positionModelType != -1)
            {
                // If the car is found, display its position and details
                printf("Car Found At Position %d:\n", positionModelType);
                printOne(carList, positionModelType); // Print the details of the found car
            }
            else
            {
                // If the car is not found, inform the user
                printf("Car With Model And Type '%s' Not Found.\n", modelType);
            }
            break;

        case 7:
            // 🔢 Count and display the total number of cars in the list
            printf("Total Number Of Cars = %d\n", countCars(carList));
            break;

        case 8:
            // 🔀 Sort the cars in the linked list by carId in ascending order
            sortCarId(&carList);
            printf("Cars Sorted Based on CarId.\n");
            break;

        case 9:
            // ❌ Remove the data of the nth car from the list
            printf("Currently There Are %d Cars.\n", countCars(carList));
            do
            {
                // Ask for the position of the car to remove (valid range: 1 to total number of cars)
                printf("Which Car Do You Wish To Remove – Enter A Value Between 1 and %d: ", countCars(carList));
                scanf("%d", &whichOne);
            } while (whichOne < 1 || whichOne > countCars(carList)); // Repeat until a valid position is entered
            oneLessCar(&carList, whichOne); // Call the function to remove the car at the given position
            break;

        case 10:
            // 🧹 Remove all cars from the linked list (clearing all nodes)
            noMoreCars(&carList);
            printf("All Cars Removed. Linked List is now empty.\n");
            break;

        case 11:
            // 🚪 Exit the program
            printf("Exiting Program...\n");
            break;

        default:
            // ❌ Handle invalid input (if the user enters an option that is not 1-11)
            printf("Invalid choice. Please Try Again.\n");
        }
    } while (choice != 11); // 🌀 Loop continues until the user chooses option 11 (Exit)

    return 0; // End of the program
}