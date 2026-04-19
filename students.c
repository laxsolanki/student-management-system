#include<stdio.h>
#include<string.h>

int main(){

FILE *fp,*temp;

char password[20];

printf("Enter password: ");
scanf("%s",password);

if(strcmp(password,"Shubham@iitj") == 0){

int roll, cls;
char name[50], father[50], mother[50], batch[20];

while(1){

int choice;

printf("\n.....Student Record System.....\n");
printf("1 Add student information\n");
printf("2 View All students\n");
printf("3 Search student\n");
printf("4 Delete student\n");
printf("5 Update student\n");
printf("6 Exit\n");

printf("Enter choice: ");
scanf("%d",&choice);


if(choice == 1){

fp = fopen("student.txt","a");

if(fp == NULL){
printf("File error!\n");
continue;
}
while(1){
    int valid = 1;

    printf("Enter name: ");
    scanf(" %49[^\n]", name);

    for(int i = 0; name[i] != '\0'; i++){
        if(name[i] >= '0' && name[i] <= '9'){
            valid = 0;
            break;
        }
    }

    if(valid){
        break;  
    }
    else{
        printf("Invalid name! Digits are not allowed. Try again.\n");
    }
}

 

printf("Enter roll number: ");
 scanf("%d",&roll);
     



while(1){
 int valid=1;

printf("Enter father name: ");
scanf(" %49[^\n]", father);
for(int i = 0; father[i] != '\0'; i++){
        if(father[i] >= '0' && father[i] <= '9'){
            valid = 0;
            break;
        }
    }

    if(valid){
        break;  
    }
    else{
        printf("Invalid  name! Digits are not allowed. Try again.\n");
    }
}
while(1){
int valid=1;
printf("Enter mother name: ");
scanf(" %49[^\n]", mother);
for(int i = 0; mother[i] != '\0'; i++){
        if(mother[i] >= '0' && mother[i] <= '9'){
            valid = 0;
            break;
        }
    }

    if(valid){
        break;  
    }
    else{
        printf("Invalid  name! Digits are not allowed. Try again.\n");
    }
}
  while (1){
printf("Enter class: ");
scanf("%d",&cls);
if(cls>0&&cls<13){
break;
}
else{
printf(" Error!!! \n invalid class  \n ");

}
}
printf("Enter batch: ");
scanf(" %19[^\n]", batch);


fprintf(fp,"%s|%d|%s|%s|%d|%s\n",
name,roll,father,mother,cls,batch);

fclose(fp);

printf("Student saved successfully\n");
}


else if(choice == 2){

fp = fopen("student.txt","r");

if(fp == NULL){
printf("No records found\n");
continue;
}

printf("\n%-15s %-6s %-15s %-15s %-6s %-10s\n",
"Name","Roll","Father","Mother","Class","Batch");

while(fscanf(fp,"%[^|]|%d|%[^|]|%[^|]|%d|%[^\n]\n",
name,&roll,father,mother,&cls,batch)!=EOF){

printf("%-15s %-6d %-15s %-15s %-6d %-10s\n",
name,roll,father,mother,cls,batch);
}

fclose(fp);
}


else if(choice == 3){

int r, found=0;

printf("Enter roll number: ");
scanf("%d",&r);

fp = fopen("student.txt","r");

if(fp == NULL){
printf("File not found\n");
continue;
}

while(fscanf(fp,"%[^|]|%d|%[^|]|%[^|]|%d|%[^\n]\n",
name,&roll,father,mother,&cls,batch)!=EOF){

if(r == roll){

printf("\nStudent Found\n");
printf("Name: %s\n",name);
printf("Father: %s\n",father);
printf("Mother: %s\n",mother);
printf("Class: %d\n",cls);
printf("Batch: %s\n",batch);

found=1;
break;
}
}

if(found==0){
printf("Record not found\n");
}

fclose(fp);
}


else if(choice == 4){

int r, found=0;

printf("Enter roll number to delete: ");
scanf("%d",&r);

fp = fopen("student.txt","r");
temp = fopen("temp.txt","w");

if(fp == NULL || temp == NULL){
printf("File error\n");
continue;
}

while(fscanf(fp,"%[^|]|%d|%[^|]|%[^|]|%d|%[^\n]\n",
name,&roll,father,mother,&cls,batch)!=EOF){

if(roll != r){
fprintf(temp,"%s|%d|%s|%s|%d|%s\n",
name,roll,father,mother,cls,batch);
}
else{
found = 1;
}
}

fclose(fp);
fclose(temp);

remove("student.txt");
rename("temp.txt","student.txt");

if(found)
printf("Student deleted successfully\n");
else
printf("Record not found\n");
}


else if(choice == 5){

int r, found = 0;

printf("Enter roll number to update: ");
scanf("%d",&r);

fp = fopen("student.txt","r");
temp = fopen("temp.txt","w");

if(fp == NULL || temp == NULL){
printf("File error\n");
continue;
}

while(fscanf(fp,"%[^|]|%d|%[^|]|%[^|]|%d|%[^\n]\n",
name,&roll,father,mother,&cls,batch)!=EOF){

if(roll == r){

printf("\nEnter NEW details\n");

printf("Enter name: ");
scanf(" %49[^\n]", name);

printf("Enter father name: ");
scanf(" %49[^\n]", father);

printf("Enter mother name: ");
scanf(" %49[^\n]", mother);

printf("Enter class: ");
scanf("%d",&cls);

printf("Enter batch: ");
scanf(" %19[^\n]", batch);

fprintf(temp,"%s|%d|%s|%s|%d|%s\n",
name,roll,father,mother,cls,batch);

found = 1;
}
else{
fprintf(temp,"%s|%d|%s|%s|%d|%s\n",
name,roll,father,mother,cls,batch);
}
}

fclose(fp);
fclose(temp);

remove("student.txt");
rename("temp.txt","student.txt");

if(found)
printf("Student updated successfully\n");
else
printf("Record not found\n");
}


else if (choice == 6){
printf("Program Exit\n");
break;
}

else{
printf("Invalid choice\n");
}

}
}

else{
printf("Invalid password\n");
}

return 0;}
