/* SCOTS GUI Maniwindow code
 * Contains the definition of all the functions used in the Mainwindow class
 * Created by: Aneesh Dahiya
 * 10/July/2017
 */



#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<fstream>
#include<iostream>
#include<string>
#include<QMessageBox>
#include<QFileDialog>
#include"new_model_dialog.h"


// Standard list of header files which need to added to each file

std::string headerfilelist="#include<iostream>\n"
                           "#include <array>\n"
                           "#include <cmath>\n"
                           "#include \"scots.hh\"\n"
                           "#include\"RungeKutta4.hh\"\n"
                           "#include \"TicToc.hh\"\n"
                           "#include <sys/time.h>\n"
                           "#include <sys/resource.h>\n";


// Main initializing function which is executed each time MAinwindow is called.

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    new_model=new New_Model_dialog(this);                // creating object of the class new_model_dialog, responsible for adding the new file name for new_model functionality/

    //listWidget->setStyleSheet("QListView::item:selected {background : transparent; border: solid 2px red;}");
    // ui->treeWidget_newmodel->setStyleSheet("selection-background-color: white; selection-color : black");
    // Code snipet for adding the background image for GUI

//    QPixmap bkgnd("/home/fmlab5/HCS.jpg");
//  bkgnd = bkgnd.scaled(this->size() /*Qt::IgnoreAspectRatio*/);
//    QPalette palette;
//    palette.setBrush(QPalette::Background, bkgnd);
//    this->setPalette(palette);

    // Code for adding background ends.


    //Hiding all other tab and widgets, they will be only shown only on choosing open_model and new_model functionality.
    ui->new_model_stacked_widget->hide();
    ui->treeWidget_newmodel->hide();
    ui->textBrowser_status->hide();

    this->setWindowTitle("SCOTS GUI");



    //Adding help texts (Hover boxes) for various features of GUI

      // for state Parameter widget :
     ui->pushButton_state_parameters->setToolTip("Press for saving the <b><i> state parameters </i></b>");
     ui->spinBox_dim_ss->setToolTip(" Enter the <b> state dimension </b> (Natural numbers only)"
                                   " <li><font color = 'blue'><i> Valid</i></font></li> "
                                   "<ul>"
                                   "<li>1</li>"
                                   "<li>2</li>"
                                   "</ul>"
                                   "<li><font color = 'red'><i> Invalid</i></font></li>"
                                   "<ul>"
                                   "<li>1.5</li>"
                                   "<li> 2,5 ...etc </li>"
                                   "</ul>");
     ui->lineEdit_eta_ss->setToolTip(" Enter the <b> eta  </b> (state quantization parameters)"
                                    "<li><i> You may use \":\", \",\",\"  \",\";\" as seperators </li>"
                                   " <li><font color = 'blue'><i> Valid </i></font></li> "
                                   "<ul>"
                                   "<li>0.2 0.3</li>"
                                   "<li>1  2</li>"
                                   "</ul>"
                                   "<li><font color = 'red'><i> Invalid</i></font></li>"
                                   "<ul>"
                                   "<li> zeroes</li>"
                                   "<li> zeroes, negative numbers, mathematical operations like 3*5, M_PI-5 etc </li>"
                                   "</ul>");
     ui->lineEdit_lb_ss->setToolTip(" Enter the <b> lower bound </b> for state"
                                "<li><i> You may use \":\", \",\",\"  \",\";\" as seperators </li>"
                                " <li><font color = 'blue'><i> Valid </i></font></li> "
                                "<ul>""\n"
                                "<li>0.2 0.3</li>"
                                "<li>1  2</li>"
                                "</ul>"
                                "<li><font color = 'red'><i> Invalid</i></font></li>"
                                "<ul>"
                                "<li>0 -2</li>"
                                "<li> zeroes, negative numbers, mathematical operations like 3*5, M_PI-5 etc </li>"
                                "</ul>");
     ui->lineEdit_ub_ss->setToolTip(" Enter the <b> upper bound </b> for state"
                                "<li><i> You may use \":\", \",\",\"  \",\";\" as seperators </li>"
                                " <li><font color = 'blue'><i> Valid </i></font></li> "
                                "<ul>"
                                "<li>0.2 0.3</li>"
                                "<li>1  2</li>"
                                "</ul>"
                                "<li><font color = 'red'><i> Invalid</i></font></li>"
                                "<ul>"
                                "<li>0 -2</li>"
                                "<li> zeroes, negative numbers, mathematical operations like 3*5, M_PI-5 etc</li>"
                                "</ul>");


      // for Input Parameter widget :
     ui->pushButton_input_parameters->setToolTip("Press for saving the <b><i> input parameters </i></b>");
     ui->spinBox_dim_ii->setToolTip(" Enter the <b> input dimension </b> (Natural numbers only)"
                                    " <li><font color = 'blue'><i> Valid</i></font></li> "
                                    "<ul>"
                                    "<li>1</li>"
                                    "<li>2</li>"
                                    "</ul>"
                                    "<li><font color = 'red'><i> Invalid</i></font></li>"
                                    "<ul>"
                                    "<li>1.5</li>"
                                    "<li> 2,5 ...etc </li>"
                                    "</ul>");
     ui->lineEdit_eta_ii->setToolTip(" Enter the <b> eta  </b> (input quantization parameters)"
                               "<li><i> You may use \":\", \",\",\"  \",\";\" as seperators </li>"
                               " <li><font color = 'blue'><i> Valid </i></font></li> "
                               "<ul>"
                               "<li>0.2 0.3</li>"
                               "<li>1  2</li>"
                               "</ul>"
                               "<li><font color = 'red'><i> Invalid</i></font></li>"
                               "<ul>"
                               "<li>0 -2</li>"
                               "<li> zeroes, negative numbers, mathematical operations like 3*5, M_PI-5 etc </li>"
                               "</ul>");
     ui->lineEdit_lb_ii->setToolTip(" Enter the <b> lower Bound </b> for input"
                               "<li><i> You may use \":\", \",\",\"  \",\";\" as seperators </li>"
                                " <li><font color = 'blue'><i> Valid </i></font></li> "
                                "<ul>"
                                "<li>0.2 0.3</li>"
                                "<li>1  2</li>"
                                "</ul>"
                                "<li><font color = 'red'><i> Invalid</i></font></li>"
                                "<ul>"
                                "<li>0 -2</li>"
                                "<li> zeroes, negative numbers, mathematical operations like 3*5, M_PI-5 etc </li>"
                                "</ul>");
     ui->lineEdit_ub_ii->setToolTip(" Enter the <b> upper bound </b> for input"
                                "<li><i> You may use \":\", \",\",\"  \",\";\" as seperators </li>"
                                " <li><font color = 'blue'><i> Valid </i></font></li> "
                                "<ul>"
                                "<li>0.2 0.3</li>"
                                "<li>1  2</li>"
                                "</ul>"
                                "<li><font color = 'red'><i> Invalid</i></font></li>"
                                "<ul>"
                                "<li>0 -2</li>"
                                "<li> zeroes, negative numbers, mathematical operations like 3*5, M_PI-5 etc </li>"
                                "</ul>");


      // for Safety specification widget

     ui->lineEdit_safety_lb->setToolTip(" Enter the <b> lower bound </b> for safe set (compatible with state dimension)"
                                "<li><i> You may use \":\", \",\",\"  \",\";\" as seperators </li>"
                                " <li><font color = 'blue'><i> Valid </i></font></li> "
                                "<ul>""\n"
                                "<li>0.2 0.3</li>"
                                "<li>1  2</li>"
                                "</ul>"
                                "<li><font color = 'red'><i> Invalid</i></font></li>"
                                "<ul>"
                                "<li>0 -2</li>"
                                "<li> zeroes, negative numbers, mathematical operations like 3*5, M_PI-5 etc </li>"
                                "</ul>");
      ui->lineEdit_safety_ub->setToolTip(" Enter the <b> Upper bound </b> for safe set (compatible with state dimension)"
                                "<li><i> You may use \":\", \",\",\"  \",\";\" as seperators </li>"
                                " <li><font color = 'blue'><i> Valid </i></font></li> "
                                "<ul>""\n"
                                "<li>0.2 0.3</li>"
                                "<li>1  2</li>"
                                "</ul>"
                                "<li><font color = 'red'><i> Invalid</i></font></li>"
                                "<ul>"
                                "<li>0 -2</li>"
                                "<li> zeroes, negative numbers, mathematical operations like 3*5, M_PI-5 etc </li>"
                                "</ul>");

      // for target/reach specification widget.

     ui->lineEdit_target_lb->setToolTip(" Enter the <b> lower bound </b> for Target set (compatible with state dimension)"
                                "<li><i> You may use \":\", \",\",\"  \",\";\" as seperators </li>"
                                " <li><font color = 'blue'><i> Valid </i></font></li> "
                                "<ul>""\n"
                                "<li>0.2 0.3</li>"
                                "<li>1  2</li>"
                                "</ul>"
                                "<li><font color = 'red'><i> Invalid</i></font></li>"
                                "<ul>"
                                "<li>0 -2</li>"
                                "<li> zeroes, negative numbers, mathematical operations like 3*5, M_PI-5 etc </li>"
                                "</ul>");
     ui->lineEdit_target_ub->setToolTip(" Enter the <b> Upper bound </b> for safe set (compatible with state dimension)"
                                "<li><i> You may use \":\", \",\",\"  \",\";\" as seperators </li>"
                                " <li><font color = 'blue'><i> Valid </i></font></li> "
                                "<ul>""\n"
                                "<li>0.2 0.3</li>"
                                "<li>1  2</li>"
                                "</ul>"
                                "<li><font color = 'red'><i> Invalid</i></font></li>"
                                "<ul>"
                                "<li>0 -2</li>"
                                "<li> zeroes, negative numbers, mathematical operations like 3*5, M_PI-5 etc </li>"
                                "</ul>");

      // for Avoid specification widget.

      ui->textEdit_avoid->setToolTip(" Enter the <b> lower bound and upper bound  </b> for Avoid set (compatible with state dimension)"
                                   "<li><i> You may use \" ; \" as seperator for row and \"   \" or \" ,\" as seperator for each element </li>"
                                  " <li><font color = 'blue'><i> Example for state dimension 3 and 2 avoid  regions namely \n (lb11,lb12,lb13) ,(ub11,ub12,ub13) and \n  be (lb21,lb22,lb23) ,(ub21,ub22,ub23) </i></font></li> "
                                  "<ul>""\n"
                                  "<li> lb11 lb12 lb13 ub11 ub12 ub13</li>"
                                  "<li> lb21 lb22 lb23 ub21 ub22 ub23</li>");




 } // end of MAINWINDOW constructor.



// Destructor of Mainwindow

MainWindow::~MainWindow()
{
    delete ui;
    delete new_model;
}

void MainWindow::bddcode()
{

    // Saving name of file into variable of class Mainwindow , newfilename from class newfilename_1 and adjusting it for writing into simulate.cc and newfile.cc.
    newfilename=this->new_model->newfilename_1;
    bddmake(); // calling makefile function for generating makefile for the code.
    std::string filename;
    filename=this->new_model->pathoffolder;
    filename=filename.append("/");    // filename is of format : home/fmlab5/filename/

    std::string filename_simulate =filename;
    filename_simulate=filename_simulate.append("simulate.cc");
    filename_simulate="/"+filename_simulate;
    filename= filename.append(newfilename);
    filename=filename.append(".cc");
    filename="/"+filename;

    std::ofstream file(filename.c_str()); // file is the write type stream for writing into the newfilenmae.cc


    // Makingfile simulation.cc only when specifications and simulations are checked.
    if((ui->checkBox_add_simulation->isChecked())&&(flag_add_avoid==0||flag_add_target==0||flag_add_safety==0))
     {
        QString starting_Point=ui->lineEdit_sim_statrting_point->text();
        QStringList list= starting_Point.split(QRegExp("(\\s|\\n|\\r|\\,|\\:|\\;|\\[|\\])+"),QString::SkipEmptyParts);
        int i=0;
        if(list.count()>Dim_ss)
        {
         QMessageBox::critical(this, "Error","The starting point isn't compatible with the dimension");
         return;
        }
      foreach (starting_Point, list)
      sim_start[i++]=starting_Point.toDouble();
      std::ofstream f_sim(filename_simulate.c_str());
       if(f_sim.is_open())
       {
           f_sim<<headerfilelist.c_str();
           f_sim<<"const double xc=70; const double xl=3; const double rc=0.005; const double rl=0.05; const double ro=1; const double vs=1; const double mu=std::sqrt(2);";
           f_sim<<"\n\n\nconst int state_dim="<<Dim_ss<<";"<<std::endl;
           f_sim<<"const int input_dim="<<Dim_ii<<";"<<std::endl;
           f_sim<<"const double tau="<<tau<<";\n\n"<<std::endl;
           f_sim<<"using state_type = std::array<double,state_dim>;"<<std::endl
               <<"using input_type = std::array<double,input_dim>;\n"<<std::endl;
           f_sim<<"auto sys_post = [](state_type &x, const std::vector<double>& u) noexcept {"<<std::endl;
           if(flag_rungge_kutta_sys==1)
           {
           f_sim<<"auto rhs =[](state_type& xx,  const state_type &x, const std::vector<double>& u) noexcept {"<<sys_post.c_str()<<std::endl<<"};";
           f_sim<<"  scots::runge_kutta_fixed4(rhs,x,u,state_dim,tau,"<<rungekutta_step<<");"<<std::endl;
           }
           else
           f_sim<<rad_post.c_str()<<std::endl;
           f_sim<<"};"<<std::endl;
           f_sim<<"\nint main()\n { \n"
                <<"Cudd manager;"<<std::endl
               <<" BDD C;"<<std::endl
               <<" scots::SymbolicSet con;"<<std::endl
               <<"  if(!read_from_file(manager,con,C,\"controller\")) {"<<std::endl
               <<"     std::cout << \"Could not read controller from controller.scs\";"<<std::endl
               <<"     return 0;"<<std::endl
               <<"     }"<<std::endl;
           f_sim<<"std::cout << \"Simulation: \";"<<std::endl
               <<"state_type x={{";
           for(int i=0;i<list.count();i++)
           {
               if(i==list.count()-1)
                 f_sim<<sim_start[i];
               else
                 f_sim<<sim_start[i]<<" , ";
           }
           f_sim<<"}};"<<std::endl;
           if(flag_target_lbub==2&&flag_add_target==2)
           {
           f_sim<<"\n\n auto target=[](const state_type& x) noexcept {"<<std::endl;
           f_sim<<"  "<<std::endl
               <<"  "<<std::endl
               <<"    if( ";
           for(int i=0;i<Dim_ss;i++)
              {
               if(i==Dim_ss-1)
                 f_sim<<lb_target[i]<<"<=x["<<i<<"] && x["<<i<<"]<="<<ub_target[i]<<")";
               else
                 f_sim<<lb_target[i]<<"<=x["<<i<<"] && x["<<i<<"]<="<<ub_target[i]<<"&&";
               }
           f_sim<<"     "<<std::endl
               <<"       return true;"<<std::endl
               <<"      return false;"<<std::endl;
           f_sim<<"};"<<std::endl;
           f_sim<<"while(1){"<<std::endl
                <<"auto u = con.restriction(manager,C,x);"<<std::endl
                <<"std::cout";
           for(int i=0;i<Dim_ss;i++)
              { if(i==Dim_ss-1)
                   f_sim<<"<<x["<<i<<"]<<\"   \"<<std::endl;";
               else
                   f_sim<<"<<x["<<i<<"]<<\"   \"";
              }
           f_sim<<" sys_post(x,u);"<<std::endl
                <<"if(target(x)) {"<<std::endl;
           f_sim<<"std::cout<<\"Arrived:\"";
           for(int i=0;i<Dim_ss;i++)
              { if(i==Dim_ss-1)
                   f_sim<<"<<x["<<i<<"]<<\"   \"<<std::endl;"<<std::endl;
               else
                   f_sim<<"<<x["<<i<<"]<<\"   \"";
              }
           f_sim<<"break;"<<std::endl<<"}"<<std::endl;
           f_sim<<"}"<<std::endl;
           f_sim<<"return 1;"<<std::endl<<"}";
           }
           if(flag_safety==2&&flag_add_safety==2)
           {
             f_sim<<"for(int i=0; i<100; i++) {"<<std::endl
                  <<"auto u = con.restriction(manager,C,x);"<<std::endl;
             f_sim<<"std::cout";
             for(int i=0;i<Dim_ss;i++)
              { if(i==Dim_ss-1)
                f_sim<<"<<x["<<i<<"]<<\"   \"<<std::endl;";
               else
                f_sim<<"<<x["<<i<<"]<<\"   \"";
              }
              f_sim<<"\n sys_post(x,u);" <<std::endl;
              f_sim<<"}\n"<<"return 1;\n }";
           }
           if(flag_add_safety!=2&&flag_add_target!=2)
               f_sim<<"return 1;"<<std::endl<<"}";
           f_sim.close();
       }
       else
           QMessageBox::critical(this,"sorry","Couldn't generate the code for simulation");
    }// end of condition for adding simulation.

    if(file.is_open()) // writing to the filename.cc
     {
      file<<headerfilelist.c_str();
      file<<"const double xc=70; const double xl=3; const double rc=0.005; const double rl=0.05; const double ro=1; const double vs=1; const double mu=std::sqrt(2);";
      file<<"\n\n\nconst int state_dim="<<Dim_ss<<";"<<std::endl;
      file<<"const int input_dim="<<Dim_ii<<";"<<std::endl;
      file<<"const double tau="<<tau<<";\n\n"<<std::endl;
      file<<"using state_type = std::array<double,state_dim>;"<<std::endl
          <<"using input_type = std::array<double,input_dim>;\n"<<std::endl
          <<"using abs_type = scots::abs_type;"<<std::endl;

      file<<"auto sys_post = [](state_type &x, const input_type &u) noexcept {"<<std::endl;
      if(flag_rungge_kutta_sys==1)
      {
       file<<"auto rhs =[](state_type& xx,  const state_type &x, const input_type &u) noexcept {"<<sys_post.c_str()<<std::endl<<"};";
       file<<"  scots::runge_kutta_fixed4(rhs,x,u,state_dim,tau,"<<rungekutta_step<<");"<<std::endl;
      }
      else
       file<<rad_post.c_str()<<std::endl;
      file<<"};"<<std::endl;
      file<<"auto rad_post = [](state_type &r,const state_type& x, const input_type &u) noexcept {\n "<<std::endl;
      if(flag_rungge_kutta_rad==1)
      {
       file<<"auto rhs =[](state_type& rr,  const state_type &r, const input_type &u) noexcept {\n"<<rad_post.c_str()<<std::endl<<"};";
       file<<"scots::runge_kutta_fixed4(rhs,r,u,state_dim,tau,"<<rungekutta_step<<");";
      }
      else
       file<<rad_post.c_str()<<std::endl;
       file<<"\n};"<<std::endl;


      file<<"\nint main()\n { \n"
          <<"  TicToc tt;\n"<<std::endl
          <<"Cudd manager;"<<std::endl
          <<"manager.AutodynEnable();"<<std::endl
          <<"  state_type eta_ss={{";
       for(int i=0;i<Dim_ss;i++)
        { if(i!=Dim_ss-1)
            file<<eta_ss[i]<<",";
         else
           file<<eta_ss[i]<<"}};\n";
        }
      file<<"  state_type lb_ss={{";
      for(int i=0;i<Dim_ss;i++)
       {if(i!=Dim_ss-1)
         file<<lb_ss[i]<<",";
        else
        file<<lb_ss[i]<<"}};\n";
       }
      file<<"  state_type ub_ss={{";
      for(int i=0;i<Dim_ss;i++)
       {if(i!=Dim_ss-1)
         file<<ub_ss[i]<<",";
        else
        file<<ub_ss[i]<<"}};\n";
       }
     file<<"  scots::SymbolicSet ss_pre(manager,state_dim,lb_ss,ub_ss,eta_ss);"<<std::endl
         <<"  scots::SymbolicSet ss_post(manager,state_dim,lb_ss,ub_ss,eta_ss);"<<std::endl
         <<"  std::cout << \"Unfiorm grid details:\" << std::endl;"<<std::endl
         <<"  ss_pre.print_info();"<<std::endl;
     file<<"\n  input_type eta_ii={{";
       for(int i=0;i<Dim_ii;i++)
        { if(i!=Dim_ii-1)
          file<<eta_ii[i]<<",";
          else
          file<<eta_ii[i]<<"}};\n";
        }
    file<<"  input_type lb_ii={{";
      for(int i=0;i<Dim_ii;i++)
       {if(i!=Dim_ii-1)
        file<<lb_ii[i]<<",";
       else
       file<<lb_ii[i]<<"}};\n";
       }
    file<<"  input_type ub_ii={{";
     for(int i=0;i<Dim_ii;i++)
      {if(i!=Dim_ii-1)
       file<<ub_ii[i]<<",";
       else
      file<<ub_ii[i]<<"}};\n";
      }
    file<<"  scots::SymbolicSet ii(manager,input_dim,lb_ii,ub_ii,eta_ii);"<<std::endl
        <<"  std::cout << \"Unfiorm grid details:\" << std::endl;"<<std::endl
        <<"  ii.print_info();\n\n"<<std::endl;
    file<<"scots::SymbolicModel<state_type,input_type> sym_model(ss_pre,ii,ss_post);"<<std::endl
        <<"\n"<<std::endl
        <<"size_t no_trans;"<<std::endl;


   if(flag_avoid==2&&flag_add_avoid==2)
    {
       file<<"double H["<<avoidrows<<"]["<<Dim_ss*2<<"]= {"<<std::endl;
       for(int i=0;i<avoidrows;i++)
       { if(i==avoidrows-1)
          { file<<"{ ";
           for(int j=0;j<Dim_ss*2;j++)
            { if(j==(Dim_ss*2)-1)
                 file<<avoid[i][j];
             else
                 file<<avoid[i][j]<<" ,";
            }
            file<<" } "<<std::endl;
           }
         else
           { file<<"{ ";
            for(int j=0;j<Dim_ss*2;j++)
             { if(j==(Dim_ss*2)-1)
                  file<<avoid[i][j];
              else
                  file<<avoid[i][j]<<" ,";
              }
               file<<" } , "<<std::endl;
            }
        }
       file<<"   };"<<std::endl;
       file<<"  scots::SymbolicSet set;"<<std::endl;
       file<<"auto avoid = [&H,ss_pre](const abs_type& idx) {"<<std::endl
           <<"state_type x;"<<std::endl
           <<"ss_pre.itox(idx,x);"<<std::endl
           <<"for(int i=0; i<"<<avoidrows<<"; i++) {"<<std::endl
           <<"if(";
       for(int i=0;i<Dim_ss;i++)
       {
         file<<"(H[i]["<<i<<"])<=x["<<i<<"] &&";
       }
       int j=0; ;
       for(int i=Dim_ss; i<2*Dim_ss;i++ ,j++)
       { if(i==2*Dim_ss-1)
           file<<"(H[i]["<<i<<"])>=x["<<j<<"]";
         else
            file<<"(H[i]["<<i<<"])>=x["<<j<<"] &&";
       }
       file<<")"<<std::endl<<"    return true; }"<<std::endl<<"return false; \n  };"<<std::endl;
       file<<" BDD A = ss_pre.ap_to_bdd(manager,avoid);"<<std::endl;
       file<<"write_to_file(manager,ss_pre,A,\"obstacles\");"<<std::endl;
       file<<" set = scots::SymbolicSet(scots::SymbolicSet(ss_pre,ii),ss_post);"<<std::endl;
       file<<"tt.tic();"<<std::endl
           <<"BDD tf =sym_model.compute_gb(manager,sys_post,rad_post,avoid,no_trans);"<<std::endl
           <<"tt.toc();"<<std::endl
           <<"std::cout << \"No of Transitions \" << no_trans  << std::endl;"<<std::endl;
       file<<"scots::write_to_file(manager,set,tf,\"tf\");"<<std::endl;

         }
    else
     {
       file<<"tt.tic(); \nBDD tf =sym_model.compute_gb(manager,sys_post,rad_post,no_trans);"<<std::endl
           <<"tt.toc();"<<std::endl
           <<"std::cout << \"No of Transitions \" << no_trans  << std::endl;"<<std::endl;
       //file<<"manager.DebugCheck();"<<std::endl;
     }

    if(flag_target_lbub==2&&flag_add_target==2)  // adding reachability specification.--------------------
    {
        QMessageBox::information(this,"Hello","Target specification for upper bound and lower bound successfully added !");
        file<<"\n\n auto target=[&ss_pre](const scots::abs_type& idx) noexcept {"<<std::endl;
        file<<"    state_type x;"<<std::endl
            <<"    ss_pre.itox(idx,x);"<<std::endl
            <<"    if( ";
            for(int i=0;i<Dim_ss;i++)
            {
              if(i==Dim_ss-1)
                 file<<lb_target[i]<<"<=x["<<i<<"] && x["<<i<<"]<="<<ub_target[i]<<")";
              else
                  file<<lb_target[i]<<"<=x["<<i<<"] && x["<<i<<"]<="<<ub_target[i]<<"&&";
             }
        file<<"     "<<std::endl
            <<"       return true;"<<std::endl
            <<"      return false;"<<std::endl;
        file<<"};"<<std::endl;
        file<<"BDD T = ss_pre.ap_to_bdd(manager,target);"<<std::endl;
        file<<" write_to_file(ss_pre,target,\"target\");"<<std::endl
            <<" std::cout << \"  Synthesis: \";"<<std::endl
            <<"scots::EnfPre enf_pre(manager,tf,sym_model);"

            <<" tt.tic();"<<std::endl
            <<"BDD X=manager.bddOne();"<<std::endl
            <<"BDD XX =manager.bddZero();"<<std::endl
            <<"BDD C = manager.bddZero();"<<std::endl
            <<"BDD U = ii.get_cube(manager);"<<std::endl
            <<"size_t i;"<<std::endl
            <<"for(i=1; XX != X; i++ ) {"<<std::endl
            <<"X=XX;"<<std::endl
            <<"XX=enf_pre(X) | T;"<<std::endl
            <<"/* new (state/input) pairs */"<<std::endl
            <<"BDD N = XX & (!(C.ExistAbstract(U)));"<<std::endl
            <<"/* add new (state/input) pairs to the controller */"<<std::endl
            <<"C=C | N;"<<std::endl
            <<"/* print progress */"<<std::endl
            <<"scots::print_progress(i);"<<std::endl
            <<"}"<<std::endl
            <<"std::cout << \"Number of iterations: \" << i << std::endl;"<<std::endl
            <<"tt.toc();"<<std::endl
            <<"std::cout << \"Winning domain size: \" << ss_pre.get_size(manager,C) << std::endl;"<<std::endl
            <<"scots::SymbolicSet controller(ss_pre,ii);"<<std::endl
            <<"std::cout << \"Write controller to controller.scs \";"<<std::endl
            <<"if(write_to_file(manager,controller,C,\"controller\"))"<<std::endl
            <<"std::cout << \"Done. \";"<<std::endl
            <<"return 1;"<<std::endl;
     }
    else if(flag_safety==2&&flag_add_safety==2) // adding safety configuration.
     {   QMessageBox::information(this,"Hello","Safety specification for upper bound and lower bound successfully added !");
          file<<"\n\n auto safe=[&ss_pre](const scots::abs_type& idx) noexcept {"<<std::endl;
          file<<"    state_type x;"<<std::endl
              <<"    ss_pre.itox(idx,x);"<<std::endl
              <<"    if( ";
              for(int i=0;i<Dim_ss;i++)
              {
                if(i==Dim_ss-1)
                   file<<lb_safety[i]<<"<=x["<<i<<"] && x["<<i<<"]<="<<ub_safety[i]<<")";
                else
                    file<<lb_safety[i]<<"<=x["<<i<<"] && x["<<i<<"]<="<<ub_safety[i]<<"&&";
               }
          file<<"     "<<std::endl
              <<"       return true;"<<std::endl
              <<"      return false;"<<std::endl;
          file<<"};"<<std::endl;

          file<<"BDD S = ss_pre.ap_to_bdd(manager,safe);"<<std::endl
              <<"scots::EnfPre enf_pre(manager,tf,sym_model);"<<std::endl
              <<"tt.tic();"<<std::endl
              <<"size_t i,j;"<<std::endl
              <<"/* outer fp*/"<<std::endl
              <<"BDD Z=manager.bddOne();"<<std::endl
              <<"BDD ZZ=manager.bddZero();"<<std::endl
              <<"/* inner fp*/"<<std::endl
              <<"BDD Y=manager.bddZero();"<<std::endl
              <<"BDD YY=manager.bddOne();"<<std::endl
              <<"/* the controller */"<<std::endl
              <<"BDD C=manager.bddZero();"<<std::endl
              <<"/* helper */"<<std::endl
              <<"BDD U=ii.get_cube(manager);"<<std::endl
              <<"/* as long as not converged */"<<std::endl
              <<"for(i=1; ZZ != Z; i++) {"<<std::endl
              <<"Z=ZZ;"<<std::endl
              <<"BDD preZ=enf_pre(Z);"<<std::endl
              <<"/* init inner fp */"<<std::endl
              <<"YY = manager.bddOne();"<<std::endl
              <<"for(j=1; YY != Y; j++) {"<<std::endl
              <<"  Y=YY;"<<std::endl
              <<"  YY = ( enf_pre(Y) & S ) | preZ;"<<std::endl
              <<"}"<<std::endl
              <<"ZZ=YY;"<<std::endl;

          file<<"std::cout << \"Inner: \" << j << std::endl;"<<std::endl
              <<"/* remove all state-input pairs that have been added"<<std::endl
              <<" * to the controller already in the previous iterations */"<<std::endl
              <<"BDD N = ZZ & (!(C.ExistAbstract(U)));"<<std::endl
              <<"/* add the remaining pairs to the controller */"<<std::endl
              <<"C=C | N;"<<std::endl
              <<"}"<<std::endl;

          file<<"std::cout << \"Outer: \" << i << std::endl;"<<std::endl
              <<"tt.toc();"<<std::endl
              <<"std::cout << \"Winning domain size: \" << ss_pre.get_size(manager,C) << std::endl;"<<std::endl
              <<"\n\n /* symbolic set for the controller */"<<std::endl
              <<"scots::SymbolicSet controller(ss_pre,ii);"<<std::endl
              <<"std::cout << \"Write controller to controller.scs \"<<std::endl;"<<std::endl
              <<"if(write_to_file(manager,controller,C,\"controller\"))"<<std::endl
              <<"std::cout << \"Done. \"<<std::endl;"<<std::endl
              <<"return 1;"<<std::endl;


        }
    file<<"}";
    file.close();
  } // writing to the filenam.cc ends
  else // Filename.cc couldn't open hence showing appropriate message.
    std::cout<<"File for writing the main code didn't open";


}

//Pushbutton for generating the code under Generate code widget Name of pushbutton: " Generate code ".

void MainWindow::on_pushButton_clicked()
{

    QMessageBox::information(this,"Hello","Generating the code");

    // Checking what all specifications are selected ,it is checked whether any specification is added in generate code tab and if yes then are the specification parameters.
    // if not then suitable message is displayed.
    // Begin checking of specification.
    flag_add_avoid=0;
    flag_add_safety=0;
    flag_add_target=0;

    if(ui->checkBox_add_avoid->isChecked()&&ui->checkBox_add_safety->isChecked()&&ui->checkBox_add_target->isChecked()) // All three specification can't be added altogether.
    {
         QMessageBox::critical(this,"Error","Can't select all three specification");
         return;
    }
    else if(ui->checkBox_add_safety->isChecked()&&ui->checkBox_add_target->isChecked())                                // Safety and reachability can't be added together.
    {
        QMessageBox::critical(this,"Error","Can't select all reachability and safety together");
        return;
    }


     // since combination of specification is checked , checking for whether the chosen specifications parameters are added or not ,if not then exit from function.
    if(ui->checkBox_add_avoid->isChecked())
    {
        if(flag_avoid!=2)
        {
            QMessageBox::critical(this,"Specification missing","Add Avoid specification");
            return;
        }
        flag_add_avoid=2;

     }
    if(ui->checkBox_add_target->isChecked())
    {
        if(flag_target_lbub!=2)
        {
            QMessageBox::critical(this,"Specification missing","Add target specification");
            return;
        }
        flag_add_target=2;
     }
    if(ui->checkBox_add_safety->isChecked())
    {
        if(flag_safety!=2)
        {
            QMessageBox::critical(this,"Specification missing","Add safety specification");
            return;
        }
        flag_add_safety=2;
     }

   // End of checking specification.

    makefile(); // calling makefile function for generating makefile for the code.

    if(ui->radioButton_BDD->isChecked())
    {
        bddcode();
        return;
    }

      /*std::ifstream file1 ("newfilename.txt");
        if(file1.is_open())
              {
               std::getline(file1,newfilename);
               file1.close();
              }
        else
            QMessageBox::critical(this,"Error", "Couldnt get name of model");
       */

     // Saving name of file into variable of class Mainwindow , newfilename from class newfilename_1 and adjusting it for writing into simulate.cc and newfile.cc.
     newfilename=this->new_model->newfilename_1;

     std::string filename;
     filename=this->new_model->pathoffolder;
     filename=filename.append("/");    // filename is of format : home/fmlab5/filename/


   /*   rad_post="\nauto rhs =[](state_type& rr,  const state_type &r, const input_type &u) noexcept "----xxxxxxxxxxxxxxxxx
                         "\n{"
                         "\n if(u[0]==1) {\n"
                         "\n   rr[0]=-rl/xl*r[0];"
                         "\n    rr[1]=-1/(xc*(ro+rc))*r[1];"
                         "\n             } "
                         "\n    else {"
                         "\n       rr[0]=-(1/xl)*(rl+ro*rc/(ro+rc))*r[0]+(1/xl)*ro/(5*(ro+rc))*r[1];"
                         "\n       rr[1]=5*(1/xc)*ro/(ro+rc)*r[0]-(1/xc)*(1/(ro+rc))*r[1];"
                         "\n         }"
                         "\n};";
    sys_post="\n\n auto rhs =[](state_type& xx,  const state_type &x, const input_type &u) noexcept "
                         "\n {"
                         "\n    if(u[0]==1) {"
                         "\n      xx[0]=-rl/xl*x[0]+vs/xl;"
                         "\n      xx[1]=-1/(xc*(ro+rc))*x[1];"
                         "\n                }"
                         "\n    else {"
                         "\n      xx[0]=-(1/xl)*(rl+ro*rc/(ro+rc))*x[0]-(1/xl)*ro/(5*(ro+rc))*x[1]+vs/xl;"
                         "\n      xx[1]=(1/xc)*5*ro/(ro+rc)*x[0]-(1/xc)*(1/(ro+rc))*x[1];"
                         "\n         }"
                         "\n };";*/
   //std::string filename="/NewMOdel";filename=filename.append(newfilename);filename=filename.append("/"); -----xxxxxx

   std::string filename_simulate =filename;
   filename_simulate=filename_simulate.append("simulate.cc");
   filename_simulate="/"+filename_simulate;
   filename= filename.append(newfilename);
   filename=filename.append(".cc");
   filename="/"+filename;

   // filename_simulate = /home/fmalb5/newfilename/simulate.cc   ------xxxxxx
   // filename = /home/fmlab5/newfilename/newfilename.cc              ----xxxxxx



   /*QString treename=QString::fromStdString(newfilename);                     ---XXXXXXX
   ui->treeWidget_newmodel->setHeaderLabel(treename);*/


   std::ofstream file(filename.c_str()); // file is the write type stream for writing into the newfilenmae.cc



   if((ui->checkBox_add_simulation->isChecked())&&(flag_add_avoid==0||flag_add_target==0||flag_add_safety==0)) // Makingfile simulation.cc only when specifications and simulations are checked.
   {   QString starting_Point=ui->lineEdit_sim_statrting_point->text();
       QStringList list= starting_Point.split(QRegExp("(\\s|\\n|\\r|\\,|\\:|\\;|\\[|\\])+"),QString::SkipEmptyParts);
       int i=0;
       if(list.count()>Dim_ss)
       {
           QMessageBox::critical(this, "Error","The starting point isn't compatible with the dimension");
           return;
       }
       foreach (starting_Point, list)
               sim_start[i++]=starting_Point.toDouble();
     std::ofstream f_sim(filename_simulate.c_str());
      if(f_sim.is_open())
      {
          f_sim<<headerfilelist.c_str();
          f_sim<<"const double xc=70; const double xl=3; const double rc=0.005; const double rl=0.05; const double ro=1; const double vs=1; const double mu=std::sqrt(2);";
          f_sim<<"\n\n\nconst int state_dim="<<Dim_ss<<";"<<std::endl;
          f_sim<<"const int input_dim="<<Dim_ii<<";"<<std::endl;
          f_sim<<"const double tau="<<tau<<";\n\n"<<std::endl;
          f_sim<<"using state_type = std::array<double,state_dim>;"<<std::endl
              <<"using input_type = std::array<double,input_dim>;\n"<<std::endl;
          f_sim<<"auto sys_post = [](state_type &x, const input_type &u) noexcept {"<<std::endl;
          if(flag_rungge_kutta_sys==1)
          {
          f_sim<<"auto rhs =[](state_type& xx,  const state_type &x, const input_type &u) noexcept {"<<sys_post.c_str()<<std::endl<<"};";
          f_sim<<"  scots::runge_kutta_fixed4(rhs,x,u,state_dim,tau,"<<rungekutta_step<<");"<<std::endl;
          }
          else
          f_sim<<rad_post.c_str()<<std::endl;
          f_sim<<"};"<<std::endl;
          f_sim<<"\nint main()\n { \n"
              <<" scots::StaticController con;"<<std::endl
              <<"  if(!read_from_file(con,\"controller\")) {"<<std::endl
              <<"     std::cout << \"Could not read controller from controller.scs\";"<<std::endl
              <<"     return 0;"<<std::endl
              <<"     }"<<std::endl;
          f_sim<<"std::cout << \"Simulation: \";"<<std::endl
              <<"state_type x={{";
          for(int i=0;i<list.count();i++)
          {
              if(i==list.count()-1)
                f_sim<<sim_start[i];
              else
                f_sim<<sim_start[i]<<" , ";
          }
          f_sim<<"}};"<<std::endl;
          if(flag_target_lbub==2&&flag_add_target==2)
          {
          f_sim<<"\n\n auto target=[](const state_type& x) noexcept {"<<std::endl;
          f_sim<<"  "<<std::endl
              <<"  "<<std::endl
              <<"    if( ";
          for(int i=0;i<Dim_ss;i++)
             {
              if(i==Dim_ss-1)
                f_sim<<lb_target[i]<<"<=x["<<i<<"] && x["<<i<<"]<="<<ub_target[i]<<")";
              else
                f_sim<<lb_target[i]<<"<=x["<<i<<"] && x["<<i<<"]<="<<ub_target[i]<<"&&";
              }
          f_sim<<"     "<<std::endl
              <<"       return true;"<<std::endl
              <<"      return false;"<<std::endl;
          f_sim<<"};"<<std::endl;
          f_sim<<"while(1){"<<std::endl
               <<"std::vector<input_type> u = con.get_control<state_type,input_type>(x);"<<std::endl
               <<"std::cout";
          for(int i=0;i<Dim_ss;i++)
             { if(i==Dim_ss-1)
                  f_sim<<"<<x["<<i<<"]<<\"   \"<<std::endl;";
              else
                  f_sim<<"<<x["<<i<<"]<<\"   \"";
             }
          f_sim<<" sys_post(x,u[0]);"<<std::endl
               <<"if(target(x)) {"<<std::endl;
          f_sim<<"std::cout<<\"Arrived:\"";
          for(int i=0;i<Dim_ss;i++)
             { if(i==Dim_ss-1)
                  f_sim<<"<<x["<<i<<"]<<\"   \"<<std::endl;"<<std::endl;
              else
                  f_sim<<"<<x["<<i<<"]<<\"   \"";
             }
          f_sim<<"break;"<<std::endl<<"}"<<std::endl;
          f_sim<<"}"<<std::endl;
          f_sim<<"return 1;"<<std::endl<<"}";
          }
          if(flag_safety==2&&flag_add_safety==2)
          {
            f_sim<<"for(int i=0; i<100; i++) {"<<std::endl
                 <<"std::vector<input_type> u = con.get_control<state_type,input_type>(x);"<<std::endl;
            f_sim<<"std::cout";
            for(int i=0;i<Dim_ss;i++)
             { if(i==Dim_ss-1)
               f_sim<<"<<x["<<i<<"]<<\"   \"<<std::endl;";
              else
               f_sim<<"<<x["<<i<<"]<<\"   \"";
             }
             f_sim<<"\n sys_post(x,u[0]);" <<std::endl;
             f_sim<<"}\n"<<"return 1;\n }";
          }
          if(flag_add_safety!=2&&flag_add_target!=2)
              f_sim<<"return 1;"<<std::endl<<"}";
          f_sim.close();
      }
      else
          QMessageBox::critical(this,"sorry","Couldn't generate the code for simulation");

 }// end of condition for adding simulation.

  if(file.is_open()) // writing to the filename.cc
   {
    file<<headerfilelist.c_str();
    file<<"const double xc=70; const double xl=3; const double rc=0.005; const double rl=0.05; const double ro=1; const double vs=1; const double mu=std::sqrt(2);";
    file<<"\n\n\nconst int state_dim="<<Dim_ss<<";"<<std::endl;
    file<<"const int input_dim="<<Dim_ii<<";"<<std::endl;
    file<<"const double tau="<<tau<<";\n\n"<<std::endl;
    file<<"using state_type = std::array<double,state_dim>;"<<std::endl
        <<"using input_type = std::array<double,input_dim>;\n"<<std::endl
        <<"using abs_type = scots::abs_type;"<<std::endl;

    file<<"auto sys_post = [](state_type &x, const input_type &u) noexcept {"<<std::endl;
    if(flag_rungge_kutta_sys==1)
    {
     file<<"auto rhs =[](state_type& xx,  const state_type &x, const input_type &u) noexcept {"<<sys_post.c_str()<<std::endl<<"};";
     file<<"  scots::runge_kutta_fixed4(rhs,x,u,state_dim,tau,"<<rungekutta_step<<");"<<std::endl;
    }
    else
     file<<rad_post.c_str()<<std::endl;
    file<<"};"<<std::endl;
    file<<"auto rad_post = [](state_type &r,const state_type& x, const input_type &u) noexcept {\n "<<std::endl;
    if(flag_rungge_kutta_rad==1)
    {
     file<<"auto rhs =[](state_type& rr,  const state_type &r, const input_type &u) noexcept {\n"<<rad_post.c_str()<<std::endl<<"};";
     file<<"scots::runge_kutta_fixed4(rhs,r,u,state_dim,tau,"<<rungekutta_step<<");";
    }
    else
     file<<rad_post.c_str()<<std::endl;
     file<<"\n};"<<std::endl;


    file<<"\nint main()\n { \n"
        <<"  TicToc tt;\n"<<std::endl
        <<"  state_type eta_ss={{";
     for(int i=0;i<Dim_ss;i++)
      { if(i!=Dim_ss-1)
          file<<eta_ss[i]<<",";
       else
         file<<eta_ss[i]<<"}};\n";
      }
    file<<"  state_type lb_ss={{";
    for(int i=0;i<Dim_ss;i++)
     {if(i!=Dim_ss-1)
       file<<lb_ss[i]<<",";
      else
      file<<lb_ss[i]<<"}};\n";
     }
    file<<"  state_type ub_ss={{";
    for(int i=0;i<Dim_ss;i++)
     {if(i!=Dim_ss-1)
       file<<ub_ss[i]<<",";
      else
      file<<ub_ss[i]<<"}};\n";
     }
   file<<"  scots::UniformGrid ss(state_dim,lb_ss,ub_ss,eta_ss);"<<std::endl
       <<"  std::cout << \"Unfiorm grid details:\" << std::endl;"<<std::endl
       <<"  ss.print_info();"<<std::endl;
   file<<"\n  input_type eta_ii={{";
     for(int i=0;i<Dim_ii;i++)
      { if(i!=Dim_ii-1)
        file<<eta_ii[i]<<",";
        else
        file<<eta_ii[i]<<"}};\n";
      }
  file<<"  input_type lb_ii={{";
    for(int i=0;i<Dim_ii;i++)
     {if(i!=Dim_ii-1)
      file<<lb_ii[i]<<",";
     else
     file<<lb_ii[i]<<"}};\n";
     }
  file<<"  input_type ub_ii={{";
   for(int i=0;i<Dim_ii;i++)
    {if(i!=Dim_ii-1)
     file<<ub_ii[i]<<",";
     else
    file<<ub_ii[i]<<"}};\n";
    }
  file<<"  scots::UniformGrid ii(input_dim,lb_ii,ub_ii,eta_ii);"<<std::endl
      <<"  std::cout << \"Unfiorm grid details:\" << std::endl;"<<std::endl
      <<"  ii.print_info();\n\n"<<std::endl;

  file<<"  scots::TransitionFunction tf;"<<std::endl
      <<"  scots::Abstraction<state_type,input_type> abs(ss,ii);"<< std::endl;
 if(flag_avoid==2&&flag_add_avoid==2)
  {
     file<<"double H["<<avoidrows<<"]["<<Dim_ss*2<<"]= {"<<std::endl;
     for(int i=0;i<avoidrows;i++)
     { if(i==avoidrows-1)
        { file<<"{ ";
         for(int j=0;j<Dim_ss*2;j++)
          { if(j==(Dim_ss*2)-1)
               file<<avoid[i][j];
           else
               file<<avoid[i][j]<<" ,";
          }
          file<<" } "<<std::endl;
         }
       else
         { file<<"{ ";
          for(int j=0;j<Dim_ss*2;j++)
           { if(j==(Dim_ss*2)-1)
                file<<avoid[i][j];
            else
                file<<avoid[i][j]<<" ,";
            }
             file<<" } , "<<std::endl;
          }
      }
     file<<"   };"<<std::endl;
     file<<"auto avoid = [&H,ss,eta_ss](const abs_type& idx) {"<<std::endl
         <<"state_type x;"<<std::endl
         <<"ss.itox(idx,x);"<<std::endl
         <<"for(int i=0; i<"<<avoidrows<<"; i++) {"<<std::endl
         <<"if(";
     for(int i=0;i<Dim_ss;i++)
     {
       file<<"(H[i]["<<i<<"])<=x["<<i<<"] &&";
     }
     int j=0; ;
     for(int i=Dim_ss; i<2*Dim_ss;i++ ,j++)
     { if(i==2*Dim_ss-1)
         file<<"(H[i]["<<i<<"])>=x["<<j<<"]";
       else
          file<<"(H[i]["<<i<<"])>=x["<<j<<"] &&";
     }
     file<<")"<<std::endl<<"    return true; }"<<std::endl<<"return false; \n  };"<<std::endl;
     file<<"write_to_file(ss,avoid,\"obstacles\");"<<std::endl;
     file<<"abs.compute_gb(tf,sys_post, rad_post ,avoid);"<<std::endl;

       }
  else
    file<<"abs.compute_gb(tf,sys_post, rad_post);";

  if(flag_target_lbub==2&&flag_add_target==2)  // adding reachability specification.--------------------
  {
      QMessageBox::information(this,"Hello","Target specification for upper bound and lower bound successfully added !");
      file<<"\n\n auto target=[&ss](const scots::abs_type& idx) noexcept {"<<std::endl;
      file<<"    state_type x;"<<std::endl
          <<"    ss.itox(idx,x);"<<std::endl
          <<"    if( ";
          for(int i=0;i<Dim_ss;i++)
          {
            if(i==Dim_ss-1)
               file<<lb_target[i]<<"<=x["<<i<<"] && x["<<i<<"]<="<<ub_target[i]<<")";
            else
                file<<lb_target[i]<<"<=x["<<i<<"] && x["<<i<<"]<="<<ub_target[i]<<"&&";
           }
      file<<"     "<<std::endl
          <<"       return true;"<<std::endl
          <<"      return false;"<<std::endl;
      file<<"};"<<std::endl;
      file<<" write_to_file(ss,target,\"target\");"<<std::endl
          <<" std::cout << \"  Synthesis: \";"<<std::endl
          <<" tt.tic();"<<std::endl
          <<" scots::WinningDomain win = scots::solve_reachability_game(tf,target);"<<std::endl
          <<" tt.toc();"<<std::endl
          <<" std::cout << \"Winning domain size: \" << win.get_size() << std::endl;"<<std::endl;
      file<<" std::cout << \"Write controller to controller.scs \";"<<std::endl
          <<" if(write_to_file(scots::StaticController(ss,ii,std::move(win)),\"controller\"))"<<std::endl
          <<"std::cout << \"Done.\";"<<std::endl
          <<"return 1;"<<std::endl;
   }
  else if(flag_safety==2&&flag_add_safety==2) // adding safety configuration.
   {   QMessageBox::information(this,"Hello","Safety specification for upper bound and lower bound successfully added !");
        file<<"\n\n auto safeset=[&ss](const scots::abs_type& idx) noexcept {"<<std::endl;
        file<<"    state_type x;"<<std::endl
            <<"    ss.itox(idx,x);"<<std::endl
            <<"    if( ";
            for(int i=0;i<Dim_ss;i++)
            {
              if(i==Dim_ss-1)
                 file<<lb_safety[i]<<"<=x["<<i<<"] && x["<<i<<"]<="<<ub_safety[i]<<")";
              else
                  file<<lb_safety[i]<<"<=x["<<i<<"] && x["<<i<<"]<="<<ub_safety[i]<<"&&";
             }
        file<<"     "<<std::endl
            <<"       return true;"<<std::endl
            <<"      return false;"<<std::endl;
        file<<"};"<<std::endl;
        file<<" write_to_file(ss,safeset,\"safeset\");"<<std::endl
            <<" std::cout << \"  Synthesis: \";"<<std::endl
            <<" tt.tic();"<<std::endl
            <<" scots::WinningDomain win = scots::solve_invariance_game(tf,safeset);"<<std::endl
            <<" tt.toc();"<<std::endl
            <<" std::cout << \"Winning domain size: \" << win.get_size() << std::endl;"<<std::endl;
        file<<" std::cout << \"Write controller to controller.scs \";"<<std::endl
            <<" if(write_to_file(scots::StaticController(ss,ii,std::move(win)),\"controller\"))"<<std::endl
            <<"std::cout << \"Done.\";"<<std::endl
            <<"return 1;"<<std::endl;
      }
  file<<"}";
  file.close();
} // writing to the filenam.cc ends
else // Filename.cc couldn't open hence showing appropriate message.
  std::cout<<"File for writing the main code didn't open";
}


// Pushbutton: Ok in input parameters widget,Function for taking input parameters and saving it in file named input_param.txt .
void MainWindow::on_pushButton_input_parameters_clicked()
{
   if(this->new_model->flag_filename_entered>=1)
 {
    // Taking the input parameters in format of QString
    QString dim = ui->spinBox_dim_ii->text();
    QString eta=ui->lineEdit_eta_ii->text();
    QString lb=ui->lineEdit_lb_ii->text() ;
    QString ub=ui->lineEdit_ub_ii->text();

    // defining flags for checking whether the parameters added are conmpatible or not ,O = ok & 1= ok.
    int flag_dim=0;
    int flag_eta=0;
    int flag_ub=0;
    int flag_lb=0;

    //checking whether dimension is greater than zero, toInt function ensures that dimension is integer irrespective of user input.
    if(dim.toInt()<=0)
       {
        QMessageBox::critical(this,"Error", "Dimension cant be zero or negative");
        flag_dim=1;
        return;
       }
    // since dimension is a natural number saving it into variable Dim_ii.
    Dim_ii=dim.toInt();

    // ii , ll and uu are respectively number of elements in the string containing eta, lower bound and upperbound , empty spaces and other delimiters are ignored.
    int ii = eta.split(QRegExp("(\\s|\\n|\\r|\\,|\\:|\\;|\\[|\\])+"), QString::SkipEmptyParts).count(); // number of elements in eta
    int ll= lb.split(QRegExp("(\\s|\\n|\\r|\\,|\\:|\\;|\\[|\\])+"), QString::SkipEmptyParts).count(); // number of elements in lb
    int uu = ub.split(QRegExp("(\\s|\\n|\\r|\\,|\\:|\\;|\\[|\\])+"), QString::SkipEmptyParts).count();// number of elements in ub

    // checking whether the ii ,ll and uu matches with Dim_ss or not.
    if(Dim_ii!=ii||Dim_ii!=ll||Dim_ii!=uu)
      {
        flag_dim=1;
        QMessageBox::critical(this,"Error", "input parameters do not match with the dimension");
        return;
      }
    // Saving these elements in Qstring format to array types defined in Mainwindow class definition (i.e. eta_ii ,lb_ii ,ub_ii ) and Checking further elements of eta_ii , lb_ii and ub_ii for compatability.
    // namely any element of eta_ii can't be zero or negative, any element of lower bound can't be greater than upperbound and any element of eta can't be greater than the difference between the respective element of ub_ii and lb_ii.
       QStringList list_eta= eta.split(QRegExp("(\\s|\\n|\\r|\\,|\\:|\\;|\\[|\\])+"),QString::SkipEmptyParts);
       int i=0;
       foreach (eta, list_eta)
               eta_ii[i++]=eta.toDouble();
       QStringList list_lb= lb.split(QRegExp("(\\s|\\n|\\r|\\,|\\:|\\;|\\[|\\])+"),QString::SkipEmptyParts);
       i=0;
       foreach (lb, list_lb)
               lb_ii[i++]=lb.toDouble();

       QStringList list_ub= ub.split(QRegExp("(\\s|\\n|\\r|\\,|\\:|\\;|\\[|\\])+"),QString::SkipEmptyParts);
        i=0;
       foreach (ub, list_ub)
               ub_ii[i++]=ub.toDouble();

       i=0;
       while(i<Dim_ii)
       {
           if(ub_ii[i]<lb_ii[i])
              { flag_ub=1;
                 flag_lb=1;
                 QMessageBox::critical(this,"Error", "Any element of lower bound can't be greater than any element of upper bound");
                 break;
              }
           if(ub_ii[i]-lb_ii[i]<eta_ii[i])
              { flag_eta=1;
               QMessageBox::critical(this,"Error", "Difference between the repective element of upper bound and lower bound can't be less than respective grid radius.");
                 break;
              }
           if(eta_ii[i]<=0)
             {
               flag_eta=1;
                QMessageBox::critical(this,"Error", "No dimension can have grid radius less than or equal to zero. ");
               break;
             }

           i=i+1;
       }

   if(flag_dim==1||flag_ub==1||flag_lb==1||flag_eta==1)
      {
         flag_input_parameters=1;
         QMessageBox::critical(this,"Error", "please enter the parameters again");
         ui->textBrowser_status->setText("Please add the input parameters again");
         return;
      }
  // At this point all sorts of checking terminates and the values are shown to the user in status bar + stored into the file for open model functionality.
         else
      {
       // Saving input parameters into text file for loading.
       std::string parameters_filename="/"+this->new_model->pathoffolder+"/input_param.txt";
       std::ofstream file_input(parameters_filename.c_str());
       if(file_input.is_open())
       {
           file_input<<Dim_ii<<" ";
           for(int i=0;i<Dim_ii;i++)
               file_input<<eta_ii[i]<<" ";
           for(int i=0;i<Dim_ii;i++)
               file_input<<lb_ii[i]<<" ";
           for(int i=0;i<Dim_ii;i++)
               file_input<<ub_ii[i]<<" ";
           file_input.close();
       }
       else
        {
           QMessageBox::critical(this,"ALert","couldnt write input parameters into the file , so open model functionality may not work on this model.");
           return;
        }

       flag_input_parameters=2; // it means all the parameters were successfully added and stored in the file.
       QMessageBox::information(this,"Hello", "Input Parameters added successfully !");
       ui->textBrowser_status->setText(" Input Parameters added successfully, kindly recheck them here (parameters are readjusted in scots, so recheck them once u run the generated code.");
       ui->textBrowser_status->append("Dimension is :");
       ui->textBrowser_status->append("\t"+QString::number(Dim_ii));
       ui->textBrowser_status->append("Grid Radius (eta) is :");

        eta ="\t ";
       for(int i=0;i<Dim_ii;i++)
       {  eta =eta+"  "+QString::number(eta_ii[i]);

       }
       ui->textBrowser_status->append(eta);
       ui->textBrowser_status->append("Lower Bound  is :");
        lb ="\t ";
       for(int i=0;i<Dim_ii;i++)
       {   lb =lb+"  "+QString::number(lb_ii[i]);
       }
       ui->textBrowser_status->append(lb);
       ui->textBrowser_status->append("Upper Bound is :");
       ub="\t";

       for(int i=0;i<Dim_ii;i++)
       {
           ub =ub+"  "+QString::number(ub_ii[i]);

       }
       ui->textBrowser_status->append(ub);
       ui->textBrowser_status->append("-----------------------------------------------------------");
       ui->new_model_stacked_widget->setCurrentIndex(1);

    }
  }// end of if for new model.

}


// Pushbutton: Ok in state parameters widget,Function for taking state parameters and saving it in file named state_param.txt .
void MainWindow::on_pushButton_state_parameters_clicked()
{
   if(this->new_model->flag_filename_entered>=1) // Functionality for new model. Rest of the comments same as that for above function.
   {
      QString dim = ui->spinBox_dim_ss->text();
      QString eta=ui->lineEdit_eta_ss->text();
      QString lb=ui->lineEdit_lb_ss->text() ;
      QString ub=ui->lineEdit_ub_ss->text();


      int flag_dim=0;
      int flag_eta=0;
      int flag_ub=0;
      int flag_lb=0;
      if(dim.toInt()<=0)
         {
          QMessageBox::critical(this,"Error", "Dimension cant be zero or negative");
          flag_dim=1;
          return;
         }

      Dim_ss=dim.toInt();

      int ii = eta.split(QRegExp("(\\s|\\n|\\r|\\,|\\:|\\;|\\[|\\])+"), QString::SkipEmptyParts).count(); // number of elements in eta
      int ll= lb.split(QRegExp("(\\s|\\n|\\r|\\,|\\:|\\;|\\[|\\])+"), QString::SkipEmptyParts).count(); // number of elements in lb
      int uu = ub.split(QRegExp("(\\s|\\n|\\r|\\,|\\:|\\;|\\[|\\])+"), QString::SkipEmptyParts).count();// number of elements in ub


      if(Dim_ss!=ii||Dim_ss!=ll||Dim_ss!=uu)
        {
          flag_dim=1;
          QMessageBox::critical(this,"Error", "state parameters do not match with the dimension");
          return;
        }


         QStringList list_eta= eta.split(QRegExp("(\\s|\\n|\\r|\\,|\\:|\\;|\\[|\\])+"),QString::SkipEmptyParts);
         int i=0;
         foreach (eta, list_eta)
                 eta_ss[i++]=eta.toDouble();
         QStringList list_lb= lb.split(QRegExp("(\\s|\\n|\\r|\\,|\\:|\\;|\\[|\\])+"),QString::SkipEmptyParts);
         i=0;
         foreach (lb, list_lb)
                 lb_ss[i++]=lb.toDouble();

         QStringList list_ub= ub.split(QRegExp("(\\s|\\n|\\r|\\,|\\:|\\;|\\[|\\])+"),QString::SkipEmptyParts);
          i=0;
         foreach (ub, list_ub)
                 ub_ss[i++]=ub.toDouble();

         i=0;
         while(i<Dim_ss)
         {
             if(ub_ss[i]<lb_ss[i])
                { flag_ub=1;
                   flag_lb=1;
                   QMessageBox::critical(this,"Error", "Any element of lower bound can't be greater than any element of upper bound");
                   break;
                }
             if(ub_ss[i]-lb_ss[i]<eta_ss[i])
                { flag_eta=1;
                   QMessageBox::critical(this,"Error", "Difference between the repective element of upper bound and lower bound can't be less than respective grid radius.");
                   break;
                }
             if(eta_ss[i]<=0)
               {
                 flag_eta=1;
                QMessageBox::critical(this,"Error", "No dimension can have grid radius less than or equal to zero. ");
                break;
               }

             i=i+1;
         }

     if(flag_dim==1||flag_ub==1||flag_lb==1||flag_eta==1)
     {   flag_state_parameters=1;
         QMessageBox::critical(this,"Error", "Please enter the state parameters again");
         ui->textBrowser_status->setText("Please enter the state parameters again");
         return;
      }

     else
        {
         std::string parameters_filename="/"+this->new_model->pathoffolder+"/state_param.txt";
         std::ofstream file_state(parameters_filename.c_str());
         if(file_state.is_open())
         {
             file_state<<Dim_ss<<" ";
             for(int i=0;i<Dim_ss;i++)
                 file_state<<eta_ss[i]<<" ";
             for(int i=0;i<Dim_ss;i++)
                 file_state<<lb_ss[i]<<" ";
             for(int i=0;i<Dim_ss;i++)
                 file_state<<ub_ss[i]<<" ";
             file_state.close();
         }
         else
          QMessageBox::critical(this,"ALert","couldnt write state parameters into the file");

         flag_state_parameters=2;// parameters added successfully.;
          QMessageBox::information(this,"Hello", "State Parameters added successfully !");
          ui->textBrowser_status->setText(" State Parameters added successfully, kindly recheck them here (parameters are readjusted in scots, so recheck them once u run the generated code.");
          ui->textBrowser_status->append("Dimension is :");
          ui->textBrowser_status->append("\t"+QString::number(Dim_ss));
          ui->textBrowser_status->append("Grid Radius (eta) is :");

           eta ="\t ";
          for(int i=0;i<Dim_ss;i++)
          {  eta =eta+"  "+QString::number(eta_ss[i]);

          }
          ui->textBrowser_status->append(eta);
          ui->textBrowser_status->append("Lower Bound  is :");
           lb ="\t ";
          for(int i=0;i<Dim_ss;i++)
          {   lb =lb+"  "+QString::number(lb_ss[i]);
          }
          ui->textBrowser_status->append(lb);
          ui->textBrowser_status->append("Upper Bound is :");
          ub="\t";

          for(int i=0;i<Dim_ss;i++)
          {
              ub =ub+"  "+QString::number(ub_ss[i]);

          }
          ui->textBrowser_status->append(ub);
          ui->textBrowser_status->append("-----------------------------------------------------------");
          ui->new_model_stacked_widget->setCurrentIndex(3);
        }
   }// end of if for new model.

}//end of pushbutton ok state parameters.


// Pushbutton:ok in system post widget, for inputing the system dynamics in class variables and file sys_post.txt  .
void MainWindow::on_pushButton_sys_post_clicked()
{
    if(ui->checkBox_sys_post->isChecked()) // Checking if user wants to use rungge kutta solver or not, if yes then flag_rungge_kutta_sys is set to 1.
        flag_rungge_kutta_sys=1;
    else
        flag_rungge_kutta_sys=0;

    QString qstring_sys_post=ui->textEdit_sys_post->toPlainText();
    sys_post=qstring_sys_post.toStdString();

    // saving system post parameters into text file for loading.
    std::string parameters_filename="/"+this->new_model->pathoffolder+"/sys_post.txt";
    QMessageBox::information(this,"Hello","System post entered successfully");
    std::ofstream file_sys_post(parameters_filename.c_str());
    if(file_sys_post.is_open())
    {
        file_sys_post<<sys_post.c_str();
        file_sys_post.close();
    }
    else
        QMessageBox::critical(this,"ALert","couldnt write system_post into the file");


    flag_sys_post=0;
    tau=(ui->lineEdit_tau->text()).toDouble();
    rungekutta_step=(ui->lineEdit_runggekutta_step->text()).toDouble();
    if(tau==0)
    {
        QMessageBox::warning(this,"","tau cannot be zero, setting it to 1");
        ui->lineEdit_tau->setText("1");
        tau=1;
    }
    if(rungekutta_step==0)
    {
        QMessageBox::warning(this,"!","RungeKutta step cannot be zero, setting it to 1");
        rungekutta_step=1;
        ui->lineEdit_runggekutta_step->setText("1");
    }
     ui->new_model_stacked_widget->setCurrentIndex(2);


}


// Pushbutton:ok in radius post widget, for inputing the system dynamics in class variables and file rad_post.txt  .
void MainWindow::on_pushButton_rad_post_clicked()
{
    QString qstring_rad_post=ui->textEdit_rad_post->toPlainText();
    rad_post=qstring_rad_post.toStdString();
    flag_rad_post=0;
    if(ui->checkBox_rad_post->isChecked())
        flag_rungge_kutta_rad=1;
    else
        flag_rungge_kutta_rad=0;
    std::string parameters_filename="/"+this->new_model->pathoffolder+"/rad_post.txt";
        QMessageBox::information(this,"Hello","Radius post entered successfully");
    std::ofstream file_rad_post(parameters_filename.c_str());
    if(file_rad_post.is_open())
    {
        file_rad_post<<rad_post.c_str();
        file_rad_post.close();
    }
    else
        QMessageBox::critical(this,"ALert","couldnt write radius_post into the file");
    ui->new_model_stacked_widget->setCurrentIndex(11);
}


// Function executed on clicking "Open Model" under file and menu bar.
void MainWindow:: on_actionOpen_Model_triggered()
{
    this->new_model->flag_filename_entered=0;

    path=" ";
   // Opening a browse window and saving the path of file into the directory.
    path=(QFileDialog::getExistingDirectory(this,tr("Open Model"),"/home")).toStdString();
    if(path==" ")
      {  QMessageBox::warning(this,"Warning","You didn't select any file");
         return;
      }
    this->new_model->flag_filename_entered=1;
  //this->new_model->select_stacked_widget(1);
   //  this->new_model->show();
    path.erase(0,1);
    QStringList str=QString::fromStdString(path).split("/");
    int n=str.count();
    this->new_model->newfilename_1=str[n-1].toStdString();
    newfilename=this->new_model->newfilename_1;
    this->new_model->pathoffolder=path;
    ui->new_model_stacked_widget->show();
    ui->treeWidget_newmodel->hide();
    ui->new_model_stacked_widget->setCurrentIndex(7);
    ui->textBrowser_status->hide();

}


// Function executed on clicking "New Model" under file and menu bar.
 void MainWindow::on_actionNew_Model_triggered()
   {
     this->new_model->flag_filename_entered=0;
     ui->treeWidget_newmodel->show();
     this->new_model->select_stacked_widget(0);
     new_model->show();


     ui->new_model_stacked_widget->show();
     ui->treeWidget_newmodel->hide();
     ui->new_model_stacked_widget->setCurrentIndex(7);
     ui->textBrowser_status->hide();

 }


// Function executed on clicking tree, responsible for changing the stacked widgets according to the item selected.
void MainWindow::on_treeWidget_newmodel_clicked(const QModelIndex &index)
{    ui->textBrowser_status->setText("");
     ui->new_model_stacked_widget->setCurrentIndex(5);
     if(index.parent().row()==-1)
           {
              if(index.row()==0)
              {
               ui->new_model_stacked_widget->setCurrentIndex(0);}
           if(index.row()==1)
              {
               ui->new_model_stacked_widget->setCurrentIndex(1);
              }
           if(index.row()==2)
              {
               ui->new_model_stacked_widget->setCurrentIndex(3);
              }
           if(index.row()==3)
              {
               ui->new_model_stacked_widget->setCurrentIndex(2);
              }
           if(index.row()==4)
             {
             ui->new_model_stacked_widget->setCurrentIndex(11);
            }
          }

    if(index.row()==5)
              {
               ui->new_model_stacked_widget->setCurrentIndex(6);
               ui->pushButton->show();
               ui->pushButton_compileandrun->show();
              }

     if(index.parent().parent().row()== -1&&index.parent().row()==4)
     {
          if(index.row()==0);
            ui->new_model_stacked_widget->setCurrentIndex(4);
          if(index.row()==2)
              ui->new_model_stacked_widget->setCurrentIndex(5);
          if(index.row()==1)
              ui->new_model_stacked_widget->setCurrentIndex(9);
     }
}



void MainWindow::bddmake()
{

          std::string path1="/"+path;
           path1.append("/");
           path1.append("Makefile");
           std::ofstream file1 (path1.c_str());
              if(file1.is_open())
                 {
                    file1<<"#"<<std::endl
                          <<"# compiler"<<std::endl
                          <<"#"<<std::endl
                          <<"CC\t= g++"<<std::endl
                          <<"#CC\t= clang++"<<std::endl
                          <<"#CXXFLAGS 		= -g -Wall -Wextra -std=c++11 -DSCOTS_BDD"<<std::endl
                          <<"CXXFLAGS 		= -Wall -Wextra -std=c++11 -O3 -DNDEBUG -DSCOTS_BDD"<<std::endl
                          <<"\n#"<<std::endl
                          <<"# scots "<<std::endl
                          <<"#"<<std::endl
                          <<"SCOTSROOT\t= "<<path_of_scots.c_str()<<std::endl
                          <<"SCOTSINC\t= -I$(SCOTSROOT)/src  -I$(SCOTSROOT)/utils/"<<std::endl
                          <<"\n#"<<std::endl
                          <<"# cudd "<<std::endl
                          <<"#"<<std::endl
                          <<"CUDDINC =  -I/opt/local/include "<<std::endl
                          <<"CUDDLIB =  -L/opt/local/lib -lcudd"<<std::endl
                          <<"\n.PHONY: "<<newfilename;
                    if(ui->checkBox_add_simulation->isChecked())
                        file1<<" simulate"<<std::endl;
                    else
                        file1<<std::endl;

                       file1<<"\nTARGET = "<<newfilename;
                    if(ui->checkBox_add_simulation->isChecked())
                        file1<<" simulate"<<std::endl;
                    else
                        file1<<std::endl;

                    file1<<"\nall: $(TARGET)"<<std::endl
                         <<"\n"<<newfilename<<":"<<std::endl
                         <<"\t$(CC) $(CXXFLAGS) $(CUDDINC) $(SCOTSINC) "<<newfilename<<".cc -o  "<<newfilename<<"\t$(CUDDLIB)"<<std::endl;
                    if(ui->checkBox_add_simulation->isChecked())
                     file1<<"\nsimulate:"<<std::endl
                          <<"\t$(CC) $(CXXFLAGS) $(CUDDINC) $(SCOTSINC) simulate.cc -o simulate\t$(CUDDLIB)"<<std::endl;

                     file1<<"\nclean:"<<std::endl
                          <<"\t"<<"rm "<<newfilename<<" simulate"<<std::endl;
                    file1.close();
                 }
              else
                 std::cout<<"\n Couldn't write in makefile";


}

// Functions that writee Makefile for the model , it is called in the function for pushbutton for generating the code.
void MainWindow::makefile()
{
              std::string path1="/"+path;
               path1.append("/");
               path1.append("Makefile");
               std::ofstream file1 (path1.c_str());
                  if(file1.is_open())
                     {
                        file1<<"#"<<std::endl
                              <<"# compiler"<<std::endl
                              <<"#"<<std::endl
                              <<"CC\t= g++"<<std::endl
                              <<"#CC\t= clang++"<<std::endl
                              <<"CXXFLAGS\t= -g -Wall -Wextra -std=c++11"<<std::endl
                              <<"CXXFLAGS\t= -Wall -Wextra -std=c++11 -O3 -DNDEBUG"<<std::endl
                              <<"\n#"<<std::endl
                              <<"# scots "<<std::endl
                              <<"#"<<std::endl
                              <<"SCOTSROOT\t= "<<path_of_scots.c_str()<<std::endl
                              <<"SCOTSINC\t= -I$(SCOTSROOT)/src  -I$(SCOTSROOT)/utils/"<<std::endl
                              <<"\n.PHONY: "<<newfilename;
                        if(ui->checkBox_add_simulation->isChecked())
                            file1<<" simulate"<<std::endl;
                        else
                            file1<<std::endl;
                            file1<<"\nTARGET = "<<newfilename;
                        if(ui->checkBox_add_simulation->isChecked())
                            file1<<" simulate"<<std::endl;
                        else
                            file1<<std::endl;
                            file1<<"\nall: $(TARGET)"<<std::endl

                              <<"\n"<<newfilename<<":"<<std::endl
                              <<"\t$(CC) $(CXXFLAGS) $(SCOTSINC) "<<newfilename<<".cc -o  "<<newfilename<<std::endl;
                         if(ui->checkBox_add_simulation->isChecked())
                          file1<<"\nsimulate:"<<std::endl
                              <<"\t$(CC) $(CXXFLAGS) $(SCOTSINC) simulate.cc -o simulate"<<std::endl;

                          file1<<"\nclean:"<<std::endl
                              <<"\t"<<"rm "<<newfilename<<" simulate"<<std::endl;
                        file1.close();
                     }
                  else
                     std::cout<<"\n Couldn't write in makefile";

}

//Pushbutton: "Compile and run code" in Generate code stacked widget.
void MainWindow::on_pushButton_compileandrun_clicked()
{
    ui->textBrowser_status->setText("Runing the code...");
    ui->textBrowser_status->append("...");
    QMessageBox::information(this,"Hello","Compiling and running the code");



    std::string command="cd /"+path+"; make " ;
    if(system(command.c_str()))
        {
         QMessageBox::critical(this,"Compile and Run error","couldn't Make File");
        // return;
        }
//    command="cd /"+path+"; rm output.txt ; rm simulation.txt";
//    system(command.c_str());

    std::string outputfile="/"+path+"/output.txt", content;
    // clearing the previous content of file.
    std::fstream file(outputfile.c_str(),std::ios::out|std::ios::trunc);
    file.close();
    command="cd /"+path+"; ./"+newfilename +" >> output.txt";
    system(command.c_str());
    QString str="";
    std::ifstream file_read_output(outputfile.c_str());
        if(file_read_output.is_open())
        {
            while(std::getline(file_read_output,content))
            str=str.append("\n"+QString::fromStdString(content));
            ui->textBrowser_status->setText(str);
            file_read_output.close();
        }

  if(ui->checkBox_add_simulation->isChecked())
     {  std::string simulationfile="/"+path+"/simulation.txt" ,content;
        // clearing the previous content of file.
        std::fstream file(simulationfile.c_str(),std::ios::out|std::ios::trunc);
        file.close();
        command="cd /"+path+";./simulate >> simulation.txt" ;
        system(command.c_str());
        {

            QString str="";
            std::ifstream file_read_output(simulationfile.c_str());
            if(file_read_output.is_open())
              {
                while(std::getline(file_read_output,content))
                str=str.append("\n"+QString::fromStdString(content));
                ui->textBrowser_status->append(str);
                file_read_output.close();
              }

        }
     }


}



//Pushbutton: "ok" in avoid stack widget.
void MainWindow::on_pushButton_avoid_clicked()
{
    QString matrix=ui->textEdit_avoid->toPlainText();
    std::string str=matrix.toStdString();
    QStringList matrixrow=matrix.split(QRegExp("(\\;|\\n)+"),QString::SkipEmptyParts);
    QStringList matrixelement;
    //ensuring state and input parameters are added.
    if(flag_state_parameters==2&&flag_input_parameters==2)
    {

    avoidrows =matrixrow.count();
    for(int i=0;i<matrixrow.count();i++)
    {
          QStringList  matrixelement=matrixrow[i].split(QRegExp("(\\,|\\ )"),QString::SkipEmptyParts);
            for(int j=0;j<matrixelement.count();j++)
            {
                avoid[i][j]=matrixelement[j].toDouble();
                std::cout<<matrixelement[j].toDouble();
            }
    }
    flag_avoid=2;// it mean avoid specification is added successfully.
    QMessageBox::information(this,"Hello","Parameters of avoid specification successfully entered");
    }
    else
        QMessageBox::critical(this, "Error","Add the state and input parameters first");
}



//Pushbutton: "ok" in Reach/target stack widget.
void MainWindow::on_pushButton_target_bounds_clicked()
{   flag_target_lbub=0;
   //getting lowerbound and upperbound of target set
    QString lb=ui->lineEdit_target_lb->text() ;
    QString ub=ui->lineEdit_target_ub->text();
    int flag_dim_target=0;
    int flag_ub_target=0;
    int flag_lb_target=0;
    if(flag_state_parameters==2)
    {
        int ll= lb.split(QRegExp("(\\s|\\n|\\r)+"), QString::SkipEmptyParts).count(); // number of elements in lb
        int uu = ub.split(QRegExp("(\\s|\\n|\\r)+"), QString::SkipEmptyParts).count();// number of elements in ub
        if(Dim_ss!=ll||Dim_ss!=uu)
          {
            flag_dim_target=1;
            QMessageBox::critical(this,"Error", "upper bound and lower bound do not match with dimension");
          }
        if(flag_dim_target!=1)
        {

            QStringList list_lb= lb.split(QRegExp("(\\s|\\n|\\r)+"),QString::SkipEmptyParts);
            int i=0;
            foreach (lb, list_lb)
                    lb_target[i++]=lb.toDouble();

            QStringList list_ub= ub.split(QRegExp("(\\s|\\n|\\r)+"),QString::SkipEmptyParts);
             i=0;
            foreach (ub, list_ub)
                    ub_target[i++]=ub.toDouble();

            i=0;
            while(i<Dim_ss)
            {
                if(ub_target[i]<lb_target[i])
                   {  flag_ub_target=1;
                      flag_lb_target=1;
                      break;
                   }

                i=i+1;
            }

        }
        if(flag_dim_target==1&&flag_ub_target==1&&flag_lb_target==1)
        {   flag_target_lbub=1;
            QMessageBox::critical(this,"Error", "Please enter the lower bound and upper bound again");
         }
        else
           {
            QMessageBox::information(this,"Hello","Parameters of target specification successfully entered");
            flag_target_lbub=2;

        }
     }
    else
        QMessageBox::critical(this,"Error", "Please enter the state parameters first");
}


//Pushbutton: "ok" in Safety stack widget
void MainWindow::on_pushButton_safety_clicked()
{
        flag_safety=0;
       //getting lowerbound and upperbound of target set
        QString lb=ui->lineEdit_safety_lb->text() ;
        QString ub=ui->lineEdit_safety_ub->text();
        int flag_dim_safety=0;
        int flag_ub_safety=0;
        int flag_lb_safety=0;
        if(flag_state_parameters==2)
        {
            int ll= lb.split(QRegExp("(\\s|\\n|\\r)+"), QString::SkipEmptyParts).count(); // number of elements in lb
            int uu = ub.split(QRegExp("(\\s|\\n|\\r)+"), QString::SkipEmptyParts).count();// number of elements in ub
            if(Dim_ss!=ll||Dim_ss!=uu)
              {
                flag_dim_safety=1;
                QMessageBox::critical(this,"Error", "upper bound and lower bound do not match with dimension");
              }
            if(flag_dim_safety!=1)
            {

                QStringList list_lb= lb.split(QRegExp("(\\s|\\n|\\r)+"),QString::SkipEmptyParts);
                int i=0;
                foreach (lb, list_lb)
                        lb_safety[i++]=lb.toDouble();

                QStringList list_ub= ub.split(QRegExp("(\\s|\\n|\\r)+"),QString::SkipEmptyParts);
                 i=0;
                foreach (ub, list_ub)
                    ub_safety[i++]=ub.toDouble();

                i=0;
                while(i<Dim_ss)
                {
                    if(ub_safety[i]<lb_safety[i])
                       {  flag_ub_safety=1;
                          flag_lb_safety=1;
                          break;
                       }


                    i=i+1;
                }

            }
            if(flag_dim_safety==1&&flag_ub_safety==1&&flag_lb_safety==1)
            {   flag_safety=1; // lb and ub are not correct.
                QMessageBox::critical(this,"Error", "Please enter the lower bound and upper bound again");
             }
            else
               { flag_safety=2;//parameters added are fine.
                 QMessageBox::information(this,"Hello","Parameters of safety specification successfully entered");

            }
         }
        else
            QMessageBox::critical(this,"Error", "Please enter the state parameters first");


    }


void MainWindow::on_pushButton_2_clicked() // Pushbutton: "Click here" introduced in the beginning, right after clicking new_model and open_model
{
    if(this->new_model->flag_filename_entered==2||this->new_model->flag_filename_entered==1)
    {

        if(this->new_model->flag_filename_entered==2)
        {
            path=this->new_model->pathoffolder;
        }


         newfilename=this->new_model->newfilename_1;
         ui->new_model_stacked_widget->setCurrentIndex(8);
         ui->treeWidget_newmodel->setHeaderLabel(QString::fromStdString(this->new_model->newfilename_1));
         setWindowTitle(QString::fromStdString(this->new_model->newfilename_1));
         ui->treeWidget_newmodel->show();
         ui->textBrowser_status->show();
        //flag_newmodel=2;
        //Initializing input widget for new model
        flag_input_parameters=0;
        ui->lineEdit_eta_ii->setText(" ");
        ui->lineEdit_lb_ii->setText(" ");
        ui->lineEdit_ub_ii->setText(" ");
        ui->spinBox_dim_ii->cleanText();


        //Initializing state widget for new model
        flag_state_parameters=0;
        ui->lineEdit_eta_ss->setText(" ");
        ui->lineEdit_lb_ss->setText(" ");
        ui->lineEdit_ub_ss->setText(" ");
        ui->spinBox_dim_ss->cleanText();

        //Initializing System Post Widget for new model.
        flag_rungge_kutta_sys=0;
        flag_sys_post=0;
        ui->textEdit_sys_post->setText(" ");

        //Initializing Radius Post Widget for new model.
        flag_rungge_kutta_rad=0;
        flag_rad_post=0;
        ui->textEdit_rad_post->setText(" ");

        //Initializing Avoid widget for new model
         flag_add_avoid=0;
         flag_avoid=0;
         ui->textEdit_avoid->setText(" ");

         // Initializing Target widget for new model
         flag_add_target=0;
         flag_target_lbub=0;
         ui->lineEdit_target_lb->setText(" ");
         ui->lineEdit_target_ub->setText(" ");

         // Initializing safety widget for new model
         flag_add_safety=0;
         flag_safety=0;
         ui->lineEdit_safety_lb->setText(" ");
         ui->lineEdit_safety_ub->setText(" ");

         ui->textBrowser_status->setText("");
         ui->lineEdit_tau->setText("");
         ui->lineEdit_runggekutta_step->setText("");

      }
    //condition for open model functionality.
    if(this->new_model->flag_filename_entered==1)
       {
        std::string temp="/"+this->new_model->pathoffolder+"/state_param.txt";
        std::ifstream file_state(temp.c_str());
        if(file_state.is_open())
        {   QString state_param ,eta="",ub="",lb="";
            int i=0;
            std::string params;
            std::getline(file_state,params);
            state_param = QString::fromStdString(params);
            QStringList list =state_param.split(" ",QString::SkipEmptyParts);
            ui->spinBox_dim_ss->setValue(list[0].toInt());
            for(i=1;i<=list[0].toInt();i++)
            {
              eta =eta+ " " +list[i];
            }
            for(int j=0;j<list[0].toInt();j++)
            {
               lb=lb+ " "+list[i++];
            }
            for(int j=0;j<list[0].toInt();j++)
            {
               ub=ub+" "+list[i];
               i=i+1;
            }
            //ub=ub+list[6];
            ui->lineEdit_eta_ss->setText(eta);
            ui->lineEdit_ub_ss->setText(ub);
            ui->lineEdit_lb_ss->setText(lb);
            file_state.close();
            ui->textBrowser_status->setText("state parameters added successfully");
        }
        else
            ui->textBrowser_status->setText("Couldn't add state parameters.");

        //Adding input parameters.
        temp="/"+this->new_model->pathoffolder+"/input_param.txt";
        std::ifstream file_input(temp.c_str());
        if(file_input.is_open())
        {   QString input_param ,eta="",ub="",lb="";
            int i=0;
            std::string params;
            std::getline(file_input,params);
            input_param = QString::fromStdString(params);
            QStringList list =input_param.split(" ",QString::SkipEmptyParts);
            ui->spinBox_dim_ii->setValue(list[0].toInt());
            for(i=1;i<=list[0].toInt();i++)
            {
              eta =eta + " " +list[i];
            }
            for(int j=0;j<list[0].toInt();j++)
            {
               lb=lb+ " " +list[i++];
            }
            for(int j=0;j<list[0].toInt();j++)
            {
               ub=ub+ " " +list[i];
               i=i+1;
            }
            ui->lineEdit_eta_ii->setText(eta);
            ui->lineEdit_ub_ii->setText(ub);
            ui->lineEdit_lb_ii->setText(lb);
            file_input.close();
            ui->textBrowser_status->append("input parameters added successfully");
        }
        else
            ui->textBrowser_status->append("Couldn't add input parameters.");
       // Adding Radius Post
        temp="/"+this->new_model->pathoffolder+"/rad_post.txt";
        std::ifstream file_rad(temp.c_str());
        if(file_rad.is_open())
        {   QString rad_post;

            std::string post;
            while(std::getline(file_rad,post))
            {
               rad_post=rad_post.append("\n"+QString::fromStdString(post));
            }
            ui->textEdit_rad_post->setText(rad_post);
            file_rad.close();
            ui->textBrowser_status->append("Radius post added successfully ");
        }
        else
            ui->textBrowser_status->append("couldn't add radius post ");

      //Adding System post
        temp="/"+this->new_model->pathoffolder+"/sys_post.txt";
        std::ifstream file_sys(temp.c_str());
        if(file_sys.is_open())
        {   QString sys_post;

            std::string post;
            while(std::getline(file_sys,post))
            {
               sys_post=sys_post.append("\n"+QString::fromStdString(post));
            }
            ui->textEdit_sys_post->setText(sys_post);
            file_sys.close();
            ui->textBrowser_status->append("System post added successfully ");
        }
        else
            ui->textBrowser_status->append("Couldn't add system post ");

    }
    if(this->new_model->flag_filename_entered==0)
       QMessageBox::critical(this,"Sorry","It seems you forgot to add the filename, please add the file name again by clicking on new model up in the menu bar");



}


// feature to change the path of SCOTS.
void MainWindow::on_actionPath_for_SCOTS_triggered()
{
   QString str=QFileDialog::getExistingDirectory(this,tr("Select folder containing SCOTS_v0.2"),"/home");
   if(str.isEmpty())
   {
       QMessageBox::warning(this,"Nothing Selected","No path selected setting the default path as:/home/fmlab5/SCOTSv0.2");
       path_of_scots= "/home/fmlab5/SCOTSv0.2";
       return;
   }
   path_of_scots=str.toStdString();

}

// Shows about.
void MainWindow::on_actionAbout_triggered()
{   this->new_model->select_stacked_widget(2);
    new_model->show();

}
