#ifndef STUDENT_H_
#define STUDENT_H_
#include <iostream>
using namespace std;

struct Course
{
    int courseId;
    string courseName;
    Course* next;
};

class Student {
public:
    Student(const int iD = 0, const string firstName = "", const string lastName = "");
    Student(const Student &sToCopy);
    ~Student();

    int getID() const;
    string getFirstName() const;
    string getLastName() const;

    Course* getCourse( const int courseId);
    void operator=(const Student &right);
    void showTabbedRepresentation();

private:
    string firstName;
    string lastName;
    int id;

    Course * courses;
    int noOfCourses;
    int size;
};

#endif