#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>

#ifndef FILE
#define FILE 

namespace file {
    //@print_file()
    //@param: std::string fileName
    //@description: Takes in a fileName as a parameter, then it will read the file and
    //prints out everything within the file.

    void print_file(void* fileName);

    //@print_row()
    //@param: std::string fileName, int row
    //@description: Takes in a fileName and row number as parameters, then it will read
    //the file and prints out the content within the row number.

    void print_row(void* fileName, int row);


    void add(int a, int b);

}
#endif
