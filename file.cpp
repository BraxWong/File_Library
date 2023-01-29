#include "file.h"
using namespace file;

namespace file {

    bool print_file(std::string fileName){

        
        std::string fileType, line, word;

        std::cout << "What type of file is it? (txt, csv, etc?)\n";
        std::getline(std::cin,fileType);

        //Checks if the user input is missing a '.'
        if(fileType[0] != '.'){

            fileType = '.' + fileType;

        }


        std::fstream file;
        file.open(fileName + fileType,std::ios::in);

        //Check if the file exists or not
        if(!file.good()){

            return false;

        }

        while(file.good()){

            std::getline(file,line);
            std::stringstream s(line);
      
            while(std::getline(s,word,'\n')){

                std::cout << word << "\n";

            }

        }
        
        //Operation complete
        return true;

    }

    bool print_row(std::string fileName, int row){

        std::string fileType, line, word;
        int rowCount = 0;

        std::cout << "What type of file is it? (txt, csv, etc?)\n";
        std::getline(std::cin,fileType);

        //Checks if the user input is missing a '.'
        if(fileType[0] != '.'){

            fileType = '.' + fileType;

        }

        std::fstream file;
        file.open(fileName + fileType,std::ios::in);

        //Check if the file exists or not
        if(!file.good()){

            return false;

        }

        while(file.good()){

            std::getline(file,line);
            std::stringstream s(line);
            rowCount++;

            while(std::getline(s,word,'\n') && rowCount == row){

                std::cout << word << "\n";

            }

        }

        //Operation complete  
        return true;

    }

       bool find_word(std::string fileName, std::string target) {

        std::string fileType, line, word;
        std::cout << "What type of file is it? (txt, csv, etc?)\n";
        std::getline(std::cin,fileType);

        //Checks if the user input is missing a '.'
        if(fileType[0] != '.'){

            fileType = '.' + fileType;

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

    bool createNewFile(std::string fileName) {
        
        char illegalChar[] = {'#','%','&','{','}','<','>','*','?','/',' ','$','!',':','@','+','`','|','=','"'};
        //Checks for illegal character within the file name
        for(int i = 0; i < 19; ++i){
          for(unsigned long j = 0; j < fileName.length(); ++j) {
            if(fileName[j] == illegalChar[i]){
              std::cout << "Error: Illegal character detected. " << illegalChar[i] << " is not allowed in the file name.\n";
              return false;
            }
          }
        }
        //Checks for special rules
        if(fileName[0] == ' ' | fileName[fileName.length()] == ' ' | fileName[0] == '.' | fileName[fileName.length()] == '.' | fileName[0] == '-' | fileName[fileName.length()] == '-' | fileName[0] == '_' | fileName[fileName.length()] == '_' ){
          std::cout << "Space, period, hyphen, or underline is detected at the start or end of filename.\n";
          return false;
        }
        //Creates the file
        std::ofstream newFile(fileName);
        newFile.close();
        return true;
    }

}

int main() {

    file::createNewFile("something.txt");
    return 0;

}
