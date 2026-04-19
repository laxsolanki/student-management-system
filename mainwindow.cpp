#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QHeaderView>
#include <QTableWidget>
#include <QTableWidgetItem>

extern "C"{
#include "student.h"
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->hide();
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels({"Name", "Roll", "Father", "Mother", "Class", "Batch"
    });
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    ui->tableWidget->setColumnWidth(0, 150); // Name
    ui->tableWidget->setColumnWidth(1, 60);  // Roll (4 digit)
    ui->tableWidget->setColumnWidth(2, 150); // Father
    ui->tableWidget->setColumnWidth(3, 150); // Mother
    ui->tableWidget->setColumnWidth(4, 50);  // Class (2-3 digit)
    ui->tableWidget->setColumnWidth(5, 50);  // Batch (2-3 digit)
}
MainWindow::~MainWindow()
{
    delete ui;
}

// ADD
void MainWindow::on_Add_clicked()
{
    if(ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty())
    {
        QMessageBox::warning(this,"Error","Fill required fields!");
        return;
    }
    {
        QByteArray nameArr = ui->lineEdit->text().toUtf8();
        QByteArray rollArr = ui->lineEdit_2->text().toUtf8();
        QByteArray fatherArr = ui->lineEdit_3->text().toUtf8();
        QByteArray motherArr = ui->lineEdit_4->text().toUtf8();
        QByteArray classArr = ui->lineEdit_5->text().toUtf8();
        QByteArray batchArr = ui->lineEdit_6->text().toUtf8();

        char *name = nameArr.data();
        char *roll = rollArr.data();
        char *father = fatherArr.data();
        char *mother = motherArr.data();
        char *cls = classArr.data();
        char *batch = batchArr.data();
        int res = addStudent(name, roll, father, mother, cls, batch);
        if(res == 1)
        {
            QMessageBox::warning(this,"Error","Invalid Name (only alphabets)");
            return;
        }
        if(res == 2)
        {
            QMessageBox::warning(this,"Error","Roll must be number");
            return;
        }
        if(res == 3)
        {
            QMessageBox::warning(this,"Error","Invalid Father Name");
            return;
        }
        if(res == 4)
        {
            QMessageBox::warning(this,"Error","Invalid Mother Name");
            return;
        }
        if(res == 5)
        {
            QMessageBox::warning(this,"Error","Class must be 1-12");
            return;
        }
        if(res == 6)
        {
            QMessageBox::warning(this,"Error","All fields required");
            return;
        }
        if(res == 0)
        {
            QMessageBox::information(this,"Success","Student Saved");
        }
    }
    on_ViewAll_clicked();
    on_refreshButton_clicked();
}

// VIEW
void MainWindow::on_ViewAll_clicked()
{
    FILE *fp = fopen("student.txt", "r");

    if(fp == NULL){
        QMessageBox::warning(this, "Error", "File not found!");
        return;
    }
    struct student s;
    if(ui->tableWidget->isVisible())
        ui->tableWidget->hide();
    else
    ui->tableWidget->show();
    ui->tableWidget->setRowCount(0);
    char line[200];
    int row = 0;
    while(fgets(line, sizeof(line), fp)) 
    {
        QString str = QString(line).trimmed();
        QStringList list = str.split(",");
        ui->tableWidget->insertRow(row);
        for(int i = 0; i < list.size(); i++){
            ui->tableWidget->setItem(row, i, new QTableWidgetItem(list[i]));
        }
        row++;
    }
    fclose(fp);
}

// SEARCH
void MainWindow::on_Search_clicked()
{
    QString key = ui->lineEdit->text().trimmed();
    if(key.isEmpty())
        key = ui->lineEdit_2->text().trimmed();
    if(key.isEmpty())
    {
        QMessageBox::warning(this,"Error","Enter Name or Roll");
        return;
    }

    QString keyLower = key.toLower();
    FILE *fp = fopen("student.txt", "r");
    if(fp == NULL){
        QMessageBox::warning(this, "Error", "File not found!");
        return;
    }
    ui->tableWidget->setRowCount(0); 
    ui->tableWidget->show();
    char line[200];
    int row = 0;
    bool found = false;
    while(fgets(line, sizeof(line), fp))
    {
        QString str = QString(line).trimmed();
        QStringList list = str.split(",");
        if(list.size() < 2)
            continue;
        QString name = list[0].trimmed().toLower();
        QString roll = list[1].trimmed();

        if(roll == key || name.contains(keyLower))
        {
            ui->tableWidget->insertRow(row);
            for(int i = 0; i < list.size(); i++){
                ui->tableWidget->setItem(row, i, new QTableWidgetItem(list[i]));
                }
            row++;
            found = true;
        }
    }
    fclose(fp);
    if(!found){
        QMessageBox::warning(this,"Error","Student not found");
    }
}

// DELETE
void MainWindow::on_Delete_clicked()
{
    int row = ui->tableWidget->currentRow();
    if(ui->tableWidget->currentRow() < 0)
        return;
    QString name = ui->tableWidget->item(row,0)->text();
    QString roll = ui->tableWidget->item(row,1)->text();
    ui->tableWidget->removeRow(row);
deleteStudent(roll.toUtf8().data());
    QMessageBox::information(this,"Deleted","Record Deleted!");
    on_ViewAll_clicked();
}

// UPDATE
void MainWindow::on_Update_clicked()
{
    QString name = ui->lineEdit->text().trimmed();
    QString roll = ui->lineEdit_2->text().trimmed();
    QString father = ui->lineEdit_3->text().trimmed();
    QString mother = ui->lineEdit_4->text().trimmed();
    QString cls = ui->lineEdit_5->text().trimmed();
    QString batch = ui->lineEdit_6->text().trimmed();

    if(roll.isEmpty()){
        QMessageBox::warning(this,"Error","Enter Roll first!");
        return;
    }
    if(name.isEmpty() || father.isEmpty() || mother.isEmpty() || cls.isEmpty() || batch.isEmpty()){
        QMessageBox::warning(this,"Error","Fill all details before update!");
        return;
    }
    char result[500];
    if(!searchStudent(roll.toUtf8().data(), result)){
        QMessageBox::warning(this,"Error","Record not found!");
        return;
    }
    updateStudent(name.toUtf8().data(),
                  roll.toUtf8().data(),
                  father.toUtf8().data(),
                  mother.toUtf8().data(),
                  cls.toUtf8().data(),
                  batch.toUtf8().data());

    QMessageBox::information(this,"Updated","Record Updated!");
    on_ViewAll_clicked();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit->setFocus();
}
void MainWindow::on_refreshButton_clicked()
{
    ui->lineEdit->clear();     // name
    ui->lineEdit_2->clear();   // roll
    ui->lineEdit_3->clear();   // father
    ui->lineEdit_4->clear();   // mother
    ui->lineEdit_5->clear();   // class
    ui->lineEdit_6->clear();   // batch
ui->lineEdit_2->setReadOnly(false);
    ui->lineEdit->setFocus();
}
void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    ui->lineEdit->setText(ui->tableWidget->item(row,0)->text()); // Name
    ui->lineEdit_2->setText(ui->tableWidget->item(row,1)->text()); // Roll
    ui->lineEdit_3->setText(ui->tableWidget->item(row,2)->text()); // Father
    ui->lineEdit_4->setText(ui->tableWidget->item(row,3)->text()); // Mother
    ui->lineEdit_5->setText(ui->tableWidget->item(row,4)->text()); // Class
    ui->lineEdit_6->setText(ui->tableWidget->item(row,5)->text()); // Batch
    ui->lineEdit_2->setReadOnly(true);
}

// EXIT
void MainWindow::on_Exit_clicked()
{
    close();
}
void MainWindow::on_refresh_clicked()
{
    on_refreshButton_clicked();
}
