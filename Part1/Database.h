#pragma once

#include <string>

// Superclass for DatabaseArray and DatabaseLinkedList
class Database {
public:
	virtual void AddStudent(std::string name) = 0;
	virtual bool AddCourse(const int& student_index, const char course_name[7], const float& credit, const char& grade) = 0;
	virtual bool GradeCourse(const int& student_index, const char course_name[7], const char& grade) = 0;
	virtual bool DeleteStudent(const int& student_index) = 0;
	virtual bool DeleteCourse(const int& student_index, const char course_name[7]) = 0;
	virtual bool DisplayStudentCourses(const int& student_index) = 0;
	virtual void DisplayStudents() = 0;
	virtual const int Size() const = 0;
};