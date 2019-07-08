#ifndef COMPLETITION_H
#define COMPLETITION_H

#include "abstract_completion_window.h"
#include <QMap>

namespace Ui {
class Completition;
}

struct DictionaryItem;
class DictionaryItemWidget;
class QVBoxLayout;

class CompletitionWindow : public AbstractCompletionWindow {
  Q_OBJECT

public:
  explicit CompletitionWindow(QWidget *parent = nullptr);
  ~CompletitionWindow() override;

  void setItems(const QList<DictionaryItem> &items,
                const QString &inputText) override;

private:
  void createNewWidgets(const QString &inputText);
  void removeOldWidgets();
  void adjustSize();
  void onApplicationStateChanged(Qt::ApplicationState state);

  Ui::Completition *ui;
  QList<DictionaryItem> items;
  QMap<QString, DictionaryItemWidget *> dictionaryWidgets;
  QVBoxLayout *widgetsFrameLayout;
};

#endif // COMPLETITION_H
