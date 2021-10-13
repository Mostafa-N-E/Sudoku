#include "help.h"
#include "ui_help.h"

HELP::HELP(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HELP)
{

    ui->setupUi(this);
    initialize();
}

HELP::~HELP()
{
    delete ui;
}
void HELP::initialize(){
    //    HELP *help;
    //    help->setWindowTitle("HELP");
        ui->textEdit->setText("Sudoku is a brain challenging number game, played on a 3x3 sudoku board.\nThe object of the sudoku game is simple.Every row, column, in the sudoku board must \ncontain the digits 1 through 3 only once!");
        ui->lineEdit_2->setText("1");
        ui->lineEdit_4->setText("3");
        ui->lineEdit_9->setText("2");
        ui->lineEdit_10->setText("2");
        ui->lineEdit_11->setText("1");
        ui->lineEdit_12->setText("3");
        ui->lineEdit_13->setText("3");
        ui->lineEdit_14->setText("2");
        ui->lineEdit_15->setText("1");
        ui->lineEdit_16->setText("1");
        ui->lineEdit_17->setText("3");
        ui->lineEdit_18->setText("2");
}
