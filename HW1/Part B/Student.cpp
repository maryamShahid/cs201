#include <iostream>
#include <string>
using namespace std;
#include "Student.h"
#include "Course.h"

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

void Student::operator=(const Student &right) {
    if( this != &right) {
        if( noOfCourses != right.getNoOfCourses()) {
            if( noOfCourses > 0)
                delete [] courses;
            noOfCourses = right.getNoOfCourses();
            if( noOfCourses > 0)
                courses = new Course[noOfCourses];
            else
                courses = NULL;
        }
        for (int i = 0; i < noOfCourses; i++)
            courses[i] = right.getCourses()[i];
        id = right.getID();
        firstName = right.getFirstName();
        lastName = right.getLastName();
    }
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

void Student::showTabbedRepresentation() {
    cout << this->id << "\t\t" << this->firstName << "\t\t" << this->lastName << endl;
}

int Student::getNoOfCourses() const{
    return noOfCourses;
}

Course* Student::getCourses() const {
    return courses;
}
void Student::addCourse(const int courseId, const string courseName)
{
    int index = -1;
    for (int i = 0; i < noOfCourses; i++)
    {
        if(courses[i].getCID() == courseId)
            index = i;
    }
    if(index != -1)
        cout << "Student " << id << " is already enrolled in course " << courseId << endl;
    else
    {
        Course *tempCourses = new Course[noOfCourses + 1];
        Course newCourse(courseId, courseName);
        for(int i = 0; i < noOfCourses; i++)
        {
            tempCourses[i] = courses[i];
        }
        tempCourses[noOfCourses] = newCourse;
        delete [] courses;
        courses = tempCourses;
        tempCourses = NULL;
        delete [] tempCourses;
        noOfCourses++;
        cout << "Course " << courseId << " has been added to Student " << id << endl;
    }
}

void Student::withdrawCourse(const int courseId) {
    int count = -1;
    for (int i = 0; i < noOfCourses; i++) {
        if(courses[i].getCID() == courseId)
            count = i;
    }
    if(count == -1)
        cout << "Student " << id << " is not enrolled in course " << courseId << endl;
    else {
        Course *tempCourses = new Course[noOfCourses - 1];
        int check = 0;
        for (int i = 0; i < noOfCourses - 1; i++)
        {
            if (count == check)
                check++;
            tempCourses[i] = courses[check];
            check++;
        }
        noOfCourses--;
        cout << "Student " << id << " has been withdrawn from course " << courseId << endl;
        delete [] courses;
        courses = tempCourses;
        tempCourses = NULL;
        delete [] tempCourses;
    }
}

bool Student::cancelCourse(const int courseId)
{
    int count = -1;
    for (int i = 0; i < noOfCourses; i++) {
        if(courses[i].getCID() == courseId)
            count = i;
    }
    if (count == -1)
        return false;
    else {
        Course *temp = new Course[noOfCourses - 1];
        int x = 0;
        for(int i = 0; i < noOfCourses - 1; i++)
        {
            if (count == x)
                x++;
            temp[i] = courses[x];
            x++;
        }
        noOfCourses--;
        delete [] courses;
        courses = temp;
        temp = NULL;
        delete [] temp;
        return true;
    }
}