#include <iostream>
#include <filesystem>
#include <string>

namespace qpg 
{
    void cloneRepo(std::string nameOfDir) {
        std::string cloneString{"git clone https://github.com/QuiltMC/quilt-template-mod " + nameOfDir};
        int returnValue{std::system(cloneString.c_str())};
        if(returnValue != 0) {
            throw std::invalid_argument("Error ocoured while running git.");
        }
        std::filesystem::remove_all(nameOfDir + "/.git");
        
    }
}

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
            std::string{"quiltprojectgen <PATH>"});
        }
    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what();
        return 1;
    }
}
