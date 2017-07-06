#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"new_model_dialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int Dim_ss=2 ,Dim_ii=1 ; double tau=1;
    double eta_ss[10]={0.5, 0.5} ,lb_ss[10]={0 ,0} ,ub_ss[10]={1 ,1} ,lb_ii[10]={1},ub_ii[10]={2},eta_ii[10]={1};
    int flag_input_parameters=0;
    int flag_state_parameters=0 ,flag_rad_post=0 ,flag_sys_post=0;
    std::string rad_post;
    std::string sys_post;
    std::string newfilename="New_Model.cpp";
    double avoid[20][20];
    int avoidrows=0;
    int flag_target_lbub=0 ,flag_rungge_kutta_rad=0,flag_rungge_kutta_sys=0,flag_avoid=0,flag_safety=0;
    double lb_target[20],ub_target[20] ,lb_avoid[20],ub_avoid[20],lb_safety[20],ub_safety[20];
    double rungekutta_step=1 ;
    int flag_add_avoid=0 ,flag_add_safety=0,flag_add_target=0 ,flag_simulation=0;
    std::string path;
    std::string path_of_scots="/home/fmlab5/SCOTSv0.2";

private slots:
    void on_pushButton_clicked();

    void on_pushButton_input_parameters_clicked();

    void on_pushButton_state_parameters_clicked();

    void on_pushButton_sys_post_clicked();

    void on_pushButton_rad_post_clicked();

    void on_actionNew_Model_triggered();

    void on_treeWidget_newmodel_clicked(const QModelIndex &index);
    void makefile();

    void on_pushButton_compileandrun_clicked();

    void on_actionOpen_Model_triggered();


    void on_pushButton_target_bounds_clicked();


    void on_pushButton_safety_clicked();

    void on_pushButton_avoid_clicked();

    void on_pushButton_2_clicked();

    void on_actionPath_for_SCOTS_triggered();

    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;
    New_Model_dialog *new_model;

};

#endif // MAINWINDOW_H
