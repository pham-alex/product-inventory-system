#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_LEN 50

struct Product {
    char name[MAX_LEN + 1];
    int id;
    int quantity;
    float price;
    char category[MAX_LEN + 1];
};

//function prototypes
void add_product(struct Product products[], int *count);
void find_product(struct Product products[], int count);
void update_quantity(struct Product products[], int count);
void remove_product(struct Product products[], int *count);
void display_products(struct Product products[], int count);
void save_to_csv(struct Product products[], int count);


int main(void) {
    struct Product products[MAX_PRODUCTS];
    int product_count = 0;
    int code;

    while (1) {
        printf("\nPRODUCT INVENTORY SYSTEM\n");
        printf("1 - Add Product\n");
        printf("2 - Find Product\n");
        printf("3 - Update Quantity\n");
        printf("4 - Remove Product\n");
        printf("5 - Display Inventory\n");
        printf("6 - Save to CSV\n");
        printf("7 - Quit\n");
        printf("Select a code: ");

        scanf("%d", &code);
        while (getchar()!='\n');

        switch(code) {
            case 1:
                add_product(products, &product_count);
                break;
            case 2:
                find_product(products, product_count);
                break;
            case 3:
                update_quantity(products, product_count);
                break;
            case 4:
                remove_product(products, &product_count);
                break;
            case 5:
                display_products(products, product_count);
                break;
            case 6:
                save_to_csv(products, product_count);
                break;
            case 7:
                printf("Exiting product inventory system.\n");
                return 0;
            default:
                printf("\n\nInvalid code. Enter a number between 1 and 7.\n");
        
        }
    }
    return 0;
}

void add_product(struct Product products[], int *count) {
    if (*count >= MAX_PRODUCTS) {
        printf("The inventory is full.\n");
        return;
    }

    printf("\nEnter the product name: ");
    fgets(products[*count].name, MAX_LEN + 1, stdin);
    products[*count].name[strcspn(products[*count].name, "\n")] = '\0';

    while (1) {
        printf("Enter product ID: ");
        if (scanf("%d", &products[*count].id) == 1){
            break;
        }

        printf("\nInvalid ID format. Enter a number.\n");
        while(getchar()!='\n');
    }

    while (1){
        printf("Enter quantity: ");
        if(scanf("%d", &products[*count].quantity) == 1){
            break;
        }
        printf("\nInvalid quantity format. Enter a number.\n");
        while(getchar()!='\n');
    }
    while(1){
        printf("Enter price: ");
        if(scanf("%f", &products[*count].price) == 1){
            break;
        }
        printf("\nInvalid price format. Enter a number\n");
        while(getchar() != '\n');
    }

    while(getchar() != '\n');
    
    printf("Enter category: ");
    fgets(products[*count].category, MAX_LEN + 1, stdin);
    products[*count].category[strcspn(products[*count].category, "\n")] = '\0';

    printf("Successfully added %s in the inventory!\n", products[*count].name);
    (*count)++;
}

void find_product(struct Product products[], int count){
    char name[MAX_LEN + 1];
    char category[MAX_LEN + 1];
    char exit;
    int id;
    int quantity;
    float price;
    int choice;
    int i;
    int found = 0;

    printf("\n1 - Find product by name\n");
    printf("2 - Find product by ID\n");
    printf("3 - Find product by Quantity\n");
    printf("4 - Find product by Price\n");
    printf("5 - Find product by Category\n");
    printf("Select an option: ");

    while(scanf("%d", &choice) != 1 || choice < 1 || choice > 5){
        printf("Invalid option. Enter a number between 1 to 5: ");
        while(getchar()!='\n');
    }

    while(getchar()!='\n');

    switch(choice){
        case 1:
            printf("\nEnter name of product: ");
            fgets(name, MAX_LEN + 1, stdin);
            name[strcspn(name, "\n")] = '\0';

            for(i = 0; i < count; i++){
                if(strcmp(products[i].name, name) == 0) {
                    found = 1;
                    printf("Name: %s\n", products[i].name);
                    printf("ID: %d\n", products[i].id);
                    printf("Quantity: %d\n", products[i].quantity);
                    printf("Price: $%.2f\n", products[i].price);
                    printf("Category: %s\n", products[i].category);
                }
            }
            break;

        case 2:
            printf("\nEnter product ID: ");
            while(scanf("%d", &id) != 1){
                printf("Invalid ID format. Enter a number: ");
                while(getchar()!='\n');
            }
            while(getchar()!='\n');
            for(i = 0; i < count; i++){
                if(products[i].id == id){
                    found = 1;
                    printf("\nName: %s\n", products[i].name);
                    printf("ID: %d\n", products[i].id);
                    printf("Quantity: %d\n", products[i].quantity);
                    printf("Price: $%.2f\n", products[i].price);
                    printf("Category: %s\n", products[i].category);
                }
            }
            break;

        case 3:
            printf("\nEnter quantity: ");
            while(scanf("%d", &quantity) != 1){
                printf("Invalid quantity format. Enter a number: ");
                while(getchar()!='\n');
            }
            while(getchar()!='\n');
            for(i = 0; i < count; i++){
                if(products[i].quantity == quantity){
                    found = 1;
                    printf("\nName: %s\n", products[i].name);
                    printf("ID: %d\n", products[i].id);
                    printf("Quantity: %d\n", products[i].quantity);
                    printf("Price: $%.2f\n", products[i].price);
                    printf("Category: %s\n", products[i].category);
                }
            }
            break;

        case 4:
            printf("\nEnter price: ");
            while(scanf("%f", &price) != 1){
                printf("Invalid price format. Enter a number: ");
                while(getchar()!='\n');
            }
            while(getchar()!='\n');
            for(i = 0; i < count; i++){
                if(products[i].price == price){
                    found = 1;
                    printf("\nName: %s\n", products[i].name);
                    printf("ID: %d\n", products[i].id);
                    printf("Quantity: %d\n", products[i].quantity);
                    printf("Price: $%.2f\n", products[i].price);
                    printf("Category: %s\n", products[i].category);
                }
            }
            break;

        case 5:
            printf("\nEnter category of product: ");
            fgets(category, MAX_LEN + 1, stdin);
            category[strcspn(category, "\n")] = '\0';

            for(i = 0; i < count; i++){
                if(strcmp(products[i].category, category) == 0) {
                    found = 1;
                    printf("Name: %s\n", products[i].name);
                    printf("ID: %d\n", products[i].id);
                    printf("Quantity: %d\n", products[i].quantity);
                    printf("Price: $%.2f\n", products[i].price);
                    printf("Category: %s\n", products[i].category);
                }
            }
            break;
    }
    if(!found){
        printf("\nProduct not found.\n");
    }
    printf("\nEnter E to return to product inventory system menu: ");
    while (1){
        scanf(" %c", &exit);
        while(getchar()!='\n');

        if (exit == 'e' || exit == 'E'){
            return;
        }
        printf("Invalid input. Enter E to return: ");
    }
}

void update_quantity(struct Product products[], int count){
    char name[MAX_LEN + 1];
    int new_quan;
    int i;

    printf("\nEnter product name: ");
    fgets(name, MAX_LEN + 1, stdin);
    name[strcspn(name, "\n")] = '\0';

    for(i = 0; i < count; i++){
        if (strcmp(products[i].name, name) == 0){
            printf("Current quantity for %s: %d\n", products[i].name, products[i].quantity);
            printf("Enter new quantity for %s: ", products[i].name);
            scanf("%d", &new_quan);

            products[i].quantity = new_quan;

            while(getchar() != '\n');
            
            printf("Quantity has been updated.\n");
            return;
        }
    }

    printf("Product not found.\n");
}

void remove_product(struct Product products[], int *count){
    char name[MAX_LEN + 1];
    int i;
    int found = 0;

    printf("\nEnter name of product to remove: ");
    fgets(name, MAX_LEN + 1, stdin);
    name[strcspn(name, "\n")] = '\0';

    for(i = 0; i < *count; i++){
        if(strcmp(products[i].name, name) == 0){
            found = 1;

            printf("Removed product %s.\n", products[i].name);

            for(; i < *count - 1; i++){
                products[i] = products[i + 1];
            }

            (*count)--;
            break;
        }
    }
    if(!found){
        printf("Product not found.\n");
    }
}

void display_products(struct Product products[], int count){
    int i;
    char exit;

    if (count == 0) {
        printf("\nInventory is empty.\n");
        printf("Enter E to return to product inventory system menu: ");
        scanf(" %c", &exit);
        while(getchar()!='\n');

        return;
    }

    printf("\n============================= INVENTORY =============================\n");
    printf("%-30s %-8s %-10s %-10s %-15s\n",
           "Name", "ID", "Quantity", "Price", "Category");

    printf("-----------------------------------------------------------------------\n");

    for (i = 0; i < count; i++) {
        printf("%-30s %-8d %-10d $%-9.2f %-15s\n",
               products[i].name,
               products[i].id,
               products[i].quantity,
               products[i].price,
               products[i].category);
    }
    printf("\nEnter E to return to product inventory system menu: ");
    while (1){
        scanf(" %c", &exit);
        while(getchar()!='\n');

        if (exit == 'e' || exit == 'E'){
            return;
        }
        printf("Invalid input. Enter E to return: ");
    }
}

void save_to_csv(struct Product products[], int count){
    FILE *file;
    int i; 

    file = fopen("inventory.csv", "w");

    if(file == NULL) {
        printf("Failed to create CSV file.\n");
        return;
    }

    fprintf(file, "Name,ID,Quantity,Price,Category\n");

    for(i = 0; i < count; i++){
        fprintf(file, "%s,%d,%d,%.2f,%s\n", products[i].name, products[i].id, products[i].quantity, products[i].price, products[i].category);
    }

    fclose(file);
    printf("\nSuccessfully saved inventory to inventory.csv\n");
}