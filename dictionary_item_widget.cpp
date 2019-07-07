#include "dictionary_item_widget.h"
#include "ui_dictionary_item_widget.h"

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
