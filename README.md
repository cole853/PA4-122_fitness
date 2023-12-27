# PA4-122_fitness
A fitness app for CPTS 122 programming assignment 4. Completed on 3/4/2021.

This fitness app allows a user to store their diet and exercise plans for a week. When the program starts users have the option to load their diet plan from DietPlan.txt, load their exercise plan from ExercisePlan.txt, store either of these plans to their files, display plans, edit plans, or exit.

# Nine Files Are Required:

DietPlan.h: contains the DietPlan class which is used to store the diet plan for one day.

DietPlan.cpp: contains the definitions for DietPlan class functions.

ExcercisePlan.h: contains the ExercisePlan class which is used to store the exercise plan for one day.

ExercisePlan.cpp: contains the definitions ExercisePlan class functions.

FitnessAppWrapper.h: contains the FitnessAppWrapper class where arrays of ExcercisePlan and DietPlan objects are modified.

FitnessAppWrapper.cpp: contains the definitions for FitnessAppWrapper class functions.

main.cpp: contains the main function for the program where FitnessAppWrapper.runApp() is called.

DietPlan.txt: contains diet plan information.

ExercisePlan.txt: contains exercise plan information.

# Possible Improvements

This program could be improved by allowing the user to store more than 7 days of diet and exercise plans.

DietPlan and ExercisePlan classes could have used inheritance instead of rewriting functions that are the same in both classes.
