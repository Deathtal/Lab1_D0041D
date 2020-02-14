#pragma once

#include "Database.h"

namespace LinkedList {
	struct Course {
		char Name[7];
		float Credit;
		char Grade;
		Course* Next = nullptr;
	};

	struct Student {
		std::string Name;
		Student* Next;
		Course* Courses = nullptr; // Points at the head of the Course list
	};
}

class DatabaseLinkedList : public Database {
private:
	LinkedList::Student* _head = nullptr;
	int _size = 0;

public:
	DatabaseLinkedList();
	void AddStudent(std::string name);
	bool AddCourse(const int& student_index, const char course_name[7], const float& credit, const char& grade);
	bool GradeCourse(const int& student_index, const char course_name[7], const char& grade);
	bool DeleteStudent(const int& student_index);
	bool DeleteCourse(const int& student_index, const char course_name[7]);
	bool DisplayStudentCourses(const int& student_index);
	void DisplayStudents();
	const int Size() const;
};