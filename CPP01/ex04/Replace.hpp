#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <string>
# include <iostream>
# include <fstream>

class Replace
{
    public:
        Replace(std::string filename, std::string s1, std::string s2);

        bool readFile();
        void replaceText();
        bool writeFile();
    private:
        std::string _filename;
        std::string _s1;
        std::string _s2;
        std::string content;
};

#endif