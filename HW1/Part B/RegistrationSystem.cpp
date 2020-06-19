#include "RegistrationSystem.h"
#include "Student.h"
using namespace std;

RegistrationSystem::RegistrationSystem() {
    noOfStudents = 0;
    students = NULL;
}

RegistrationSystem::~RegistrationSystem() {
    if (students)
        delete [] students;
}

void RegistrationSystem::operator=(const RegistrationSystem &right) {
    if (this == &right)
        return;
    if (students != NULL)
        delete [] students;
    noOfStudents = right.noOfStudents;
    students = new Student[noOfStudents];
    for(size_t i = 0; i < noOfStudents; i++)
        students[i] = right.students[i];
}

void RegistrationSystem::addStudent( const int studentId, const string firstName, const string lastName ) {
    int index = 0;
    for(int i = 0; i < noOfStudents; i++ )
    {
        if(students[i].getID() == studentId)
            index = -10;
    }
    if(index < 0)
        cout << "Student " << studentId << " already exists" << endl;
    else {
        Student newStudent(studentId, firstName, lastName);
        Student *temp = new Student[noOfStudents + 1];
        if(students == NULL)
            temp[0] = newStudent;
        else {
            int count = 0;
            for(int i = 0; i < noOfStudents; i++) {
                if(students[i].getID() < studentId) {
                    temp[count] = students[i];
                    count++;
                }
            }
            temp[count] = newStudent;
            count++;
            for(int i = count - 1; i < noOfStudents; i++)
            {
                temp[count] = students[i];
                count++;
            }
        }
        noOfStudents++;
        delete [] students;
        students = temp;
        temp = NULL;
        delete [] temp;
        cout << "Student " << studentId << " has been added" << endl;
    }
}

int RegistrationSystem::contains(const int studentId) {
    for(unsigned int i = 0; i < noOfStudents; i++)
        if(students[i].getID() == studentId) {
            return i;
    }
    return -1;
}

void RegistrationSystem::deleteStudent( const int studentId ) {
    int res = contains(studentId);
    if (res >= 0) {
        for(size_t i = res; i < noOfStudents - 1; i++) {
            students[i] = students[i + 1];
        }
        noOfStudents--;
        Student *temp = new Student[noOfStudents];
        for(size_t i = 0; i < noOfStudents; i++) {
            temp[i] = students[i];
        }
        delete [] students;
        students = temp;
        temp = NULL;
        delete temp;
        cout << "Student " << studentId << " has been deleted" << endl;
    }
    else
        cout << "Student " << studentId << " does not exist" << endl;
}

void RegistrationSystem::showStudent(const int studentID)
{
    int count = -1;
    for(int i = 0; i < noOfStudents; i++) {
        if(students[i].getID() == studentID)
            count = i;
    }
    if(count == -1)
        cout << "Student " << studentID << " does not exist" << endl;
    else {
        cout << "Student id \tFirst Name \tLast Name" << endl;
        students[count].showTabbedRepresentation();
        if(students[count].getNoOfCourses() != 0) {
            cout << " \tCourse id \tCourse Name" << endl;
            for(int i = 0; i < students[count].getNoOfCourses(); i++)
                cout << "\t"<< students[count].getCourses()[i].getCID()
                << "\t\t" << students[count].getCourses()[i].getCourseName() << endl;
        }
    }
}

void RegistrationSystem::showAllStudents() {
    if (students == NULL)
        cout << "There are no students in the system" << endl;
    else {
        cout << "Student id \tFirst Name \tLast Name" << endl;
        for (int i = 0; i < noOfStudents; i++) {
            students[i].showTabbedRepresentation();
            if(students[i].getNoOfCourses() != 0) {
                cout << "\tCourse id\tCourse Name" << endl;
                for(int j = 0; j < students[i].getNoOfCourses(); j++)
                    cout << "\t"<< students[i].getCourses()[j].getCID()
                    << "\t\t" << students[i].getCourses()[j].getCourseName() << endl;
            }
        }
    }
}

void RegistrationSystem::addCourse( const int studentId, const int courseId, const string courseName ) {
    int count = -1;
    for (int i = 0; i < noOfStudents; i++) {
        if(students[i].getID() == studentId)
            count = i;
    }
    if (count == -1)
        cout << "Student does not exist" << endl;
    else
        students[count].addCourse(courseId, courseName);
}

void RegistrationSystem::withdrawCourse( const int studentId, const int courseId ) {
    int count = -1;
    for (int i = 0; i < noOfStudents; i++) {
        if(students[i].getID() == studentId)
            count = i;
    }
    if (count == -1)
        cout << "Student " << studentId << " does not exist" << endl;
    else {
        students[count].withdrawCourse(courseId);
    }
}

void RegistrationSystem::cancelCourse( const int courseId ) {
    bool course = false;
    for (int i = 0; i < noOfStudents; i++) {
        course = students[i].cancelCourse(courseId);
    }
    if (course)
        cout << "Course " << courseId << " has been canceled" << endl;
    else
        cout << "Course " << courseId << " does not exist" << endl;
}

void RegistrationSystem::showCourse( const int courseId ) {
    bool course = false;
    int check = -1;
    for(int i = 0; i < noOfStudents; i++) {
        for(int j = 0; j < students[i].getNoOfCourses(); j++) {
            if((students[i].getCourses()[j].getCID() == courseId) && check == -1) {
                cout << "Course id \tCourse Name" << endl;
                cout << courseId << "\t" << students[i].getCourses()[j].getCourseName() << endl;
                cout << "\tStudent id \tFirst name \tLast name" << endl;
                cout << "\t";
                students[i].showTabbedRepresentation();
                course = true;
                check = 0;
            }
            else if (students[i].getCourses()[j].getCID() == courseId) {
                cout << "\t";
                students[i].showTabbedRepresentation();
            }
        }
    }
    if (!course)
        cout << "Course " << courseId << " does not exist" << endl;
}