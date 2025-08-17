#include <QTextStream>
#include <QString>
#include <QFile>

QTextStream cout(stdout);
QTextStream cerr(stderr);

int main() {
    QString str, newstr;
    QTextStream strbuf(&str);             /* strbuf is initialized with the address of str.*/

    int lucky = 7;
    float pi = 3.14;
    double e = 2.71;

    cout << "An in-memory stream" << Qt::endl;
    strbuf << "luckynumber: " << lucky << Qt::endl
        << "pi: " << pi << Qt::endl
        << "e: " << e << Qt::endl;

    cout << str;

    QFile data("mydata");
    data.open(QIODevice::WriteOnly);      /* Creates (or overwrites)
                                             a disk file for output. */
    QTextStream out(&data);               /* An output file stream. */
    out << str ;
    data.close();

    cout << "Read data from the file - watch for errors." << Qt::endl;
    if(data.open(QIODevice::ReadOnly)) {  /* Make sure the file exists before
                                             attempting to read.*/
        QTextStream in(&data);              /* An input file stream. */
        int lucky2;
        in >> newstr >> lucky2;
        if (lucky != lucky2)
            cerr << "ERROR! wrong " << newstr << lucky2  << Qt::endl;
        else
            cout << newstr << " OK" << Qt::endl;

        float pi2;
        in >> newstr >> pi2;
        if (pi2 != pi)
            cerr << "ERROR! Wrong " << newstr << pi2 << Qt::endl;
        else
            cout << newstr << " OK" << Qt::endl;

        double e2;
        in >> newstr >> e2;
        if (e2 != e)
            cerr << "ERROR: Wrong " << newstr << e2 <<  Qt::endl;
        else
            cout << newstr << " OK" << Qt::endl;
        data.close();
    }

    cout << "Read from file line-by-line" << Qt::endl;
    if(data.open(QIODevice::ReadOnly)) {
        QTextStream in(&data);              /* An input file stream. */
        while (not in.atEnd()) {
            newstr = in.readLine();
            cout << newstr << Qt::endl;
        }
        data.close();
    }
    return 0;
}
