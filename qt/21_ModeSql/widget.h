#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlField>
#include <QTableView>
#include <QMessageBox>
#include <QSqlTableModel>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btnAdd_clicked();

    void on_btnDelete_clicked();

    void on_btnQuery_clicked();

private:
    Ui::Widget *ui;
    QSqlTableModel *tblMode;
    QSqlDatabase dataBase;

};
#endif // WIDGET_H
