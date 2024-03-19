#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int emp_id;
    char emp_name[100];
    int emp_depid;
    char emp_phone[15];
    float emp_salary;
};

void EmployeesName(struct Employee e[], int ne) {
    printf("Employee Records:\n");
    printf("-----------------\n");
    for (int i = 0; i < ne; i++) {
        printf("ID: %d\n", e[i].emp_id);
        printf("Name: %s\n", e[i].emp_name);
        printf("Department ID: %d\n", e[i].emp_depid);
        printf("Phone: %s\n", e[i].emp_phone);
        printf("Salary: %.2f\n", e[i].emp_salary);
        printf("\n");
    }
}

int main() {
    struct Employee e[100];
    int ne, i;
    
    printf("Enter the number of employees: ");
    scanf("%d", &ne);
    
    for (i = 0; i < ne; i++) {
        printf("Enter details for employee %d:\n", i + 1);
        printf("Employee ID: ");
        scanf("%d", &e[i].emp_id);
        printf("Employee Name: ");
        scanf("%s", e[i].emp_name);
        printf("Department ID: ");
        scanf("%d", &e[i].emp_depid);
        printf("Employee Phone: ");
        scanf("%s", e[i].emp_phone);
        printf("Employee Salary: ");
        scanf("%f", &e[i].emp_salary);
    }
    
    for (i = 0; i < ne - 1; i++) {
        for (int j = 0; j < ne - i - 1; j++) {
                struct Employee temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            
        }
    }
    
    EmployeesName(e, ne);
    
    return 0;
}
