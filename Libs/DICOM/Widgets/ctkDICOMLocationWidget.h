#ifndef __ctkDICOMLocationWidget_h
#define __ctkDICOMLocationWidget_h

// QT includes 
#include <QWidget>

// qCTK includes
#include <ctkPimpl.h>

#include "CTKDICOMWidgetsExport.h"

class ctkDICOMLocationWidgetPrivate;

class CTK_DICOM_WIDGETS_EXPORT ctkDICOMLocationWidget : public QWidget
{
public:
  typedef QWidget Superclass;
  explicit ctkDICOMLocationWidget(QWidget* parent=0);
  virtual ~ctkDICOMLocationWidget();

private:
  QCTK_DECLARE_PRIVATE(ctkDICOMLocationWidget);
};

#endif