#include <QApplication>

#include "mainwindow.hpp"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  a.setOrganizationName("Rostislav Kiselyov");
  a.setOrganizationDomain("https://www.linkedin.com/in/rostislav-kiselev/");
  a.setApplicationName("AEdit an advanced editor");
  a.setApplicationVersion("0.1.0 Beta");
  MainWindow w;
  w.show();
  return a.exec();
}
