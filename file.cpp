#include "file.h"
using namespace file;

namespace file {

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

    void print_row(std::string fileName, int row){

        std::string fileType, line, word;
        int rowCount = 0;

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
            rowCount++;

            while(std::getline(s,word,'\n') && rowCount == row){

                std::cout << word << "\n";

            }

        }

    }

       bool find_word(std::string fileName, std::string target) {

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

            while(std::getline(s,word,' ')){

                if(word == target){
            
                    std::cout << target << " is found\n";
                    return true;

                }

            }

        }
      
        std::cout << target << " is not found\n";
        return false;

    }

    bool find_sentence(std::string fileName, std::string target){
      int sentenceCounter = target.length();
      std::cout << sentenceCounter << " " << fileName << "\n";
      return true;
    }

}

int main() {
    std::string arg = "Check";
    std::string arg2 = "Blah hello from the other side";
    file::find_sentence(arg,arg2);
    return 0;
}
