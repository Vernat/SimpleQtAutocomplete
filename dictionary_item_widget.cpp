#include "dictionary_item_widget.h"
#include "ui_dictionary_item_widget.h"
#include <QPalette>

DictionaryItemWidget::DictionaryItemWidget(const DictionaryItem &item,
                                           QWidget *parent)
    : QWidget(parent), ui(new Ui::DictionaryItemWidget), item(item) {
  ui->setupUi(this);
  ui->name->setText(item.name);
  ui->description->setText(item.description);
  setFixedHeight(DICTIONARY_WIDGET_HEIGHT);
  setFixedSize(DICTIONARY_WIDGET_WIDTH, DICTIONARY_WIDGET_HEIGHT);
}

DictionaryItemWidget::~DictionaryItemWidget() { delete ui; }

QString DictionaryItemWidget::name() const { return item.name; }

void DictionaryItemWidget::enterEvent(QEvent *event) {
  changeTextColor(Qt::lightGray);
  return QWidget::enterEvent(event);
}

void DictionaryItemWidget::leaveEvent(QEvent *event) {
  changeTextColor(Qt::black);
  return QWidget::leaveEvent(event);
}

void DictionaryItemWidget::changeTextColor(const Qt::GlobalColor color) {
  QPalette p(palette());
  p.setColor(QPalette::WindowText, color);
  setPalette(p);
}
