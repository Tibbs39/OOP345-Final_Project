// Name: Kenneth Yue
// Seneca Student ID: 127932176
// Seneca email: kyue3@myseneca.ca
// Date of completion: November 14, 2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#ifndef UTILITIES_H
#define UTILITIES_H
#include <string>

class Utilities {
    size_t m_widthField = 1;
    static char m_delimiter;

    public:

        void setFieldWidth(size_t);

        size_t getFieldWidth() const;

        const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);

        static void setDelimiter(const char&);

        const char getDelimiter() const;
};


#endif // UTILITIES_H