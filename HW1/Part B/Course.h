#ifndef COURSE_H
#define COURSE_H
using namespace std;
#include <string>

class Course
{
public:
    Course( const int courseID = 0, const string courseName = "");
    ~Course();
    void operator=(const Course &right);

    int getCID() const;
    string getCourseName() const;

private:
    int courseID;
    string courseName;
};

#endif