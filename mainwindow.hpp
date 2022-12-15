#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QApplication>
#include <QCloseEvent>
#include <QColorDialog>
#include <QDesktopServices>
#include <QFile>
#include <QFileDialog>
#include <QFontDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QTextStream>
#include <QUrl>

#include "aboutdialog.hpp"
#include "finddialog.hpp"
#include "replacedialog.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_actionNew_triggered();

  void on_actionOpen_triggered();

  void on_actionSave_triggered();

  void on_actionSave_as_triggered();

  void on_actionExit_triggered();

  void on_actionCut_triggered();

  void on_actionCopy_triggered();

  void on_actionPaste_triggered();

  void on_actionFind_triggered();

  void on_actionReplace_triggered();

  void on_actionSelect_all_triggered();

  void on_actionZoom_in_triggered();

  void on_actionZoom_out_triggered();

  void on_actionBold_triggered();

  void on_actionItalic_triggered();

  void on_actionUnderline_triggered();

  void on_actionStrike_triggered();

  void on_actionColor_triggered();

  void on_actionFont_triggered();

  void on_actionHelp_triggered();

  void on_actionAbout_triggered();

  void on_textEdit_textChanged();

  void on_actionUndo_triggered();

  void on_actionRedo_triggered();

 private:
  Ui::MainWindow *ui;

  bool m_changed;
  QString m_path;

  void openFile();
  void newFile();
  void saveFile(QString path);
  void saveFileAs();
  void checkSave();

  // QWidget interface
 protected:
  void closeEvent(QCloseEvent *event) override;
};
#endif  // MAINWINDOW_HPP
