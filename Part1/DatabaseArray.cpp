#include "DatabaseArray.h"
#include <iostream>

DatabaseArray::DatabaseArray() {}

void DatabaseArray::AddStudent(std::string name) { // Adds student to the database
	Array::Student student{ name };
	_students.push_back(student);
}

bool DatabaseArray::AddCourse(const int& student_index, const char course_name[7], const float& credit, const char& grade) { // Adds a course to a student
	if (student_index >= _students.size()) {
		std::cout << "ERROR: Student index not found\n";
		return 0;
	}
	Array::Course course{ course_name[0], credit, grade };
	for (int i = 1; i < 7; ++i) {
		course.Name[i] = course_name[i];
	}
	_students[student_index].Courses.push_back(course);
	return 1;
};


bool DatabaseArray::GradeCourse(const int& student_index, const char course_name[7], const char& grade) { // Modifies the grade of a course of a student
	if (student_index >= _students.size()) {
		std::cout << "ERROR: Student index not found\n";
		return 0;
	}
	Array::Student& student = _students[student_index];
	for (int i = 0; i < student.Courses.size(); ++i) {
		if (student.Courses[i].Name == course_name) {
			student.Courses[i].Grade = grade;
			return 1;
		}
	}
	return 0;
}

bool DatabaseArray::DeleteStudent(const int& student_index) { // Deletes a student from the database
	if (student_index >= _students.size()) {
		std::cout << "ERROR: Student index not found\n";
		return 0;
	}
	_students.erase(_students.begin() + student_index);
	return 1;
}

bool DatabaseArray::DeleteCourse(const int& student_index, const char course_name[7]) { // Deletes a course of a student
	if (student_index >= _students.size()) {
		std::cout << "ERROR: Student index not found\n";
		return 0;
	}
	Array::Student& student = _students[student_index];
	for (int i = 0; i < student.Courses.size(); ++i) {
		if (student.Courses[i].Name == course_name) {
			student.Courses.erase(student.Courses.begin() + i);
			return 1;
		}
	}
	return 0;
}

bool DatabaseArray::DisplayStudentCourses(const int& student_index) { // Display all courses of a student aswell as thier grade and credit
	if (student_index >= _students.size()) {
		std::cout << "ERROR: Student index not found\n";
		return 0;
	}
	Array::Student& student = _students[student_index];
	std::cout << "Student: " << student.Name << "\nCourses:\n";
	for (int i = 0; i < student.Courses.size(); ++i) {
		std::cout << "\t" << student.Courses[i].Name << ": Grade:" << student.Courses[i].Grade << " Credit: " << student.Courses[i].Credit << "\n";
	}
	std::cout << "\n";
	return 1;
}

void DatabaseArray::DisplayStudents() { // Displays the name and index of all the students in the database
	for (int i = 0; i < _students.size(); ++i) {
		std::cout << i << ". " << _students[i].Name << "\n";
	}
}

const int DatabaseArray::Size() const { // Returns the size of the vector
	return _students.size();
}