/*
		Programmer: Cole Clark
		Date: 3/4/2021

			Description: application that allows users to edit their diet and exercise plans. Solution for PA 4
*/

#pragma once

#include <iostream>
#include <fstream>

#include "ExercisePlan.h"
#include "DietPlan.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::fstream;
using std::ostream;

class FitnessAppWrapper
{
public:
	FitnessAppWrapper();
	~FitnessAppWrapper();



	void runApp(void); 

private:

	void loadDailyDietPlan(fstream& dietInputStream, DietPlan& plan); //reads one daily plan from the DietPlan.txt file
	void loadWeeklyDietPlan(fstream& dietInputStream, DietPlan weeklyPlan[]); //reads 7 of the daily plans from the DietPlan.txt file
	void displayDailyDietPlan(DietPlan& plan); //prints one daily plan to the screen
	void displayWeeklyDietPlan(DietPlan weeklyPlan[]); //prints 7 of the daily plans to the screen
	void storeDailyDietPlan(fstream& dietOutputStream, DietPlan& plan); //writes a daily diet plan to the DietPlan.txt file
	void storeWeeklyDietPlan(fstream& dietOutputStream, DietPlan weeklyPlan[]); //writes 7 daily diet plans to the DietPlan.txt file
	void editDietPlan(DietPlan weeklyPlan[]); //allows the user to choose a day and part of the plan to change and then changes it

	void loadDailyExercisePlan(fstream& exerciseInputStream, ExercisePlan& plan); //reads one daily plan from the ExercisePlan.txt file 
	void loadWeeklyExercisePlan(fstream& exerciseInputStream, ExercisePlan weeklyPlan[]); //reads 7 of the daily plans from the ExercisePlan.txt file
	void displayDailyExercisePlan(ExercisePlan& plan); //prints one daily plan to the screen
	void displayWeeklyExercisePlan(ExercisePlan weeklyPlan[]); //prints 7 of the daily plans to the screen
	void storeDailyExercisePlan(fstream& exerciseOutputStream, ExercisePlan& plan); //writes a daily exercise plan to the ExercisePlan.txt file
	void storeWeeklyExercisePlan(fstream& exerciseOutputStream, ExercisePlan weeklyPlan[]); //writes 7 daily diet plans to the ExercisePlan.txt file
	void editExercisePlan(ExercisePlan weeklyPlan[]); //allows the user to choose a day and part of the plan to change and then changes it

	int displayMenu(void); //displays the menu and allows the user to choose a menu item then returns the user's input

	fstream dietStream;

	fstream exerciseStream;

	ExercisePlan ePlan[7];
	DietPlan dPlan[7];

};

