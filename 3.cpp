// Задание 3. Вариант 5.
// Шифр Альбам. Алфавит случайным образом вписывают подряд в две строки:
// первая половина в первой строке, вторая половина — под первой. Шифрование
// текста происходит заменой буквы на соседнюю ей по вертикали.

#include "VelichkoGS_String.h"
#include <fstream>

bool isUpper(char c) {
    return (c >= 'А' && c <= 'Я');
}

char toLower(char c) {
    if (c >= 'А' && c <= 'Я') {
        return (char)(c - ((int)'А' - 'а'));
    } else {
        return c;
    }
}

char toUpper(char c) {
    if (c >= 'а' && c <= 'я') {
        return (char)(c - ((int)'а' - 'А'));
    } else {
        return c;
    }
}

int main() {
    VelichkoGS_String code[2] = {"съжцбфвкзюоплынр", "тящеьэшчмйагиудх"};

    std::ifstream fin;
    fin.open("input3.txt");

    std::ofstream fout;
    fout.open("output3_code.txt");

    VelichkoGS_String s;
    getline(fin, s);

    while (!fin.eof()) {
        for (size_t i = 0; i < s.length(); ++i) {
            if (toLower(s[i]) >= 'а' && toLower(s[i]) <= 'я') {
                if (code[0].find(toLower(s[i])) < code[0].length()) {
                    if (isUpper(s[i])) {
                        s[i] = toUpper(code[1][code[0].find(toLower(s[i]))]);
                    } else {
                        s[i] = code[1][code[0].find(toLower(s[i]))];
                    }
                } else {
                    if (isUpper(s[i])) {
                        s[i] = toUpper(code[0][code[1].find(toLower(s[i]))]);
                    } else {
                        s[i] = code[0][code[1].find(toLower(s[i]))];
                    }
                }
            }
        }

        fout << s << '\n';
        getline(fin, s);
    }

    for (size_t i = 0; i < s.length(); ++i) {
        if (toLower(s[i]) >= 'а' && toLower(s[i]) <= 'я') {
            if (code[0].find(toLower(s[i])) < code[0].length()) {
                if (isUpper(s[i])) {
                    s[i] = toUpper(code[1][code[0].find(toLower(s[i]))]);
                } else {
                    s[i] = code[1][code[0].find(toLower(s[i]))];
                }
            } else {
                if (isUpper(s[i])) {
                    s[i] = toUpper(code[0][code[1].find(toLower(s[i]))]);
                } else {
                    s[i] = code[0][code[1].find(toLower(s[i]))];
                }
            }
        }
    }

    fout << s.substr(0, s.length() - 1);

    fin.close();
    fout.close();

    fin.open("output3_code.txt");
    fout.open("output3_decode.txt");

    getline(fin, s);

    while (!fin.eof()) {
        for (size_t i = 0; i < s.length(); ++i) {
            if (toLower(s[i]) >= 'а' && toLower(s[i]) <= 'я') {
                if (code[0].find(toLower(s[i])) < code[0].length()) {
                    if (isUpper(s[i])) {
                        s[i] = toUpper(code[1][code[0].find(toLower(s[i]))]);
                    } else {
                        s[i] = code[1][code[0].find(toLower(s[i]))];
                    }
                } else {
                    if (isUpper(s[i])) {
                        s[i] = toUpper(code[0][code[1].find(toLower(s[i]))]);
                    } else {
                        s[i] = code[0][code[1].find(toLower(s[i]))];
                    }
                }
            }
        }

        fout << s << '\n';
        getline(fin, s);
    }

    for (size_t i = 0; i < s.length(); ++i) {
        if (toLower(s[i]) >= 'а' && toLower(s[i]) <= 'я') {
            if (code[0].find(toLower(s[i])) < code[0].length()) {
                if (isUpper(s[i])) {
                    s[i] = toUpper(code[1][code[0].find(toLower(s[i]))]);
                } else {
                    s[i] = code[1][code[0].find(toLower(s[i]))];
                }
            } else {
                if (isUpper(s[i])) {
                    s[i] = toUpper(code[0][code[1].find(toLower(s[i]))]);
                } else {
                    s[i] = code[0][code[1].find(toLower(s[i]))];
                }
            }
        }
    }

    fout << s.substr(0, s.length() - 1);

    fin.close();
    fout.close();
}