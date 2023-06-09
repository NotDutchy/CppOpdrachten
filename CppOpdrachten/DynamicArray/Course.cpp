#include "Course.h"
#include <iostream>

using namespace std;

Course::Course(const std::string& courseName, int capacity) {
	numberOfStudents = 0;
	this->courseName = courseName;
	this->capacity = capacity;
	students = new std::string[capacity];
}

Course::Course(const Course& course) {
	numberOfStudents = course.getNumberOfStudents();
	this->courseName = course.courseName;
	this->capacity = course.capacity;
	//this->students = course.students;
	this->students = new std::string[this->capacity];
	for (int i = 0; i < this->capacity; i++) {
		this->students[i] = course.students[i];
	}
}

Course::~Course() {
	delete[] students;
}

std::string Course::getCourseName() const {
	return courseName;
}

void Course::addStudent(const std::string& name) {

	if (numberOfStudents >= capacity) {
		string* newStudents;
		int newCapacity = capacity + 1;
		newStudents = new string[newCapacity];
		for (int i = 0; i < capacity; i++)
		{
			newStudents[i] = students[i];
			cout << students[i] << " Has been placed into the new array " << newStudents[i] << endl;
		}
		delete[] students;

		students = newStudents;
		capacity = newCapacity;
	}
	students[numberOfStudents] = name;
	numberOfStudents++;
}

void Course::dropStudent(const std::string& name) {
	string* newStudents = new string[capacity];
	int newNumberOfStudents = 0;

	for (int i = 0; i < numberOfStudents; i++)
	{
		if (students[i] != name)
		{
			newStudents[newNumberOfStudents] = students[i];
			newNumberOfStudents++;
		}
	}
	delete[] students;

	numberOfStudents = newNumberOfStudents;
	students = newStudents;
}

std::string* Course::getStudents() const {
	return students;
}

int Course::getNumberOfStudents() const {
	return numberOfStudents;
}

void Course::clear()
{
	delete[] students;

	students = new string[capacity];
	numberOfStudents = 0;
}
