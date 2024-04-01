// Задание 2. Вариант 3.
// Текстовый файл состоит из символов. Текст разбит на строки различной длины.
// В каждой строке заменить все маленькие буквы после пробела или точки на
// большие. Вывести в файл результат.

#include "VelichkoGS_String.h"
#include <fstream>

int min(int a, int b) {
    return (a < b ? a : b);
}

int main() {
    std::ifstream fin;
    fin.open("input2.txt");

    std::ofstream fout;
    fout.open("output2.txt");

    VelichkoGS_String s;
    getline(fin, s);

    while (!fin.eof()) {
        size_t pos = min(s.find(' '), s.find('.'));

        for (size_t i = pos + 1; i < s.length(); ++i) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                s[i] += ((int)'A' - 'a');
            }
        }

        fout << s << '\n';
        getline(fin, s);
    }

    size_t pos = min(s.find(' '), s.find('.'));

    for (size_t i = pos + 1; i < s.length(); ++i) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] += ((int)'A' - 'a');
        }
    }

    fout << s.substr(0, s.length() - 1);

    fin.close();
    fout.close();
}