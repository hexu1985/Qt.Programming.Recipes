#include "window.h"
#include <QFrame>
#include <QLabel>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

Window::Window(QWidget *parent)
    : QWidget(parent)
{
   setMinimumSize(500, 600);

   QLabel *label = new QLabel();
   label->setText("Label with a Frame");
   label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
   label->setFrameStyle(QFrame::Panel | QFrame::Raised);
   label->setLineWidth(3);
   label->setMinimumSize(25, 30);

   auto *frame1 = new QFrame(this);
   frame1->setFrameStyle(QFrame::Box);
   frame1->setLineWidth(3);
   frame1->setMidLineWidth(2);
   frame1->setMinimumSize(25, 30);

   auto *frame2 = new QFrame(this);
   frame2->setFrameStyle(QFrame::Box | QFrame::Raised);
   frame2->setLineWidth(3);
   frame2->setMidLineWidth(2);
   frame2->setMinimumSize(25, 30);

   auto *frame3 = new QFrame(this);
   frame3->setFrameStyle(QFrame::Box | QFrame::Sunken);
   frame3->setLineWidth(3);
   frame3->setMidLineWidth(2);
   frame3->setMinimumSize(25, 30);

   QPushButton *pb_close = new QPushButton();
   pb_close->setText("Close");

   QGridLayout *grid = new QGridLayout();
   grid->setVerticalSpacing(20);

   grid->addWidget(label);
   grid->addWidget(frame1);
   grid->addWidget(frame2);
   grid->addWidget(frame3);

   QHBoxLayout *layout = new QHBoxLayout();
   layout->addStretch();
   layout->addWidget(pb_close);
   layout->addStretch();

   QVBoxLayout *layout_main = new QVBoxLayout(this);
   layout_main->addLayout(grid);
   layout_main->addSpacing(25);
   layout_main->addLayout(layout);

   connect(pb_close, &QPushButton::clicked, this, &QWidget::close);
}


