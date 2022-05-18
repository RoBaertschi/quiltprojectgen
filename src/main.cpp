#include <iostream>
#include <filesystem>
#include <string>

#include "../include/Clone.hpp"

int main(int argc, char *argv[])
{
    try {
        if(argc >= 2) {
            std::string path{argv[1]};
            qpg::cloneRepo(path);
        }
        else
        {
            throw std::invalid_argument(std::string{"There are not enough Arguments for this Command\n"} + 
            std::string{"quiltprojectgen <PATH>\n"});
        }
    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what();
        return 1;
    }
}
