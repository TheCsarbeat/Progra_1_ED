#include "estructuras_progressbar.h"

EstructuraProgressBar::EstructuraProgressBar(QFrame * f, QLabel * lb){
    progressBar = f;
    lbProgress = lb;
    setValue(0);

}

void EstructuraProgressBar::setValue(int value){
    progressBar->setGeometry(0,0,value,20);
    lbProgress->setText(QString::number(value)+" %");
}
