#include "simple_matcher.h"
#include <QList>

SimpleMatcher::SimpleMatcher() {}

void SimpleMatcher::setupDictionary(
    const std::shared_ptr<const Dictionary> &dictionary) {
  this->dictionary = dictionary;
}

QList<DictionaryItem> SimpleMatcher::match(const QString &str) {
  return QList<DictionaryItem>(); // TODO: finish me
}
