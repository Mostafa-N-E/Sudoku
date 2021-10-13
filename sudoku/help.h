#ifndef HELP_H
#define HELP_H

#include <QDialog>

namespace Ui {
class HELP;
}

class HELP : public QDialog
{
    Q_OBJECT

public:
    explicit HELP(QWidget *parent = nullptr);
    ~HELP();

private slots:
    void on_HELP_accepted();

    void on_HELP_finished(int result);

    void on_pushButton_clicked();
    void initialize();

private:
    Ui::HELP *ui;
};

#endif // HELP_H
