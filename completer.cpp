#include "completer.h"
#include "abstract_dictionary_provider.h"
#include "completition_window.h"
#include "dictionary_item.h"
#include "simple_matcher.h"
#include <QDebug>
#include <QLineEdit>

const int X_OFFSET = -10;
const int Y_OFFSET = -7;

Completer::Completer(
    QLineEdit *controlledEdit, std::shared_ptr<AbstractMatcher> &matcher,
    std::shared_ptr<AbstractDictionaryProvider> &dictionaryProvider,
    QObject *parent)
    : AbstractCompleter(parent), controlledEdit(controlledEdit),
      matcher(matcher), dictionaryProvider(dictionaryProvider) {
  dictionary = dictionaryProvider->getDictionary();
  matcher->setupDictionary(dictionary);

  completitionWindow = new CompletitionWindow();

  connect(controlledEdit, &QLineEdit::textChanged, this,
          &Completer::onTextChanged);

  connect(completitionWindow, &CompletitionWindow::selected, this,
          &Completer::onItemSelected);
}

void Completer::onTextChanged(const QString &newText) {
  const int cursorPos = controlledEdit->cursorPosition();

  if (newText.size() > 0 && cursorPos == newText.size()) {
    const auto matchedItems = matcher->match(newText);
    completitionWindow->setItems(matchedItems);
    completitionWindow->move(getCursorPosition(newText));
    completitionWindow->show();
  } else {
    completitionWindow->hide();
  }
}

void Completer::onItemSelected(const DictionaryItem &item) {
  controlledEdit->setText(item.name);
  completitionWindow->hide();
}

QPoint Completer::getCursorPosition(const QString &text) const {
  return controlledEdit->mapToGlobal(
      QPoint(X_OFFSET, controlledEdit->geometry().bottom() + Y_OFFSET));
}
