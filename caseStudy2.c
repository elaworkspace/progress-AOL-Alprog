#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void welcome();
void makeReservation();
void confirmReservation(char* name, char* email, char* phone);
void displayMenu();

int main() {
    int choice;

    welcome();

    while (1) {
        printf("\n--- What would you like to do? ---\n");
        printf("1. Make a Reservation\n");
        printf("2. View Menu\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                makeReservation();
                break;
            case 2:
                displayMenu();
                break;
            case 3:
                printf("Thank you for visiting! Goodbye.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void welcome() {
    printf("\n--- Welcome to [...] ---\n");
    printf("We are delighted to serve you!\n\n");
}

void makeReservation() {
	system("cls");
	
    char name[100], email[100], phone[15];

    printf("\n--- Make a Reservation ---\n");
    printf("Enter your name: ");
    scanf(" %[^\n]%*c", name);
    printf("Enter your email address: ");
    scanf(" %[^\n]%*c", email);
    printf("Enter your phone number: ");
    scanf(" %[^\n]%*c", phone);

    confirmReservation(name, email, phone);
}

void confirmReservation(char* name, char* email, char* phone) {
	system("cls");
    printf("\n--- Reservation Confirmation ---\n");
    printf("Reservation under the name: %s\n", name);
    printf("Email: %s\n", email);
    printf("Phone: %s\n", phone);
    printf("Your reservation has been confirmed. Thank you!\n\n");
}

void displayMenu() {
    printf("\n--- Menu ---\n");

    printf("\nStarters:\n");
    printf("1. Tomato Soup\n");
    printf("2. Caesar Salad\n");

    printf("\nMain Courses:\n");
    printf("1. Grilled Chicken\n");
    printf("2. Vegan Lasagna (Vegan)\n");
    printf("3. Quinoa Bowl (Vegan)\n");

    printf("\nDesserts:\n");
    printf("1. Chocolate Cake\n");
    printf("2. Fruit Salad\n");

    printf("\nWine Selection:\n");
    printf("1. Chardonnay\n");
    printf("2. Merlot\n");
    printf("3. Cabernet Sauvignon\n");

    printf("\nEnjoy exploring our menu!\n\n");
}
