/**
 * Collaborated with: 
 * Ethan Wan,  
 * Mariam Golwalla,  
 * zybooks.com - CS 10C,
 * CS 10C lecture slides
 * github.com to host our code
**/

#ifndef __PRINTJOB_H
#define __PRINTJOB_H

using namespace std;

class PrintJob {
private:
  int priority;
  int jobNumber;
  int numPages;

public:
  PrintJob ( int, int, int);
  int getPriority ( );
  int getJobNumber ( );
  int getPages ( );
  //You can add additional functions here
};
#endif