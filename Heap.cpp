/**
 * Collaborated with: 
 * Ethan Wan,  
 * Mariam Golwalla,  
 * zybooks.com - CS 10C,
 * CS 10C lecture slides
 * github.com to host our code
**/

#include "Heap.h"

Heap::Heap() {
    numItems = 0;

    for (int i = 0; i < MAX_HEAP_SIZE; i++) {
        arr[i] = nullptr;
    }
}

void Heap::enqueue( PrintJob* insert) {
    PrintJob* temp;

    // if full array
    if (numItems > 9)
        return;
    
    // if empty array
    if (numItems == 0) {
        arr[0] = insert;
        numItems++;
        return;
    }
    
    /* Personal implementation
    for (int i = 0; i < numItems; i++) {
        if (arr[i]->getPriority() < insert->getPriority()) {
            numItems++;

            for (int j = numItems - 1; j > i; j--) {
                arr[j] = arr[j-1];
            }

            arr[i] = insert;
            break;
        }
    } */

    numItems++;
    arr[numItems - 1] = insert;

    for (int i = numItems - 1; i > 0; i--) {
        if (arr[i]->getPriority() > arr[i-1]->getPriority()) {
            temp = arr[i-1];
            arr[i-1] = arr[i];
            arr[i] = temp;
        }
    }
}

void Heap::dequeue() {
    // if empty array
    if (numItems < 1) 
        return;
    
    PrintJob* temp;

    arr[0] = arr[numItems-1];

    numItems--;

    for (int i = 0; i < numItems; i++) {
        if (arr[i]->getPriority() < arr[i+1]->getPriority()) {
            temp = arr[i+1];
            arr[i+1] = arr[i];
            arr[i] = temp;
        }
    }
}

PrintJob* Heap::highest() {
    int highestIndex = 0;
    for (int i = 0; i < numItems - 1; i++) {
        if (arr[i]->getPriority() < arr[i+1]->getPriority())
            highestIndex = i + 1;
    }

    return arr[highestIndex];
}

// uses highest function
void Heap::print() {
    // zybooks use
    PrintJob* value = highest();

    cout << "Priority: " << value->getPriority() 
         << ", Job Number: " << value->getJobNumber()
         << ", Number of Pages: " << value->getPages()
         << endl;
    

    /* // Personal use, for displaying all the values in arr[]
    for (int i = 0; i < numItems; i++) {
        cout << "Priority: " << arr[i]->getPriority() 
             << ", Job Number: " << arr[i]->getJobNumber()
             << ", Number of Pages: " << arr[i]->getPages()
             << endl;
    } */
}

void Heap::trickleDown(int value){
    
}