/*
		Programmer: Cole Clark
		Date: 3/4/2021

			Description: application that allows users to edit their diet and exercise plans. Solution for PA 4
*/

#include "DietPlan.h"

//constructor
DietPlan::DietPlan(const std::string newPlanName, const std::string newDate, const int newGoalCalories)
{
	planName = newPlanName;
	date = newDate;
	goalCalories = newGoalCalories;
}

//copy constructor
DietPlan::DietPlan(const DietPlan& copy)
{
	planName = copy.planName;
	date = copy.date;
	goalCalories = copy.goalCalories;
}

//destructor
DietPlan::~DietPlan()
{
	cout << "Inside DietPlan's destructor!" << endl;
}

//getters
int DietPlan::getGoalCalories()
{
	return goalCalories;
}

std::string DietPlan::getPlanName()
{
	return planName;
}

std::string DietPlan::getDate()
{
	return date;
}

//setters
void DietPlan::setGoalCalories(const int newGoalCalories)
{
	goalCalories = newGoalCalories;

}

void DietPlan::setPlanName(const std::string newPlanName)
{
	planName = newPlanName;
}

void DietPlan::setDate(const std::string newDate)
{
	date = newDate;
}

fstream& operator>> (fstream& input, DietPlan& rhs)
{
	char planName[100];
	char goal[100];
	char date[100];
	char dummy[100];

	input.getline(planName, 100);
	input.getline(goal, 100);
	input.getline(date, 100);
	input.getline(dummy, 100);

	int goalCalories = atoi(goal);

	//cout << planName << endl << goal << endl << date << endl;

	rhs.setPlanName(planName);
	rhs.setGoalCalories(goalCalories);
	rhs.setDate(date);

	

	return input;

}

fstream& operator<< (fstream& output, DietPlan& rhs)
{

	output << rhs.getPlanName() << endl;
	output << rhs.getGoalCalories() << endl;
	output << rhs.getDate() << endl << endl;

	return output;
}

ostream& operator<< (ostream& output, DietPlan& rhs)
{

	output << rhs.getPlanName() << endl;
	output << rhs.getGoalCalories() << endl;
	output << rhs.getDate() << endl << endl;

	return output;
}