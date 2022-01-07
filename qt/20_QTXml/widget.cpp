#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //readXmlDom();
    writeXmlDom();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::readXmlDom()
{
    // 打开xml文件
    QFile file(":/test.xml");
    if(!file.open(QFile::ReadOnly))
    {
        QMessageBox::critical(this,"critical","open file error");
        return;
    }

    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        qDebug()<< "set dom content error";
        return;
    }

    file.close();
    //  获取根节点
    QDomElement root = doc.documentElement();
    qDebug() << root.nodeName() << " " << root.tagName();
    // 获取第一个子节点
    QDomNode node = root.firstChild();
    //如果节点不为空
    while(!node.isNull())
    {
        if(node.isElement()) //如果节点是元素
        {
            QDomElement e = node.toElement(); // 转换为元素
            qDebug() << e.tagName()<<" " << e.attribute("id")<<" " << e.attribute("time");
            QDomNodeList lists = e.childNodes();
            for(int i=0;i<lists.count();i++)
            {
                QDomNode n = lists.at(i);
                if(node.isElement())
                {
                    qDebug()<<n.nodeName()<<":"<<n.toElement().text();
                }
            }
            node = node.nextSibling();
        }
    }

}
//生成一个xml文件
void Widget::writeXmlDom()
{
    QFile file("test2.xml");
    if(!file.open(QFile::WriteOnly|QFile::Truncate))
    {
        QMessageBox::critical(this,"critical","open file failed");
        return;
    }

    QDomDocument doc;
    // 写入xml头部
    QDomProcessingInstruction instruction;
    instruction = doc.createProcessingInstruction("xml","version=\"1.0\",encoding=\"UTF-8\"");
    doc.appendChild(instruction);

    //添加根节点
    QDomElement root = doc.createElement("library");
    doc.appendChild(root);

    // 添加第一个子节点及其子元素
    QDomElement book = doc.createElement("book");
    book.setAttribute("id",1);  //创建属性的 第一种方式
    QDomAttr time = doc.createAttribute("time"); // 创建属性的第二种方式
    time.setValue("2013/6/13");
    book.setAttributeNode(time);

    //创建子元素
    QDomElement title = doc.createElement("title");
    QDomText txt = doc.createTextNode("C++ Primary");
    book.appendChild(title);
    title.appendChild(txt);

    // 第二个子元素
    QDomElement author = doc.createElement("author");
    txt = doc.createTextNode("Stanley Lippman");
    author.appendChild(txt);
    book.appendChild(author);

    root.appendChild(book);

    // 第二个子节点及其 子元素
    book = doc.createElement("book");
    book.setAttribute("id",2);
    time=doc.createAttribute("time");
    time.setValue("2007/5/25");
    book.setAttributeNode(time);
    title=doc.createElement("title");
    txt = doc.createTextNode("Thinking java");
    book.appendChild(title);
    title.appendChild(txt);

    author = doc.createElement("author");
    txt = doc.createTextNode("Bruce Eckel");
    author.appendChild(txt);
    book.appendChild(author);

    root.appendChild(book);

    // 写入文件
    QTextStream outStream(&file);
    doc.save(outStream,4);//缩进4格
    file.close();
}
