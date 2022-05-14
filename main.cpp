#include <iostream>
#include <filesystem>
#include <string>

namespace qpg 
{
    void cloneRepo(std::string nameOfDir) {
        std::string cloneString{"git clone https://github.com/QuiltMC/quilt-template-mod " + nameOfDir};
        int returnValue{std::system(cloneString.c_str())};
        std::filesystem::remove_all(nameOfDir + "/.git");
        if(returnValue == 128) {
            throw std::invalid_argument("Please chose an other folder or make sure that nothing is in the folder.");
        }
    }
}

int main(int argc, char *argv[])
{
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
