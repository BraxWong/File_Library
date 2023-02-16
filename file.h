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
    //@param: std::string fileName, std::string fileType
    //@return: true(if the file exists), false (if the file does not exist)
    //@description: Takes in a fileName as a parameter, then it will read the file and
    //prints out everything within the file.
     
    bool print_file(std::string fileName, std::string fileType);

    //@print_row()
    //@param: std::string fileName,std::string fileType, int row
    //@return: true(if the file exists), false(if the file does not exist)
    //@description: Takes in a fileName and row number as parameters, then it will read
    //the file and prints out the content within the row number.
    
    bool print_row(std::string fileName, std::string fileType, int row);

    //@find_word()
    //@param: std::string fileName,std::string fileType, std::string target
    //@return: true(target is found), false(target isn't found)
    //@description: First, it will cast all the parameters into string*, then it will use
    //stringstream objects to cast it into a string. Then it will use a fstream object to 
    //open the file. It will traverse the entire file until it either finds the target_word,
    //or it has reached the end of the file without finding the target_word.

    bool find_word(std::string fileName, std::string fileType,std::string target);

    //@find_sentence()
    //@param: std::string fileName, std::string fileType, std::string target
    //@return: true(target is found), false(target isn't found)
    //@description: First, it will cast all the parameters into string*, then it will use
    //stringstream objects to cast it into a string. It will then count the number of words 
    //within the target string. Then it will use a fstream object to 
    //open the file. It will traverse the entire file until it either finds the target_word,
    //or it has reached the end of the file without finding the target_word.

    bool find_sentence(std::string fileName, std::string fileType, std::string target);

    //@createNewFile()
    //@param: std::string fileName, std::string fileType
    //@return: true(file is able to be created), false(fileName contains illegal characters)
    //@description: First, it will check for illegal character within the file name. If an illegal character or 
    //rules are found, the function will return false. Then it will create a new file using the ofstream object, 
    //the file will be placed in the project directory. The ofstream object will be closed at the end, thus returning 
    //true for signaling the completion of the function.
    bool createNewFile(std::string fileName, std::string fileType);

    //@checkFileType()
    //@param: std::string fileName, std::string fileType
    //@return: std::string fileName
    //@description: It will ask for the type of file through user input. Then it will check whether the first index
    //of the user input is '.', if so, it will return the fileName + user input. Or else, it will add the '.' into the 
    //user input. It will then return the fileName + user input.

    std::string checkFileType(std::string fileName, std::string fileType);

    //@checkFileExists()
    //@param: std::string fileName, std::string fileType
    //@return: true(if the file exists), false(if the file does not exist)
    //@description: The fileName parameter will be passed into checkFileType, which will ask for the file type from the user,
    //and it will return the fileName string. An ifstream object will be created by passing in the fileName parameter. Then ifstream.good()
    //will be used to check if the file exists or not. Return the true if the file exists, false if the file does not exists.
    bool checkFileExists(std::string fileName, std::string fileType);

    //@find_and_replace
    //@param: std::string fileName, std::string fileType, std::string origin, std::string replacement
    //@return: false(can't find origin from the file || origin == replacement), true(function executed successfully)
    //@description: The fileName and fileType parameters will be passed into checkFileType and it will return the fileName string.
    //Within the for loop, find_word() helper function will then used to find out if the origin word is present within the file,
    //it will also check whether origin and replacement are the same word. If either of them is true, the function will terminate and 
    //thus return false. Else , storeFileAsVector() helper function will be called to read and store all file data(words) into a vector of
    //string. A for loop will then be executed to find the origin word within the file. When the word has been found, it will be replaced with
    //the replacement word. An ostream object will be created and ofstream.open() will be called with the modified fileName passed in. Another for
    //loop will be started to pass all the elements within the vector of string into the ofstream object(file). The function will return true.
    bool find_and_replace(std::string fileName, std::string fileType, std::string origin, std::string replacement);

    //@write_to_file()
    //@param: std::string fileName, std::string fileType, std::string str
    //@return:  true (function executed successfully)
    //@description: The fileName will be modified by using checkFileType helper function.
    //Then an ofstream object will be created and ofstream.open() will be called with the modified
    //fileName being passed in as the argument. Then the str will be writen to the file using the
    //file object << operator. Afterwards, the function will end when true has been returned.
    bool write_to_file(std::string fileName, std::string fileType, std::string str);

    //@append_to_file()
    //@param: std::string fileName, std::string fileType, std::string str
    //@return: true(Always)
    //@description: The fileName will be modified by using checkFileType helper function.
    //Then an ofstream object will be created with std::ios::app as the second argument. 
    //Then the ofstream.open() will be called with the modified fileName being passed in as the arguement.
    //The parameter str will then be written to the file using << operator. 
    bool append_to_file(std::string fileName, std::string fileType, std::string str);

    //@storeFileAsVector()
    //@param: std::string fileName, std::string fileType
    //@return: std::vector<std::string> result(fileName data)
    //@description: The fileName will be modified by using checkFileType helper function.
    //Then an ifstream object will be created with the ifstream.open() being called with the modified 
    //fileName being passed in as the argument. File data will be push_back into the
    //vector, then the result will then be returned.
    std::vector<std::string> storeFileAsVector(std::string fileName, std::string fileType);
}
#endif
