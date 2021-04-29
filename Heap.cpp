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
    if (numItems >= MAX_HEAP_SIZE)
        return;


    arr[numItems] = insert;
    int i = numItems;
    numItems++;

    // parent node should be (i-1)/2 regardeless of root node starting node, assuming complete node, def of max heap
    // for loop should percolate up insert, check parent every run, and sets i to the location of the next parent after run
    /*
    for (int i = numItems - 1; (i != 0) && (arr[(i-1)/2]->getPriority() < arr[i]->getPriority()); i = (i-1)/2) {
        temp = arr[(i-1)/2];
        arr[(i-1)/2] = arr[i];
        arr[i] = temp;
    } */

    while((i != 0) && (arr[(i-1)/2]->getPriority() < arr[i]->getPriority()))
       {
           temp = arr[(i-1)/2];
           arr[(i-1)/2] = arr[i];
           arr[i] = temp;
           
           i = (i-1)/2;
       }
}

void Heap::dequeue() {
    // if empty array
    if (numItems < 1) 
        return;
    
    //PrintJob* temp = arr[0];

    arr[0] = arr[numItems-1];
    //delete temp;
    numItems--;

    trickleDown(0);
}

PrintJob* Heap::highest() {
    if (numItems < 1)
        return nullptr;

    return arr[0];
}

// uses highest function
void Heap::print() {
    // zybooks use
       
    PrintJob* value = highest();

    cout << "Priority: " << value->getPriority() 
         << ", Job Number: " << value->getJobNumber()
         << ", Number of Pages: " << value->getPages()
         << endl;
    
    /*
    // Personal use, for displaying all the values in arr[]
    for (int i = 0; i < numItems; i++) {
        cout << "Priority: " << arr[i]->getPriority() 
             << ", Job Number: " << arr[i]->getJobNumber()
             << ", Number of Pages: " << arr[i]->getPages()
             << endl;
    } */
}

void Heap::trickleDown(int location){
    int leftChild = 2*location + 1;
    int rightChild = 2*location + 2;

    int index = location;

    if (leftChild < numItems && (arr[leftChild]->getPriority() > arr[index]->getPriority()))
        index = leftChild;

    if (rightChild < numItems && (arr[rightChild]->getPriority() > arr[index]->getPriority()))
        index = rightChild;

    if (location != index) {
        PrintJob *temp = arr[location];
        arr[location] = arr[index];
        arr[index] = temp;

        trickleDown(index);
    }
}