#include <iostream>
#include <filesystem>
#include <string>

#include "Clone.hpp"
#include "Flags.hpp"

qpg::Flag flag = qpg::Flag::none;

int main(int argc, char *argv[])
{
    try {
        if(argc >= 2) {
            if (argc >= 3)
            {
                for (size_t i = 2; i < argc; i++)
                {
                    if (std::string{"-r"}.compare(argv[i]))
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
                    } else if (std::string{"-d"}.compare(argv[i]))
                    {
                        flag = qpg::Flag::deleteDirAfterwards;
                        std::cout << "WARN: Only use -d for testing." << std::endl;
                    }
                    
                    
                }
                
                
                
            }
            
            std::string path{argv[1]};
            qpg::cloneRepo(path);
            std::filesystem::remove_all(path);
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
