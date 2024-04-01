// Задание 4. Вариант 9.
// Какой символ чаще всего встречается непосредственно перед запятой.
// Реже всего. Выведите на экран и в файл.

#include "VelichkoGS_String.h"
#include <iostream>
#include <fstream>

int main() {
    setlocale(LC_ALL, "Russian");
    std::ifstream fin;
    fin.open("input4.txt");

    int count[256];
    int countComma[256];
    VelichkoGS_String alph = "абвгдежзийклмнопрстуфхцчшщъыьэюяАБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ.!?,:;-\"\'()[]{} ";

    for (size_t i = 0; i < 256; ++i) {
        count[i] = 0;
        countComma[i] = 0;
    }

    VelichkoGS_String s;
    getline(fin, s);

    while (!fin.eof()) {
        for (size_t i = 0; i < s.length(); ++i) {
            ++count[s[i] + 128];

            if (i < s.length() - 1 && s[i + 1] == ',') {
                ++countComma[s[i] + 128];
            }
        }

        getline(fin, s);
    }

    fin.close();

    for (size_t i = 0; i < s.length() - 1; ++i) {
        ++count[s[i] + 128];

        if (i < s.length() - 2 && s[i + 1] == ',') {
            ++countComma[s[i] + 128];
        }
    }

    VelichkoGS_String minS, maxS;
    minS.pushback(alph[0]);
    maxS.pushback(alph[0]);

    for (size_t i = 1; i < alph.length(); ++i) {
        if (countComma[alph[i] + 128] < countComma[minS[0] + 128]) {
            minS.clear();
            minS.pushback(alph[i]);
        } else if (countComma[alph[i] + 128] == countComma[minS[0] + 128]) {
            minS.pushback(alph[i]);
        }

        if (countComma[alph[i] + 128] > countComma[maxS[0] + 128]) {
            maxS.clear();
            maxS.pushback(alph[i]);
        } else if (countComma[alph[i] + 128] == countComma[maxS[0] + 128]) {
            maxS.pushback(alph[i]);
        }
    }

    std::ofstream fout;
    fout.open("output4.txt");

    for (size_t i = 0; i < alph.length(); ++i) {
        std::cout << "Количество символа '" << alph[i] << "' в тексте: " << count[alph[i] + 128] << '\n';
        fout << "Количество символа '" << alph[i] << "' в тексте: " << count[alph[i] + 128] << '\n';
    }

    std::cout << '\n';
    fout << '\n';

    std::cout << "Чаще всего перед запятой встречаются символы '" << maxS[0] << "'";

    for (size_t i = 1; i < maxS.length(); ++i) {
        std::cout << ", '" << maxS[i] << "'"; 
    }

    std::cout << " : " << countComma[maxS[0] + 128] << " раз\n";

    std::cout << "Реже всего перед запятой встречаются символы '" << minS[0] << "'";

    for (size_t i = 1; i < minS.length(); ++i) {
        std::cout << ", '" << minS[i] << "'"; 
    }

    std::cout << " : " << countComma[minS[0] + 128] << " раз";

    fout << "Чаще всего перед запятой встречаются символы '" << maxS[0] << "'";

    for (size_t i = 1; i < maxS.length(); ++i) {
        fout << ", '" << maxS[i] << "'"; 
    }

    fout << " : " << countComma[maxS[0] + 128] << " раз\n";

    fout << "Реже всего перед запятой встречаются символы '" << minS[0] << "'";

    for (size_t i = 1; i < minS.length(); ++i) {
        fout << ", '" << minS[i] << "'"; 
    }

    fout << " : " << countComma[minS[0] + 128] << " раз";

    fout.close();
}