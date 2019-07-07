#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class AbstractCompleter;
struct DictionaryItem;
typedef QList<DictionaryItem> Dictionary;

class Widget : public QWidget {
  Q_OBJECT

public:
  explicit Widget(QWidget *parent = nullptr);
  ~Widget();

private:
  void showSelectedItem(const DictionaryItem &item);
  void onSubmitClicked();

  Ui::Widget *ui;
  AbstractCompleter *completer;
  std::shared_ptr<const Dictionary> dictionary;
};

#endif // WIDGET_H
