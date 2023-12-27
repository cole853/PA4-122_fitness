/*
		Programmer: Cole Clark
		Date: 3/4/2021

			Description: application that allows users to edit their diet and exercise plans. Solution for PA 4
*/

#include "FitnessAppWrapper.h"

FitnessAppWrapper::FitnessAppWrapper()
{
	dietStream.open("DietPlan.txt");

	exerciseStream.open("ExercisePlan.txt");
}

FitnessAppWrapper::~FitnessAppWrapper()
{
	cout << "Inside FitnessAppWrapper's destructor! Closing open files!" << endl;

	if (dietStream.is_open())
	{
		dietStream.close();
	}
	if (exerciseStream.is_open())
	{
		exerciseStream.close();
	}
}

void FitnessAppWrapper::runApp(void)
{
	int choice = 0;

	if (dietStream.fail()|| exerciseStream.fail())
	{
		cout << "Files failed to open" << endl;
	}
	else
	{

		do
		{
			system("cls");
			choice = displayMenu();
			system("cls");
			if (choice == 1)
			{
				dietStream.close();
				dietStream.open("DietPlan.txt");
				loadWeeklyDietPlan(dietStream, dPlan);

				cout << "Weekly diet plan has been loaded successfully!" << endl << endl;
				system("pause");
			}
			else if (choice == 2)
			{
				exerciseStream.close();
				exerciseStream.open("ExercisePlan.txt");
				loadWeeklyExercisePlan(exerciseStream, ePlan);

				cout << "Weekly exercise plan has been loaded successfully!" << endl << endl;
				system("pause");
			}
			else if (choice == 3)
			{
				if (dPlan[0].getPlanName() == "")
				{
					cout << "No plans have been loaded" << endl;
					system("pause");
				}
				else
				{
					dietStream.close();
					dietStream.open("DietPlan.txt");
					storeWeeklyDietPlan(dietStream, dPlan);

					cout << "Weekly diet plan has been stored successfully!" << endl << endl;
					system("pause");
				}
			}
			else if (choice == 4)
			{

				if (ePlan[0].getPlanName() == "")
				{
					cout << "No plans have been loaded" << endl;
					system("pause");
				}
				else
				{
					exerciseStream.close();
					exerciseStream.open("ExercisePlan.txt");
					storeWeeklyExercisePlan(exerciseStream, ePlan);

					cout << "Weekly exercise plan has been stored successfully!" << endl << endl;
					system("pause");
				}
			}
			else if (choice == 5)
			{
				if (dPlan[0].getPlanName() == "")
				{
					cout << "No plans have been loaded" << endl;
					system("pause");
				}
				else
				{
					displayWeeklyDietPlan(dPlan);
					system("pause");
				}
			}
			else if (choice == 6)
			{
				if (ePlan[0].getPlanName() == "")
				{
					cout << "No plans have been loaded" << endl;
					system("pause");
				}
				else
				{
					displayWeeklyExercisePlan(ePlan);
					system("pause");
				}
			}
			else if (choice == 7)
			{
				if (dPlan[0].getPlanName() == "")
				{
					cout << "No plans have been loaded" << endl;
					system("pause");
				}
				else
				{
					editDietPlan(dPlan);
					system("pause");
				}
			}
			else if (choice == 8)
			{
				if (ePlan[0].getPlanName() == "")
				{
					cout << "No plans have been loaded" << endl;
					system("pause");
				}
				else
				{
					editExercisePlan(ePlan);
					system("pause");
				}
			}
			else if (choice == 9)
			{
				if (dPlan[0].getPlanName() == "" && ePlan[0].getPlanName() == "")
				{
					cout << "Neither plan was loaded... goodbye" << endl;
				}
				else if (dPlan[0].getPlanName() == "" && ePlan[0].getPlanName() != "")
				{
					exerciseStream.close();
					exerciseStream.open("ExercisePlan.txt");
					storeWeeklyExercisePlan(exerciseStream, ePlan);

					cout << "Weekly exercise plan has been stored successfully!" << endl
						<< "Diet plan was not loaded... goodbye" << endl;
				}
				else if (dPlan[0].getPlanName() != "" && ePlan[0].getPlanName() == "")
				{
					dietStream.close();
					dietStream.open("DietPlan.txt");
					storeWeeklyDietPlan(dietStream, dPlan);

					cout << "Weekly diet plan has been stored successfully!" << endl
						<< "Exercise plan was not loaded... goodbye" << endl;
				}
				else if (dPlan[0].getPlanName() != "" && ePlan[0].getPlanName() != "")
				{
					dietStream.close();
					dietStream.open("DietPlan.txt");
					exerciseStream.close();
					exerciseStream.open("ExercisePlan.txt");

					storeWeeklyDietPlan(dietStream, dPlan);
					storeWeeklyExercisePlan(exerciseStream, ePlan);

					cout << "Both plans stored successfully!... goodbye" << endl;
				}
				system("pause");
			}

		} while (choice != 9);
	}
}



void FitnessAppWrapper::loadDailyDietPlan(fstream& dietInputStream, DietPlan& plan)
{
	dietInputStream >> plan;
}

void FitnessAppWrapper::loadWeeklyDietPlan(fstream& dietInputStream, DietPlan weeklyPlan[])
{
	for (int i = 0; i != 7; ++i)
	{
		loadDailyDietPlan(dietInputStream, weeklyPlan[i]);
	}
}

void FitnessAppWrapper::displayDailyDietPlan(DietPlan& plan)
{
	cout << plan;
}

void FitnessAppWrapper::displayWeeklyDietPlan(DietPlan weeklyPlan[])
{
	for (int i = 0; i != 7; ++i)
	{
		displayDailyDietPlan(weeklyPlan[i]);
	}
}

void FitnessAppWrapper::storeDailyDietPlan(fstream& dietOutputStream, DietPlan& plan)
{
	dietOutputStream << plan;
}

void FitnessAppWrapper::storeWeeklyDietPlan(fstream& dietOutputStream, DietPlan weeklyPlan[])
{
	for (int i = 0; i != 7; ++i)
	{
		storeDailyDietPlan(dietOutputStream, weeklyPlan[i]);
	}
}

void FitnessAppWrapper::editDietPlan(DietPlan weeklyPlan[])
{
	int dayResponse = 0;

	do
	{
		system("cls");
		displayWeeklyDietPlan(weeklyPlan);
		cout << "Enter the number of the day you would like to edit: ";
		cin >> dayResponse;

	} while (dayResponse > 7 || dayResponse < 1);

	int editResponse = 0;
	do
	{
		system("cls");

		displayDailyDietPlan(weeklyPlan[dayResponse - 1]);

		cout << endl << "Enter 1 to edit plan name, 2 to edit goal, or 3 to edit date: ";
		cin >> editResponse;

	} while (editResponse > 3 || editResponse < 1);

	system("cls");

	if (editResponse == 1)
	{
		std::string planName = "";

		cout << "New plan name: ";
		cin >> planName;

		weeklyPlan[dayResponse - 1].setPlanName(planName);
	}
	else if (editResponse == 2)
	{
		int newGoal = 0;

		cout << "New goal: ";
		cin >> newGoal;

		weeklyPlan[dayResponse - 1].setGoalCalories(newGoal);
	}
	else if (editResponse == 3)
	{
		std::string date = "";

		cout << "New date: ";
		cin >> date;

		weeklyPlan[dayResponse - 1].setDate(date);
	}
	cout << endl;
	displayDailyDietPlan(weeklyPlan[dayResponse - 1]);

}


void FitnessAppWrapper::loadDailyExercisePlan(fstream& exerciseInputStream, ExercisePlan& plan)
{
	exerciseInputStream >> plan;
}

void FitnessAppWrapper::loadWeeklyExercisePlan(fstream& exerciseInputStream, ExercisePlan weeklyPlan[])
{
	for (int i = 0; i != 7; ++i)
	{
		loadDailyExercisePlan(exerciseInputStream, weeklyPlan[i]);
	}
}

void FitnessAppWrapper::displayDailyExercisePlan(ExercisePlan& plan)
{
	cout << plan;
}

void FitnessAppWrapper::displayWeeklyExercisePlan(ExercisePlan weeklyPlan[])
{
	for (int i = 0; i != 7; ++i)
	{
		displayDailyExercisePlan(weeklyPlan[i]);
	}
}

void FitnessAppWrapper::storeDailyExercisePlan(fstream& exerciseOutputStream, ExercisePlan& plan)
{
	exerciseOutputStream << plan;
}

void FitnessAppWrapper::storeWeeklyExercisePlan(fstream& exerciseOutputStream, ExercisePlan weeklyPlan[])
{
	for (int i = 0; i != 7; ++i)
	{
		storeDailyExercisePlan(exerciseOutputStream, weeklyPlan[i]);
	}
}

void FitnessAppWrapper::editExercisePlan(ExercisePlan weeklyPlan[])
{
	int dayResponse = 0;

	do
	{
		system("cls");
		displayWeeklyExercisePlan(weeklyPlan);
		cout << "Enter the number of the day you would like to edit: ";
		cin >> dayResponse;

	} while (dayResponse > 7 || dayResponse < 1);

	int editResponse = 0;
	do
	{
		system("cls");

		displayDailyExercisePlan(weeklyPlan[dayResponse - 1]);

		cout << endl << "Enter 1 to edit plan name, 2 to edit goal, or 3 to edit date: ";
		cin >> editResponse;

	} while (editResponse > 3 || editResponse < 1);

	system("cls");

	if (editResponse == 1)
	{
		std::string planName = "";

		cout << "New plan name: ";
		cin >> planName;

		weeklyPlan[dayResponse - 1].setPlanName(planName);
	}
	else if (editResponse == 2)
	{
		int newGoal = 0;

		cout << "New goal: ";
		cin >> newGoal;

		weeklyPlan[dayResponse - 1].setGoalSteps(newGoal);
	}
	else if (editResponse == 3)
	{
		std::string date = "";

		cout << "New date: ";
		cin >> date;

		weeklyPlan[dayResponse - 1].setDate(date);
	}

	cout << endl;

	displayDailyExercisePlan(weeklyPlan[dayResponse - 1]);

}


int FitnessAppWrapper::displayMenu(void)
{
	int choice = 0;

	do
	{

		system("cls");
		cout << "1. Load weekly diet plan from file." << endl
			<< "2. Load weekly exercise plan from file." << endl
			<< "3. Store weekly diet plan to file." << endl
			<< "4. Store weekly exercise plan to file." << endl
			<< "5. Display weekly diet plan to screen." << endl
			<< "6. Display weekly exercise plan to screen." << endl
			<< "7. Edit daily diet plan." << endl
			<< "8. Edit daily exercise plan." << endl
			<< "9. Exit." << endl << endl
			<< "Enter the number corresponding to your choice: ";

		cin >> choice;

	} while (choice > 9 || choice < 1);

	return choice;
}

