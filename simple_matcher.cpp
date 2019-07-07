#include "simple_matcher.h"
#include <QList>

SimpleMatcher::SimpleMatcher() {}

void SimpleMatcher::setupDictionary(
    const std::shared_ptr<const Dictionary> &dictionary) {
  this->dictionary = dictionary;
}

QList<DictionaryItem> SimpleMatcher::match(const QString &str) {
  QList<DictionaryItem> list;
  for (const auto &item : *dictionary) {
    if (item.name.startsWith(str)) {
      list << item;
    }
  }
  return list;
}
