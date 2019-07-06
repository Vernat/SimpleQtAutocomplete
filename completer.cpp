#include "completer.h"
#include "dictionary_item.h"

Completer::Completer(
    QLineEdit *controlledEdit, std::shared_ptr<AbstractMatcher> matcher,
    std::shared_ptr<AbstractDictionaryProvider> &dictionaryProvider,
    QObject *parent)
    : AbstractCompleter(parent), controlledEdit(controlledEdit),
      matcher(matcher), dictionaryProvider(dictionaryProvider) {}
