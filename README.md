# ADVANCED DATA STRUCTURES- Building a Task Scheduler Application

1. General
 
Problem description
 
Wayne Enterprises is developing a new city. They are constructing many buildings and plan to use software to keep track of all buildings under construction in this new city. A building record has the following fields:
buildingNum: unique integer identifier for each building.
executed_time: total number of days spent so far on this building.
total_time: the total number of days needed to complete the construction of the building.
 
Goal achieved using a min-heap and a Red-Black Tree (RBT)
 
A min heap should be used to store (buildingNums,executed_time,total_time) triplets ordered by executed_time. 
An RBT should be used store (buildingNums,executed_time,total_time) triplets ordered by buildingNum. 
 
Programming Environment: C++
Must include a makefile that creates an executable file named risingCity.


Program should execute using the following:
For c/c++:
$ ./ risingCity file_name
Where file_name is the name of the file that has the input test data.
 
Time Complexity- O(log n)
