#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Struct for menu items
typedef struct {
    char item[50];
    int price;
} MenuItem;

// Menu items grouped by category
MenuItem appetizers[] = {{"Truffle Arancini", 80}, {"Caprese Salad", 75}, {"Smoked Salmon Tartare", 100}};
MenuItem mainCourses[] = {{"Beef Wellington", 250}, {"Lobster Thermidor", 300}, {"Wild Mushroom Risotto", 180}};
MenuItem desserts[] = {{"Tiramisu", 90}, {"Crème Brûlée", 85}, {"Molten Lava Cake", 95}};
MenuItem snacks[] = {{"Cheese Platter", 120}, {"Bruschetta Trio", 60}, {"Mini Sliders", 110}};
MenuItem beverages[] = {{"Espresso Martini", 150}, {"Freshly Squeezed Orange Juice", 50}, {"Classic Mojito", 120}};

// Arrays to handle menu categories dynamically
MenuItem *categories[] = {appetizers, mainCourses, desserts, snacks, beverages};
int categorySizes[] = {3, 3, 3, 3, 3};
char *categoryNames[] = {"Appetizers", "Main Courses", "Desserts", "Snacks", "Beverages"};

// functions
int validateName(const char *name);
int validateEmail(const char *email);
int validatePhone(const char *phone);
void displayMenu();
void processOrder();
void makeReservation();

// Main function
int main() {
    int choice;

    printf("\n--- Welcome to Our Restaurant ---\n");
    printf("We are delighted to serve you!\n\n");

    while (1) {
        printf("\n--- What would you like to do? ---\n");
        printf("1. Make a Reservation\n");
        printf("2. Order Food\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                makeReservation();
                break;
            case 2:
                processOrder();
                break;
            case 3:
                printf("Thank you for visiting! Goodbye.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Validation functions
int validateName(const char *name) { 
    return strspn(name, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ") == strlen(name); 
}

int validateEmail(const char *email) { 
    return strstr(email, "@gmail.com") && strlen(strstr(email, "@gmail.com")) == 10; 
}

int validatePhone(const char *phone) { 
    return strspn(phone, "0123456789") == strlen(phone); 
}

// Display menu
void displayMenu() {
    printf("\n--- Menu ---\n");
    int index = 1;

    for (int i = 0; i < 5; i++) {
        printf("\n%s:\n", categoryNames[i]);
        for (int j = 0; j < categorySizes[i]; j++, index++) {
            printf("%d. %s - $%d\n", index, categories[i][j].item, categories[i][j].price);
        }
    }
}

// Process order
void processOrder() {
    int totalBill = 0, totalItems = 15; // Total items across all categories
    char orderInput[200], *token;

    do {
        displayMenu();
        printf("\nEnter the numbers of the items you'd like to order, separated by commas: ");
        scanf(" %[^\n]%*c", orderInput);

        token = strtok(orderInput, ",");
        while (token) {
            int choice = atoi(token) - 1, index = 0;

            if (choice < 0 || choice >= totalItems) {
                printf("Invalid choice: %d. Skipping this item.\n", choice + 1);
            } else {
                for (int i = 0; i < 5; i++) {
                    if (choice < index + categorySizes[i]) {
                        int itemIndex = choice - index;
                        totalBill += categories[i][itemIndex].price;
                        printf("Added '%s' to your order. Current total: $%d\n", categories[i][itemIndex].item, totalBill);
                        break;
                    }
                    index += categorySizes[i];
                }
            }
            token = strtok(NULL, ",");
        }

        printf("\nWould you like to order more items? (y/n): ");
        char cont;
        scanf(" %c", &cont);
        if (tolower(cont) != 'y') break;
    } while (1);

    printf("\n--- Final Bill ---\n");
    printf("Total amount due: $%d\n", totalBill);
    printf("Thank you for your order!\n");
}

// Make reservation
void makeReservation() {
    char name[100], email[100], phone[15];

    printf("\n--- Make a Reservation ---\n");
    do {
        printf("Enter your name: ");
        scanf(" %[^\n]%*c", name);
        if (validateName(name)) break;
        printf("Invalid name. Please use only alphabets.\n");
    } while (1);

    do {
        printf("Enter your email address: ");
        scanf(" %[^\n]%*c", email);
        if (validateEmail(email)) break;
        printf("Invalid email. Please use a valid Gmail address.\n");
    } while (1);

    do {
        printf("Enter your phone number: ");
        scanf(" %[^\n]%*c", phone);
        if (validatePhone(phone)) break;
        printf("Invalid phone number. Please use only digits.\n");
    } while (1);

    printf("\n--- Reservation Confirmation ---\n");
    printf("Name: %s\nEmail: %s\nPhone: %s\nReservation confirmed. Thank you!\n", name, email, phone);
}
