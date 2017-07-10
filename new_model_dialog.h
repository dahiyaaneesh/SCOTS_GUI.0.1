


#ifndef NEW_MODEL_DIALOG_H
#define NEW_MODEL_DIALOG_H

#include <QDialog>

namespace Ui {
class New_Model_dialog;
}

class New_Model_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit New_Model_dialog(QWidget *parent = 0);
    ~New_Model_dialog();
     std::string newfilename_1 ,pathoffolder;
     int flag_filename_entered=0;
     void select_stacked_widget(int i);

private slots:
    void on_pushButton_filename_clicked();

    void on_pushButton_openmodel_clicked();

private:
    Ui::New_Model_dialog *ui;
};

#endif // NEW_MODEL_DIALOG_H
