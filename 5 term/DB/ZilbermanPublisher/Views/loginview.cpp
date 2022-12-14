#include "loginview.h"
#include "ui_loginview.h"

LoginView::LoginView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginView)
{
    ui->setupUi(this);
    dbService = new DatabaseService();
}

LoginView::~LoginView()
{
    delete ui;
}

void LoginView::on_pushButton_clicked()
{
    QString login = ui->username_edit->text();
    QString password = ui->password_edit->text();

    Manager *loginUser = dbService->getManager(login, password);
    if (loginUser == NULL)
        return;

    QMessageBox::information(0, "Добро пожаловать", "Здравствуйте, " + loginUser->getName() + " " + loginUser->getPatronymic() + "!");

    if(loginUser->getPosition() == "Client manager") {
        ClientMangerView *clientView = new ClientMangerView(this->dbService, loginUser);
        clientView->show();
    }
    else if(loginUser->getPosition() == "Print center manager") {
        PrintCenterManagerView *printCenterView = new PrintCenterManagerView(this->dbService, loginUser);
        printCenterView->show();
    }
    else if(loginUser->getPosition() == "Administrator") {
        AdminView *adminView = new AdminView(this->dbService, loginUser);
        adminView->show();
    }

    this->close();
}

