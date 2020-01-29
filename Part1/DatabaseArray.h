#pragma once

#include <vector>
#include "Database.h"

struct Course {
	std::string ID;
	float Credit;
	char Grade;
};

struct Student {
	std::string Name;
	std::vector<Course> Courses;
};

class DatabaseArray : public Database {
private:
	std::vector<Student> _Students;

public:

};