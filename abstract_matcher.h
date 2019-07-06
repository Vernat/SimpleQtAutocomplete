#ifndef ABSTRACT_MATCHER_H
#define ABSTRACT_MATCHER_H

#include "dictionary_item.h"

class AbstractMatcher {
public:
  virtual ~AbstractMatcher() = default;

  virtual void
  setupDictionary(const std::shared_ptr<const Dictionary> &dictionary) = 0;
  virtual QList<DictionaryItem> match(const QString &str) = 0;
};

#endif // ABSTRACT_MATCHER_H
