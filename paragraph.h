#ifndef PARAGRAPH_H
#define PARAGRAPH_H
//#include "header2.h"
#include "ExceptionInterface.h"
#pragma once
using namespace std;

class paragraph
{
protected:
    string description;
public:
    // геттер и сеттер
    string getDescription();
    void setDescription(string description);
    //

    paragraph() = default;
    ~paragraph() = default;
};

#endif // PARAGRAPH_H
