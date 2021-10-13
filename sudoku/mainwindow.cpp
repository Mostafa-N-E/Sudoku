#include "mainwindow.h"
#include "help.h"
#include "solve_sudoku.h"
#include "genrate_sudoku.h"
#include "ui_mainwindow.h"
#include <qmessagebox.h>
#include <stdlib.h>

void check(int inp[1][9][9]);
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
int generat[1][9][9]={0};

int v;

void MainWindow::on_start_clicked()
{
    generat[1][9][9]={0};
    generate(generat);

    SolveSudoku(generat);

    ui->lineEdit_1->setText(QString::number(generat[0][0][0]));
    ui->lineEdit_3->setText(QString::number(generat[0][0][2]));
    ui->lineEdit_4->setText(QString::number(generat[0][0][3]));
    ui->lineEdit_6->setText(QString::number(generat[0][0][5]));
    ui->lineEdit_7->setText(QString::number(generat[0][0][6]));
    ui->lineEdit_10->setText(QString::number(generat[0][1][0]));
    ui->lineEdit_11->setText(QString::number(generat[0][1][1]));
    ui->lineEdit_20->setText(QString::number(generat[0][2][1]));
    ui->lineEdit_21->setText(QString::number(generat[0][2][2]));
    ui->lineEdit_26->setText(QString::number(generat[0][2][7]));
    ui->lineEdit_27->setText(QString::number(generat[0][2][8]));
    ui->lineEdit_32->setText(QString::number(generat[0][3][4]));
    ui->lineEdit_35->setText(QString::number(generat[0][3][7]));
    ui->lineEdit_37->setText(QString::number(generat[0][4][0]));
    ui->lineEdit_40->setText(QString::number(generat[0][4][3]));
    ui->lineEdit_42->setText(QString::number(generat[0][4][4]));
    ui->lineEdit_41->setText(QString::number(generat[0][4][5]));
    ui->lineEdit_45->setText(QString::number(generat[0][4][8]));
    ui->lineEdit_47->setText(QString::number(generat[0][5][1]));
    ui->lineEdit_50->setText(QString::number(generat[0][5][4]));
    ui->lineEdit_52->setText(QString::number(generat[0][5][6]));
    ui->lineEdit_55->setText(QString::number(generat[0][6][0]));
    ui->lineEdit_56->setText(QString::number(generat[0][6][1]));
    ui->lineEdit_61->setText(QString::number(generat[0][6][6]));
    ui->lineEdit_62->setText(QString::number(generat[0][6][7]));
    ui->lineEdit_71->setText(QString::number(generat[0][7][7]));
    ui->lineEdit_72->setText(QString::number(generat[0][7][8]));
    ui->lineEdit_75->setText(QString::number(generat[0][8][2]));
    ui->lineEdit_76->setText(QString::number(generat[0][8][3]));
    ui->lineEdit_78->setText(QString::number(generat[0][8][5]));
    ui->lineEdit_79->setText(QString::number(generat[0][8][6]));
}

void MainWindow::on_refresh_clicked()
{
    ui->lineEdit_1->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");
    ui->lineEdit_6->setText("");
    ui->lineEdit_7->setText("");
    ui->lineEdit_8->setText("");
    ui->lineEdit_9->setText("");

    ui->lineEdit_10->setText("");
    ui->lineEdit_11->setText("");
    ui->lineEdit_12->setText("");
    ui->lineEdit_13->setText("");
    ui->lineEdit_14->setText("");
    ui->lineEdit_15->setText("");
    ui->lineEdit_16->setText("");
    ui->lineEdit_17->setText("");
    ui->lineEdit_18->setText("");

    ui->lineEdit_19->setText("");
    ui->lineEdit_20->setText("");
    ui->lineEdit_21->setText("");
    ui->lineEdit_22->setText("");
    ui->lineEdit_23->setText("");
    ui->lineEdit_24->setText("");
    ui->lineEdit_25->setText("");
    ui->lineEdit_26->setText("");
    ui->lineEdit_27->setText("");

    ui->lineEdit_28->setText("");
    ui->lineEdit_29->setText("");
    ui->lineEdit_30->setText("");
    ui->lineEdit_31->setText("");
    ui->lineEdit_32->setText("");
    ui->lineEdit_33->setText("");
    ui->lineEdit_34->setText("");
    ui->lineEdit_35->setText("");
    ui->lineEdit_36->setText("");

    ui->lineEdit_37->setText("");
    ui->lineEdit_38->setText("");
    ui->lineEdit_39->setText("");
    ui->lineEdit_40->setText("");
    ui->lineEdit_42->setText("");
    ui->lineEdit_41->setText("");
    ui->lineEdit_43->setText("");
    ui->lineEdit_44->setText("");
    ui->lineEdit_45->setText("");

    ui->lineEdit_46->setText("");
    ui->lineEdit_47->setText("");
    ui->lineEdit_48->setText("");
    ui->lineEdit_49->setText("");
    ui->lineEdit_50->setText("");
    ui->lineEdit_51->setText("");
    ui->lineEdit_52->setText("");
    ui->lineEdit_53->setText("");
    ui->lineEdit_54->setText("");

    ui->lineEdit_55->setText("");
    ui->lineEdit_56->setText("");
    ui->lineEdit_57->setText("");
    ui->lineEdit_58->setText("");
    ui->lineEdit_59->setText("");
    ui->lineEdit_60->setText("");
    ui->lineEdit_61->setText("");
    ui->lineEdit_62->setText("");
    ui->lineEdit_63->setText("");

    ui->lineEdit_64->setText("");
    ui->lineEdit_65->setText("");
    ui->lineEdit_66->setText("");
    ui->lineEdit_67->setText("");
    ui->lineEdit_68->setText("");
    ui->lineEdit_69->setText("");
    ui->lineEdit_70->setText("");
    ui->lineEdit_71->setText("");
    ui->lineEdit_72->setText("");

    ui->lineEdit_73->setText("");
    ui->lineEdit_74->setText("");
    ui->lineEdit_75->setText("");
    ui->lineEdit_76->setText("");
    ui->lineEdit_77->setText("");
    ui->lineEdit_78->setText("");
    ui->lineEdit_79->setText("");
    ui->lineEdit_80->setText("");
    ui->lineEdit_81->setText("");
    on_start_clicked();
}

void MainWindow::on_solve_clicked()
{

    int inp[1][9][9]={0};
    inp[0][0][0] = ui->lineEdit_1->text().toInt();
    inp[0][0][1] = ui->lineEdit_2->text().toInt();
    inp[0][0][2] = ui->lineEdit_3->text().toInt();
    inp[0][0][3] = ui->lineEdit_4->text().toInt();
    inp[0][0][4] = ui->lineEdit_5->text().toInt();
    inp[0][0][5] = ui->lineEdit_6->text().toInt();
    inp[0][0][6] = ui->lineEdit_7->text().toInt();
    inp[0][0][7] = ui->lineEdit_8->text().toInt();
    inp[0][0][8] = ui->lineEdit_9->text().toInt();

    inp[0][1][0] = ui->lineEdit_10->text().toInt();
    inp[0][1][1] = ui->lineEdit_11->text().toInt();
    inp[0][1][2] = ui->lineEdit_12->text().toInt();
    inp[0][1][3] = ui->lineEdit_13->text().toInt();
    inp[0][1][4] = ui->lineEdit_14->text().toInt();
    inp[0][1][5] = ui->lineEdit_15->text().toInt();
    inp[0][1][6] = ui->lineEdit_16->text().toInt();
    inp[0][1][7] = ui->lineEdit_17->text().toInt();
    inp[0][1][8] = ui->lineEdit_18->text().toInt();

    inp[0][2][0] = ui->lineEdit_19->text().toInt();
    inp[0][2][1] = ui->lineEdit_20->text().toInt();
    inp[0][2][2] = ui->lineEdit_21->text().toInt();
    inp[0][2][3] = ui->lineEdit_22->text().toInt();
    inp[0][2][4] = ui->lineEdit_23->text().toInt();
    inp[0][2][5] = ui->lineEdit_24->text().toInt();
    inp[0][2][6] = ui->lineEdit_25->text().toInt();
    inp[0][2][7] = ui->lineEdit_26->text().toInt();
    inp[0][2][8] = ui->lineEdit_27->text().toInt();

    inp[0][3][0] = ui->lineEdit_28->text().toInt();
    inp[0][3][1] = ui->lineEdit_29->text().toInt();
    inp[0][3][2] = ui->lineEdit_30->text().toInt();
    inp[0][3][3] = ui->lineEdit_31->text().toInt();
    inp[0][3][4] = ui->lineEdit_32->text().toInt();
    inp[0][3][5] = ui->lineEdit_33->text().toInt();
    inp[0][3][6] = ui->lineEdit_34->text().toInt();
    inp[0][3][7] = ui->lineEdit_35->text().toInt();
    inp[0][3][8] = ui->lineEdit_36->text().toInt();

    inp[0][4][0] = ui->lineEdit_37->text().toInt();
    inp[0][4][1] = ui->lineEdit_38->text().toInt();
    inp[0][4][2] = ui->lineEdit_39->text().toInt();
    inp[0][4][3] = ui->lineEdit_40->text().toInt();
    inp[0][4][4] = ui->lineEdit_42->text().toInt();
    inp[0][4][5] = ui->lineEdit_41->text().toInt();
    inp[0][4][6] = ui->lineEdit_43->text().toInt();
    inp[0][4][7] = ui->lineEdit_44->text().toInt();
    inp[0][4][8] = ui->lineEdit_45->text().toInt();

    inp[0][5][0] = ui->lineEdit_46->text().toInt();
    inp[0][5][1] = ui->lineEdit_47->text().toInt();
    inp[0][5][2] = ui->lineEdit_48->text().toInt();
    inp[0][5][3] = ui->lineEdit_49->text().toInt();
    inp[0][5][4] = ui->lineEdit_50->text().toInt();
    inp[0][5][5] = ui->lineEdit_51->text().toInt();
    inp[0][5][6] = ui->lineEdit_52->text().toInt();
    inp[0][5][7] = ui->lineEdit_53->text().toInt();
    inp[0][5][8] = ui->lineEdit_54->text().toInt();

    inp[0][6][0] = ui->lineEdit_55->text().toInt();
    inp[0][6][1] = ui->lineEdit_56->text().toInt();
    inp[0][6][2] = ui->lineEdit_57->text().toInt();
    inp[0][6][3] = ui->lineEdit_58->text().toInt();
    inp[0][6][4] = ui->lineEdit_59->text().toInt();
    inp[0][6][5] = ui->lineEdit_60->text().toInt();
    inp[0][6][6] = ui->lineEdit_61->text().toInt();
    inp[0][6][7] = ui->lineEdit_62->text().toInt();
    inp[0][6][8] = ui->lineEdit_63->text().toInt();

    inp[0][7][0] = ui->lineEdit_64->text().toInt();
    inp[0][7][1] = ui->lineEdit_65->text().toInt();
    inp[0][7][2] = ui->lineEdit_66->text().toInt();
    inp[0][7][3] = ui->lineEdit_67->text().toInt();
    inp[0][7][4] = ui->lineEdit_68->text().toInt();
    inp[0][7][5] = ui->lineEdit_69->text().toInt();
    inp[0][7][6] = ui->lineEdit_70->text().toInt();
    inp[0][7][7] = ui->lineEdit_71->text().toInt();
    inp[0][7][8] = ui->lineEdit_72->text().toInt();

    inp[0][8][0] = ui->lineEdit_73->text().toInt();
    inp[0][8][1] = ui->lineEdit_74->text().toInt();
    inp[0][8][2] = ui->lineEdit_75->text().toInt();
    inp[0][8][3] = ui->lineEdit_76->text().toInt();
    inp[0][8][4] = ui->lineEdit_77->text().toInt();
    inp[0][8][5] = ui->lineEdit_78->text().toInt();
    inp[0][8][6] = ui->lineEdit_79->text().toInt();
    inp[0][8][7] = ui->lineEdit_80->text().toInt();
    inp[0][8][8] = ui->lineEdit_81->text().toInt();

    check(inp);


}

void check(int inp[1][9][9]){
    bool flag = true;

    for(int i=0 ;i<9 && flag; i++){
        for(int j=0 ;j<9 && flag; j++){
            if(inp[0][i][j] == 0){
                flag = false;
                QMessageBox messagebox1;
                messagebox1.setWindowTitle("ERROR");
                messagebox1.setText("You must put all rows and columns with number 1, 2 and 3");
                messagebox1.setStyleSheet("background:#00B8B3");
                messagebox1.exec();
            }
        }
    }
    if(flag){
        if(is_solve(inp)){
            QMessageBox messagebox2;
            messagebox2.setWindowTitle("succesful");
            messagebox2.setText("Congratulaions\t\t\t\t\t\t\nYour solution is correct");
            messagebox2.setStyleSheet("background:#00B8B3");
            messagebox2.exec();
        }
        else {
            QMessageBox messagebox3;
            messagebox3.setWindowTitle("Unsuccesful");
            messagebox3.setText("Sorry\t\t\t\t\t\t\t\nYour solution is not correct");
            messagebox3.setStyleSheet("background:#00B8B3");
            messagebox3.exec();
        }
    }
}

void MainWindow::on_HELP_clicked()
{
    HELP *help;
    help = new HELP();
    help->show();
}

void copy(int res[1][9][9],int generat[1][9][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            res[0][i][j] = generat[0][i][j];
        }
    }
}


void MainWindow::on_show_solve_clicked()
{
    int res[1][9][9];
    copy(res,generat);
    SolveSudoku(res);
//    copy_S(res);
    ui->lineEdit_1->setText(QString::number(res[0][0][0]));
    ui->lineEdit_2->setText(QString::number(res[0][0][1]));
    ui->lineEdit_3->setText(QString::number(res[0][0][2]));
    ui->lineEdit_4->setText(QString::number(res[0][0][3]));
    ui->lineEdit_5->setText(QString::number(res[0][0][4]));
    ui->lineEdit_6->setText(QString::number(res[0][0][5]));
    ui->lineEdit_7->setText(QString::number(res[0][0][6]));
    ui->lineEdit_8->setText(QString::number(res[0][0][7]));
    ui->lineEdit_9->setText(QString::number(res[0][0][8]));

    ui->lineEdit_10->setText(QString::number(res[0][1][0]));
    ui->lineEdit_11->setText(QString::number(res[0][1][1]));
    ui->lineEdit_12->setText(QString::number(res[0][1][2]));
    ui->lineEdit_13->setText(QString::number(res[0][1][3]));
    ui->lineEdit_14->setText(QString::number(res[0][1][4]));
    ui->lineEdit_15->setText(QString::number(res[0][1][5]));
    ui->lineEdit_16->setText(QString::number(res[0][1][6]));
    ui->lineEdit_17->setText(QString::number(res[0][1][7]));
    ui->lineEdit_18->setText(QString::number(res[0][1][8]));

    ui->lineEdit_19->setText(QString::number(res[0][2][0]));
    ui->lineEdit_20->setText(QString::number(res[0][2][1]));
    ui->lineEdit_21->setText(QString::number(res[0][2][2]));
    ui->lineEdit_22->setText(QString::number(res[0][2][3]));
    ui->lineEdit_23->setText(QString::number(res[0][2][4]));
    ui->lineEdit_24->setText(QString::number(res[0][2][5]));
    ui->lineEdit_25->setText(QString::number(res[0][2][6]));
    ui->lineEdit_26->setText(QString::number(res[0][2][7]));
    ui->lineEdit_27->setText(QString::number(res[0][2][8]));

    ui->lineEdit_28->setText(QString::number(res[0][3][0]));
    ui->lineEdit_29->setText(QString::number(res[0][3][1]));
    ui->lineEdit_30->setText(QString::number(res[0][3][2]));
    ui->lineEdit_31->setText(QString::number(res[0][3][3]));
    ui->lineEdit_32->setText(QString::number(res[0][3][4]));
    ui->lineEdit_33->setText(QString::number(res[0][3][5]));
    ui->lineEdit_34->setText(QString::number(res[0][3][6]));
    ui->lineEdit_35->setText(QString::number(res[0][3][7]));
    ui->lineEdit_36->setText(QString::number(res[0][3][8]));

    ui->lineEdit_37->setText(QString::number(res[0][4][0]));
    ui->lineEdit_38->setText(QString::number(res[0][4][1]));
    ui->lineEdit_39->setText(QString::number(res[0][4][2]));
    ui->lineEdit_40->setText(QString::number(res[0][4][3]));
    ui->lineEdit_42->setText(QString::number(res[0][4][4]));
    ui->lineEdit_41->setText(QString::number(res[0][4][5]));
    ui->lineEdit_43->setText(QString::number(res[0][4][6]));
    ui->lineEdit_44->setText(QString::number(res[0][4][7]));
    ui->lineEdit_45->setText(QString::number(res[0][4][8]));

    ui->lineEdit_46->setText(QString::number(res[0][5][0]));
    ui->lineEdit_47->setText(QString::number(res[0][5][1]));
    ui->lineEdit_48->setText(QString::number(res[0][5][2]));
    ui->lineEdit_49->setText(QString::number(res[0][5][3]));
    ui->lineEdit_50->setText(QString::number(res[0][5][4]));
    ui->lineEdit_51->setText(QString::number(res[0][5][5]));
    ui->lineEdit_52->setText(QString::number(res[0][5][6]));
    ui->lineEdit_53->setText(QString::number(res[0][5][7]));
    ui->lineEdit_54->setText(QString::number(res[0][5][8]));

    ui->lineEdit_55->setText(QString::number(res[0][6][0]));
    ui->lineEdit_56->setText(QString::number(res[0][6][1]));
    ui->lineEdit_57->setText(QString::number(res[0][6][2]));
    ui->lineEdit_58->setText(QString::number(res[0][6][3]));
    ui->lineEdit_59->setText(QString::number(res[0][6][4]));
    ui->lineEdit_60->setText(QString::number(res[0][6][5]));
    ui->lineEdit_61->setText(QString::number(res[0][6][6]));
    ui->lineEdit_62->setText(QString::number(res[0][6][7]));
    ui->lineEdit_63->setText(QString::number(res[0][6][8]));

    ui->lineEdit_64->setText(QString::number(res[0][7][0]));
    ui->lineEdit_65->setText(QString::number(res[0][7][1]));
    ui->lineEdit_66->setText(QString::number(res[0][7][2]));
    ui->lineEdit_67->setText(QString::number(res[0][7][3]));
    ui->lineEdit_68->setText(QString::number(res[0][7][4]));
    ui->lineEdit_69->setText(QString::number(res[0][7][5]));
    ui->lineEdit_70->setText(QString::number(res[0][7][6]));
    ui->lineEdit_71->setText(QString::number(res[0][7][7]));
    ui->lineEdit_72->setText(QString::number(res[0][7][8]));

    ui->lineEdit_73->setText(QString::number(res[0][8][0]));
    ui->lineEdit_74->setText(QString::number(res[0][8][1]));
    ui->lineEdit_75->setText(QString::number(res[0][8][2]));
    ui->lineEdit_76->setText(QString::number(res[0][8][3]));
    ui->lineEdit_77->setText(QString::number(res[0][8][4]));
    ui->lineEdit_78->setText(QString::number(res[0][8][5]));
    ui->lineEdit_79->setText(QString::number(res[0][8][6]));
    ui->lineEdit_80->setText(QString::number(res[0][8][7]));
    ui->lineEdit_81->setText(QString::number(res[0][8][8]));
}
