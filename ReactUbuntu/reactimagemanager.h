#ifndef REACTIMAGEMANAGER_H
#define REACTIMAGEMANAGER_H

#include "reactviewmanager.h"


class ReactPropertyHandler;

class ReactImageManager : public ReactViewManager
{
  Q_OBJECT
  Q_INTERFACES(ReactModuleInterface)

public:
  ReactImageManager(QObject* parent = 0);
  ~ReactImageManager();

  void setBridge(ReactBridge* bridge) override;

  ReactViewManager* viewManager() override;
  ReactPropertyHandler* propertyHandler(QObject* object) override;

  QString moduleName() override;
  QList<ReactModuleMethod*> methodsToExport() override;
  QVariantMap constantsToExport() override;

  QQuickItem* view(const QVariantMap& properties) const override;

private Q_SLOTS:
  void statusChanged();

private:
  void configureView(QQuickItem* view) const;
};

#endif // REACTIMAGEMANAGER_H
