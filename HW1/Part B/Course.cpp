#include "Course.h"

Course::Course( const int courseID, const string courseName) {
    this->courseID = courseID;
    this->courseName = courseName;
}

Course::~Course() {
}

void Course::operator=(const Course &right) {
    if (this != &right) {
        courseID = right.getCID();
        courseName = right.getCourseName();
    }
}

int Course::getCID() const {
    return courseID;
}

string Course::getCourseName() const {
    return courseName;
}