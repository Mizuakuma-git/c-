// Learning C++ 
// Challenge 04_05
// Calculate a GPA, by Eduardo Corpeño 

#include <iostream>
#include <vector>
#include "records.h"

int main(){
    float GPA = 0.0f;
    int id;
    int total_credits = 0;
    
    std::vector<Student> students = {Student(1, "George P. Burdell"),
                                    Student(2, "Nancy Rhodes")};

    std::vector<Course> courses = {Course(1, "Algebra", 5),
                                Course(2, "Physics", 4),
                                Course(3, "English", 3),
                                Course(4, "Economics", 4)};

    std::vector<Grade> grades = {Grade(1, 1, 'B'), Grade(1, 2, 'A'), Grade(1, 3, 'C'),
                                Grade(2, 1, 'A'), Grade(2, 2, 'A'), Grade(2, 4, 'B')};

    std::cout << "Enter a student ID: " << std::flush;
    std::cin >> id;

    // Calculate the GPA for the selected student.
    // Write your code here
    for (Grade& grade : grades){
        if (grade.get_student_id() == id){
            int credit = 0;
            for (auto course : courses){
                if (grade.get_course_id() == course.get_id())
                    credit = course.get_credits();
            };
            total_credits += credit;
            switch (grade.get_grade()){
                case 'A':
                    GPA += 4*credit;
                    break;
                case 'B':
                    GPA += 3*credit;
                    break;
                case 'C':
                    GPA += 2*credit;
                    break;
                case 'D':
                    GPA += 1*credit;
                    break;
                default:
                    GPA += 0*credit;
                    break;
            };
        };
    };

    GPA /= total_credits;

    std::string student_str;
    student_str = students[id-1].get_name(); // Change this to the selected student's name

    std::cout << "The GPA for " << student_str << " is " << GPA << std::endl;
    
    std::cout << std::endl << std::endl;
    return (0);
}
