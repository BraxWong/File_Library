#include "file.h"
using namespace file;

namespace file {

    void print_file(void* fileName){

        
        std::string fileType, line, word, *fn = static_cast<std::string*> (fileName);

        std::cout << "What type of file is it? (txt, csv, etc?)\n";
        std::getline(std::cin,fileType);

        //Checks if the user input is missing a '.'
        if(fileType[0] != '.'){

            fileType = '.' + fileType;
            std::cout << fileType << std::endl;

        }

        std::stringstream ss;
        ss << *fn;
        std::string fn1 = ss.str();

        std::fstream file;
        file.open(fn1 + fileType,std::ios::in);

        while(file.good()){

            std::getline(file,line);
            std::stringstream s(line);
      
            while(std::getline(s,word,'\n')){

                std::cout << word << "\n";

            }

        }

    }

    void print_row(void* fileName, int row){

        std::string fileType, line, word, *fn = static_cast<std::string*> (fileName);
        int rowCount = 0;

        std::cout << "What type of file is it? (txt, csv, etc?)\n";
        std::getline(std::cin,fileType);

        //Checks if the user input is missing a '.'
        if(fileType[0] != '.'){

            fileType = '.' + fileType;
            std::cout << fileType << std::endl;

        }

        std::stringstream ss;
        ss << *fn;
        std::string fn1 = ss.str();
        std::fstream file;
        std::cout << fn1 << std::endl;
        file.open(fn1 + fileType,std::ios::in);

        while(file.good()){

            std::getline(file,line);
            std::stringstream s(line);
            rowCount++;

            while(std::getline(s,word,'\n') && rowCount == row){

                std::cout << word << "\n";

            }

        }

    }

    void add(int a, int b){

        std::cout << a + b << "\n";
        
    }
}

int main() {
    std::string arg = "Check";
    file::print_file(static_cast<void*>(&arg));
    file::print_row(static_cast<void*>(&arg),4);
    add(1,2);
    return 0;
}
