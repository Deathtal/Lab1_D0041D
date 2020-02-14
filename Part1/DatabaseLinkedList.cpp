#include "DatabaseLinkedList.h"
#include <iostream>

DatabaseLinkedList::DatabaseLinkedList() {

}

void DatabaseLinkedList::AddStudent(std::string name) {
	LinkedList::Student* student = new LinkedList::Student{ name };
	if (_size > 0) {
		student->Next = _head;
	}
	_head = student;
	_size++;
}

bool DatabaseLinkedList::AddCourse(const int& student_index, const char course_name[7], const float& credit, const char& grade) {
	if (student_index >= _size) {
		std::cout << "ERROR: Student index not found\n";
		return 0;
	}
	LinkedList::Student* currentStudent = _head;
	for (int i = 0; i < student_index; ++i) {
		currentStudent = currentStudent->Next;
	}
	LinkedList::Course* newCourse = new LinkedList::Course{ course_name[0], course_name[1], course_name[2], course_name[3], course_name[4], course_name[5], course_name[6], credit, grade };
	newCourse->Next = currentStudent->Courses;
	currentStudent->Courses = newCourse;
	return 1;
};


bool DatabaseLinkedList::GradeCourse(const int& student_index, const char course_name[7], const char& grade) {
	if (student_index >= _size) {
		std::cout << "ERROR: Student index not found\n";
		return 0;
	}
	LinkedList::Student* currentStudent = _head;
	for (int i = 0; i < student_index; ++i) {
		currentStudent = currentStudent->Next;
	}
	LinkedList::Course* currentCourse = currentStudent->Courses;
	while (currentCourse->Next) {
		currentCourse = currentCourse->Next;
		if (currentCourse->Name == course_name) {
			currentCourse->Grade = grade;
			return 1;
		}
	}
	return 0;
}

bool DatabaseLinkedList::DeleteStudent(const int& student_index) {
	if (student_index >= _size) {
		std::cout << "ERROR: Student index not found\n";
		return 0;
	}
	if (student_index == 0) {
		LinkedList::Student* nextStudent = _head->Next;
		delete _head;
		_head = nextStudent;
		_size--;
		return 1;
	}
	LinkedList::Student* currentStudent = _head;
	LinkedList::Student* delStudent = currentStudent->Next;
	for (int i = 1; i < student_index; ++i) {
		currentStudent = delStudent;
		delStudent = delStudent->Next;
	}
	if (delStudent->Next) {
		currentStudent->Next = delStudent->Next;
	}
	else {
		currentStudent->Next = nullptr;
	}
	delete delStudent;
	_size--;
	return 1;
}

bool DatabaseLinkedList::DeleteCourse(const int& student_index, const char course_name[7]) {
	if (student_index >= _size) {
		std::cout << "ERROR: Student index not found\n";
		return 0;
	}
	LinkedList::Student* currentStudent = _head;
	for (int i = 0; i < student_index; ++i) {
		currentStudent = currentStudent->Next;
	}
	if (!currentStudent->Courses) {
		return 0;
	}
	LinkedList::Course* previusCourse = currentStudent->Courses;
	LinkedList::Course* nextCourse = previusCourse->Next;
	if (previusCourse->Name == course_name) {
		previusCourse->Next = previusCourse->Next->Next;
		delete nextCourse;
		return 1;
	}
	while (nextCourse) {
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

bool DatabaseLinkedList::DisplayStudentCourses(const int& student_index) {
	if (student_index >= _size) {
		std::cout << "ERROR: Student index not found\n";
		return 0;
	}
	LinkedList::Student* currentStudent = _head;
	for (int i = 0; i < student_index; ++i) {
		currentStudent = currentStudent->Next;
	}
	std::cout << "Student " << currentStudent->Name << ":\n";
	LinkedList::Course* currentCourse = currentStudent->Courses;
	if (!currentCourse) {
		std::cout << "Courses: No active courses\n";
		return 0;
	}
	std::cout << "Courses:\n";
	while (currentCourse) {
		currentCourse = currentCourse->Next;
		std::cout << "\t" << currentCourse->Name << ": Grade: " << currentCourse->Grade << " Credit: " << currentCourse->Credit << "\n";
	}
	return 1;
}

void DatabaseLinkedList::DisplayStudents() {
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

const int DatabaseLinkedList::Size() const {
	return _size;
}