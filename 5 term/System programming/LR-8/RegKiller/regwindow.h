#ifndef REGWINDOW_H
#define REGWINDOW_H

#include <QMainWindow>
#include <windows.h>

#include <settingswindow.h>

#include <Entities/regunit.h>

#include <Services/regworkerservice.h>

QT_BEGIN_NAMESPACE
namespace Ui { class RegWindow; }
QT_END_NAMESPACE

class RegWindow : public QMainWindow
{
    Q_OBJECT

public:
    RegWindow(QWidget *parent = nullptr);
    ~RegWindow();

private slots:
    void on_searchButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::RegWindow *ui;
    RegWorkerService *regWorkerService;
    uint option;

    void regRead(LPCTSTR subkey, LPCTSTR name, DWORD type);
};
#endif // REGWINDOW_H
