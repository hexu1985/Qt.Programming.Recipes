#ifndef MY_DIALOGS_INC
#define MY_DIALOGS_INC

#include <QString>
#include <QMainWindow> 

class Dialogs: public QMainWindow {
    Q_OBJECT

public:
    Dialogs();

private slots:
    void askQuestion(); 
    void askDumbQuestion(); 

private:
    QString answer; 
};

#endif
