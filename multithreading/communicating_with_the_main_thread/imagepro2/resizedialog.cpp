#include "resizedialog.h"

ResizeDialog::ResizeDialog(QWidget *parent)
    : QDialog(parent)
{
    // 设置对话框属性
    setGeometry(0, 0, 190, 129);
    setWindowTitle("Image Pro");

    // 创建主垂直布局
    verticalLayout = new QVBoxLayout(this);

    // 创建主标签
    mainLabel = new QLabel(this);
    mainLabel->setText("Enter new size:");
    verticalLayout->addWidget(mainLabel);

    // 创建水平布局用于宽高输入
    horizontalLayout = new QHBoxLayout();

    // 创建宽度SpinBox
    widthSpinBox = new QSpinBox(this);
    QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    widthSpinBox->setSizePolicy(sizePolicy);
    widthSpinBox->setMaximum(10000);
    horizontalLayout->addWidget(widthSpinBox);

    // 创建x标签
    xLabel = new QLabel(this);
    xLabel->setText("x");
    xLabel->setAlignment(Qt::AlignCenter);
    horizontalLayout->addWidget(xLabel);

    // 创建高度SpinBox
    heightSpinBox = new QSpinBox(this);
    heightSpinBox->setSizePolicy(sizePolicy);
    heightSpinBox->setMaximum(10000);
    horizontalLayout->addWidget(heightSpinBox);

    verticalLayout->addLayout(horizontalLayout);

    // 创建按钮布局
    buttonLayout = new QHBoxLayout();

    // 创建水平弹簧
    horizontalSpacer = new QSpacerItem(0, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);
    buttonLayout->addItem(horizontalSpacer);

    // 创建OK按钮
    okButton = new QPushButton(this);
    okButton->setText("OK");
    okButton->setDefault(true);
    buttonLayout->addWidget(okButton);

    // 创建Cancel按钮
    cancelButton = new QPushButton(this);
    cancelButton->setText("Cancel");
    buttonLayout->addWidget(cancelButton);

    verticalLayout->addLayout(buttonLayout);

    // 连接信号和槽
    connect(okButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);
}

ResizeDialog::~ResizeDialog()
{
    // 自动删除所有子部件和布局
}

int ResizeDialog::getWidth() const
{
    return widthSpinBox->value();
}

int ResizeDialog::getHeight() const
{
    return heightSpinBox->value();
}

void ResizeDialog::setWidth(int value)
{
    widthSpinBox->setValue(value);
}

void ResizeDialog::setHeight(int value)
{
    heightSpinBox->setValue(value);
}
