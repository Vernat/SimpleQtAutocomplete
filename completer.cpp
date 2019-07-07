#include "completer.h"
#include "abstract_dictionary_provider.h"
#include "completition_window.h"
#include "dictionary_item.h"
#include "simple_matcher.h"
#include <QDebug>
#include <QLineEdit>

Completer::Completer(
    QLineEdit *controlledEdit, std::shared_ptr<AbstractMatcher> &matcher,
    std::shared_ptr<AbstractDictionaryProvider> &dictionaryProvider,
    QObject *parent)
    : AbstractCompleter(parent), controlledEdit(controlledEdit),
      matcher(matcher), dictionaryProvider(dictionaryProvider) {
  dictionary = dictionaryProvider->getDictionary();
  matcher->setupDictionary(dictionary);

  connect(controlledEdit, &QLineEdit::textChanged, this,
          &Completer::onTextChanged);

  completition = new CompletitionWindow();
  //  completition->show();
}

void Completer::onTextChanged(const QString &newText) {
  const int cursorPos = controlledEdit->cursorPosition();
  qDebug() << "newText=" << newText << "  cursorPos= " << cursorPos;

  if (newText.size() > 0 && cursorPos == newText.size()) {
    const auto matchedItems = matcher->match(newText);
    completition->setItems(matchedItems);
    completition->show();
  } else {
    completition->hide();
  }
}
