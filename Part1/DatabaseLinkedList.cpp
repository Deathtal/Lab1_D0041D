#include "DatabaseLinkedList.h"
#include <iostream>

DatabaseLinkedList::DatabaseLinkedList() {}

void DatabaseLinkedList::AddStudent(std::string name) { // Creates a new student and makes them the new _head, adds old _head as that student's Next
	LinkedList::Student* student = new LinkedList::Student{ name };
	if (_size > 0) {
		student->Next = _head;
	}
	_head = student;
	_size++;
}

bool DatabaseLinkedList::AddCourse(const int& student_index, const char course_name[7], const float& credit, const char& grade) { // Adds a course to a student
	if (student_index >= _size) {
		std::cout << "ERROR: Student index not found\n";
		return 0;
	}
	LinkedList::Student* currentStudent = _head;
	for (int i = 0; i < student_index; ++i) { // Find student by index
		currentStudent = currentStudent->Next;
	}
	LinkedList::Course* newCourse = new LinkedList::Course{ course_name[0], course_name[1], course_name[2], course_name[3], course_name[4], course_name[5], course_name[6], credit, grade };
	newCourse->Next = currentStudent->Courses;
	currentStudent->Courses = newCourse;
	return 1;
};


bool DatabaseLinkedList::GradeCourse(const int& student_index, const char course_name[7], const char& grade) { // Modify the grade of a course of a student
	if (student_index >= _size) {
		std::cout << "ERROR: Student index not found\n";
		return 0;
	}
	LinkedList::Student* currentStudent = _head;
	for (int i = 0; i < student_index; ++i) { // Find student by index
		currentStudent = currentStudent->Next;
	}
	LinkedList::Course* currentCourse = currentStudent->Courses;
	while (currentCourse->Next) { // Repeat while not at the end of the list
		currentCourse = currentCourse->Next;
		if (currentCourse->Name == course_name) { // Modify the grade if it has the correct name
			currentCourse->Grade = grade;
			return 1;
		}
	}
	return 0;
}

bool DatabaseLinkedList::DeleteStudent(const int& student_index) { // Delete a student from the 
	if (student_index >= _size) {
		std::cout << "ERROR: Student index not found\n";
		return 0;
	}
	if (student_index == 0) { // In case of _head
		LinkedList::Student* nextStudent = _head->Next;
		delete _head;
		_head = nextStudent;
		_size--;
		return 1;
	}
	LinkedList::Student* currentStudent = _head;
	LinkedList::Student* delStudent = currentStudent->Next;
	for (int i = 1; i < student_index; ++i) { // Find student by index
		currentStudent = delStudent;
		delStudent = delStudent->Next;
	}
	if (delStudent->Next) { // If the student to be deleted is not at the end of the list
		currentStudent->Next = delStudent->Next;
	}
	else { // If the student to be deleted is at the end of the list
		currentStudent->Next = nullptr;
	}
	delete delStudent;
	_size--;
	return 1;
}

bool DatabaseLinkedList::DeleteCourse(const int& student_index, const char course_name[7]) { // Delete a course of a student
	if (student_index >= _size) {
		std::cout << "ERROR: Student index not found\n";
		return 0;
	}
	LinkedList::Student* currentStudent = _head;
	for (int i = 0; i < student_index; ++i) { // Find student by index
		currentStudent = currentStudent->Next;
	}
	if (!currentStudent->Courses) { // If the student does not have any courses
		return 0;
	}
	LinkedList::Course* previusCourse = currentStudent->Courses;
	LinkedList::Course* nextCourse = previusCourse->Next;
	if (previusCourse->Name == course_name) {
		previusCourse->Next = previusCourse->Next->Next;
		delete nextCourse;
		return 1;
	}
	while (nextCourse) { // Repeat until end of list
		previusCourse = nextCourse;
		nextCourse = nextCourse->Next;
		if (nextCourse->Name == course_name) {
			previusCourse->Next = nextCourse->Next;
			delete nextCourse;
			return 1;
		}
	}
	return 0;
}

bool DatabaseLinkedList::DisplayStudentCourses(const int& student_index) { // Display the courses of a student
	if (student_index >= _size) {
		std::cout << "ERROR: Student index not found\n";
		return 0;
	}
	LinkedList::Student* currentStudent = _head;
	for (int i = 0; i < student_index; ++i) { // Find student by index
		currentStudent = currentStudent->Next;
	}
	std::cout << "Student " << currentStudent->Name << ":\n";
	LinkedList::Course* currentCourse = currentStudent->Courses;
	if (!currentCourse) { // In case of the student not having any courses
		std::cout << "Courses: No active courses\n";
		return 0;
	}
	std::cout << "Courses:\n";
	while (currentCourse) { // Go through and print all the courses and thier credit and grade
		currentCourse = currentCourse->Next;
		std::cout << "\t" << currentCourse->Name << ": Grade: " << currentCourse->Grade << " Credit: " << currentCourse->Credit << "\n";
	}
	return 1;
}

void DatabaseLinkedList::DisplayStudents() { // Displays the name and index of all the students in the database
	if (_size < 1) {
		std::cout << "No students in database\n";
		return;
	}
	LinkedList::Student* currentStudent = _head;
	for (int i = 0; i < _size; ++i) {
		std::cout << i << ". " << currentStudent->Name << "\n";
		currentStudent = currentStudent->Next;
	}
}

const int DatabaseLinkedList::Size() const { // Returns the size of the database
	return _size;
}