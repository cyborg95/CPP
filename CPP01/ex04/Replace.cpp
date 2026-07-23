#include "Replace.hpp"

Replace::Replace(std::string filename, std::string s1, std::string s2)
    : _filename(filename), _s1(s1), _s2(s2) {}

bool Replace::readFile()
{
    std::ifstream infile(_filename.c_str());
    if (!infile)
        return false;
    std::string line;
    while (std::getline(infile, line))
    {
        content += line;
        if (!infile.eof())
            content += "\n";
    }
    infile.close();
    return true;
}

void Replace::replaceText()
{
    std::size_t pos = 0;

    while ((pos = content.find(_s1, pos)) != std::string::npos)
    {
        content.erase(pos, _s1.length());
        content.insert(pos, _s2);
        pos += _s2.length();
    }
}

bool Replace::writeFile()
{
    std::ofstream outfile((_filename + ".replace").c_str());

    if (!outfile)
        return false;

    outfile << content;
    outfile.close();

    return true;
}