#pragma once

#include <string>

struct Student;

class Database {
public:
	virtual void AddStudent(std::string name) = 0;
	virtual bool AddCourse(std::string name, std::string course) = 0;
	virtual bool DeleteStudent(std::string name) = 0;
	virtual bool DeleteCourse(std::string name, std::string course) = 0;
	virtual bool DisplayCourses(std::string name) = 0;
	virtual bool DisplayStudents(std::string course) = 0;
	virtual Student FindStudent(std::string name) = 0;
};