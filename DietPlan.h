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
using std::ostream;
using std::fstream;

class DietPlan
{
public:

	//constructor
	DietPlan(const std::string newPlanName = "", const std::string newDate = "", const int newGoalCalories = 0);

	//copy constructor
	DietPlan(const DietPlan& copy);

	~DietPlan(); //destructor

	//getters
	int getGoalCalories();
	std::string getPlanName();
	std::string getDate();

	//setters
	void setGoalCalories(const int newGoalCalories);
	void setPlanName(const std::string newPlanName);
	void setDate(const std::string newDate);




private:

	int goalCalories;
	std::string planName;
	std::string date;
};


fstream& operator>> (fstream& input, DietPlan& rhs);

fstream& operator<< (fstream& output, DietPlan& rhs);

ostream& operator<< (ostream& output, DietPlan& rhs);