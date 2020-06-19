#include <iostream>
#include <string>
using namespace std;

#include "Student.h"

class RegistrationSystem {
public:
    RegistrationSystem();
    ~RegistrationSystem();
    void operator=(const RegistrationSystem &right);
    void addStudent( const int studentId, const string firstName, const string lastName );
    int contains(const int studentId);
    void deleteStudent( const int studentId );

    //void addCourse( const int studentId, const int courseId, const string courseName );
    //void withdrawCourse( const int studentId, const int courseId );
    //void cancelCourse( const int courseId );

    void showStudent( const int studentId );
    //void showCourse( const int courseId );
    void showAllStudents();

private:
    unsigned int noOfStudents;
    unsigned int size;
    Student *students;
};
