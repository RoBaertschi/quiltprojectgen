#include <quiltprojectgen/Clone.hpp>
#include <iostream>
#include <filesystem>

namespace qpg
{
    void cloneRepo(std::string nameOfDir) {
        std::string cloneString{"git clone https://github.com/QuiltMC/quilt-template-mod " + nameOfDir};
        int returnValue{std::system(cloneString.c_str())};
        if(returnValue != 0) {
            throw std::invalid_argument("Error ocoured while running git. ERROR: " + std::to_string(returnValue) + "\n");
        }
        std::filesystem::remove_all(nameOfDir + "/.git");
    }
} // namespace qpg

