
#include "Replace.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    Replace replacer(filename, s1, s2);

    if (!replacer.readFile())
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }

    replacer.replaceText();

    if (!replacer.writeFile())
    {
        std::cerr << "Error: Could not write to file " << filename + ".replace" << std::endl;
        return 1;
    }

    return 0;
}