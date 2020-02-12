#pragma once

#include <string>

class Database {
public:
	virtual void AddStudent(std::string_view name) = 0;
	virtual bool AddCourse(unsigned int student_index, const char course_name[7]) = 0;
	virtual bool DeleteStudent(unsigned int student_index) = 0;
	virtual bool DeleteCourse(unsigned int student_index, std::string course) = 0;
	virtual bool DisplayStudentCourses(unsigned int student_index) = 0;
	virtual bool DisplayStudents() = 0;
};