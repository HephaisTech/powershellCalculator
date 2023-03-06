#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QtWidgets>
#include <QDoubleSpinBox>

class Calculator : public QWidget
{
    Q_OBJECT
    private:
        QLabel *ttr;
        QDoubleSpinBox *number1;
        QDoubleSpinBox *number2;
        QComboBox *opera;
        QPushButton *equal;
        QLineEdit *result;
        QPushButton *exit;

    public:
        Calculator();
        ~Calculator();
    public slots:
        void calculer();
        void confirmExit();

};

#endif // CALCULATOR_H
