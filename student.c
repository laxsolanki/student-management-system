#include<stdio.h>
#include<string.h>
#include "student.h"
#include <ctype.h>
#include <stdlib.h>


int isValidName(const char *str)
{
    for(int i = 0; str[i]; i++)
    {
        if(!isalpha(str[i]) && str[i] != ' ')
            return 0;
    }
    return 1;
}


int isNumber(const char *str)
{
    for(int i = 0; str[i]; i++)
    {
        if(!isdigit(str[i]))
            return 0;
    }
    return 1;
}


int isValidClass(const char *cls)
{
    int c = atoi(cls);
    return (c >= 1 && c <= 12);
}

int addStudent(char name[], char roll[], char father[], char mother[], char cls[], char batch[])
{

if(strlen(name)==0 || strlen(roll)==0 || strlen(father)==0 || strlen(mother)==0 || strlen(cls)==0)
        return 6;

    // 🔥 alag-alag validation
    if(!isValidName(name))
        return 1;
    if(!isNumber(roll))
        return 2;

    if(!isValidName(father))
        return 3;

    if(!isValidName(mother))
        return 4;



    if(!isValidClass(cls))
        return 5;


    FILE *fp = fopen("student.txt","a");
    if(fp == NULL) return 7;

    fprintf(fp,"%s,%s,%s,%s,%s,%s\n", name, roll, father, mother, cls, batch);

    fclose(fp);
return 0;
}

void viewStudent(char data[])
{
    FILE *fp = fopen("student.txt","r");

    if(fp == NULL){
        strcpy(data,"No records found");
        return;
    }

    char line[200];
    data[0] = '\0';

    while(fgets(line,sizeof(line),fp)){
        strcat(data,line);
    }

    fclose(fp);
}
void toLowerCase(char *str)
{
    for(int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
}

int searchStudent(char key[], char result[])
{
    FILE *fp = fopen("student.txt","r");
    if(fp == NULL) return 0;

    char line[200];

    while(fgets(line,sizeof(line),fp))
    {
     char name[50], roll[20], father[50], mother[50], cls[20], batch[20];

        sscanf(line,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",
               name, roll, father, mother, cls, batch);


        char tempName[50], tempKey[50];
        strcpy(tempName, name);
        strcpy(tempKey, key);

        toLowerCase(tempName);
        toLowerCase(tempKey);


        if(strcmp(roll, key) == 0 || strcmp(tempName, tempKey) == 0)
        {
            strcpy(result,line);
            fclose(fp);
            return 1;
        }
}

    fclose(fp);
    return 0;
}

void deleteStudent(char key[])
{
    FILE *fp = fopen("student.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    char line[200];

    while(fgets(line, sizeof(line), fp))
    {
        char copy[200];
        strcpy(copy, line);

        char *token = strtok(copy, ",");   // name
        token = strtok(NULL, ",");         // roll

        if(token != NULL)
        {
            token[strcspn(token,"\n")] = 0;

            if(strcmp(token, key) == 0)
            {
                continue;   // ❌ skip → delete
            }
        }

        fputs(line, temp);  // ✅ keep
    }

    fclose(fp);
    fclose(temp);

    remove("student.txt");
    rename("temp.txt", "student.txt");
}

void updateStudent(char name[], char roll[], char father[], char mother[], char cls[], char batch[])
{

if(!isValidName(name) || !isValidName(father) || !isValidName(mother))
{
    printf("Invalid Name/Father/Mother\n");
    return;
}

if(!isNumber(roll))
{
    printf("Invalid Roll\n");
    return;
}

if(!isValidClass(cls))
{
    printf("Invalid Class\n");
    return;
}
    FILE *fp = fopen("student.txt","r");
    FILE *temp = fopen("temp.txt","w");

    if(fp == NULL || temp == NULL) return;

    char line[200];

    while(fgets(line,sizeof(line),fp))
    {
char fileName[50], fileRoll[20], fileFather[50], fileMother[50], fileClass[10], fileBatch[10];
 // ✅ correct parsing (6 fields)
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%s",
               fileName, fileRoll, fileFather, fileMother, fileClass, fileBatch);

        // ✅ roll match
        if(strcmp(fileRoll, roll) == 0)
        {
            fprintf(temp,"%s,%s,%s,%s,%s,%s\n", name, roll, father, mother, cls, batch);
        }
        else
        {
            fprintf(temp,"%s",line);
        }
    }


fclose(fp);
    fclose(temp);

    remove("student.txt");
    rename("temp.txt","student.txt");
}