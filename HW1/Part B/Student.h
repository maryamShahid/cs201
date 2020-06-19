#ifndef STUDENT_H_
#define STUDENT_H_
#include <iostream>
#include "Course.h"
using namespace std;

class Student {
public:
    Student(const int iD = 0, const string firstName = "", const string lastName = "");
    Student(const Student &sToCopy);
    ~Student();
    int getID() const;
    string getFirstName() const;
    string getLastName() const;
    void operator=(const Student &right);
    void showTabbedRepresentation();
    Course* getCourses() const;
    void addCourse(const int courseId, const string courseName);
    void withdrawCourse(const int courseId);
    bool cancelCourse(const int courseId);
    int getNoOfCourses() const;

private:
    int id;
    string firstName;
    string lastName;

    Course * courses;
    int noOfCourses;
    int size;
};

#endif