#ifndef STUDENT_H
#define STUDENT_H

struct student {
    char name[50];
    char roll[20];
    char father[50];
    char mother[50];
    char cls[20];
    char batch[20];
};

#ifdef __cplusplus
extern "C" {
#endif


int addStudent(char name[], char roll[], char father[], char mother[], char cls[], char batch[]);

void viewStudent(char data[]);

int searchStudent(char key[], char result[]);

void deleteStudent(char key[]);

void updateStudent(char name[], char roll[], char father[], char mother[], char cls[], char batch[]);

//void addStudent(char name[], char roll[]);

#ifdef __cplusplus
}
#endif

#endif
