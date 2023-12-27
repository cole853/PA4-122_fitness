/*
		Programmer: Cole Clark
		Date: 3/4/2021

			Description: application that allows users to edit their diet and exercise plans. Solution for PA 4
*/

#include "ExercisePlan.h"

//constructor
ExercisePlan::ExercisePlan(const std::string newPlanName, const std::string newDate, const int newGoalSteps)
{
	planName = newPlanName;
	date = newDate;
	goalSteps = newGoalSteps;
}

//copy constructor
ExercisePlan::ExercisePlan(const ExercisePlan& copy)
{
	planName = copy.planName;
	date = copy.date;
	goalSteps = copy.goalSteps;
}

//destructor
ExercisePlan::~ExercisePlan()
{
	cout << "Inside ExercisePlan's destructor!" << endl;
}

//getters
int ExercisePlan::getGoalSteps()
{
	return goalSteps;
}

std::string ExercisePlan::getPlanName()
{
	return planName;
}

std::string ExercisePlan::getDate()
{
	return date;
}

//setters
void ExercisePlan::setGoalSteps(const int newGoalSteps)
{
	goalSteps = newGoalSteps;
}

void ExercisePlan::setPlanName(const std::string newPlanName)
{
	planName = newPlanName;
}

void ExercisePlan::setDate(const std::string newDate)
{
	date = newDate;
}

fstream & operator>> (fstream &input, ExercisePlan &rhs)
{
	char planName[100];
	char goal[100];
	char date[100];
	char dummy[100];

	input.getline(planName, 100);
	input.getline(goal, 100);
	input.getline(date, 100);
	input.getline(dummy, 100);

	int goalSteps = atoi(goal);

	//cout << planName << endl << goal << endl << date << endl;

	rhs.setPlanName(planName);
	rhs.setGoalSteps(goalSteps);
	rhs.setDate(date);



	return input;

}

fstream& operator<< (fstream& output, ExercisePlan& rhs)
{

	output << rhs.getPlanName() << endl;
	output << rhs.getGoalSteps() << endl;
	output << rhs.getDate() << endl << endl;

	return output;
}

ostream& operator<< (ostream& output, ExercisePlan& rhs)
{

	output << rhs.getPlanName() << endl;
	output << rhs.getGoalSteps() << endl;
	output << rhs.getDate() << endl << endl;

	return output;
}