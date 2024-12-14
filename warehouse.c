#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 5
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
} StockItem;

typedef struct {
    StockItem items[MAX_ITEMS];
    int front;
    int rear;
    int count;
} StockQueue;

void initializeQueue(StockQueue *q);
int isFull(StockQueue *q);
int isEmpty(StockQueue *q);
void enqueue(StockQueue *q, char name[], int quantity);
void dequeue(StockQueue *q);
void displayQueue(StockQueue *q);

int main() {
    StockQueue warehouse;
    initializeQueue(&warehouse);
    int choice;
    char name[NAME_LENGTH];
    int quantity;

    while (1) {
        printf("\n--- FIFO Warehouse Stock Management ---\n");
        printf("1. Add Stock (Enqueue)\n");
        printf("2. Remove Stock (Dequeue)\n");
        printf("3. Display Stock\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                if (!isFull(&warehouse)) {
                    printf("Enter item name: ");
                    fgets(name, NAME_LENGTH, stdin);
                    name[strcspn(name, "\n")] = '\0';
                    printf("Enter quantity: ");
                    scanf("%d", &quantity);
                    enqueue(&warehouse, name, quantity);
                } else {
                    printf("Warehouse is full! Cannot add more stock.\n");
                }
                break;
            case 2:
                dequeue(&warehouse);
                break;
            case 3:
                displayQueue(&warehouse);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void initializeQueue(StockQueue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

int isFull(StockQueue *q) {
    return q->count == MAX_ITEMS;
}

int isEmpty(StockQueue *q) {
    return q->count == 0;
}

void enqueue(StockQueue *q, char name[], int quantity) {
    if (isFull(q)) {
        printf("Queue is full! Cannot add item.\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_ITEMS;
    strcpy(q->items[q->rear].name, name);
    q->items[q->rear].quantity = quantity;
    q->count++;
    printf("Item \"%s\" with quantity %d added to warehouse.\n", name, quantity);
}

void dequeue(StockQueue *q) {
    if (isEmpty(q)) {
        printf("Warehouse is empty! No stock to remove.\n");
        return;
    }
    printf("Item \"%s\" with quantity %d removed from warehouse.\n", q->items[q->front].name, q->items[q->front].quantity);
    q->front = (q->front + 1) % MAX_ITEMS;
    q->count--;
}

void displayQueue(StockQueue *q) {
    if (isEmpty(q)) {
        printf("Warehouse is empty!\n");
        return;
    }
    printf("\nCurrent Stock in Warehouse:\n");
    int index = q->front;
    for (int i = 0; i < q->count; i++) {
        printf("%d. Item: %s | Quantity: %d\n", i + 1, q->items[index].name, q->items[index].quantity);
        index = (index + 1) % MAX_ITEMS;
    }
}
