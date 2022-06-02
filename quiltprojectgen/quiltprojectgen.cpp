#include <iostream>
#include <filesystem>
#include <string>

#include <quiltprojectgen/Clone.hpp>
#include <quiltprojectgen/Flags.hpp>

qpg::Flag flag = qpg::Flag::none;



int main(int argc, char *argv[])
{
    try {
        if(argc >= 2) {
          std::string path{argv[1]};
          if (path.find(";") != std::string::npos or
              path.find("&") != std::string::npos or
              path.find("|") != std::string::npos) {
            throw std::invalid_argument("Error no ; or & or | allowed");
            }
            

            if (argc >= 3)
            {
                for (size_t i = 2; i < argc; i++)
                {
                    if (std::string{"-r"}.compare(argv[i]) == 0)
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
                    }else if (std::string{"-d"}.compare(argv[i]) == 0)
                    {
                        flag = qpg::Flag::deleteDirAfterwards;
                        std::cout << "WARN: Only use -d for testing." << std::endl;
                    } else 
                    {
                        throw std::invalid_argument(std::string{"There are wrong Argumments!!\n"} + 
                            std::string{"quiltprojectgen <PATH> [-r]\n"});
                    }
                    
                }
                
                
                
            }
            
            qpg::cloneRepo(path);
            if(flag == qpg::Flag::deleteDirAfterwards ){
                std::filesystem::remove_all(path);
            }
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
