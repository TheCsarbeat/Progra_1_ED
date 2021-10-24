#include "estructuras_progressbar.h"

EstructuraProgressBar::EstructuraProgressBar(QFrame * f, QLabel * lb){
    progressBar = f;
    lbProgress = lb;
    setValue(0);

}

void EstructuraProgressBar::setValue(int value){
    //progressBar->resize(value, 20);
    lbProgress->setText(QString::number(value)+" %");
    lbProgress->update();
}
