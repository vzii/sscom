# sscom
Linux版本 串口调试助手

# 效果
## Linux预览效果
![GitHub Logo](/assert/sscom_for_linux_0.2.png)

## Mac预览效果
tHub Logo](/assert/sscom_for_mac.png)

## 未实现功能
![GitHub Logo](/assert/sscom_for_linux_0.2_unspport.png)

# 使用
两种方法，下载编译好的；下载源码自行编译。

## 下载编译好的
移步至 https://github.com/kangear/sscom/releases 下载AppImage版本，可以任意Linux发行版直接运行。如果运行不了，记得提issue。

## Linux自行源码编译
```shell
sudo apt-get install qtcreator libqt5serialport5-dev libudev-dev qt5-default
qmake 
make
```
## Mac自行源码编译
```shell
brew install qt5
qmake 
make
```

# 解决
```
sscom.pro:12: Unable to find file for inclusion /src/serialport/qt4support/serialport.pr，
要使用qt5编译 ，
```
