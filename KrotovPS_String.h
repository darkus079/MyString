#pragma once
#include <iostream>
#include <algorithm>

const size_t INF = (size_t)1e9;

class KrotovPS_String {
private:
    size_t _size = 0;
    char* _str = nullptr;

    void swap(KrotovPS_String& string);

public:
    KrotovPS_String() = default;
    KrotovPS_String(const char string[]);
    KrotovPS_String(size_t size, char c = ' ');
    KrotovPS_String(const KrotovPS_String &str);
    ~KrotovPS_String() ;

    size_t length() const;
    bool empty() const;
    char& operator[](size_t index);
    const char& operator[](size_t index) const;
    void clear();
    void pushBack(char c);
    void popBack();
    void append(const KrotovPS_String& str);
    void erase(size_t start, size_t count = 1);
    void insert(size_t start, size_t count, char c);
    void insert(size_t start, const KrotovPS_String& string);
    void toUpper();
    void toLower();
    void reverse();
    size_t find(char c) const;
    size_t count(char c) const;
    KrotovPS_String substr(size_t start, size_t count = INF) const;

    KrotovPS_String& operator=(KrotovPS_String str);
    KrotovPS_String& operator+=(const KrotovPS_String& str);
    KrotovPS_String operator+(const KrotovPS_String& str) const;

    bool operator==(const KrotovPS_String& string) const;
    bool operator!=(const KrotovPS_String& string) const;
    bool operator<=(const KrotovPS_String& string) const;
    bool operator<(const KrotovPS_String& string) const;
    bool operator>=(const KrotovPS_String& string) const;
    bool operator>(const KrotovPS_String& string) const;
};

std::istream& operator>>(std::istream& in, KrotovPS_String& string);
std::ostream& operator<<(std::ostream& out, const KrotovPS_String& string);

void getline(std::istream& in, KrotovPS_String& string);