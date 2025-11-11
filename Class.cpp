#include "Class.hpp"
#include <iterator>


Class::Class(const std::string& name, const std::string& num, const std::vector<int>& secs, int max, int actual)
    : courseName(name), 
      courseNumber(num), 
      sections(secs), 
      maxAttendance(max), 
      actualEnrolled(actual) {
}

bool Class::operator<(const Class& other) const {
    return this->actualEnrolled < other.actualEnrolled;
}

Class Class::operator+(const Class& other) const {

    std::vector<int> mergedSections = this->sections;
    
    mergedSections.insert(mergedSections.end(), other.sections.begin(), other.sections.end());

    return Class(
        this->courseName,
        this->courseNumber,
        mergedSections,
        this->maxAttendance + other.maxAttendance,
        this->actualEnrolled + other.actualEnrolled
    );
}

// Ostream (<<) Operator Implementation
std::ostream& operator<<(std::ostream& os, const Class& c) {
    os << "Course: " << c.courseName << " (" << c.courseNumber << ")" << std::endl;
    os << "  Enrolled: " << c.actualEnrolled << " / " << c.maxAttendance << std::endl;
    
    os << "  Sections (CRNs): ";
    if (c.sections.empty()) {
        os << "None";
    } else {
        // Loop to print CRNs
        for (size_t i = 0; i < c.sections.size(); ++i) {
            os << c.sections[i];
            if (i < c.sections.size() - 1) {
                os << ", ";
            }
        }
    }

    os << std::endl;
    
    return os;
}