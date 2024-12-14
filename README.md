#  Warehouse  Management System FIFO

## Description

This is a straightforward **First In, First Out (FIFO)** warehouse stock management system built with the **C programming language**. It helps you keep track of stock items using a queue structure, making sure the first item you add to the warehouse is the first one to be removed. The system allows you to:

- **Add new stock items** (enqueue)
- **Remove the oldest stock items** (dequeue)
- **View the current stock** in the warehouse

## Features

- **Add Stock**: Easily add a new item with a specific quantity to the warehouse.
- **Remove Stock**: Take out the oldest item from the warehouse, following the FIFO principle.
- **Display Stock**: See all the items currently in the warehouse.
- **User-Friendly Menu**: A simple, interactive text-based menu to guide you through the operations.

## Requirements

- **C Compiler**: Such as `gcc` (GNU Compiler Collection)
- **Operating System**: Works on Windows, Linux, or macOS

## How to Compile and Run

1. **Compile the Code**:

   ```bash
   gcc fifo_warehouse.c -o fifo_warehouse
   ```

2. **Run the Program**:

   ```bash
   ./fifo_warehouse
   ```

## Sample Menu Output

```
--- FIFO Warehouse Stock Management ---
1. Add Stock (Enqueue)
2. Remove Stock (Dequeue)
3. Display Stock
4. Exit
Enter your choice: 1
Enter item name: Item A
Enter quantity: 100
Item "Item A" with quantity 100 added to warehouse.

--- FIFO Warehouse Stock Management ---
Enter your choice: 3

Current Stock in Warehouse:
1. Item: Item A | Quantity: 100

--- FIFO Warehouse Stock Management ---
Enter your choice: 2
Item "Item A" with quantity 100 removed from warehouse.

--- FIFO Warehouse Stock Management ---
Enter your choice: 4
Exiting...
```

## Code Structure

- **`StockItem`**: Stores the name and quantity of each stock item.
- **`StockQueue`**: Manages the queue of stock items.
- **Functions**:
  - `initializeQueue`: Sets up the queue.
  - `isFull`: Checks if the warehouse is at full capacity.
  - `isEmpty`: Checks if the warehouse is empty.
  - `enqueue`: Adds a new item to the warehouse.
  - `dequeue`: Removes the oldest item from the warehouse.
  - `displayQueue`: Shows the current stock items.

## Limitations

- The warehouse can hold a maximum of 5 items (you can change this by modifying `MAX_ITEMS` in the code).
- The interface is simple and text-based.

##

## Author

SARHAN SALAM BAKARMAN

