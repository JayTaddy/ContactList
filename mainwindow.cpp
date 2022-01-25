#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "contactlistprovider.h"
#include <QScrollArea>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QPalette>
#include <QLabel>
#include <QPixmap>
#include <QRegion>
#include <QCheckBox>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  this->setWindowTitle("Contact List Viewer");
  this->setMinimumSize(490,400);

  ContacListProvider *contact = new ContacListProvider();
  contact->addContact("Sviatoslav", "Trenchuk");
  contact->addContact("Sviatoslav", "Trenchuk");
  contact->addContact("Sviatoslav", "Trenchuk");
  contact->addContact("Sviatoslav", "Trenchuk");
  contact->addContact("Sviatoslav", "Trenchuk");
  contact->addContact("Sviatoslav", "Trenchuk");
  contact->addContact("Sviatoslav", "Trenchuk");
  contact->addContact("Sviatoslav", "Trenchuk");
  contact->addContact("Sviatoslav", "Trenchuk");
  contact->addContact("Sviatoslav", "Trenchuk");
  contact->addContact("Sviatoslav", "Trenchuk");
  contact->addContact("Sviatoslav", "Trenchuk");
  contact->addContact("Sviatoslav", "Trenchuk");
  contact->addContact("Sviatoslav", "Trenchuk");
  contact->addContact("Sviatoslav", "Trenchuk");
  contact->addContact("Sviatoslav", "Trenchuk");
  contact->addContact("Sviatoslav", "Trenchuk");


  QScrollArea *scrollArea = new QScrollArea(this);
  QWidget * pWgt = new QWidget;

  QVBoxLayout *pLayout = new QVBoxLayout();

  QPalette paletteForButtons;
  paletteForButtons.setColor(QPalette::Button, QColor(Qt::cyan));
  QPalette paletteIfFavourite;
  paletteIfFavourite.setColor(QPalette::Button, QColor(Qt::red));

  QPixmap contactImage (":/download.png");

  for(unsigned int counter = 0; counter < contact->getNumberOfContacts(); counter++) {
    QPushButton *pBtn = new QPushButton(this);
    pBtn->setAutoFillBackground(true);
    pBtn->setText(QString::fromStdString(contact->getFirstName(counter)) + " " + QString::fromStdString(contact->getSecondName(counter)));
    pBtn->setPalette(paletteForButtons);
    pBtn->setMinimumSize(450, 50);
    pLayout->addWidget(pBtn);

    QCheckBox *cBtn = new QCheckBox(pBtn);
    cBtn->move(430, 20);

    QLabel *labelForImage = new QLabel(pBtn);

    labelForImage->setPixmap(contactImage);
    labelForImage->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    labelForImage->setFixedSize(50, 50);
    QRegion *region = new QRegion(0, 0, labelForImage->width(), labelForImage->height(), QRegion::Ellipse);
    labelForImage->setScaledContents(true);
    labelForImage->setMask(*region);
  }

  pWgt->setLayout(pLayout);
  scrollArea->setWidget(pWgt);
  setCentralWidget(scrollArea);
}

void MainWindow::handleButton() {

}

void MainWindow::checkButton(){

}

MainWindow::~MainWindow()
{
  delete ui;
}

