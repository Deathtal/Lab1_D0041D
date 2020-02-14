#include <iostream>
#include "InstrumentationTimer.h"
#include "DatabaseArray.h"
#include "DatabaseLinkedList.h"
#include <cstdlib>


int main() {
	std::cout << "LinkedList:\n";
	{
		DatabaseLinkedList foo;
		InstrumentationTimer time("LinkedList total time");
		{
			InstrumentationTimer time("AddStudent");
			for (int i = 0; i < 100000; ++i) {
				foo.AddStudent("someone");
			}
		}
		{
			InstrumentationTimer time("AddCourse");
			for (int i = 0; i < 100000; ++i) {
				foo.AddCourse(rand() % foo.Size(), "d00dle", 69, 'S');
			}
		}
		{
			InstrumentationTimer time("DeleteCourse");
			for (int i = 0; i < 100000; ++i) {
				foo.DeleteCourse(rand() % foo.Size(), "d00dle");
			}
		}
		{
			InstrumentationTimer time("DeleteStudent");
			for (int i = 0; i < 100000; ++i) {
				if (foo.Size() > 0) {
					foo.DeleteStudent(rand() % foo.Size());
					continue;
				}
				break;
			}
		}
	}
	std::cout << "\n\nArray:\n";
	{
		DatabaseArray bar;
		InstrumentationTimer time("Array total time");
		{
			InstrumentationTimer time("AddStudent");
			for (int i = 0; i < 100000; ++i) {
				bar.AddStudent("someone");
			}
		}
		{
			InstrumentationTimer time("AddCourse");
			for (int i = 0; i < 100000; ++i) {
				bar.AddCourse(rand() % bar.Size(), "d00dle", 69, 'S');
			}
		}
		{
			InstrumentationTimer time("DeleteCourse");
			for (int i = 0; i < 100000; ++i) {
				bar.DeleteCourse(rand() % bar.Size(), "d00dle");
			}
		}
		{
			InstrumentationTimer time("DeleteStudent");
			for (int i = 0; i < 100000; ++i) {
				if (bar.Size() > 0) {
					bar.DeleteStudent(rand() % bar.Size());
					continue;
				}
				break;
			}
		}
	}
}