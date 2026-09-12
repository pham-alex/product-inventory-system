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


int main(void) {
    struct Product products[MAX_PRODUCTS];
    int product_count = 0;
    char code;

    while (1) {
        printf("\nPRODUCT INVENTORY SYSTEM\n");
        printf("a - Add Product\n");
        printf("f - Find Product\n");
        printf("u - Update Quantity\n");
        printf("r - Remove Product\n");
        printf("d - Display Inventory\n");
        printf("q - Quit\n");
        printf("Select a code: ");

        scanf(" %c", &code);
        while (getchar()!='\n');

        switch(code) {
            case 'a':
                add_product(products, &product_count);
                break;
            case 'f':
                find_product(products, product_count);
                break;
            case 'u':
                update_quantity(products, product_count);
                break;
            case 'r':
                remove_product(products, &product_count);
                break;
            case 'd':
                display_products(products, product_count);
                break;
            case 'q':
                printf("Exiting product inventory system.\n");
                return 0;
            default:
                printf("\n\nInvalid code.\n");
        
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

    printf("Enter product ID: ");
    scanf("%d", &products[*count].id);

    printf("Enter quantity: ");
    scanf("%d", &products[*count].quantity);

    printf("Enter price: ");
    scanf("%f", &products[*count].price);

    while (getchar() != '\n');

    printf("Enter category: ");
    fgets(products[*count].category, MAX_LEN + 1, stdin);
    products[*count].category[strcspn(products[*count].category, "\n")] = '\0';

    printf("Successfully added %s in the inventory!\n", products[*count].name);
    (*count)++;
}

void find_product(struct Product products[], int count){
    char name[MAX_LEN + 1];
    int i;

    printf("\nEnter product name: ");
    fgets(name, MAX_LEN + 1, stdin);
    name[strcspn(name, "\n")] = '\0';

    for(i = 0; i < count; i++){
        if(strcmp(products[i].name, name) == 0) {
            printf("Name: %s\n", products[i].name);
            printf("ID: %d\n", products[i].id);
            printf("Quantity: %d\n", products[i].quantity);
            printf("Price: $%.2f\n", products[i].price);
            printf("Category: %s\n", products[i].category);
            return;
        }
    }
    
    printf("Can not find product.\n");
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

    if (count == 0) {
        printf("\nInventory is empty.\n");
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
}