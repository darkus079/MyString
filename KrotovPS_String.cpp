#include "pch.h"
#include "framework.h"
#include "KrotovPS_String.h"

void KrotovPS_String::swap(KrotovPS_String &string) {
    std::swap(_str, string._str);
    std::swap(_size, string._size);
}

KrotovPS_String::KrotovPS_String(size_t size, char c) : _size(size), _str(new char[size]) {   
    for (size_t i = 0; i < _size; ++i) {
        _str[i] = c;
    }
}

KrotovPS_String::KrotovPS_String(const char string[]) {
    size_t i = 0;

    while (string[i] != '\0') {
        ++i;
        ++_size;
    }

    _str = new char[_size];

    for (size_t i = 0; i < _size; ++i) {
        _str[i] = string[i];
    }
}

KrotovPS_String::KrotovPS_String(const KrotovPS_String& str) : _size(str._size), _str(new char[str._size]) {
    std::copy(str._str, str._str + str._size, _str);
}

KrotovPS_String::~KrotovPS_String() {
    delete[] _str;
}

size_t KrotovPS_String::length() const {
    return _size;
}

bool KrotovPS_String::empty() const {
    return (_size == 0);
}

char& KrotovPS_String::operator[](size_t index) {
    if (index >= _size) {
        throw "Выход за границы строки!";
    }

    return _str[index];
}

const char& KrotovPS_String::operator[](size_t index) const {
    if (index >= _size) {
        throw "Выход за границы строки!";
    }

    return _str[index];
}

void KrotovPS_String::clear() {
    _size = 0;
    delete[] _str;
    _str = nullptr;
}

void KrotovPS_String::pushBack(char c) {
    char* tmp = new char[_size + 1];

    for (size_t i = 0; i < _size; ++i) {
        tmp[i] = _str[i];
    }

    tmp[_size] = c;
    delete[] _str;
    _str = tmp;
    ++_size;
}

void KrotovPS_String::popBack() {
    if (_size == 0) {
        throw "Невозможно удалить символ из пустой строки!";
    }

    char* tmp = new char[_size - 1];

    for (size_t i = 0; i < _size - 1; ++i) {
        tmp[i] = _str[i];
    }

    delete[] _str;
    _str = tmp;
    --_size;
}

void KrotovPS_String::append(const KrotovPS_String &string) {
    (*this) += string;
}

void KrotovPS_String::erase(size_t start, size_t count) {
    if (start <= _size && count > 0) { 
        size_t len = _size - (start + count - 1 < _size ? count : _size - start);
        char* tmp = new char[len];

        for (size_t i = 0; i < start; ++i) {
            tmp[i] = _str[i];
        }

        for (size_t i = start + count; i < _size; ++i) {
            tmp[i - count] = _str[i];
        }

        delete[] _str;
        _str = tmp;
        _size = len;
    }
}

void KrotovPS_String::insert(size_t start, size_t count, char c) {
    if (start > _size) {
        throw "Выход за границы строки!";
    }

    char* tmp = new char[_size + count];

    for (size_t i = 0; i < start; ++i) {
        tmp[i] = _str[i];
    }

    for (size_t i = 0; i < count; ++i) {
        tmp[start + i] = c;
    }

    for (size_t i = start; i < _size; ++i) {
        tmp[i + count] = _str[i];
    }

    delete[] _str;
    _str = tmp;
    _size = _size + count;
}

void KrotovPS_String::insert(size_t start, const KrotovPS_String& string) {
    if (start > _size) {
        throw "Выход за границы строки!";
    }

    char* tmp = new char[_size + string._size];
    
    for (size_t i = 0; i < start; ++i) {
        tmp[i] = _str[i];
    }

    for (size_t i = 0; i < string._size; ++i) {
        tmp[start + i] = string._str[i];
    }

    for (size_t i = start; i < _size; ++i) {
        tmp[i + string._size] = _str[i];
    }

    delete[] _str;
    _str = tmp;
    _size = _size + string._size;
}

void KrotovPS_String::toUpper() {
    for (size_t i = 0; i < _size; ++i) {
        if (_str[i] >= 'a' && _str[i] <= 'z') {
            _str[i] += (int)'A' - 'a';
        }
    }
}

void KrotovPS_String::toLower() {
    for (size_t i = 0; i < _size; ++i) {
        if (_str[i] >= 'A' && _str[i] <= 'Z') {
            _str[i] += (int)'a' - 'A';
        }
    }
}

void KrotovPS_String::reverse() {
    for (size_t i = 0; i < _size / 2; ++i) {
        size_t tmp = _str[i];
        _str[i] = _str[_size - i - 1];
        _str[_size - i - 1] = tmp;
    }
}

size_t KrotovPS_String::find(char c) const {
    for (size_t i = 0; i < _size; ++i) {
        if (_str[i] == c) {
            return i;
        }
    }

    return _size;
}

size_t KrotovPS_String::count(char c) const {
    size_t res = 0;

    for (size_t i = 0; i < _size; ++i) {
        if (_str[i] == c) {
            ++res;
        }
    }

    return res;
}

KrotovPS_String KrotovPS_String::substr(size_t start, size_t count) const {
    if (start >= _size) {
        throw "Выход за пределы строки!";
    }

    size_t len = (count < _size - start ? count : _size - start);
    KrotovPS_String res(len);

    for (size_t i = start; i < start + len; ++i) {
        res._str[i - start] = _str[i];
    }

    return res;
}

KrotovPS_String& KrotovPS_String::operator=(KrotovPS_String string) {
    swap(string);
    return *this;
}

KrotovPS_String& KrotovPS_String::operator+=(const KrotovPS_String& string) {
    char* tmp = new char[_size + string._size];

    for (size_t i = 0; i < _size; ++i) {
        tmp[i] = _str[i];
    }

    for (size_t i = _size; i < _size + string._size; ++i) {
        tmp[i] = string._str[i - _size];
    }

    delete[] _str;
    _str = tmp;
    _size = _size + string._size;
    
    return *this;
}

KrotovPS_String KrotovPS_String::operator+(const KrotovPS_String& string) const {
    KrotovPS_String res(*this);
    res += string;
    return res;
}

bool KrotovPS_String::operator<(const KrotovPS_String& string) const {
    size_t len = (_size < string._size ? _size : string._size);

    for (size_t i = 0; i < len; ++i) {
        if (_str[i] > string._str[i]) {
            return false;
        }
        else if (_str[i] < string._str[i]) {
            return true;
        }
    }

    return (_size < string._size);
}

bool KrotovPS_String::operator==(const KrotovPS_String& string) const {
    return !(*this < string) && !(string < *this);
}

bool KrotovPS_String::operator!=(const KrotovPS_String& string) const {
    return (*this < string) || (string < *this);
}

bool KrotovPS_String::operator<=(const KrotovPS_String& string) const {
    return (*this < string || *this == string);
}

bool KrotovPS_String::operator>(const KrotovPS_String& string) const {
    return !(*this <= string);
}

bool KrotovPS_String::operator>=(const KrotovPS_String& string) const {
    return !(*this < string);
}

std::istream& operator>>(std::istream& in, KrotovPS_String& string) {
    string.clear();

    while (in) {
        char c;
        c = in.get();

        if (c != ' ' && c != '\n') {
            string.pushBack(c);
            break;
        }
    }

    while (in) {
        char c;
        c = in.get();

        if (c == ' ' || c == '\n') {
            break;
        } else {
            string.pushBack(c);
        }
    }

    return in;
}

std::ostream& operator<<(std::ostream& out, const KrotovPS_String& string) {
    for (size_t i = 0; i < string.length(); ++i) {
        out << string[i];
    }
    
    return out;
}

void getline(std::istream& in, KrotovPS_String& string) {
    string.clear();

    while (in) {
        char c;
        c = in.get();

        if (c == '\n') {
            break;
        } else {
            string.pushBack(c);
        }
    }
}