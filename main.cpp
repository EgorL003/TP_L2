#include <iostream>
#include <fstream>
#include "Interface.h"
#include <cstring>

int getWords();

int main() {
    setlocale(LC_ALL, "Russian");
    Interface Table;
    char menu;
    int iCount;

    do {
        system("cls");
        std::cout << "----------| MENU |	" << std::endl;
        std::cout << "1. Add train" << std::endl
            << "2. Extract train" << std::endl
            << "3. Sort trains by alphabet" << std::endl
            << "4. Sort by word length" << std::endl
            << "5. Redacting" << std::endl
            << "6. Bring a list of trains" << std::endl
            << "7. Search for trains by time" << std::endl
            << "8. Search for trains by arrival location" << std::endl
            << "9. Count the number of words in a file" << std::endl
            << "0. Exit" << std::endl
            << "Choose: ";
        std::cin >> menu;

        if (!(std::cin.peek() == '\n' || std::cin.peek() == EOF)) {
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "[Error] Enter the menu item within [0-9]" << std::endl;
            system("pause");
            continue;
        }
        std::cin.ignore(INT_MAX, '\n');

        switch (menu) {
        case '1':
            Table.add();
            break;
        case '2':
            Table.del();
            break;
        case '3':
            Table.sort();
            break;
        case '4':
            Table.sortup();
            break;
        case '5':
            Table.red();
            break;
        case '6':
            Table.print();
            break;
        case '7':
            Table.search();
            break;
        case '8':
            Table.searchArr();
            break;
        case '9':
            iCount = getWords();
            if (iCount != -1)
                std::cout << "The number of words: " << iCount << std::endl;
            break;
        case '0':
            break;
        default:
            std::cout << "[Error] Enter the menu item within [0-9]" << std::endl;
            break;
        }

        system("pause");
    } while (menu != '0');

    return 0;
}

int getWords() {
    std::ifstream inputFile("Text.txt"); // открываем файл для чтения 
    if (!inputFile.is_open()) { // проверяем, открылся ли файл
        std::cerr << "Unable to open file" << std::endl;
        return -1;
    }

    std::string word;
    int wordCount = 0;
    while (inputFile >> word) {
        // Проверяем, состоит ли слово из 4 или менее букв
        if (word.length() <= 4) {
            bool isAllAlpha = true;
            for (char c : word) { // проверяем каждый символ в слове
                if (!std::isalpha(c)) { // если встретился не буквенный символ 
                    isAllAlpha = false;
                    break;
                }
            }
            if (isAllAlpha) {
                wordCount++; // увеличиваем счетчик слов
            }
        }
    }

    inputFile.close(); // закрываем файл 
    return wordCount;
}

