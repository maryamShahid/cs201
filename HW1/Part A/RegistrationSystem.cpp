#include "RegistrationSystem.h"
#include "Student.h"
using namespace std;

RegistrationSystem::RegistrationSystem() {
    noOfStudents = 0;
    size = 0;
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

    size = right.size;
    noOfStudents = size;
    students = new Student[size];
    for(size_t i = 0; i < size; i++)
        students[i] = right.students[i];
}

void RegistrationSystem::addStudent( const int studentId, const string firstName, const string lastName )
{
    int index = 0;
    for(int i = 0; i < noOfStudents; i++ )
    {
        if(students[i].getID() == studentId)
            index = -10;
    }
    if(index < 0)
        cout << "Student " << studentId << " already exists" << endl;
    else
    {
        Student newStudent(studentId, firstName, lastName);
        Student *temp = new Student[noOfStudents + 1];
        if(students == NULL)
            temp[0] = newStudent;
        else
        {
            int count = 0;
            for(int i = 0; i < noOfStudents; i++)
            {
                if(students[i].getID() < studentId)
                {
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
        size++;
        noOfStudents = size;
        delete [] students;
        students = temp;
        temp = NULL;
        delete [] temp;
        cout << "Student " << studentId << " has been added" << endl;
    }
}

int RegistrationSystem::contains(const int studentId) {
    for(unsigned int i = 0; i < size; i++)
        if(students[i].getID() == studentId) {
            return i;
    }
    return -1;
}

void RegistrationSystem::deleteStudent( const int studentId ) {
    int res = contains(studentId);
    if (res >= 0) {
        for(size_t i = res; i < size - 1; i++) {
            students[i] = students[i + 1];
        }
        size--;
        noOfStudents = size;
        Student *temp = new Student[size];
        for(size_t i = 0; i < size; i++) {
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
    for(int i = 0; i < noOfStudents; i++)
    {
        if(students[i].getID() == studentID)
            count = i;
    }
    if(count == -1)
        cout << "Student " << studentID << " does not exist" << endl;
    else
    {
        cout << "Student id \tFirst Name \tLast Name" << endl;
        students[count].showTabbedRepresentation();
    }
}

void RegistrationSystem::showAllStudents()
{
    if(students == NULL)
        cout << "There are no students in the system" << endl;
    else
    {
        cout << "Student id \tFirst Name \tLast Name" << endl;
        for(int i = 0; i < noOfStudents; i++)
        {
            students[i].showTabbedRepresentation();
        }
    }
}