/*
 ============================================================================
 Name        : car_registry.c
 Author      : ariel
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "car-registry.txt"

struct Cars {
	char model[50];
	int year;
	char brand[50];
	char licensePlateLetters[3];
	int licensePlateNumbers;
};

int startProgram();
struct Cars *getStructFromFile(int size);
int choicesToListStruct();
int displayAllCars();
FILE *readFile (char * filename, char * mode);
int displayCarsByYear();
int diplayCarFromYear();
int displayCarsByModel();
int addCar();
int lineCounter();
int userChoice();

int main(void)
{
	startProgram();
	return 0;
}

int startProgram() {
	int choice = 0;
	int answer = 1;

	choice = userChoice();

	do {
		switch(choice) {
		case 1:
			choicesToListStruct();
			choice = userChoice();
			break;
		case 2:
			addCar();
			choice = userChoice();
			break;
		case 3:
			printf("That is it for today! See you soon!");
			exit(0);
			break;
		default:
			printf("Inexistent choice\n");
			break;
		}
	} while (answer == 1);

	return 0;

}

int userChoice() {
	int choice = 0;

	printf("\n************Car Registry************\n");
	printf("Choose one of the options bellow:\n");
	printf("1- List registered cars\n");
	printf("2- Add new car\n");
	printf("3- Exit\n");
	printf("Option: ");
	scanf("%d", &choice);

	return choice;
}

int choicesToListStruct() {
	int choice = 0;

	printf("\nChoose how to list the cars\n");
	printf("1- List all cars\n");
	printf("2- List cars by manufacturing year\n");
	printf("3- List cars from a specific manufacturing year\n");
	printf("4- List cars by model\n");
	printf("5- Return to menu\n");
	printf("6- Exit\n");
	printf("Option: ");
	scanf("%d", &choice);

	switch(choice) {
	case 1:
		displayAllCars();
		break;
	case 2:
		displayCarsByYear();
		break;
	case 3:
		diplayCarFromYear();
		break;
	case 4:
		displayCarsByModel();
		break;
	case 5:
		startProgram();
		break;
	case 6:
		printf("That is it for today! See you soon!");
		exit(0);
		break;
	default:
		printf("Inexistent option\n");
		break;
	}

	return 0;
}

FILE *readFile (char * filename, char * mode) {
	FILE *fp;
	fp = fopen(filename, mode);
	if(fp == NULL) {
		printf("Inexistent file\n\n");
		main();
	}
	return fp;
}

int lineCounter()
{
	FILE *fp = readFile(FILENAME, "r");
	char ch;
	int lineCounter = 0;

	while((ch = fgetc(fp)) != EOF)
	{
		if(ch == '\n')
			lineCounter++;
	}
	fclose(fp);
	fp = NULL;

	return lineCounter;
}

struct Cars *getStructFromFile(int size) {
	FILE *fp = readFile(FILENAME, "r");

	// reads file and passes it to structure
	char token[121];
	char * item;
	struct Cars *carList = malloc(sizeof(struct Cars) * size);
	int index;

	while (fgets(token, 120, fp)) {
		item = strtok(token, " ");
		strncpy(carList[index].brand, item, sizeof(carList[index].brand));

		item = strtok(NULL, " ");
		carList[index].year = atoi(item);

		item = strtok(NULL, " ");
		strncpy(carList[index].model, item, sizeof(carList[index].model));

		item = strtok(NULL, " ");
		strncpy(carList[index].licensePlateLetters, item, sizeof(carList[index].licensePlateLetters));

		item = strtok(NULL, " ");
		carList[index].licensePlateNumbers = atoi(item);

		index++;
	}
	fclose(fp);
	fp = NULL;

	return carList;
}

int displayAllCars() {

	int size = lineCounter();
	struct Cars *carList = getStructFromFile(size);

	// sort elements by manufacturing year
	int i, j, temp;
	for (i = 0; i < size; i++) {
		for (j = i + 1; j < size; j++) {
			if (carList[i].year > carList[j].year) {
				temp = carList[i].year;
				carList[i].year = carList[j].year;
				carList[j].year = temp;
			}
		}
	}

	// display cars
	for(i = 0; i < size; i++) {
		printf("\nCar %d\nModel: %s\n", i + 1, carList[i].model);
		printf("Year: %d\n", carList[i].year);
		printf("Brand: %s\n", carList[i].brand);
		printf("License Plate: %s-%d\n", carList[i].licensePlateLetters, carList[i].licensePlateNumbers);
	}
	free(carList);

	return 0;
}

int displayCarsByYear() {
	int size = lineCounter();
	struct Cars *carList = getStructFromFile(size);

	// search cars by manufacturing year
	int i, searchedYear;
	printf("Insert year to search for cars: ");
	scanf("%d", &searchedYear);
	printf("\n****Cars Manufactured in %d****\n", searchedYear);

	for(i = 0; i < size; i++) {
		if(searchedYear == carList[i].year) {
			printf("\nModel: %s\n", carList[i].model);
			printf("Year: %d\n", carList[i].year);
			printf("Brand: %s\n", carList[i].brand);
			printf("License Plate: %s-%d\n", carList[i].licensePlateLetters, carList[i].licensePlateNumbers);
		}
	}
	free(carList);

	return 0;
}

int diplayCarFromYear() {
	int size = lineCounter();
	struct Cars *carList = getStructFromFile(size);
	int i, searchedYear;

	// list cars from a certain manufacturing year
	printf("Insert manufacturing year from which to search for: ");
	scanf("%d", &searchedYear);
	for(i = 0; i < size; i++) {
		if(searchedYear <= carList[i].year) {
			printf("\nCar Manufactured in %d\nModel: %s\n", carList[i].year, carList[i].model);
			printf("Year: %d\n", carList[i].year);
			printf("Brand: %s\n", carList[i].brand);
			printf("License Plate: %s-%d\n", carList[i].licensePlateLetters, carList[i].licensePlateNumbers);
		}
	}
	free(carList);
	return 0;
}

int displayCarsByModel() {
	int size = lineCounter();
	struct Cars *carList = getStructFromFile(size);
	char model[50];

	printf("Insert car model to search for: ");
	scanf("%s", model);
	printf("\nCars of the model: %s\n", model);

	int i;
	for(i = 0; i < size; i++) {
		if(strncmp(model, carList[i].model, 50) == 0) {
			printf("Model: %s\n", carList[i].model);
			printf("Year: %d\n", carList[i].year);
			printf("Brand: %s\n", carList[i].brand);
			printf("License Plate: %s-%d\n", carList[i].licensePlateLetters, carList[i].licensePlateNumbers);
		}
	}
	free(carList);
	return 0;
}

int addCar()
{
	FILE *fp = readFile(FILENAME, "a");

	int insertedNumber;
	printf("How many cars do you want to insert: ");
	scanf("%d", &insertedNumber);

	struct Cars carList[insertedNumber];

	int i;
	for (i = 0; i < insertedNumber; i++)
	{
		printf("\nInsert car brand: ");
		scanf("%s", carList[i].brand);

		printf("Insert manufacturing year: ");
		scanf("%d", &carList[i].year);

		printf("Insert car model: ");
		scanf("%s", carList[i].model);

		printf("Insert license plate letters: ");
		scanf("%s", carList[i].licensePlateLetters);
		printf("Insert license plate numbers: ");
		scanf("%d", &carList[i].licensePlateNumbers);

	}

	// puts file on structure
	for (i = 0; i < insertedNumber; i++)
	{
		fprintf(
				fp,
				"%s %d %s %s %d\n",
				carList[i].brand,
				carList[i].year,
				carList[i].model,
				carList[i].licensePlateLetters,
				carList[i].licensePlateNumbers
		);
	}

	fclose(fp);
	fp = NULL;
	printf("\nCars added with success!!\n\n");

	return 0;
}

