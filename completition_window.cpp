#include "completition_window.h"
#include "dictionary_item.h"
#include "dictionary_item_widget.h"
#include "ui_completition.h"
#include <QDebug>
#include <QListWidgetItem>

CompletitionWindow::CompletitionWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::Completition) {
  ui->setupUi(this);
  QVBoxLayout *layout = new QVBoxLayout;
  widgetsFrameLayout = new QVBoxLayout;
  ui->widgetsFrame->setLayout(layout);
  ui->widgetsFrame->setFixedWidth(DICTIONARY_WIDGET_WIDTH);

  setWindowFlags(Qt::Window | Qt::FramelessWindowHint |
                 Qt::WindowStaysOnTopHint);
  setAttribute(Qt::WA_ShowWithoutActivating, true);
}

CompletitionWindow::~CompletitionWindow() { delete ui; }

void CompletitionWindow::setItems(const QList<DictionaryItem> &items) {

  this->items = items;
  removeOldWidgets();
  createNewWidgets();
  adjustSize();
}

void CompletitionWindow::createNewWidgets() {
  for (const auto &item : items) {
    auto dictionaryItem = new DictionaryItemWidget(item);
    ui->widgetsFrame->layout()->addWidget(dictionaryItem);
    dictionaryWidgets.insert(item.name, dictionaryItem);
  }
}

void CompletitionWindow::removeOldWidgets() {
  auto it = dictionaryWidgets.begin();
  while (it != dictionaryWidgets.end()) {
    it.value()->deleteLater();
    ++it;
  }
  dictionaryWidgets.clear();
}

void CompletitionWindow::adjustSize() {
  const auto newHeight = items.size() * DICTIONARY_WIDGET_HEIGHT;
  ui->widgetsFrame->setFixedHeight(newHeight + 10);
  setFixedHeight(newHeight);
}
