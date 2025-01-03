#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Struct for menu items
typedef struct {
    char item[50];
    int price;   
} menu;

// Items Available in Menu
// grouped by category: Appetizers, Main Course, Dessert, Snack, and Beverage
menu appetizers[] = {
	{"Truffle Arancini", 80}, 
	{"Caprese Salad", 75}, 
	{"Smoked Salmon Tartare", 100}
};
menu mainCourses[] = {
	{"Beef Wellington", 250}, 
	{"Lobster Thermidor", 300}, 
	{"Wild Mushroom Risotto", 180}
};
menu desserts[] = {
	{"Tiramisu", 90}, 
	{"Creme Brule", 85}, 
	{"Molten Lava Cake", 95}
};
menu snacks[] = {
	{"Cheese Platter", 120}, 
	{"Bruschetta Trio", 60}, 
	{"Mini Sliders", 110}
};
menu beverages[] = {
	{"Espresso Martini", 150}, 
	{"Freshly Squeezed Orange Juice", 50}, 
	{"Classic Mojito", 120}
};

menu *categories[] = {appetizers, mainCourses, desserts, snacks, beverages};
int categorySizes[] = {3, 3, 3, 3, 3};
char categoryNames[][20] = {"Appetizers", "Main Courses", "Desserts", "Snacks", "Beverages"};

// Struct for customers
typedef struct {
    char name[100];
    char email[100];
    char phone[15];
} customer;

// Functions
int validateName(char name[]);
int validateEmail(char email[]);
int validatePhone(char phone[]);

void welcome();
void displayMenu();
void processOrder();
void makeReservation();
void openHistory();
void sortReservations(customer list[], int count);

int main() {
    welcome();

    while (1) {
        printf("\n--- What would you like to do? ---\n");
        printf("1. Make a Reservation\n");
        printf("2. Order Food\n");
        printf("3. See Order History\n");
        printf("4. Exit\n");
        printf(">> ");
        int choice;
        scanf("%d", &choice); getchar();

        switch (choice) {
            case 1:
                makeReservation();
                break;
            case 2:
            	system("cls");
                processOrder();
                break;
            case 3:
                openHistory();
                break;
            case 4:
                printf("\nThank you for visiting! Goodbye.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}

// To validate name, name must consists of only alphabets
int validateName(char name[]) {
	int i;
    for (i = 0; name[i] != '\0'; i++) {
        if (!((name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z') || name[i] == ' ')) {
            return 0;
        }
    }
    return 1;
}

// To validate email, email must end with "@gmail.com"
int validateEmail(char email[]) {
    int len = strlen(email), i;
    char *domain = "@gmail.com";
    int domainLen = strlen(domain);

    if (len < domainLen) return 0;

    for (i = 0; i < domainLen; i++) {
        if (email[len - domainLen + i] != domain[i]) {
            return 0;
        }
    }
    return 1;
}

// To validate phone number, phone number must consists of only digits
int validatePhone(char phone[]) {
	int i;
    for (i = 0; phone[i] != '\0'; i++) {
        if (phone[i] < '0' || phone[i] > '9') {
            return 0;
        }
    }
    return 1;
}

// The welcoming page
void welcome(){
	puts(" _    _  ___  __    __  __  __  __  ___    ____  __  ");
	puts("( \\/\\/ )(  _)(  )  / _)/  \\(  \\/  )(  _)  (_  _)/  \\ ");
	puts(" \\    /  ) _) )(__( (_( () ))    (  ) _)    )( ( () )");
	puts("  \\/\\/  (___)(____)\\__)\\__/(_/\\/\\_)(___)   (__) \\__/ ");
	puts("");
	puts(" ______  __  __  ______\t\t       _..._");		
	puts("/\\__  _\\/\\ \\_\\ \\/\\  ___\\\t    .-'_..._''.");		
	puts("\\/_/\\ \\/\\ \\  __ \\ \\  __\\\t  .' .'      '.\                      __.....__   ");		
	puts("   \\ \\_\\ \\ \\_\\ \\_\\ \\_____\\ \t / .'                        _.._ .-''         '.");		
	puts("    \\/_/  \\/_/\\/_/\\/_____/\t. '                        .' .._/     .-''\"'-.  `.");		
	puts("\t\t\t\t| |                 __     | '  /     /________\   \\");		
	puts("\t\t\t\t| |              .:--.'. __| |__|                  |");		
	puts("\t\t\t\t . '             / |   \ |__   __\    .-------------'");		
	puts("\t\t\t\t  \ '.          .`\" __ | |  | |   \    '-.____...---.");		
	puts("\t\t\t\t  '. `._____.-'/ .'.''| |  | |    `.             .'");		
	puts("\t\t\t\t    `-.______ / / /   | |_ | |      `''-...... -'");		
	puts("\t\t\t\t                 `--'  `\"  |_|");	
	puts("");	
	puts("");	
	printf("Please enter any key to start ordering . . . ");	
	getchar();
	system("cls");	
}

// To display menu when ordering
void displayMenu() {
    printf("\n--- Menu ---\n");
    int index = 1, i, j;

    for (i = 0; i < 5; i++) {
        printf("\n%s:\n", categoryNames[i]);
        for (j = 0; j < categorySizes[i]; j++, index++) {
            printf("%d. %s - $%d\n", index, categories[i][j].item, categories[i][j].price);
        }
    }
}

// To make a reservation
// Customer must make a reservation first to order 
void makeReservation() {
	system("cls");
    customer c;
    printf("\n--- Make a Reservation ---\n");
    while (1) {
        printf("Enter your name: ");
        scanf(" %[^\n]%*c", c.name); 
        if (validateName(c.name)) break;
        printf("Invalid name. Please use only alphabets.\n\n");
    }
	
	if(c.name[0] >= 'a' && c.name[0] <= 'z') c.name[0] = toupper(c.name[0]);
	
    while (1) {
        printf("Enter your email address: ");
        scanf(" %[^\n]%*c", c.email); 
        if (validateEmail(c.email)) break;
        printf("Invalid email. Please use a valid Gmail address.\n\n");
    }

    while (1) {
        printf("Enter your phone number: ");
        scanf(" %[^\n]%*c", c.phone); 
        if (validatePhone(c.phone)) break;
        printf("Invalid phone number. Please use only digits.\n\n");
    }

    FILE *file = fopen("reservation_history.txt", "w");
    if (file) {
        fprintf(file, "%s,%s,%s\n", c.name, c.email, c.phone);
        fclose(file);
    }

    printf("\n\n--- Reservation Confirmation ---\n");
    printf("Name: %s\nEmail: %s\nPhone: %s\nReservation confirmed. Thank you!\n", c.name, c.email, c.phone);
    getchar();
    system("cls");
}

// To process the order and show the receipt
void processOrder() {
    int totalBill = 0, totalItems = 15, itemCount = 0, i;
    char orderInput[200], *token, cont;
    char orderedItems[200][50];
    int orderedPrices[200];
    displayMenu();

    do {
        printf("\nEnter the index of the items you'd like to order, separated by commas: ");
        scanf(" %[^\n]%*c", orderInput);

        token = strtok(orderInput, ",");
        while (token) {
            int choice = atoi(token) - 1, index = 0;

            if (choice < 0 || choice >= totalItems) {
                printf("Invalid choice: %d. Skipping this item.\n", choice + 1);
            } else {
                for (i = 0; i < 5; i++) {
                    if (choice < index + categorySizes[i]) {
                        int itemIndex = choice - index;
                        totalBill += categories[i][itemIndex].price;

                        strcpy(orderedItems[itemCount], categories[i][itemIndex].item);
                        orderedPrices[itemCount] = categories[i][itemIndex].price;
                        itemCount++;

                        printf("Added '%s' to your order. Current total: $%d\n", categories[i][itemIndex].item, totalBill);
                        break;
                    }
                    index += categorySizes[i];
                }
            }
            token = strtok(NULL, ",");
        }

        printf("\nWould you like to order more items? (y/n): ");
        scanf("%c", &cont);
        getchar();

        if ((cont != 'y' && cont != 'Y') && (cont != 'n' && cont != 'N')) {
            printf("Invalid choice. Please enter yes (y) or no (n).\n");
        } else if (cont == 'n' || cont == 'N') {
            break;
        }
    } while (cont != 'n' || cont != 'N');

    printf("\nProcessing . . . \n");

    printf("\n\n--- Final Bill ---\n\n");
    printf("Ordered Items:\n");
    for (i = 0; i < itemCount; i++) {
        printf("\t%s - $%d\n", orderedItems[i], orderedPrices[i]);
    }
    printf("\nTotal amount due: $%d\n", totalBill);
    printf("Thank you for your order!\n");
    getchar();
    system("cls");
}

// To see previous order history
void openHistory() {
	system("cls");
    FILE *file = fopen("reservation_history.txt", "r");
    char line[256];
    customer customers[100];
    int count = 0, i;

    if (file) {
        while (fgets(line, sizeof(line), file)) {
            sscanf(line, "%[^,],%[^,],%[^\n]", customers[count].name, customers[count].email, customers[count].phone);
            count++;
        }
        fclose(file);

        sortReservations(customers, count);

        printf("\n--- Reservation History (Sorted Alphabetically) ---\n");
        for (i = 0; i < count; i++) {
            printf("Name: %s, Email: %s, Phone: %s\n", customers[i].name, customers[i].email, customers[i].phone);
        }
    } else {
        printf("\nNo reservation history found.\n\n");
    }
    getchar();
    system("cls");
}

// To sort reservations alphabetically by name
void sortReservations(customer list[], int count) {
    customer temp;
    int i, j;
    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (strcmp(list[i].name, list[j].name) > 0) {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}
