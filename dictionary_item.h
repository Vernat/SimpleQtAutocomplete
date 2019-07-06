#ifndef DICTIONARY_ITEM_H
#define DICTIONARY_ITEM_H

#include <QString>

struct DictionaryItem {
  DictionaryItem(const QString &name, const QString &description)
      : name(name), description(description) {}

  QString name;
  QString description;
};

typedef QList<DictionaryItem> Dictionary;

#endif // DICTIONARY_ITEM_H
