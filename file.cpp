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

    bool find_word(void* fileName, void* target) {

        std::string* ptr1 = static_cast<std::string*> (target), *ptr2 = static_cast<std::string*> (fileName);
        std::string fileType, line, word;
        std::stringstream ss1,ss2;

        ss2 << *ptr1;
        ss1 << *ptr2;
        std::string fn = ss1.str(), target_word = ss2.str();

        std::cout << "What type of file is it? (txt, csv, etc?)\n";
        std::getline(std::cin,fileType);

        //Checks if the user input is missing a '.'
        if(fileType[0] != '.'){

            fileType = '.' + fileType;
            std::cout << fileType << std::endl;

        }
        std::fstream file;
        file.open(fn + fileType,std::ios::in);

        while(file.good()){
    
            std::getline(file,line);
            std::stringstream s(line);

            while(std::getline(s,word,' ')){

                if(word == target_word){
            
                    std::cout << target_word << " is found\n";
                    return true;

                }

            }

        }
      
        std::cout << target_word << " is not found\n";
        return false;

    }

}

int main() {
    std::string arg = "Check";
    std::string arg2 = "Blah";
    //file::print_file(static_cast<void*>(&arg));
    //file::print_row(static_cast<void*>(&arg),4);
    file::find_word(static_cast<void*>(&arg),static_cast<void*>(&arg2));
    return 0;
}
