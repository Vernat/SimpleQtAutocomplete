#include "widget.h"
#include "completer.h"
#include "fake_dictionary_provider.h"
#include "simple_matcher.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);
  std::shared_ptr<AbstractMatcher> matcher = std::make_shared<SimpleMatcher>();
  std::shared_ptr<AbstractDictionaryProvider> dictionaryProvider =
      std::make_shared<FakeDictionaryProvider>();
  completer = new Completer(ui->searchEdit, matcher, dictionaryProvider, this);

  connect(completer, &AbstractCompleter::selected, this,
          &Widget::showSelectedItem);
}

Widget::~Widget() { delete ui; }

void Widget::showSelectedItem(const DictionaryItem &item) {
  ui->valueView->setText(item.name);
  ui->descriptionView->setText(item.description);
}
