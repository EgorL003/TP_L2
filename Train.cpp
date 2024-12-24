#include "Train.h"

std::ostream& operator<<(std::ostream& stream, Train& obj) {
    stream << "----------| Train |-----------" << std::endl
        << "Destination: " << obj.getEndPoint() << std::endl
        << "Number: " << obj.getTrainNum() << std::endl
        << "Departure time: " << obj.getTimeStartHours() << ":" << obj.getTimeStartMinutes() << std::endl;
    return stream;
}

Train::Train() {
    sEndPoint = "";
    sTrainNum = "";
    sTimeStartHours = "";
    sTimeStartMinutes = "";
}

Train::Train(const Train& obj) {
    sEndPoint = obj.sEndPoint;
    sTrainNum = obj.sTrainNum;
    sTimeStartHours = obj.sTimeStartHours;
    sTimeStartMinutes = obj.sTimeStartMinutes;
}

Train::~Train() {
}

void Train::setEndPoint(std::string _sEndPoint) {
    sEndPoint = _sEndPoint;
}

void Train::setTrainNum(std::string _sTrainNum) {
    sTrainNum = _sTrainNum;
}

void Train::setTimeStartHours(std::string _sTimeStart) {
    sTimeStartHours = _sTimeStart;
}

void Train::setTimeStartMinutes(std::string _sTimeStart) {
    sTimeStartMinutes = _sTimeStart;
}

std::string Train::getEndPoint() {
    return sEndPoint;
}

std::string Train::getTrainNum() {
    return sTrainNum;
}

std::string Train::getTimeStartHours() {
    return sTimeStartHours;
}

std::string Train::getTimeStartMinutes() {
    return sTimeStartMinutes;
}
