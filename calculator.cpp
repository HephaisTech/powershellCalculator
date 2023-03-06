#include <QApplication>
#include <QtWidgets>
#include <QDoubleSpinBox>

#include "calculator.h"

Calculator::Calculator():QWidget()
{
    setFixedSize(500,200);
    ttr = new QLabel("Special calculator");
    number1 = new QDoubleSpinBox;
    number2 = new QDoubleSpinBox;
    opera = new QComboBox;
    opera->addItem("+");
    opera->addItem("-");
    opera->addItem("*");
    opera->addItem("/");
    opera->addItem("%");
    /*QRadioButton *oper1 = new QRadioButton("+");
    QRadioButton *oper2 = new QRadioButton("-");
    QRadioButton *oper3 = new QRadioButton("*");
    QRadioButton *oper4 = new QRadioButton("/");
    QRadioButton *oper5 = new QRadioButton("%");
    QVBoxLayout * vBox = new QVBoxLayout;
    vBox->addWidget(oper1);
    vBox->addWidget(oper2);
    vBox->addWidget(oper3);
    vBox->addWidget(oper4);
    vBox->addWidget(oper5);
    QGroupBox * opera = new QGroupBox;
    opera->setLayout(vBox);*/

    equal = new QPushButton("=");
    result = new QLineEdit;
    exit = new QPushButton("Exit");

    //configurations des éléments
    number1->setFixedSize(150,30);
    number1->setMinimum(-999999999);
    number1->setMaximum(999999999);

    number2->setFixedSize(150,30);
    number2->setMinimum(-999999999);
    number2->setMaximum(999999999);

    opera->setFixedSize(60,20);
    result->setFixedSize(150,30);

    //Format des composants
    ttr->setFont(QFont("Georgia", 16, QFont::Bold));
    number1->setFont(QFont("Georgia", 10, QFont::Bold, false));
    number2->setFont(QFont("Georgia", 10, QFont::Bold, false));
    opera->setFont(QFont("Georgia", 10, QFont::Bold, false));
    equal->setFont(QFont("Georgia", 10, QFont::Bold, false));
    result->setFont(QFont("Georgia", 10, QFont::Bold, false));

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(ttr,0,0,1,3,Qt::AlignCenter);
    layout->addWidget(number1,1,0);
    layout->addWidget(opera,1,1);
    layout->addWidget(number2,1,2);
    layout->addWidget(equal,2,1,1,1,Qt::AlignCenter);
    layout->addWidget(result,2,2);
    layout->addWidget(exit,3,1,1,1,Qt::AlignCenter);

    QVBoxLayout *mainWin = new QVBoxLayout;
    mainWin->addLayout(layout);

    //connexion de slots et de signals
    QObject::connect(equal, SIGNAL(clicked()), this, SLOT(calculer()));
    QObject::connect(exit, SIGNAL(clicked()), this, SLOT(confirmExit()));

    this->setLayout(mainWin);//ajout du layout principal

}

Calculator::~Calculator()
{

}

void Calculator::calculer(){
    if(number1->text().isEmpty())
    {
        QMessageBox::critical(this,"Exigence","Saisissez le premier nombre !", QMessageBox::Ok);
        number1->setFocus();
    }
    else if(number2->text().isEmpty())
    {
        QMessageBox::critical(this,"Exigence","Saisissez le deuxième nombre !", QMessageBox::Ok);
        number2->setFocus();
    }
    else
    {
        QString strOpera;
        double valNum1, valNum2;
        double valRslt;
        long R, N1, N2;

        valNum1 = number1->text().toDouble();
        valNum2 = number2->text().toDouble();
        N1 = number1->text().toLong();
        N2 = number2->text().toLong();
        strOpera = opera->currentText();

        if (strOpera=="+"){
            valRslt = valNum1 + valNum2;
        }else if (strOpera=="-"){
            valRslt = valNum1 - valNum2;
        }else if (strOpera=="*"){
            valRslt = valNum1 * valNum2;
        }else if (strOpera=="/"){
            valRslt = valNum1 / valNum2;
        }else if (strOpera=="%"){
            R = N1 % N2;
        }
        result->setText(QString::number(valRslt));
        number1->setFocus();
    }
}

void Calculator::confirmExit(){
    int rep = QMessageBox::question(this,"Question", "Voulez vous réellement quitter ?", QMessageBox ::Yes | QMessageBox::No);
    if (rep == QMessageBox::Yes){
        qApp->quit();
    }
}
