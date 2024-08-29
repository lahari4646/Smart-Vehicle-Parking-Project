#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPOTS 10

typedef struct Vehicle {
    char plate_number[20];
    struct Vehicle* next;
} Vehicle;

typedef struct ParkingSpot {
    int spot_number;
    Vehicle* vehicle;
} ParkingSpot;

ParkingSpot parking_lot[MAX_SPOTS];

// Function to initialize the parking lot
void initialize_parking_lot() {
    for (int i = 0; i < MAX_SPOTS; i++) {
        parking_lot[i].spot_number = i + 1;
        parking_lot[i].vehicle = NULL;
    }
}

// Function to park a vehicle
void park_vehicle(char plate_number[]) {
    for (int i = 0; i < MAX_SPOTS; i++) {
        if (parking_lot[i].vehicle == NULL) {
            Vehicle* new_vehicle = (Vehicle*)malloc(sizeof(Vehicle));
            strcpy(new_vehicle->plate_number, plate_number);
            new_vehicle->next = NULL;
            parking_lot[i].vehicle = new_vehicle;
            printf("Vehicle %s parked at spot %d.\n", plate_number, parking_lot[i].spot_number);
            return;
        }
    }
    printf("Parking lot is full. No available spots.\n");
}

// Function to remove a vehicle
void remove_vehicle(char plate_number[]) {
    for (int i = 0; i < MAX_SPOTS; i++) {
        Vehicle* vehicle = parking_lot[i].vehicle;
        if (vehicle != NULL && strcmp(vehicle->plate_number, plate_number) == 0) {
            free(vehicle);
            parking_lot[i].vehicle = NULL;
            printf("Vehicle %s removed from spot %d.\n", plate_number, parking_lot[i].spot_number);
            return;
        }
    }
    printf("Vehicle with plate number %s not found in the parking lot.\n", plate_number);
}

// Function to display the parking lot status
void display_parking_lot() {
    printf("Parking Lot Status:\n");
    for (int i = 0; i < MAX_SPOTS; i++) {
        if (parking_lot[i].vehicle != NULL) {
            printf("Spot %d: %s\n", parking_lot[i].spot_number, parking_lot[i].vehicle->plate_number);
        } else {
            printf("Spot %d: Empty\n", parking_lot[i].spot_number);
        }
    }
}

// Main function
int main() {
    initialize_parking_lot();
    int choice;
    char plate_number[20];

    while (1) {
        printf("\nParking Lot Management System\n");
        printf("1. Park Vehicle\n");
        printf("2. Remove Vehicle\n");
        printf("3. Display Parking Lot Status\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter vehicle plate number: ");
                scanf("%s", plate_number);
                park_vehicle(plate_number);
                break;
            case 2:
                printf("Enter vehicle plate number: ");
                scanf("%s", plate_number);
                remove_vehicle(plate_number);
                break;
            case 3:
                display_parking_lot();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}