#include "file.h"
#include <cstdlib>
using namespace file;

namespace file {

    bool print_file(std::string fileName, std::string fileType){


        std::string line, word;

        fileName = checkFileType(fileName, fileType);


        std::fstream file;
        file.open(fileName,std::ios::in);

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

    bool print_row(std::string fileName, std::string fileType, int row){

        std::string fn, line, word;
        int rowCount = 0;

        fn = checkFileType(fileName, fileType);

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

       bool find_word(std::string fileName, std::string fileType, std::string target) {
          bool word_found = false;
          std::string fn, line, word;
          fn = checkFileType(fileName, fileType);
          std::fstream file;
          file.open(fn ,std::ios::in);

          while(file.good()){

              std::getline(file,line);
              std::stringstream s(line);

              while(std::getline(s,word,' ')){

                  if(word == target){

                      std::cout << target << " is found\n";
                      word_found = true;

                  }

              }

          }

          std::cout << target << " is not found\n";
          return word_found;

    }

    bool find_sentence(std::string fileName, std::string fileType, std::string target){
      bool sentence_found = false;
      //Storing the sentence into a vector of string
      std::vector<std::string> targetVector;
      std::stringstream ss(target);
      std::string word1;
      while(ss >> word1){
        targetVector.push_back(word1);
      }

      std::string line, word;
      int count = 0;
      fileName = checkFileType(fileName, fileType);
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
                      sentence_found = true;
                    }
                }

                else {
                    count = 0;
                }

            }

      }
      std::cout << target << " is not found\n";
      return sentence_found;
    }

    bool createNewFile(std::string fileName, std::string fileType) {
        bool fileCreated = true;
        char illegalChar[] = {'#','%','&','{','}','<','>','*','?','/',' ','$','!',':','@','+','`','|','=','"'};
        //Checks for illegal character within the file name
        for(int i = 0; i < 19; ++i){
          for(unsigned long j = 0; j < fileName.length(); ++j) {
            if(fileName[j] == illegalChar[i]){
              std::cout << "Error: Illegal character detected. " << illegalChar[i] << " is not allowed in the file name.\n";
              fileCreated = false;
            }
          }
        }
        //Checks for special rules
        if(fileName[0] == ' ' || fileName[fileName.length()] == ' ' || fileName[0] == '.' || fileName[fileName.length()] == '.' || fileName[0] == '-' || fileName[fileName.length()] == '-' || fileName[0] == '_' || fileName[fileName.length()] == '_' ){
          std::cout << "Space, period, hyphen, or underline is detected at the start or end of filename.\n";
          fileCreated = false;
        }

        fileName = checkFileType(fileName, fileType);
        //Creates the file
        std::ofstream newFile(fileName);
        newFile.close();
        return fileCreated;
    }

    std::string checkFileType(std::string fileName, std::string fileType){


        //Checks if the user input is missing a '.'
        if(fileType[0] != '.'){

            fileType = '.' + fileType;

        }

        //Checks for txt
        if(fileType[1] == 't' && fileType[2] == 'x' && fileType[3] == 't' && fileType.length() == 4){
            return fileName + fileType;
        }
        else if(fileType[1] == 'c' && fileType[2] == 's' && fileType[3] == 'v' && fileType.length() == 4){
            return fileName + fileType;
        }
        else {
            return NULL;
        }
    }

    bool checkFileExists(std::string fileName, std::string fileType){
        bool fileExists = false;
        fileName = checkFileType(fileName, fileType);
        std::ifstream file(fileName);
        if(file.good()){
            fileExists = true;
        }
        return fileExists;
    }


    bool find_and_replace(std::string fileName, std::string fileType, std::string origin, std::string replacement){
      std::vector<std::string> str;
      //Checks if the file exists or not
      if(!checkFileExists(fileName, fileType)){
        return false;
      }
      fileName = checkFileType(fileName, fileType);
      //Uses find_word() to find out if the origin word is present within the file
      //Also makes sure origin and replacement are not the same word
      if(!find_word("Check",fileType, origin) || origin == replacement){
        return false;
      }
      //Uses storeFileAsVector() to convert file data to a vector
      str = storeFileAsVector("Check", fileType);
      //Iterating through the vector to check if the origin word is present
      for(unsigned long i = 0; i < str.size(); ++i){
        if(str[i] == origin){
          str[i] = replacement;
          break;
        }
      }
      //Opening the file
      std::ofstream ofile;
      ofile.open(fileName);
      //Writing the data back to the file with replaced data
      for(unsigned long i = 0; i < str.size(); ++i){
        ofile << str[i];
        if(str[i] != "\n"){
          ofile << " ";
        }
      }
      return true;
    }

    bool write_to_file(std::string fileName, std::string fileType, std::string str){
      std::ofstream file;
      fileName = checkFileType(fileName, fileType);
      file.open(fileName);
      file << str;
      return true;
    }


    bool append_to_file(std::string fileName, std::string fileType, std::string str){
      fileName = checkFileType(fileName, fileType);
      std::ofstream ofile;
      ofile.open(fileName, std::ios::app);
      ofile << str;
      ofile.close();
      std::cout << str << "\nHas been appended to file " << fileName << " successfully.\n";
      return true;
    }


    std::vector<std::string> storeFileAsVector(std::string fileName, std::string fileType){
      std::string line, word, temp;
      std::vector<std::string> result;
      fileName = checkFileType(fileName, fileType);
      std::ifstream ifile;
      ifile.open(fileName);

      while(ifile.good()){
        std::getline(ifile,line);
        std::stringstream ss(line);
        while(std::getline(ss,temp,' ')){
          result.push_back(temp);
        }
        result.push_back("\n");
      }
      return result;
    }

    bool compress_file(std::string fileName) {
      bool file_compressed = false;
      std::fstream file;
      file.open(fn,std::ios::in);
      if(file.good()) {
        std::string command = "gzip -k " + fileName;
        std::system(command);
        file_compressed = true;
      }
      return file_compressed;
    }

    bool decompress_file(std::string fileName){
      bool file_decompressed = false;
      std::fstream file;
      file.open(fn,std::ios::in);
      if(file.good()) {
        std::string command = "gzip -d " + fileName;
        std::system(command);
        file_decompressed = true;
      }
      return file_decompressed;
    }
}


