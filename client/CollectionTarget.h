#ifndef COLLECTIONTARGET_H
#define COLLECTIONTARGET_H

#include <QWidget>

// Include the common stuff about the PickleFish
#include "PickleFishCommon.h"

QT_BEGIN_NAMESPACE
class QDialogButtonBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QAction;
QT_END_NAMESPACE



class CollectionTarget
{
 public:
    QLabel           *hostLabel;
    QLabel           *portLabel;
    QLineEdit        *hostLineEdit;
    QLineEdit        *portLineEdit;
    CollectionTarget();
};

#endif
