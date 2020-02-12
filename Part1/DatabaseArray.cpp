#include "DatabaseArray.h"
#include <iostream>

DatabaseArray::DatabaseArray() {

}

void DatabaseArray::AddStudent(std::string name) {
	Student student{name};
	_students.push_back(student);
}

bool DatabaseArray::AddCourse(const int& student_index, const char course_name[7], const float& credit, const char& grade) {
	if (student_index >= _students.size()) {
		return 0;
	}
	Course course{ course_name[0], credit, grade };
	for (int i = 1; i < 7; ++i) {
		course.Name[i] = course_name[i];
	}
	_students[student_index].Courses.push_back(course);
	return 1;
};


bool DatabaseArray::GradeCourse(const int& student_index, const char course_name[7], const char& grade) {
	if (student_index >= _students.size()) {
		return 0;
	}
	Student& student = _students[student_index];
	for (int i = 0; i < student.Courses.size(); ++i) {
		if (student.Courses[i].Name == course_name) {
			student.Courses[i].Grade = grade;
			return 1;
		}
	}
	return 0;
}

bool DatabaseArray::DeleteStudent(const int& student_index) {
	if (student_index >= _students.size()) {
		return 0;
	}
	_students.erase(_students.begin() + student_index);
	return 1;
}

bool DatabaseArray::DeleteCourse(const int& student_index, const char course_name[7]) {
	if (student_index >= _students.size()) {
		return 0;
	}
	Student& student = _students[student_index];
	for (int i = 0; i < student.Courses.size(); ++i) {
		if (student.Courses[i].Name == course_name) {
			student.Courses.erase(student.Courses.begin() + i);
			return 1;
		}
	}
	return 0;
}

bool DatabaseArray::DisplayStudentCourses(const int& student_index) {
	if (student_index >= _students.size()) {
		return 0;
	}
	Student& student = _students[student_index];
	std::cout << "Student: " << student.Name << "\nCourses:\n";
	for (int i = 0; i < student.Courses.size(); ++i) {
		std::cout << "\t" << student.Courses[i].Name << ": Grade:" << student.Courses[i].Grade << " Credit: " << student.Courses[i].Credit << "\n";
	}
	std::cout << "\n";
	return 1;
}

void DatabaseArray::DisplayStudents() {
	for (int i = 0; i < _students.size(); ++i) {
		std::cout << i << ". " << _students[i].Name << "\n";
	}
}

const int DatabaseArray::Size() const {
	return _students.size();
}