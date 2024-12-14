#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 25 // Maximum length for car model and type strings

// 🚗 Structure to represent a car in the system
struct car
{
   int year;               // The manufacturing year of the car
   double price;           // The price of the car
   char model[MAX_LENGTH]; // The model name of the car (e.g., "Civic", "Corolla", etc.)
   char type[MAX_LENGTH];  // The type of the car (e.g., "Sedan", "SUV", etc.)
   int carId;              // Unique auto-generated identifier for each car
   struct car *nextCar;    // Pointer to the next car node in the singly linked list
};

typedef struct car a3Car; // Alias for struct car to simplify usage

// 📘 Function Prototypes

/**
 * @brief Adds a new car to the linked list.
 *
 * @param headLL Pointer to the head of the linked list of cars.
 *
 * This function prompts the user for car details (year, price, model, type)
 * and automatically generates a unique `carId` for the new car.
 * The new car is added at the end of the linked list.
 */
void addNewCar(struct car **headLL);

/**
 * @brief Prints the details of all cars in the linked list.
 *
 * @param headLL Pointer to the head of the linked list of cars.
 *
 * This function iterates through the entire linked list and prints
 * all details (year, price, model, type, carId) of each car.
 */
void printAll(struct car *headLL);

/**
 * @brief Prints the details of a specific car by its position in the list.
 *
 * @param headLL Pointer to the head of the linked list of cars.
 * @param whichOne The position of the car to print (starting from 1 for the first car).
 *
 * This function prints the details of the car at the specified position in the list.
 * If the position is invalid (out of range), it shows an appropriate message.
 */
void printOne(struct car *headLL, int whichOne);

/**
 * @brief Searches for a car by its unique carId.
 *
 * @param headLL Pointer to the head of the linked list of cars.
 * @param key The carId to search for.
 * @return The position (1-indexed) of the car if found, or -1 if not found.
 *
 * This function searches for a car with a matching carId in the linked list.
 * It returns the position of the car (starting from 1) or -1 if the car is not found.
 */
int lookForCarId(struct car *headLL, int key);

/**
 * @brief Searches for a car by its model or type.
 *
 * @param headLL Pointer to the head of the linked list of cars.
 * @param key The model or type to search for (case-insensitive).
 * @return The position (1-indexed) of the first match, or -1 if no match is found.
 *
 * This function searches for the first car that matches the specified model or type
 * in the linked list. The search is case-insensitive and returns the position
 * of the match or -1 if no match is found.
 */
int lookForCarModelType(struct car *headLL, char key[100]);

/**
 * @brief Sorts the linked list of cars by carId in ascending order.
 *
 * @param headLL Pointer to the head of the linked list of cars.
 *
 * This function sorts the linked list using a sorting algorithm (like bubble sort)
 * based on the carId of each car. After sorting, the cars are in ascending order
 * according to their carId.
 */
void sortCarId(struct car **headLL);

/**
 * @brief Loads car data from a file and populates the linked list.
 *
 * @param headLL Pointer to the head of the linked list of cars.
 * @param fileName The name of the file containing car data.
 *
 * This function reads car data from a specified file and adds each car to the linked list.
 * Each line in the file may contain information like year, price, model, type, and carId.
 * The file should be formatted correctly to avoid data corruption.
 */
void loadCarData(struct car **headLL, char fileName[MAX_LENGTH]);

/**
 * @brief Counts the total number of cars in the linked list.
 *
 * @param headLL Pointer to the head of the linked list of cars.
 * @return The total number of cars in the list.
 *
 * This function counts the total number of nodes (cars) in the linked list
 * and returns that number.
 */
int countCars(a3Car *headLL);

/**
 * @brief Frees all memory allocated for the linked list.
 *
 * @param headLL Pointer to the head of the linked list of cars.
 *
 * This function frees all the memory associated with the linked list
 * and sets the head pointer to NULL to prevent dangling pointers.
 */
void noMoreCars(a3Car **headLL);

/**
 * @brief Deletes a specific car from the linked list.
 *
 * @param headLL Pointer to the head of the linked list of cars.
 * @param whichOne The position of the car to delete (starting from 1 for the first car).
 *
 * This function deletes the car at the specified position in the list.
 * If the position is invalid (out of range), it shows an appropriate message.
 * It properly handles the memory deallocation to avoid memory leaks.
 */
void oneLessCar(a3Car **headLL, int whichOne);