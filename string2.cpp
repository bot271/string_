//
//  string1.cpp
//  string1
//
//  Created by Mingze Lee on 2024/9/29.
//

#include <iostream>
#include "string1.h"
#include <cstring>
#include <cctype>


int String::num_strings = 0;

String::String(const char * s)
{
    len_ = std::strlen(s);
    str_ = new char [len_ + 1];
    strcpy(str_, s);
    ++num_strings;
}

String::String()
{
    len_ = 0;
    str_ = new char [1];
    str_[0] = '\0';
    ++num_strings;
}

String::String(const String & st)
{
    len_ = st.len_;
    str_ = new char [len_ + 1];
    std::strcpy(str_, st.str_);
    ++num_strings;
}

String::~String()
{
    delete [] str_;
    --num_strings;
}

int String::length() const
{
    return len_;
}

String & String::operator=(const String & st)
{
    if (this == & st)
        return * this;
    delete [] str_;
    len_ = st.len_;
    str_ = new char [len_ + 1];
    std::strcpy(str_, st.str_);
    return *this;
}

String & String::operator=(const char * s)
{
    len_ = std::strlen(s);
    delete [] str_;
    str_ = new char [len_ + 1];
    std::strcpy(str_ ,s);
    return * this;
}

int String::how_many() const
{
    return num_strings;
}

char & String::operator[](int i)
{
    return str_[i];
}

const char & String::operator[](int i) const
{
    return str_[i];
}

String String::operator+(const String & st)
{
    char * pc1 = new char [st.len_ + (*this).len_ + 1];
    strcpy(pc1, (*this).str_);
    strcat(pc1, st.str_);
    return String(pc1);
}

bool operator<(const String & st1, const String & st2)
{
    return (strcmp(st1.str_, st2.str_) < 0);
}

bool operator>(const String & st1, const String & st2)
{
    return (strcmp(st1.str_, st2.str_) > 0);
}

bool operator==(const String & st1, const String & st2)
{
    return (!std::strcmp(st1.str_, st2.str_));
}

std::ostream & operator<<(std::ostream & os, const String & st)
{
    os << "String content: " << st.str_;
    return os;
}

std::istream & operator>>(std::istream & is, String & st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        st = temp;
    while (is.get() != '\n')
        continue;
    return is;
}

void String::Stringlow()
{
    for (int i = 0; i < len_; ++i)
    {
        if (isalpha(*(str_ + i)))
            str_[i] = toupper(str_[i]);
    }
}

void String::Stringup()
{
    for (int i = 0; i < len_; ++i)
    {
        if (isalpha(*(str_ + i)))
            str_[i] = tolower(str_[i]);
    }
}


