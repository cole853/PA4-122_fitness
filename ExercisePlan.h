/*
		Programmer: Cole Clark
		Date: 3/4/2021

			Description: application that allows users to edit their diet and exercise plans. Solution for PA 4
*/

#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::ios;
using std::fstream;
using std::ostream;

class ExercisePlan
{
public:

	//constructor
	ExercisePlan(const std::string newPlanName = "", const std::string newDate = "", const int newGoalSteps = 0);

	//copy constructor
	ExercisePlan(const ExercisePlan& copy);

	~ExercisePlan(); //destructor

	//getters
	int getGoalSteps();
	std::string getPlanName();
	std::string getDate();

	//setters
	void setGoalSteps(const int newGoalSteps);
	void setPlanName(const std::string newPlanName);
	void setDate(const std::string newDate);


private:

	int goalSteps;
	std::string planName;
	std::string date;
};

fstream & operator>> (fstream& input, ExercisePlan& rhs);

fstream& operator<< (fstream& output, ExercisePlan& rhs);

ostream& operator<< (ostream& output, ExercisePlan& rhs);