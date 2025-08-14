#include <QString>
#include <QTextStream>

QTextStream cout(stdout);  /* Define QTextStreams that look like C++ 
                            standard iostreams. */
QTextStream cin(stdin);

int main() {
    QString s1("This "), s2("is a "), s3("string.");
    s1 += s2;  // concatenation
    QString s4 = s1 + s3;
    cout << s4 << Qt::endl;
    cout << "The length of that string is " << s4.length() << Qt::endl;
    cout << "Enter a sentence with whitespaces: " << Qt::endl;
    s2 = cin.readLine();     /* not iostream, QTextStream::readLine()! */
    cout << "Here is your sentence: \n" << s2 << Qt::endl;
    cout << "The length of your sentence is: " << s2.length() << Qt::endl;
    return 0;
}

