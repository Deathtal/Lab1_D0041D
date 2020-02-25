#include <iostream>
#include "InstrumentationTimer.h"
#include "DatabaseArray.h"
#include "DatabaseLinkedList.h"
#include <cstdlib>

#define AMOUNT_OF_ACTIONS 100000 // Macro for changing the amount of times the method that are being benchmarked will be repeated

int main() {
	// Was originally going to have a function that calls methods of a database and times them
	std::cout << "LinkedList:\n";
	{
		srand(69); // Sets the seed of rand()
		DatabaseLinkedList foo;
		InstrumentationTimer timer("LinkedList total time"); // timer
		{
			InstrumentationTimer timer1("AddStudent");
			for (int i = 0; i < AMOUNT_OF_ACTIONS; ++i) {
				foo.AddStudent("someone"); // Adds a student to the database
			}
		}
		{
			InstrumentationTimer timer2("AddCourse");
			for (int i = 0; i < AMOUNT_OF_ACTIONS; ++i) {
				foo.AddCourse(rand() % foo.Size(), "d00dle", 69, 'S'); // Adds a course to a random student
			}
		}
		{
			InstrumentationTimer timer3("DeleteCourse");
			for (int i = 0; i < AMOUNT_OF_ACTIONS; ++i) {
				foo.DeleteCourse(rand() % foo.Size(), "d00dle"); // Deletes a course on a random student
			}
		}
		{
			InstrumentationTimer timer4("DeleteStudent");
			for (int i = 0; i < AMOUNT_OF_ACTIONS; ++i) {
				if (foo.Size() > 0) { // In case the size of the database is 0
					foo.DeleteStudent(rand() % foo.Size()); // Deletes a random student from the database
					continue;
				}
				break;
			}
		}
	}
	std::cout << "\n\nArray:\n";
	{
		srand(69);
		DatabaseArray bar;
		InstrumentationTimer timer("Array total time");
		{
			InstrumentationTimer timer1("AddStudent");
			for (int i = 0; i < AMOUNT_OF_ACTIONS; ++i) {
				bar.AddStudent("someone"); // Adds a student to the database
			}
		}
		{
			InstrumentationTimer timer2("AddCourse");
			for (int i = 0; i < AMOUNT_OF_ACTIONS; ++i) {
				bar.AddCourse(rand() % bar.Size(), "d00dle", 69, 'S'); // Adds a course to a random student
			}
		}
		{
			InstrumentationTimer timer3("DeleteCourse");
			for (int i = 0; i < AMOUNT_OF_ACTIONS; ++i) {
				bar.DeleteCourse(rand() % bar.Size(), "d00dle"); // Deletes a course on a random student
			}
		}
		{
			InstrumentationTimer timer4("DeleteStudent");
			for (int i = 0; i < AMOUNT_OF_ACTIONS; ++i) {
				if (bar.Size() > 0) { // In case the size of the database is 0
					bar.DeleteStudent(rand() % bar.Size()); // Deletes a random student from the database
					continue;
				}
				break;
			}
		}
	}
}