#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    (void)argv;
    if (argc != 4) {
        std::cout << "Usage: ./file <filename> <s1> <s2>" << std::endl;
        return (1);
    }

    std::string filename = "example.txt";
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        std::cerr << "Error: could not open file " << filename << std::endl;
        return 1;
    }
    std::string line;
    while (std::getline(infile, line)) {
        std::cout << line << std::endl;
}
    return (0);
}