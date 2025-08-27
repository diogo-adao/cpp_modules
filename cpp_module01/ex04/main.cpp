#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[])
{
    if (argc != 4) {
        std::cout << "Usage: ./file <filename> <s1> <s2>" << std::endl;
        return (1);
    }

    std::string filename = argv[1];
    std::ifstream infile(filename.c_str());
    if (!infile.is_open()) {
        std::cerr << "Error: could not open file " << filename << std::endl;
        return 1;
    }
    std::ofstream outfile((filename + ".replace").c_str());

    std::string line;
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    while (std::getline(infile, line)) {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        outfile << line << "\n"; 
    }

    infile.close();
    outfile.close();
    return (0);
}