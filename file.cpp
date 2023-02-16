#include "file.h"
using namespace file;

namespace file {

    bool print_file(std::string fileName){

        
        std::string line, word;

        std::string fn = checkFileType(fileName); 


        std::fstream file;
        file.open(fn,std::ios::in);

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

        std::string fn, line, word;
        int rowCount = 0;

        fn = checkFileType(fileName); 

        std::fstream file;
        file.open(fn,std::ios::in);

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

        std::string fn, line, word;
        fn = checkFileType(fileName);
        std::fstream file;
        file.open(fn ,std::ios::in);

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
      //Storing the sentence into a vector of string
      std::vector<std::string> targetVector;
      std::stringstream ss(target);
      std::string word1;
      while(ss >> word1){
        targetVector.push_back(word1);
      }

      std::string fileType, line, word;
      int count = 0;
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
                if(word == targetVector[count]){
                    count++;
                    if(count == static_cast<int> (targetVector.size())) {
                      std::cout << target << " is found\n";
                      return true;
                    }
                }

                else {
                    count = 0;
                }

            }

      }
      std::cout << target << " is not found\n";
      return false;
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
        if(fileName[0] == ' ' || fileName[fileName.length()] == ' ' || fileName[0] == '.' || fileName[fileName.length()] == '.' || fileName[0] == '-' || fileName[fileName.length()] == '-' || fileName[0] == '_' || fileName[fileName.length()] == '_' ){
          std::cout << "Space, period, hyphen, or underline is detected at the start or end of filename.\n";
          return false;
        }
        //Creates the file
        std::ofstream newFile(fileName);
        newFile.close();
        return true;
    }

    std::string checkFileType(std::string fileName){

        std::string fileType;
        std::cout << "What type of file is it? (txt, csv, etc?)\n";
        std::getline(std::cin,fileType);

        //Checks if the user input is missing a '.'
        if(fileType[0] != '.'){

            fileType = '.' + fileType;

        }
        
        return fileName + fileType;

    }

    bool checkFileExists(std::string fileName){

        fileName = checkFileType(fileName);
        std::ifstream file(fileName);
        if(file.good()){
            return true;
        }
        return false;
    }


    bool find_and_replace(std::string fileName, std::string origin, std::string replacement){
      std::string str;
      fileName = checkFileType(fileName);
      //Check if the file exists within the repo folder
      //if(!checkFileExists(fileName)) {
         // return false;
      //}

      //Read the entire file and store it as a string at str
      std::ifstream infile;
      infile.open(fileName);
      std::getline(infile,str);

      std::cout << str << "\n";
      //Find the origin within str and store the ptr 
      auto ptr = str.find(origin);

      //run it until it is the end of the string
      while(ptr != std::string::npos){
         // Replace the word at the ptr location for specific length with the replacement word.
         str.replace(ptr,origin.length(),replacement);
         //           ^        ^              ^
         //           |        |              |
         //       Location   length    replacement word
         
         //Keep looking for the word starting from ptr location 
         ptr = str.find(origin,      ptr);
         //                ^          ^
         //                |          |
         //             target     location  
      }
      std::ofstream ofile;
      ofile.open(fileName);
      ofile << str;
      return true;
    }

    bool write_to_file(std::string fileName, std::string str){
      std::ofstream file;
      fileName = checkFileType(fileName);
      file.open(fileName);
      file << str;
      return true;
    }


    bool append_to_file(std::string fileName, std::string str){
      fileName = checkFileType(fileName);
      std::ofstream ofile;
      ofile.open(fileName, std::ios::app);
      ofile << str;
      ofile.close();
      std::cout << str << "\nHas been appended to file " << fileName << " successfully.\n";
      return true;
    }


    std::string storeFileAsString(std::string fileName){
      std::string line, word, temp, result;
      fileName = checkFileType(fileName);
      std::ifstream ifile;
      ifile.open(fileName);
      
      while(ifile.good()){
        std::getline(ifile,line);
        std::stringstream ss(line);
        while(std::getline(ss,temp,'\n')){
          result+=temp;
        }
      }
      return result;
    }
}

int main() {

    std::cout << file::storeFileAsString("Check") << "\n";
    //std::cout <<  file::find_and_replace("Check","123","456") << "\n";
    //std::cout << file::write_to_file("Check","Bskdlajfkjdhasfjdasjfhdasjfjdsah");
    //file::append_to_file("Check", "Hi My name is what?");
    return 0;

} 
