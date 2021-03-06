/*=========================================================================

  Library:   CTK

  Copyright (c) Kitware Inc.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.commontk.org/LICENSE

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

=========================================================================*/

#ifndef __ctkDICOMServerNodeWidget_h
#define __ctkDICOMServerNodeWidget_h

// Qt includes 
#include <QWidget>
#include <QString>
#include <QList>
#include <QMap>

#include "ctkDICOMWidgetsExport.h"

class QTableWidgetItem;
class ctkDICOMServerNodeWidgetPrivate;

class CTK_DICOM_WIDGETS_EXPORT ctkDICOMServerNodeWidget : public QWidget
{
Q_OBJECT;
public:
  typedef QWidget Superclass;
  explicit ctkDICOMServerNodeWidget(QWidget* parent=0);
  virtual ~ctkDICOMServerNodeWidget();

  QString                callingAETitle();
  QMap<QString,QVariant> parameters();

  QStringList            nodes()const;
  QStringList            checkedNodes()const;
  QMap<QString,QVariant> nodeParameters(const QString &node)const ;

public slots:
  void addNode ();
  void removeNode ();
  void onCellChanged (int row, int column);
  void onCurrentItemChanged(QTableWidgetItem* current, QTableWidgetItem *previous);

  void readSettings();
  void saveSettings();

protected:
  QScopedPointer<ctkDICOMServerNodeWidgetPrivate> d_ptr;
  enum ServerColumns{
    NameColumn = 0,
    AETitleColumn,
    AddressColumn,
    PortColumn
  };
private:
  Q_DECLARE_PRIVATE(ctkDICOMServerNodeWidget);
  Q_DISABLE_COPY(ctkDICOMServerNodeWidget);
};

#endif
