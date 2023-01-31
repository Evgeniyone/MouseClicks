#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
  void OnNumberButtonClicked();
  void SetRandomNumber();
  void ChangeLabels();
  void closeEvent(QCloseEvent *event);

  void on_start_button__clicked();

  void on_stop_button__clicked();

 private:
  void StartGame();

  Ui::MainWindow *ui;
  uint8_t count_on_number_clicked_ = 0;
  QTimer *timer_ = nullptr;
  int correct_count_ = 0;
  int incorrect_count_ = 0;
  const uint8_t kHightestNumber = 10;
  const int kGameTime = 2000;  // 2 seconds
};
#endif  // MAINWINDOW_H
