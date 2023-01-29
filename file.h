#ifndef FILE1
#define FILE1 

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
namespace file {

    //@print_file()
    //@param: std::string fileName
    //@return: true(if the file exists), false (if the file does not exist)
    //@description: Takes in a fileName as a parameter, then it will read the file and
    //prints out everything within the file.
     
    bool print_file(std::string fileName);

    //@print_row()
    //@param: std::string fileName, int row
    //@return: true(if the file exists), false(if the file does not exist)
    //@description: Takes in a fileName and row number as parameters, then it will read
    //the file and prints out the content within the row number.
    
    bool print_row(std::string fileName, int row);

    //@find_word()
    //@param: std::string fileName, target
    //@return: true(target is found), false(target isn't found)
    //@description: First, it will cast all the parameters into string*, then it will use
    //stringstream objects to cast it into a string. Then it will use a fstream object to 
    //open the file. It will traverse the entire file until it either finds the target_word,
    //or it has reached the end of the file without finding the target_word.

    bool find_word(std::string fileName,std::string target);

    //@find_sentence()
    //@param: std::string fileName, target
    //@return: true(target is found), false(target isn't found)
    //@description: First, it will cast all the parameters into string*, then it will use
    //stringstream objects to cast it into a string. It will then count the number of words 
    //within the target string. Then it will use a fstream object to 
    //open the file. It will traverse the entire file until it either finds the target_word,
    //or it has reached the end of the file without finding the target_word.

    bool find_sentence(std::string fileName, std::string target);

    //@createNewFile()
    //@param: std::string fileName
    //@return: true(file is able to be created), false(fileName contains illegal characters)
    bool createNewFile(std::string fileName);
}
#endif
