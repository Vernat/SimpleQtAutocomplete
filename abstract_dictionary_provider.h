#ifndef ABSTRACT_DICTIONARY_PROVIDER_H
#define ABSTRACT_DICTIONARY_PROVIDER_H

#include "dictionary_item.h"

class AbstractDictionaryProvider {
public:
  virtual ~AbstractDictionaryProvider() = default;

  virtual std::shared_ptr<Dictionary> getDictionary() = 0;
};

#endif // ABSTRACT_DICTIONARY_PROVIDER_H
