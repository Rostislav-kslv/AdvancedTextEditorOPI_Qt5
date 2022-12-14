#include "mainwindow.hpp"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      m_changed(false),
      m_path("") {
  ui->setupUi(this);
  setCentralWidget(ui->textEdit);

  newFile();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_actionNew_triggered() {
  checkSave();
  newFile();
}

void MainWindow::on_actionOpen_triggered() {
  checkSave();
  openFile();
}

void MainWindow::on_actionSave_triggered() { saveFile(m_path); }

void MainWindow::on_actionSave_as_triggered() { saveFileAs(); }

void MainWindow::on_actionExit_triggered() { close(); }

void MainWindow::on_actionCopy_triggered() {}

void MainWindow::on_actionCut_triggered() {}

void MainWindow::on_actionPaste_triggered() {}

void MainWindow::on_actionFind_triggered() {}

void MainWindow::on_actionReplace_triggered() {}

void MainWindow::on_actionSelect_all_triggered() {}

void MainWindow::on_actionZoom_ib_triggered() {}

void MainWindow::on_actionZoom_out_triggered() {}

void MainWindow::on_actionBold_triggered() {}

void MainWindow::on_actionItalic_triggered() {}

void MainWindow::on_actionUnderline_triggered() {}

void MainWindow::on_actionStrike_triggered() {}

void MainWindow::on_actionColor_triggered() {}

void MainWindow::on_actionFont_triggered() {}

void MainWindow::on_actionHelp_triggered() {}

void MainWindow::on_actionAbout_triggered() {}

void MainWindow::on_textEdit_textChanged() { m_changed = true; }

void MainWindow::newFile() {
  ui->textEdit->clear();
  ui->statusbar->showMessage("New File");
  m_path = "";
  m_changed = false;
}

void MainWindow::openFile() {
  QString path = QFileDialog::getOpenFileName(this, "Open file");

  if (path.isEmpty()) return;

  QFile file(path);
  if (!file.open(QIODevice::ReadOnly)) {
    QMessageBox::critical(this, "Error", file.errorString());
    return;
  }
  QTextStream stream(&file);
  ui->textEdit->setHtml(stream.readAll());
  file.close();

  m_path = path;
  ui->statusbar->showMessage(m_path);
  m_changed = false;
}

void MainWindow::saveFile(QString path) {
  if (path.isEmpty()) {
    saveFileAs();
    return;
  }
  QFile file(path);

  if (!file.open(QIODevice::WriteOnly)) {
    QMessageBox::critical(this, "Error", file.errorString());
    ui->statusbar->showMessage("Error, could not save the file");
    saveFileAs();
    return;
  }

  QTextStream stream(&file);
  stream << ui->textEdit->toHtml();
  file.close();

  m_path = path;
  m_changed = false;
  ui->statusbar->showMessage(m_path);
}

void MainWindow::saveFileAs() {
  QString path = QFileDialog::getSaveFileName(this, "Save file");
  if (path.isEmpty()) return;
  saveFile(path);
}

void MainWindow::checkSave() {
  if (m_changed == false) return;

  QMessageBox::StandardButton value = QMessageBox::question(
      this, "Save File?", "Do you want to save your changes befor the exit?");
  if (value != QMessageBox::StandardButton::Yes) return;
  if (m_path.isEmpty()) {
    saveFileAs();
  } else {
    saveFile(m_path);
  }
}

void MainWindow::closeEvent(QCloseEvent *event) { event->accept(); }
