#ifndef ABSTRACT_COMPLETION_WINDOW_H
#define ABSTRACT_COMPLETION_WINDOW_H

#include <QWidget>

struct DictionaryItem;

class AbstractCompletionWindow : public QWidget {
  Q_OBJECT

public:
  AbstractCompletionWindow(QWidget *parent = nullptr) : QWidget(parent) {}
  virtual ~AbstractCompletionWindow() = default;

  virtual void setItems(const QList<DictionaryItem> &items,
                        const QString &inputText) = 0;

signals:
  void selected(const DictionaryItem &item);
};

#endif // ABSTRACT_COMPLETION_WINDOW_H
