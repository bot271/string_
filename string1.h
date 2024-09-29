//
//  string1.h
//  string1
//
//  Created by Mingze Lee on 2024/9/29.
//

#ifndef STRING1_H_
#define STRING1_H_
#include <iostream>


class String
{
private:
    char * str_;
    int len_;
    static int num_strings;
    static const int CINLIM = 80;
public:
    String(const char *);
    String();
    String(const String &);
    ~String();
    int how_many() const;
    int length () const;
    String & operator=(const String &);
    String & operator=(const char *);
    char & operator[](int);
    const char & operator[](int) const;
    friend bool operator<(const String &, const String &);
    friend bool operator>(const String &, const String &);
    friend bool operator==(const String &, const String &);
    friend std::ostream & operator<<(std::ostream &, const String &);
    friend std::istream & operator>>(std::istream &, String &);
};


#endif
