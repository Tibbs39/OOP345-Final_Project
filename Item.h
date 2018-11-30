// Name: Kenneth Yue
// Seneca Student ID: 127932176
// Seneca email: kyue3@myseneca.ca
// Date of completion: November 14, 2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#ifndef ITEM_H
#define ITEM_H
#include <string>

class Item {
    std::string m_name;
    std::string m_description;
    unsigned int m_serialNumber;
    unsigned int m_quantity;
    unsigned int static m_widthField;

    public:
        Item(const std::string&);

        const std::string& getName() const;

        const unsigned int getSerialNumber();

        const unsigned int getQuantity();

        void updateQuantity();

        void display(std::ostream&, bool) const;


};


#endif // ITEM_H