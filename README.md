# Qt Programming Recipes

## Table of contents

### [Qt入门](getting_started)
- [Hello Qt](getting_started/hello_qt)
- [建立连接](getting_started/making_connections)
- [窗口部件的布局](getting_started/laying_out_widgets)

### [窗件和设计师](widgets_and_designer)
- [设计师简介](widgets_and_designer/designer_introduction)
- [设计师和代码的集成](widgets_and_designer/designer_integration_with_code)

### [创建对话框](creating_dialogs)
- [子类化QDialog](creating_dialogs/subclassing_qdialog)
- [快速设计对话框](creating_dialogs/rapid_dialog_design)
- [改变形状的对话框](creating_dialogs/shape_changing_dialogs)
- [动态对话框](creating_dialogs/dynamic_dialogs)

### [创建自定义窗口部件](creating_custom_widgets)
- [自定义Qt窗口部件](creating_custom_widgets/customizing_qt_widgets)
- [子类化QWidgets](creating_custom_widgets/subclassing_qwidget)

### [创建主窗口](creating_main_windows)
- [子类化QMainWindow](creating_main_windows/subclassing_qmainwindow)
- [停靠窗口和工具栏](creating_main_windows/dock_windows_and_toolbars)
- [多文档界面](creating_main_windows/multiple_document_interface)

### [布局管理](layout_management)
- [窗件的布局](layout_management/layout_of_widgets)
- [分组布局](layout_management/stacked_layouts)
- [切分窗口](layout_management/splitters)

### [事件处理](event_processing)
- [重新实现事件处理器](event_processing/reimplementing_event_handlers)
- [获取鼠标事件](event_processing/processing_mouse_event)


### Ubuntu24.04 apt 安装 Qt6

```bash
$ sudo apt update
$ sudo apt install qt6-base-dev qt6-tools-dev qt6-declarative-dev qtcreator
$ qmake6 --version
QMake version 3.1
Using Qt version 6.4.2 in /usr/lib/x86_64-linux-gnu
```

### Ubuntu22.04 apt 安装 Qt5

```bash
$ sudo apt update
$ sudo apt install qtbase5-dev qt5-qmake qtbase5-dev-tools qttools5-dev-tools qttools5-dev
$ qmake --version
QMake version 3.1
Using Qt version 5.15.3 in /usr/lib/x86_64-linux-gnu
```
