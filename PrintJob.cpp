/**
 * Collaborated with: 
 * Ethan Wan,  
 * Mariam Golwalla,  
 * zybooks.com - CS 10C,
 * CS 10C lecture slides
 * github.com to host our code
**/

#include "PrintJob.h"

PrintJob::PrintJob ( int setP, int setJ, int numP ):priority(setP), jobNumber(setJ), numPages(numP){}
int PrintJob::getPriority ( ){
    return priority;
}

int PrintJob::getJobNumber ( ){
    return jobNumber;
}

int PrintJob::getPages ( ){
    return numPages;
}