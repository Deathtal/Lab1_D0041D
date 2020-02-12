#pragma once

#include <vector>
#include "Database.h"

struct Course {
	char Name[7];
	float Credit;
	char Grade;
};

struct Student {
	std::string Name;
	std::vector<Course> Courses;
};

class DatabaseArray : public Database {
private:
	std::vector<Student> _students;

public:
	DatabaseArray();
	void AddStudent(std::string name);
	bool AddCourse(const int& student_index, const char course_name[7], const float& credit, const char& grade);
	bool GradeCourse(const int& student_index, const char course_name[7], const char& grade);
	bool DeleteStudent(const int& student_index);
	bool DeleteCourse(const int& student_index, const char course_name[7]);
	bool DisplayStudentCourses(const int& student_index);
	void DisplayStudents();
	const int Size() const;
};