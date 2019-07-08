#ifndef FAKE_DICTIONARY_PROVIDER_H
#define FAKE_DICTIONARY_PROVIDER_H

#include "abstract_dictionary_provider.h"

class FakeDictionaryProvider : public AbstractDictionaryProvider {
public:
  FakeDictionaryProvider();

  std::shared_ptr<Dictionary> getDictionary() override;

private:
  std::shared_ptr<Dictionary> dictionary;
};

#endif // FAKE_DICTIONARY_PROVIDER_H
