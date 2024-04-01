// ������� 3. ������� 5.
// ���� ������. ������� ��������� ������� ��������� ������ � ��� ������:
// ������ �������� � ������ ������, ������ �������� � ��� ������. ����������
// ������ ���������� ������� ����� �� �������� �� �� ���������.

#include "VelichkoGS_String.h"
#include <fstream>

bool isUpper(char c) {
    return (c >= '�' && c <= '�');
}

char toLower(char c) {
    if (c >= '�' && c <= '�') {
        return (char)(c - ((int)'�' - '�'));
    } else {
        return c;
    }
}

char toUpper(char c) {
    if (c >= '�' && c <= '�') {
        return (char)(c - ((int)'�' - '�'));
    } else {
        return c;
    }
}

int main() {
    VelichkoGS_String code[2] = {"����������������", "����������������"};

    std::ifstream fin;
    fin.open("input3.txt");

    std::ofstream fout;
    fout.open("output3_code.txt");

    VelichkoGS_String s;
    getline(fin, s);

    while (!fin.eof()) {
        for (size_t i = 0; i < s.length(); ++i) {
            if (toLower(s[i]) >= '�' && toLower(s[i]) <= '�') {
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
        if (toLower(s[i]) >= '�' && toLower(s[i]) <= '�') {
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
            if (toLower(s[i]) >= '�' && toLower(s[i]) <= '�') {
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
        if (toLower(s[i]) >= '�' && toLower(s[i]) <= '�') {
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