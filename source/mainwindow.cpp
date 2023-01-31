#include "mainwindow.h"

#include <QCloseEvent>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QTimer>

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  setWindowTitle(QApplication::applicationName());

  ui->number_button_->setText("Click");
  ui->number_button_->setStyleSheet(QString("color: black"));
  ui->number_button_->setEnabled(false);

  connect(ui->number_button_, &QPushButton::clicked, this,
          &MainWindow::OnNumberButtonClicked);

  timer_ = new QTimer(this);
  connect(timer_, &QTimer::timeout, this, &MainWindow::ChangeLabels);
  connect(timer_, &QTimer::timeout, this, &MainWindow::SetRandomNumber);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::StartGame() {
  count_on_number_clicked_ = 0;
  correct_count_ = 0;
  incorrect_count_ = 0;
  ui->correct_counter_->setNum(correct_count_);
  ui->incorrect_counter_->setNum(incorrect_count_);
  SetRandomNumber();
  ui->number_button_->setEnabled(true);
  timer_->start(kGameTime);
}
void MainWindow::OnNumberButtonClicked() {
  ++count_on_number_clicked_;
  ui->number_button_->setStyleSheet(QString("color: yellow"));
};

void MainWindow::SetRandomNumber() {
  ui->number_button_->setText(
      QString::number(QRandomGenerator::global()->bounded(kHightestNumber)));

  ui->number_button_->setStyleSheet(QString("color: black"));
}

void MainWindow::ChangeLabels() {
  qDebug() << count_on_number_clicked_ << ui->number_button_->text().toInt();

  if (ui->number_button_->text().toInt() == count_on_number_clicked_) {
    ui->correct_counter_->setNum(++correct_count_);
    count_on_number_clicked_ = 0;
  } else {
    ui->incorrect_counter_->setNum(++incorrect_count_);
    count_on_number_clicked_ = 0;
  }
}

void MainWindow::closeEvent(QCloseEvent* event) {
  QMessageBox msg_box;
  msg_box.setText(tr("Приходите ещё."));
  QAbstractButton* button_yes =
      msg_box.addButton(tr("Обязательно приду"), QMessageBox::YesRole);

  msg_box.exec();

  if (msg_box.clickedButton() == button_yes) {
    event->accept();
  } else {
    event->ignore();
  }
}

void MainWindow::on_start_button__clicked() { StartGame(); }

void MainWindow::on_stop_button__clicked() {
  timer_->stop();
  ui->number_button_->setEnabled(false);
}
