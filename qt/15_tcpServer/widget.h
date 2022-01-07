#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <QPixmap>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QString getClientInfo(QTcpSocket *client);


private:
    Ui::Widget *ui;
    QTcpServer *server = nullptr;
    QVector<QTcpSocket*> clients;
    QMap<QString, QTcpSocket*> clientMap;
    QPixmap pix; // for icon

};
#endif // WIDGET_H
