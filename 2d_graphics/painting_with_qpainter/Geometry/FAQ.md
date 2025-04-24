### 在 Ubuntu 上，Qt 程序无法接收到 moveEvent 事件可能的原因

窗口管理器兼容性问题

Ubuntu 的默认窗口管理器（如 GNOME/Mutter 或 KWin）可能对移动事件的处理方式不同。

强制使用 X11 后端

在 Qt 5 中，某些 Wayland 合成器可能不会正确传递窗口移动事件。尝试强制使用 X11：

```bash
$ QT_QPA_PLATFORM=xcb ./build/Geometry
```
