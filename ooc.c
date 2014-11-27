#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Student {
	char firstname[200];
	char lastname[200];

} *Student;

void new_student(Student* s, char* firstname,char* lastname) {
	*s = (Student) malloc(sizeof(struct _Student));
	strcpy((*s)->firstname, firstname);
	strcpy((*s)->lastname, lastname);
}

void delete_student(Student* s) {
	free(*s);
	(*s) = NULL;
}

void student_get_name(Student s, char *name) {
	sprintf(name, "%s %s", s->firstname, s->lastname);
}

typedef struct _Employee {
	char name[400];
} *Employee;

void new_employee(Employee* e, char* name) {
	*e = (Employee) malloc(sizeof(struct _Employee));
	strcpy((*e)->name, name);
}

void delete_employee(Employee* e) {
	free(*e);
	(*e) = NULL;
}

void employee_get_name(Employee s, char *name) {
	sprintf(name, "%s", s->name);
}


void hello(void *obj, void (*p_get_name)(void*, char*), char *name) {
	char temp[400];
	p_get_name(obj, &temp);
	sprintf(name, "Hello %s", temp);
}

int main() {
	Student s;
	Employee e;
	char name[400];

	new_student(&s, "Weerasak", "Chongnguluam");
	new_employee(&e, "Kanokon Chansom");

	hello(s, student_get_name, &name);
	printf("%s\n", name);

	hello(e, employee_get_name, &name);
	printf("%s\n", name);

	delete_student(&s);
	delete_employee(&e);

	return 0;
}

