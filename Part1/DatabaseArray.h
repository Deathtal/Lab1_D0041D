#pragma once

#include <vector>
#include "Database.h"

namespace Array {
	struct Course {
		char Name[7];
		float Credit;
		char Grade;
	};

	struct Student {
		std::string Name;
		std::vector<Course> Courses; // Vector of the students courses
	};
}

class DatabaseArray : public Database {
private:
	std::vector<Array::Student> _students; // Vector of the students in the database

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