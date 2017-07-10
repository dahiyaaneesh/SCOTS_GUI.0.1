/* SCOTS GUI Dialog for new model and about code
 * Contains the definition of all the functions used in the new_model_dialog class
 * Created by: Aneesh Dahiya
 * 10/July/2017
 */

#include "new_model_dialog.h"
#include "ui_new_model_dialog.h"
#include"mainwindow.h"
#include<fstream>
#include<stdlib.h>
#include<QMessageBox>
#include<iostream>

New_Model_dialog::New_Model_dialog(QWidget *parent) :
    QDialog(parent) ,
    ui(new Ui::New_Model_dialog)
{
    ui->setupUi(this);
    this->setWindowTitle("New Model");
   /* QPixmap bkgnd("/home/fmlab5/blue.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);*/
    ui->lineEdit_filename->setToolTip(" Enter the <b> Model name </b>"
                                   " <li><font color = 'gray'><i> all the files will be saved in this folder</i></font></li> ");
    ui->lineEdit_openmodel->setToolTip("Enter the<b> path of folder </b> from where you want to load the files"
                                       "<li><i> Example :</i></li>"
                                       "<ui>"
                                       "<li> home/fmlab/foldername </li> ");
}

New_Model_dialog::~New_Model_dialog()
{
    delete ui;
}

void New_Model_dialog::on_pushButton_filename_clicked()
{   flag_filename_entered=0;
    QString qstring_filename=ui->lineEdit_filename->text();
    newfilename_1=qstring_filename.toStdString();
    std::ofstream file("newfilename.txt");
    file<<newfilename_1.c_str();
    file.close();

    //making a folder for the new model.
    std::string foldername="mkdir \"/home/fmlab5/";
    foldername=foldername.append(newfilename_1);
    foldername=foldername.append("\"");
    std::cout<<"the foldername is "<<foldername;
    if(system(foldername.c_str()))
      {
         QMessageBox::critical(this,"Error", "Folder with this name already exists!");

       }
        else
       {
         hide();
          std::ofstream file1("newfoldername.txt");
         if(file1.is_open())
            { flag_filename_entered=2;
             file1<<"home/fmlab5/"<<newfilename_1.c_str()<<std::endl;
             file1.close();
             pathoffolder="home/fmlab5/"+newfilename_1;
            }
        else
            std::cout<<"\n couldn't save foldername";}
 }

void New_Model_dialog::on_pushButton_openmodel_clicked()
{
   pathoffolder=(ui->lineEdit_openmodel->text()).toStdString();
   std::string checkfile="/"+pathoffolder+"/input_param.txt";
   QStringList str=QString::fromStdString(pathoffolder).split("/");
   int n=str.count();
   newfilename_1=str[n-1].toStdString();
   std::ifstream file(checkfile.c_str());

   if(file.is_open())
     {
       flag_filename_entered=1;
       hide();
       file.close();
     }
   else
     {

       QMessageBox::critical(this,"Error", "Path you entered is incorrect");
       flag_filename_entered=0;
     }


}
void New_Model_dialog::select_stacked_widget(int i)
{
    ui->stackedWidget->setCurrentIndex(i);
    if(i==1)
        this->setWindowTitle("Open Model");
    if(i==0)
        this->setWindowTitle("New Model");
    if(i==2)
        this->setWindowTitle("ABOUT");
}
