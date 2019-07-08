#include "widget.h"
#include "completer.h"
#include "completition_window.h"
#include "fake_dictionary_provider.h"
#include "simple_matcher.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);
  completitionWindow = new CompletitionWindow();
  std::shared_ptr<AbstractMatcher> matcher = std::make_shared<SimpleMatcher>();
  std::shared_ptr<AbstractDictionaryProvider> dictionaryProvider =
      std::make_shared<FakeDictionaryProvider>();
  dictionary = dictionaryProvider->getDictionary();
  completer = new Completer(completitionWindow, ui->searchEdit, matcher,
                            dictionaryProvider, this);

  connect(completer, &AbstractCompleter::selected, this,
          &Widget::showSelectedItem);
  connect(ui->submitButton, &QPushButton::clicked, this,
          &Widget::onSubmitClicked);
}

Widget::~Widget() {
  delete completitionWindow;
  delete ui;
}

void Widget::showSelectedItem(const DictionaryItem &item) {
  ui->valueView->setText(item.name);
  ui->descriptionView->setText(item.description);
}

void Widget::onSubmitClicked() {
  const auto currentText = ui->searchEdit->text();
  if (currentText.size() > 0) {
    for (const auto &item : *dictionary) {
      if (item.name == currentText) {
        ui->valueView->setText(item.name);
        ui->descriptionView->setText(item.description);
      }
    }
  }
}
