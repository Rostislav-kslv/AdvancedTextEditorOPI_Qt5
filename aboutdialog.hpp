#ifndef ABOUTDIALOG_HPP
#define ABOUTDIALOG_HPP

#include <QDialog>

namespace Ui {
class AboutDialog;
}

class AboutDialog : public QDialog {
  Q_OBJECT

 public:
  explicit AboutDialog(QWidget *parent = nullptr);
  ~AboutDialog();

 private slots:
  void on_buttonBox_accepted();

 private:
  Ui::AboutDialog *ui;
};

#endif  // ABOUTDIALOG_HPP
