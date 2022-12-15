#include "aboutdialog.hpp"

#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::AboutDialog) {
  ui->setupUi(this);
  ui->lblName->setText(QApplication::applicationName());
  ui->lblVersion->setText(QApplication::applicationVersion());
  ui->lblOrganization->setText(QApplication::organizationName());
  ui->lblUrl->setText(QApplication::organizationDomain());
}

AboutDialog::~AboutDialog() { delete ui; }

void AboutDialog::on_buttonBox_accepted() { accept(); }
