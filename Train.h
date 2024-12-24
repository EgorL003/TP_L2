#pragma once
#include <iostream>
#include <string>

class Train {
    std::string sEndPoint; // �������� ������ �������� 
    std::string sTrainNum; // ����� ������
    std::string sTimeStartHours; // ����� ������� 
    std::string sTimeStartMinutes; // ����� �������
public:
    Train();
    Train(const Train& obj);
    ~Train();

    // Setters
    void setEndPoint(std::string _sEndPoint);
    void setTrainNum(std::string _sTrainNum);
    void setTimeStartHours(std::string _sTimeStart);
    void setTimeStartMinutes(std::string _sTimeStart);

    // Getters
    std::string getEndPoint();
    std::string getTrainNum();
    std::string getTimeStartHours();
    std::string getTimeStartMinutes();

    // Methods
    friend std::ostream& operator<<(std::ostream& stream, Train& obj);
};
