#include <iostream>
#include <string>
using namespace std;
#include "Student.h"

Student::Student(const int id, const string firstName, const string lastName)
{
    this->id = id;
    this->firstName = firstName;
    this->lastName = lastName;

    courses = NULL;
    noOfCourses = 0;
    size = 0;
}

Student::Student(const Student &sToCopy) {
    if(courses != NULL)
        delete [] courses;

    id = sToCopy.id;
    firstName = sToCopy.firstName;
    lastName = sToCopy.lastName;

    size = sToCopy.size;
    noOfCourses = sToCopy.noOfCourses;
    courses = new Course[size];

    for(size_t i = 0; i < size; i++) {
        courses[i] = sToCopy.courses[i];
    }
}

Student::~Student() {
    if ( courses != NULL)
        delete [] courses;
}

int Student::getID() const {
    return id;
}

string Student::getFirstName() const {
    return firstName;
}

string Student::getLastName() const {
    return lastName;
}

Course* Student::getCourse(const int courseId) {
    for(size_t i = 0; i < size; i++) {
        Course* c = new Course;
        if (courses[i].courseId == courseId) {
            c = &courses[i];
        }
        return c;
    }
    return NULL;
}

void Student::operator=(const Student &right) {
    if(this != &right) { // To avoid self copying
        firstName = right.firstName;
        lastName = right.lastName;
        id = right.id;

        noOfCourses = right.noOfCourses;
        size = right.size;

        if (courses != NULL) { delete [] courses; }

        courses = new Course[size];
        for (size_t i = 0; i < noOfCourses; i++) {
            courses[i] = right.courses[i];
        }
    }
}

void Student::showTabbedRepresentation()
{
    cout << this->id << "\t\t" << this->firstName << "\t\t" << this->lastName << endl;
}
