#include "dictionary_item_widget.h"
#include "ui_dictionary_item_widget.h"
#include <QFontMetrics>
#include <QPalette>

const int TEXT_ELIDING_OFFSET = 23;

DictionaryItemWidget::DictionaryItemWidget(const QString &inputText,
                                           const DictionaryItem &item,
                                           QWidget *parent)
    : QWidget(parent), ui(new Ui::DictionaryItemWidget), item(item) {
  ui->setupUi(this);
  ui->prefix->setText(inputText);
  const auto suffixText = item.name.mid(inputText.size());
  ui->suffix->setText(suffixText);
  QFontMetrics prefixFontMetrics(ui->prefix->font());
  QFontMetrics nameFontMetrics(ui->suffix->font());
  QFontMetrics descriptionFontMetrics(ui->description->font());
  const auto descriptionLength =
      width() - prefixFontMetrics.horizontalAdvance(inputText) -
      nameFontMetrics.horizontalAdvance(suffixText) - TEXT_ELIDING_OFFSET;
  ui->description->setText(descriptionFontMetrics.elidedText(
      item.description, Qt::ElideRight, descriptionLength));
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

void DictionaryItemWidget::mouseReleaseEvent(QMouseEvent *event) {
  emit selected(item);
  return QWidget::mouseReleaseEvent(event);
}

void DictionaryItemWidget::changeTextColor(const Qt::GlobalColor color) {
  QPalette p(palette());
  p.setColor(QPalette::WindowText, color);
  setPalette(p);
}
