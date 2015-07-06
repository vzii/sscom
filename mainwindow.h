#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QFont>
#include <QPushButton>
#include <QLineEdit>
#include <QtSerialPort/QSerialPort>
#include <QIntValidator>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    struct Settings {
        QString name;
        qint32 baudRate;
        QString stringBaudRate;
        QSerialPort::DataBits dataBits;
        QString stringDataBits;
        QSerialPort::Parity parity;
        QString stringParity;
        QSerialPort::StopBits stopBits;
        QString stringStopBits;
        QSerialPort::FlowControl flowControl;
        QString stringFlowControl;
        bool localEchoEnabled;
        bool sendNewLineEnabled;
        QString stringStatus;
    }DEF_SETTINGS = {
        "",
        QSerialPort::BaudRate::Baud115200,
        QString::number(QSerialPort::Baud115200),
        QSerialPort::DataBits::Data8,
        QString::number(QSerialPort::DataBits::Data8),
        QSerialPort::Parity::NoParity,
        QString::number(QSerialPort::Parity::NoParity),
        QSerialPort::StopBits::OneStop,
        QString::number(QSerialPort::StopBits::OneStop),
        QSerialPort::FlowControl::NoFlowControl,
        QString::number(QSerialPort::FlowControl::NoFlowControl),
        false,
        true,
        ""
    };
    Settings settings() const;

private slots:
    void checkCustomBaudRatePolicy(int idx);
    void on_openserial_pushButton_pressed();
    void on_openfile_pushButton_released();
    void handleError(QSerialPort::SerialPortError error);
    void writeData();
    void readData();
    void currentIndexChanged();
    void serialPortChanged();

    void on_clear_pushButton_released();

private:
    Ui::MainWindow *ui;
    QStatusBar *mStatusBar;
    /** 网址 */
    QLabel *mStatusLabel;
    /** 状态标签 */
    QLabel *mNetAddrLabel;
    /** led */
    QLabel *mLedLabel;
    QFont font;
    /** 总接收数量显示标签 */
    QLabel *mReceiveLabel;
    /** 总发送数量显示标签 */
    QLabel *mSendLabel;
    bool isOn;
    void init();
    /** 文件路径 */
    QString mFilePath;
    QPushButton *mSendButton;
    QPushButton *mSendFileButton;
    QPushButton *mOpenSerialButton;

    QLineEdit *mOpenFileLineEdit;
    QLineEdit *mTimerSendLineEdit;

    QSerialPort *serial;
    QIntValidator *intValidator;
    void fillPortsParameters();
    Settings currentSettings;
    void updateSettings();
    void fillPortsInfo();

    bool openSerialPort();
    void closeSerialPort();
    void about();
    bool setParameter(QSerialPort *serial, Settings settings);
    Settings doSettings(bool isWrite, Settings inSettings);
};

#endif // MAINWINDOW_H
