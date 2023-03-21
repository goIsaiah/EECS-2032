#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
    int Employee_ID;
    char name[20]; // Employee name first name then last name
    char address[50]; //The employee address might contains spaces
    //Both name and address are terminated by
    //a null character
    int job_code; // An integer between 1 and 12
    float salary;
//};
}e;

//struct employee e;
// size of structure
long int size = sizeof(e);

FILE *fp, *ft;

int main(int argc, char* argv[]) {
    //printf("First argument is: %s\n", argv[1]);
    //printf("Second argument is: %d\n", atoi(argv[2]));
    fp = fopen("data.txt", "rb+");

    //Showing error if file is unable to open
    if (fp == NULL) {
        printf("\nCannot open file...");
        exit(1);
    }

    // FIND NAME GIVEN ID
    if (strcmp(argv[1], "-ID") == 0) {
        int input = atoi(argv[2]);
        int flag = 0;
        rewind(fp);

		// While File is open
		while (fread(&e, size, 1, fp) == 1) {
			// Compare the employee name with ename
			if (e.Employee_ID == input) {
                flag = 1;
				printf("%s\n", e.name);
				break;
			}
		}

        if (flag == 0) {
            printf("No such employee\n");
        }
    }

    // FIND SALARIES
    else if (strcmp(argv[1], "-s") == 0) {
        float input = atof(argv[2]);
        int flag = 0;
        rewind(fp);
        while (fread(&e, size, 1, fp) == 1) {
			// Compare the salary with e.salary
			if (e.salary >= input) {
                flag = 1;
				printf("%s, %.2f\n", e.name, e.salary);
			}
		}
    }

    // NUMBER OF EMPLOYEES
    else if (strcmp(argv[1], "-count") == 0) {
        int count = 0;
        while (fread(&e, size, 1, fp) == 1) {
            count++;
        }
        printf("%d\n", count);
    }

    // DISPLAY SALARY GIVEN NAME
    else if (strcmp(argv[1], "-name") == 0) {
        int flag = 0;
        char name[100];
        char lastname[100];
        strcpy(name, argv[2]);
        strcpy(lastname, argv[3]);
        strcat(name, " ");
        strcat(name, lastname);
        
        while (fread(&e, size, 1, fp) == 1) {
            if (strcmp(name, e.name) == 0) {
                flag = 1;
                printf("%.2f\n", e.salary);
            }
        }
        if (flag == 0) {
            printf("No such employee\n");
        }
    }
}

//vi lab6_1.c
//gcc lab6_1.c
//a.out