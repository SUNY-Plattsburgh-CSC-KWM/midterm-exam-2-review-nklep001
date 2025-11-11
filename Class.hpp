#ifndef CLASS_HPP
#define CLASS_HPP

#include <iostream>
#include <string>
#include <vector>

class Class {
private:
    std::string courseName;
    std::string courseNumber;
    std::vector<int> sections; // Vector of CRNs
    int maxAttendance;
    int actualEnrolled;

public:
    Class(const std::string& name, const std::string& num, const std::vector<int>& secs, int max, int actual);

    bool operator<(const Class& other) const;

    Class operator+(const Class& other) const;


    friend std::ostream& operator<<(std::ostream& os, const Class& c);
};

#endif // CLASS_HPP