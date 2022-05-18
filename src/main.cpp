#include <iostream>
#include <filesystem>
#include <string>

#include "../include/Clone.hpp"

int main(int argc, char *argv[])
{
    try {
        if(argc >= 2) {
            if (argc >= 3 && std::string{"-r"}.compare(argv[1]))
            {
                try
                {
                    std::filesystem::remove_all(argv[1]);
                }
                catch(const std::exception& e)
                {
                    std::cerr << "There is no Directory called " + std::string{argv[1]} << std::endl;
                    std::cerr << e.what() << '\n';
                }
                
            }
            
            std::string path{argv[1]};
            qpg::cloneRepo(path);
        }
        else
        {
            throw std::invalid_argument(std::string{"There are not enough Arguments for this Command\n"} + 
            std::string{"quiltprojectgen <PATH> [-r]\n"});
        }
    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what();
        return 1;
    }
}
