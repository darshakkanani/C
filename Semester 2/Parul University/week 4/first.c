#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

// Structure to represent an employee
struct Employee {
    int emp_id;
    char emp_name[50];
    int emp_deptid;
    char emp_phno[15];
    float emp_salary;
};

// Function to display details of all employees sorted by EMP_NAME
void displayEmployeeDetailsByName(struct Employee employees[], int n) {
    // Sort the employees based on EMP_NAME (bubble sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(employees[j].emp_name, employees[j + 1].emp_name) > 0) {
                // Swap employees
                struct Employee temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }

    // Display employee details
    printf("Employee Details Sorted by Name:\n");
    printf("EMP_ID\tEMP_NAME\tEMP_DEPTID\tEMP_PHNO\tEMP_SALARY\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t\t%d\t\t%s\t%.2f\n", employees[i].emp_id, employees[i].emp_name,
               employees[i].emp_deptid, employees[i].emp_phno, employees[i].emp_salary);
    }
}

int main() {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    if (n > MAX_EMPLOYEES) {
        printf("Maximum number of employees exceeded. Please try again with fewer employees.\n");
        return 1;
    }

    struct Employee employees[MAX_EMPLOYEES];

    // Input employee details
    for (int i = 0; i < n; i++) {
        printf("Enter details for employee %d:\n", i + 1);
        printf("EMP_ID: ");
        scanf("%d", &employees[i].emp_id);
        printf("EMP_NAME: ");
        scanf("%s", employees[i].emp_name);
        printf("EMP_DEPTID: ");
        scanf("%d", &employees[i].emp_deptid);
        printf("EMP_PHNO: ");
        scanf("%s", employees[i].emp_phno);
        printf("EMP_SALARY: ");
        scanf("%f", &employees[i].emp_salary);
    }

    // Display employee details sorted by name
    displayEmployeeDetailsByName(employees, n);

    return 0;
}
