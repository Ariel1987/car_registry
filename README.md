# Car Registry 
Program to register vehicles to a file

## General Info

The user is prompted to give the following information in order to register the cars:

- brand
- manufacturing year
- model
- license plate

The program also gives different ways to list the cars when reading the file:

- list all cars
- list cars by year
- list cars from a certain year
- list cars by model

## Technologies

- C language

## Setup

To run this program, the user must have a GCC compiler instaled in his IDE. 
It can be installed following the steps in the [GCC Official Page](https://gcc.gnu.org/install/index.html). 
For a detailed step-by-step tutorial on how to use the GCC compiler with C see [this article](https://medium.com/@laura.derohan/compiling-c-files-with-gcc-step-by-step-8e78318052).

## Features

When the user first compile and run the program, a few options will be given:

- List registered cars

- Add new car

- Exit

If the user decides to list the cars but the file still doesn't exist, a warning will be shown and return to the menu

![](prints-for-git/print2.png)

Pressing "2" adds a car. the user will get to choose how many cars to add and be prompted the information required (brand, year, model, license plate). 
The file will automatically be created. And return to the main menu.

![](prints-for-git/print3.png)

When there is already a file, the user can choose how to list the cars, being taken to a secondary menu

![](prints-for-git/print4.png)

The first option will simply list the cars in the file displaying it in ascending order from the manufacturing year and return to the main menu

The second option is to filter and display the list from a certain year. The user will be prompted to give a year. 
After displaying it, the program returns to the main menu 

![](prints-for-git/print5.png)

The third option also prompts the user with a specific year and displays all cars manufactured from that year

The fourth option will search and filter cars by model in the same way. 

Finally the user can return to the main menu by pressing "5" or exit the program pressing "6" 
