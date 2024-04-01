// Задание 5. Вариант 2.
// Алгоритм шинглов.

#include "VelichkoGS_String.h"
#include <fstream>
#include <iostream>
#include <iomanip>

void pushBack(VelichkoGS_String*& arr, size_t& sz, const VelichkoGS_String& str) {
    VelichkoGS_String* tmp = new VelichkoGS_String[sz + 1];

    for (size_t i = 0; i < sz; ++i) {
        tmp[i] = arr[i];
    }

    delete[] arr;
    tmp[sz] = str;
    arr = tmp;
    ++sz;
}

void popFront(VelichkoGS_String*& arr, size_t& sz) {
    VelichkoGS_String* tmp = new VelichkoGS_String[sz - 1];

    for (size_t i = 1; i < sz; ++i) {
        tmp[i - 1] = arr[i];
    }

    delete[] arr;
    arr = tmp;
    --sz;
}

void add(VelichkoGS_String**& arr, size_t& sz, VelichkoGS_String* shingle, size_t k) {
    VelichkoGS_String** tmp = new VelichkoGS_String*[sz + 1];

    for (size_t i = 0; i < sz; ++i) {
        tmp[i] = arr[i];
    }

    delete[] arr;

    tmp[sz] = new VelichkoGS_String[k];

    for (size_t i = 0; i < k; ++i) {
        tmp[sz][i] = shingle[i];
    }

    arr = tmp;
    ++sz;
}

bool isContains(VelichkoGS_String** arr, size_t sz, const VelichkoGS_String* shingle, size_t k) {
    bool res = false;

    for (size_t i = 0; i < sz; ++i) {
        bool shinglesEqual = true;

        for (size_t j = 0; j < k; ++j) {
            if (arr[i][j] != shingle[j]) {
                shinglesEqual = false;
            }
        }

        res = res || shinglesEqual;
    }

    return res;
}

void calcShingles(VelichkoGS_String**& shingles, size_t& shinglesSz, size_t k, const char filename[]) {
    VelichkoGS_String sep = ";:\'\",.+-=*|^<>[]{}()!/#%\t\n\\&? ";

    std::ifstream fin;
    fin.open(filename);

    VelichkoGS_String* shingle = nullptr;
    size_t shingleSz = 0;
    VelichkoGS_String token;

    while (!fin.eof()) {
        VelichkoGS_String str;
        getline(fin, str);

        for (size_t i = 0; i < str.length(); ++i) {
            if (sep.find(str[i]) == sep.length()) {
                token.pushback(str[i]);
            } else {
                if (token.length() > 0) {
                    if (shingleSz < k) {
                        pushBack(shingle, shingleSz, token);
                    } else {
                        popFront(shingle, shingleSz);
                        pushBack(shingle, shingleSz, token);
                    }

                    if (shingleSz == k) {
                        if (!isContains(shingles, shinglesSz, shingle, k)) {
                            add(shingles, shinglesSz, shingle, k);
                        }
                    }
                }

                token.clear();
            }
        }

        if (token.length() > 0) {
            if (shingleSz < k) {
                pushBack(shingle, shingleSz, token);
            } else {
                popFront(shingle, shingleSz);
                pushBack(shingle, shingleSz, token);

                if (!isContains(shingles, shinglesSz, shingle, k)) {
                    add(shingles, shinglesSz, shingle, k);
                }
            }
        }

        token.clear();
    }

    delete[] shingle;
}

void clear(VelichkoGS_String**& arr, size_t sz) {
    for (size_t i = 0; i < sz; ++i) {
        delete[] arr[i];
    }

    delete[] arr;
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Введите длину шингла: ";

    int k;
    std::cin >> k;

    while (k < 1) {
        std::cout << "Ошибка! Длина шингла должна быть положительным числом.\n";
        std::cout << "Введите длину шингла: ";
        std::cin >> k;
    }

    VelichkoGS_String** shinglesFirst = nullptr;
    size_t shinglesFirstSz = 0;

    calcShingles(shinglesFirst, shinglesFirstSz, k, "inputVelichko.txt");

    VelichkoGS_String** shinglesSecond = nullptr;
    size_t shinglesSecondSz = 0;

    calcShingles(shinglesSecond, shinglesSecondSz, k, "inputKrotov.txt");

    size_t intersection = 0;

    for (size_t i = 0; i < shinglesFirstSz; ++i) {
        if (isContains(shinglesSecond, shinglesSecondSz, shinglesFirst[i], k)) {
            ++intersection;
        }
    }

    double shinglesCoef = (double)intersection / (shinglesFirstSz + shinglesSecondSz - intersection);

    //for (size_t i = 0; i < shinglesFirstSz; ++i) {
    //    for (size_t j = 0; j < k; ++j) {
    //        std::cout << shinglesFirst[i][j] << ' ';
    //    }

    //    std::cout << '\n';
    //}

    //for (size_t i = 0; i < shinglesSecondSz; ++i) {
    //    for (size_t j = 0; j < k; ++j) {
    //        std::cout << shinglesSecond[i][j] << ' ';
    //    }

    //    std::cout << '\n';
    //}

    std::cout << "Коэффициент сходства: " << std::fixed << std::setprecision(6) << shinglesCoef;

    clear(shinglesFirst, shinglesFirstSz);
    clear(shinglesSecond, shinglesSecondSz);
}