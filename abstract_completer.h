#ifndef ABSTRACT_COMPLETER_H
#define ABSTRACT_COMPLETER_H

#include <QObject>

struct DictionaryItem;

class AbstractCompleter : public QObject {
  Q_OBJECT

public:
  AbstractCompleter(QObject *parent = nullptr) : QObject(parent) {}

signals:
  void selected(const DictionaryItem &);
};

#endif // ABSTRACT_COMPLETER_H
