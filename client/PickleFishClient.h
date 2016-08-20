#ifndef PICKLEFISHCLIENT_H
#define PICKLEFISHCLIENT_H

#include <QWidget>

// Include the common stuff about the PickleFish
#include "PickleFishCommon.h"
#include "CollectionTarget.h"

QT_BEGIN_NAMESPACE
class QDialogButtonBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QAction;
QT_END_NAMESPACE



class PickleFishClient : public QWidget
{
    Q_OBJECT

public:
    PickleFishClient(QWidget *parent = 0);

private slots:

  void targetCaptureButton();
    void showConnectResult(const QString &fortune);
    void displayError(int socketError, const QString &message);
    void enableCollection();


private:

    CollectionTarget target;
    

    // Defines the target to collect from

    // The capture controller buttons
    QPushButton      *captureControlButton; // Start or stop capture control
    QLineEdit        *captureFilter;  // the capture filter for the collector

    QLabel           *statusLabel;
    QPushButton      *connectButton; // Start the capture
    QPushButton      *quitButton;
    QDialogButtonBox *buttonBox;

};

#endif
