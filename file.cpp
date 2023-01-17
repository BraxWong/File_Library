#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <sstream>


void print_file(std::string fileName){

    std::string fileType, line, word;

    std::cout << "What type of file is it? (txt, csv, etc?)\n";
    std::getline(std::cin,fileType);

    //Checks if the user input is missing a '.'
    if(fileType[0] != '.'){

        fileType = '.' + fileType;
        std::cout << fileType << std::endl;

    }

    std::fstream file;
    file.open(fileName + fileType,std::ios::in);

    while(file.good()){

      std::getline(file,line);
      std::stringstream s(line);
      
      while(std::getline(s,word,'\n')){

          std::cout << word << "\n";

      }

    }

}

int main () {
    print_file("testing");
    return 0;
}
