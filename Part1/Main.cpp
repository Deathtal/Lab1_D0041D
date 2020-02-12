#include <iostream>
#include "InstrumentationTimer.h"
#include "DatabaseArray.h"
#include <cstdlib>


int main() {
	DatabaseArray bar;
	{
		InstrumentationTimer time("AddStudent");
		for (int i = 0; i < 10000; ++i) {
			bar.AddStudent("someone");
		}
	}
	{
		InstrumentationTimer time("AddCourse");
		for (int i = 0; i < 10000; ++i) {
			bar.AddCourse(rand() % bar.Size(), "d00dle", 69, 'S');
		}
	}
	{
		InstrumentationTimer time("DeleteCourse");
		for (int i = 0; i < 10000; ++i) {
			bar.DeleteCourse(rand() % bar.Size(), "d00dle");
		}
	}
	{
		InstrumentationTimer time("DeleteStudent");
		for (int i = 0; i < 10000; ++i) {
			bar.DeleteStudent(rand() % bar.Size());
		}
	}
	bar.DisplayStudents();
}