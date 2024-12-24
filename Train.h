#pragma once
#include <iostream>
#include <string>

class Train {
    std::string sEndPoint; // Названия пункта прибытия 
    std::string sTrainNum; // Номер поезда
    std::string sTimeStartHours; // Время отъезда 
    std::string sTimeStartMinutes; // Время отъезда
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
