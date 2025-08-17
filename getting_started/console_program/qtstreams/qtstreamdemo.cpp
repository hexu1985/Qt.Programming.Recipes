#include <QTextStream>
#include <QDebug>

QTextStream cin(stdin);
QTextStream cout(stdout);
QTextStream cerr(stderr);

int main() {
    int num1(1234), num2(2345) ;
    cout << Qt::oct << num2 << '\t'
        << Qt::hex << num2 << '\t'
        << Qt::dec << num2 
        << Qt::endl;
    double dub(1357);
    cout << dub << '\t'
        << Qt::forcesign << dub << '\t'
        << Qt::forcepoint << dub 
        << Qt::endl;
    dub = 1234.5678;
    cout << dub << '\t'
        << Qt::fixed << dub << '\t'
        << Qt::scientific << dub << '\n'
        << Qt::noforcesign << dub 
        << Qt::endl;
    qDebug() << "Here is a debug message with " << dub << "in it." ;
    qDebug("Here is one with the number %d in it.", num1 );
}
/*OUT
  4451    929     2345
  1357    +1357   +1357.00
  +1234.57        +1234.567800    +1.234568e+03
  1.234568e+03
  Here is a debug message with  1234.57 in it.
  Here is one with the number 1234 in it.
  */
