#include "Interface.h"

Interface::Interface() {
    std::cout << "Interface class constructor called" << std::endl;
    data = nullptr;
    size = 0;
}

Interface::~Interface() {
    if (data)
        delete[] data;
    std::cout << "Interface class destructor called" << std::endl;
}

void Interface::add() {
    std::string sTmp;
    int iTmp;
    try {
        system("CLS");
        std::cout << "---------| Adding |---------" << std::endl;
        Train* tmp = new Train[size + 1];
        for (int i = 0; i < size; i++) {
            tmp[i] = data[i];
        }

        std::cout << "Enter train number: ";
        getline(std::cin, sTmp);
        if (sTmp.empty())
            throw (std::string)"Train number cannot be empty";
        tmp[size].setTrainNum(sTmp);

        std::cout << "Enter the train arrival location: ";
        getline(std::cin, sTmp);
        if (sTmp.empty())
            throw (std::string)"The train arrival point cannot be empty";
        tmp[size].setEndPoint(sTmp);

        std::cout << "Enter the time of departure of the train:" << std::endl;
        std::cout << "Hours [0-23]: ";
        getline(std::cin, sTmp);
        iTmp = std::stoi(sTmp);
        if (iTmp < 0 || iTmp > 23)
            throw (std::string)"Entering an hour should be in the range from 0 to 23!";
        tmp[size].setTimeStartHours(sTmp);

        std::cout << "Minutes [0-59]: ";
        getline(std::cin, sTmp);
        iTmp = std::stoi(sTmp);
        if (iTmp < 0 || iTmp > 59)
            throw (std::string)"Entering minutes should be in the range from 0 to 59!";
        if (iTmp < 10)
            sTmp = '0' + sTmp;
        tmp[size].setTimeStartMinutes(sTmp);

        if (data)
            delete[] data;
        data = tmp;
        std::cout << "The element is successfully added" << std::endl;
        size++;
        system("pause");
    }
    catch (std::string err) {
        std::cout << "[ERROR] " + err << std::endl;
        system("pause");
    }
}

void Interface::red() {
    try {
        system("CLS");
        std::string sTmp;
        int iTmp;
        std::cout << "---------| Redacting |---------" << std::endl;
        int choise1;
        std::cout << "Enter what train do you want to change: ";
        std::cin >> choise1;
        if (choise1 < 0 || choise1 >= size)
            throw (std::string)"Those train doesn't exist";

        int choise2;
        std::cout << "Enter what parameter do you want to redact" << std::endl
            << "1. Train number" << std::endl
            << "2. Arrival location" << std::endl
            << "3. Time of departure" << std::endl;
        std::cin >> choise2;
        if (choise2 < 1 || choise2 > 3)
            throw (std::string)"Those parameter doesn't exist";

        if (choise2 == 1) {
            std::cout << "Enter new train number: ";
            std::cin.ignore(INT_MAX, '\n');
            getline(std::cin, sTmp);
            if (sTmp.empty())
                throw (std::string)"Train number cannot be empty";
            data[choise1].setTrainNum(sTmp);
        }
        if (choise2 == 2) {
            std::cout << "Enter new train arrival location: ";
            std::cin.ignore(INT_MAX, '\n');
            getline(std::cin, sTmp);
            if (sTmp.empty())
                throw (std::string)"Train arrival location cannot be empty";
            data[choise1].setEndPoint(sTmp);
        }
        if (choise2 == 3) {
            std::cout << "Enter new time of departure of the train:" << std::endl;
            std::cout << "Hours [0-23]: ";
            std::cin.ignore(INT_MAX, '\n');
            getline(std::cin, sTmp);
            iTmp = std::stoi(sTmp);
            if (iTmp < 0 || iTmp > 23)
                throw (std::string)"Entering an hour should be in the range from 0 to 23!";
            data[choise1].setTimeStartHours(sTmp);
            std::cout << "Minutes [0-59]: ";
            getline(std::cin, sTmp);
            iTmp = std::stoi(sTmp);
            if (iTmp < 0 || iTmp > 59)
                throw (std::string)"Entering minutes should be in the range from 0 to 59!";
            if (iTmp < 10)
                sTmp = '0' + sTmp;
            data[choise1].setTimeStartMinutes(sTmp);
        }

        std::cout << "The element is successfully redacted" << std::endl;
        system("pause");
    }
    catch (std::string err) {
        std::cout << "[ERROR] " + err << std::endl;
        system("pause");
    }
}

void Interface::del() {
    int index;
    system("CLS");
    std::cout << "---------| Extracting |---------" << std::endl;
    try {
        if (!size)
            throw (std::string)"No trains to extract";
        for (int i = 0; i < size; i++) {
            std::cout << i << ". " << data[i].getTrainNum() << std::endl;
        }
        std::cout << "Select the element for removal: ";
        std::cin >> index;
        if (index < 0 || index >= size)
            throw (std::string)"The selected element does not exist";

        if (size == 1) {
            delete[] data;
            data = nullptr;
            std::cout << "Item retrieved successfully" << std::endl;
            size--;
            system("pause");
            return;
        }

        Train* tmp = new Train[size - 1];
        int j = 0;
        for (int i = 0; i < size; i++) {
            if (index == i)
                continue;
            tmp[j] = data[i];
            j++;
        }
        delete[] data;
        data = tmp;
        size--;
        std::cout << "Item retrieved successfully" << std::endl;
        system("pause");
    }
    catch (std::string err) {
        std::cout << "[ERROR] " + err << std::endl;
    }
}

void Interface::sort() {
    system("CLS");
    std::cout << "---------| Sorting by alphabet |---------" << std::endl;
    try {
        if (!size)
            throw (std::string)"No trains to sort";
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (strcmp(data[j].getEndPoint().c_str(), data[j + 1].getEndPoint().c_str()) > 0) {
                    std::swap(data[j], data[j + 1]); // меняем элементы местами
                }
            }
        }
    }
    catch (std::string err) {
        std::cout << "[ERROR] " + err << std::endl;
    }
}

void Interface::sortup() {
    system("CLS");
    std::cout << "---------| Sorting by length |---------" << std::endl;
    try {
        if (!size)
            throw (std::string)"No train to sort";
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (data[j].getEndPoint().length() > data[j + 1].getEndPoint().length()) {
                    std::swap(data[j], data[j + 1]); // меняем элементы местами
                }
            }
        }
    }
    catch (std::string err) {
        std::cout << "[ERROR] " + err << std::endl;
    }
}

void Interface::search() {
    system("CLS");
    std::cout << "---------| Search |---------" << std::endl;
    try {
        if (!size)
            throw (std::string)"No trains to find";
        std::string sTime; // Время
        bool empty = true; // Флаг пустоты вывода
        int iTime;

        std::cout << "Enter hours [0-23]: ";
        std::cin >> sTime;
        iTime = std::stoi(sTime);
        if (iTime < 0 || iTime > 23)
            throw (std::string)"Entering an hour should be in the range from 0 to 23!";

        std::string sMinutes;
        std::cout << "Enter minutes [0-59]: ";
        std::cin >> sMinutes;
        int iMinutes = std::stoi(sMinutes);
        if (iMinutes < 0 || iMinutes > 59)
            throw (std::string)"Entering minutes should be in the range from 0 to 59!";

        for (int i = 0; i < size; i++) {
            if (stoi(sTime) < stoi(data[i].getTimeStartHours())) {
                std::cout << data[i];
                empty = false;
            }
            else if (stoi(sTime) == stoi(data[i].getTimeStartHours()) && stoi(sMinutes) < stoi(data[i].getTimeStartMinutes())) {
                std::cout << data[i];
                empty = false;
            }
        }
        if (!empty)
            std::cout << "There are no suitable trains for your request!" << std::endl;
    }
    catch (std::string err) {
        std::cout << "[ERROR] " + err << std::endl;
    }
}

void Interface::searchArr() {
    system("CLS");
    std::cout << "---------| Search |---------" << std::endl;
    try {
        if (!size)
            throw (std::string)"No trains to find";
        std::string Arr; // Время
        bool empty = false; // Флаг пустоты вывода
        int iTime;
        std::cout << "Enter location of arriving: ";
        
        getline(std::cin, Arr);
        for (int i = 0; i < size; i++) {
            if (Arr == data[i].getEndPoint()) {
                !empty ? empty = true : false;
                cout << data[i];
            }
        }
        if (!empty)
            std::cout << "There are no suitable trains for your request!" << std::endl;
    }
    catch (std::string err) {
        std::cout << "[ERROR] " + err << std::endl;
    }
}

void Interface::print() {
    system("CLS");
    std::cout << "---------| List |---------" << std::endl << std::endl;
    try {
        if (!size)
            throw (std::string)"No trains to output";
        for (int i = 0; i < size; i++) {
            std::cout << data[i] << std::endl;
        }
    }
    catch (std::string err) {
        std::cout << "[ERROR] " + err << std::endl;
    }
}
