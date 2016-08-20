#include "CollectionTarget.h"
QT_BEGIN_NAMESPACE
class QDialogButtonBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QAction;
QT_END_NAMESPACE


CollectionTarget::CollectionTarget(){
    //  need to have these to select where to collect from
   hostLabel = new QLabel(QObject::tr("&collector name:"));
   portLabel = new QLabel(QObject::tr("S&collector port:"));


}


