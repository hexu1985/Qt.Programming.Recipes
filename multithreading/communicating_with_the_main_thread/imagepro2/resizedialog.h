#ifndef RESIZEDIALOG_H
#define RESIZEDIALOG_H

#include <QDialog>
#include <QSpinBox>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

class ResizeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ResizeDialog(QWidget *parent = nullptr);
    ~ResizeDialog();

    int getWidth() const;
    int getHeight() const;

    void setWidth(int value);
    void setHeight(int value);

private:
    QVBoxLayout *verticalLayout;
    QLabel *mainLabel;
    QHBoxLayout *horizontalLayout;
    QSpinBox *widthSpinBox;
    QLabel *xLabel;
    QSpinBox *heightSpinBox;
    QHBoxLayout *buttonLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okButton;
    QPushButton *cancelButton;
};

#endif // RESIZEDIALOG_H
