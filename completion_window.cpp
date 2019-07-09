#include "completion_window.h"
#include "dictionary_item.h"
#include "dictionary_item_widget.h"
#include "ui_completition.h"
#include <QDebug>
#include <QFlags>
#include <QListWidgetItem>

CompletionWindow::CompletionWindow(QWidget *parent)
    : AbstractCompletionWindow(parent), ui(new Ui::Completition) {
  ui->setupUi(this);
  ui->scrollAreaWidgetContents->setFixedWidth(DICTIONARY_WIDGET_WIDTH);
  setFixedWidth(DICTIONARY_WIDGET_WIDTH);

  setWindowFlags(Qt::Window | Qt::FramelessWindowHint |
                 Qt::WindowStaysOnTopHint);
  setAttribute(Qt::WA_ShowWithoutActivating, true);

  QGuiApplication *application =
      static_cast<QGuiApplication *>(QApplication::instance());

  connect(application, &QGuiApplication::applicationStateChanged, this,
          &CompletionWindow::onApplicationStateChanged);
}

CompletionWindow::~CompletionWindow() { delete ui; }

void CompletionWindow::setItems(const QList<DictionaryItem> &items,
                                const QString &inputText) {

  this->items = items;
  removeOldWidgets();
  createNewWidgets(inputText);
  adjustSize();
}

void CompletionWindow::createNewWidgets(const QString &inputText) {
  for (const auto &item : items) {
    auto dictionaryItemWidget = new DictionaryItemWidget(inputText, item);
    connect(dictionaryItemWidget, &DictionaryItemWidget::selected, this,
            &CompletionWindow::selected);
    ui->scrollAreaWidgetContents->layout()->addWidget(dictionaryItemWidget);
    dictionaryWidgets.insert(item.name, dictionaryItemWidget);
  }
}

void CompletionWindow::removeOldWidgets() {
  auto it = dictionaryWidgets.begin();
  while (it != dictionaryWidgets.end()) {
    it.value()->deleteLater();
    ++it;
  }
  dictionaryWidgets.clear();
}

void CompletionWindow::adjustSize() {
  const auto newHeight = items.size() * DICTIONARY_WIDGET_HEIGHT;
  ui->scrollAreaWidgetContents->setFixedHeight(newHeight);
  setFixedHeight(newHeight);
}

void CompletionWindow::onApplicationStateChanged(Qt::ApplicationState state) {
  if (isVisible()) {
    setVisible(!(Qt::ApplicationInactive == state ||
                 Qt::ApplicationHidden == state ||
                 Qt::ApplicationSuspended == state));
  }
}
