#ifndef SIMPLE_MATCHER_H
#define SIMPLE_MATCHER_H

#include "abstract_matcher.h"

class SimpleMatcher : public AbstractMatcher {
public:
  SimpleMatcher();

  void setupDictionary(const std::shared_ptr<const Dictionary> &dictionary);
  QList<DictionaryItem> match(const QString &str);

private:
  std::shared_ptr<const Dictionary> dictionary;
};

#endif // SIMPLE_MATCHER_H
