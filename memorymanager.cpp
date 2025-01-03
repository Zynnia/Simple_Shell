#include <iostream>
#include <vector>
#include <fstream>
#include "memorymanager.h"
#include "kernel.h"
#include "ram.h"

int launcher(std::vector<std::string> &files ) {
    //Programs used to store the BackingStore Files
    std::vector<std::string> programs;

    //Write to the backing store
    for (auto &fileName : files) {
        std::ifstream test (fileName);
        //check if file sucessfully opened
        if (!test.is_open()) {
            std::cout << "File Failed to open" << std::endl;
        } else {
            //opening a new file for writing
            std::ofstream myfile;
            myfile.open("BackingStore/"+ fileName);
            std::string line;
            while (getline(test, line)) {
                myfile << (line + "\n");
            }
            //close the newly written file
            myfile.close();
            //close the original file
            test.close();
            //Add to the newly written files to programs
            programs.push_back("BackingStore/"+ fileName);
        }
    }
    //Pass to the kernel for processing
    myInit(programs);
    return 0;
}

int countTotalPages(std::shared_ptr<std::ifstream> &p) {
    int number = 0;
    std::string line;
    while (getline(*p, line)) {
        number++;
    }
    //reset the file pointer back to the beginning
    p->clear();
    p->seekg(0,std::ios::beg);
    //Every 4 lines is 1 page, if number isnt cleanly divisible by 4 then
    // divide and add 1.
    return (number % 4 == 0) ? (number / 4) : ((number / 4) + 1);
}

void findPage(std::shared_ptr<std::ifstream> &p, const int pageNumber) {
    //set the file pointer to the beginning
    p->seekg(0, std::ios::beg);
    int i = 1;

    //iterate through the files till we get the desired page
    std::string dummy;
    while (getline(*p,dummy)) {
        i++;
        if (i == pageNumber * 4) {
            break;
        }
    }
}

//Return array index if not null else return -1
int findFrame(std::shared_ptr<std::ifstream> p) {
    //Look for the first non null entry in ram
    int i = 0;
    for (const auto &x : ram) {
        if (x != nullptr) {
            return i;
        }
        i++;
    }
    return -1;
}




