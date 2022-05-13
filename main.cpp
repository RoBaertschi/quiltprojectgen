#include <iostream>
#include <filesystem>

int main(int argc, char *argv[])
{
    std::cout << std::filesystem::current_path();
    std::system("git clone https://github.com/QuiltMC/quilt-template-mod testquilt");
    std::filesystem::remove_all("testquilt/.git");
}
