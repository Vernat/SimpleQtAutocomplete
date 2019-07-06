#ifndef COMPLETER_H
#define COMPLETER_H

#include "abstract_completer.h"
#include <QObject>

class AbstractDictionaryProvider;
class AbstractMatcher;
typedef QList<DictionaryItem> Dictionary;
class QLineEdit;

typedef QPair<QString, QString> pair;

class Completer : public AbstractCompleter {
  Q_OBJECT
public:
  explicit Completer(
      QLineEdit *controlledEdit, std::shared_ptr<AbstractMatcher> matcher,
      std::shared_ptr<AbstractDictionaryProvider> &dictionaryProvider,
      QObject *parent = nullptr);

private:
  QLineEdit *controlledEdit;
  std::shared_ptr<AbstractMatcher> matcher;
  std::shared_ptr<AbstractDictionaryProvider> dictionaryProvider;
  std::shared_ptr<const Dictionary> dictionary;
};

#endif // COMPLETER_H
