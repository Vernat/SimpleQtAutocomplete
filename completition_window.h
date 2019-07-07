#ifndef COMPLETITION_H
#define COMPLETITION_H

#include <QMap>
#include <QWidget>

namespace Ui {
class Completition;
}

struct DictionaryItem;
class DictionaryItemWidget;
class QVBoxLayout;

class CompletitionWindow : public QWidget {
  Q_OBJECT

public:
  explicit CompletitionWindow(QWidget *parent = nullptr);
  ~CompletitionWindow();

  void setItems(const QList<DictionaryItem> &items);

private:
  void createNewWidgets();
  void removeOldWidgets();
  void adjustSize();

  Ui::Completition *ui;
  QList<DictionaryItem> items;
  QMap<QString, DictionaryItemWidget *> dictionaryWidgets;
  QVBoxLayout *widgetsFrameLayout;
};

#endif // COMPLETITION_H