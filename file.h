#ifndef FILE1
#define FILE1 

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string.h>
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

    //@find_word()
    //@param: std::string fileName, target
    //@return: true(target is found), false(target isn't found)
    //@description: First, it will cast all the parameters into string*, then it will use
    //stringstream objects to cast it into a string. Then it will use a fstream object to 
    //open the file. It will traverse the entire file until it either finds the target_word,
    //or it has reached the end of the file without finding the target_word.

    bool find_word(void* fileName,void* target);

    //@find_sentence()
    //@param: std::string fileName, target
    //@return: true(target is found), false(target isn't found)
    //@description: First, it will cast all the parameters into string*, then it will use
    //stringstream objects to cast it into a string. It will then count the number of words 
    //within the target string. Then it will use a fstream object to 
    //open the file. It will traverse the entire file until it either finds the target_word,
    //or it has reached the end of the file without finding the target_word.

    bool find_sentence(void* fileName, void* target);
}
#endif
