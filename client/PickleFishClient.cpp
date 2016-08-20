// This is the main entry for the client
#include <QtWidgets>
#include <QtNetwork>

#include "PickleFishClient.h"

PickleFishClient::PickleFishClient(QWidget *parent)
    : QWidget(parent)
{


#if 0

    // find out which IP to connect to
    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    // if we did not find one, use IPv4 localhost
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();

    hostLineEdit = new QLineEdit(ipAddress);
    portLineEdit = new QLineEdit;
    portLineEdit->setValidator(new QIntValidator(1, 65535, this));


    hostLabel->setBuddy(hostLineEdit);
    portLabel->setBuddy(portLineEdit);

    statusLabel = new QLabel(tr("This examples requires that you run the "
                                "Fortune Server example as well."));
    statusLabel->setWordWrap(true);

    getFortuneButton = new QPushButton(tr("Get Fortune"));
    getFortuneButton->setDefault(true);
    getFortuneButton->setEnabled(false);

    quitButton = new QPushButton(tr("Quit"));

    buttonBox = new QDialogButtonBox;
    buttonBox->addButton(captureButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);

    connect(getFortuneButton, SIGNAL(clicked()), this, SLOT(requestNewFortune()));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));

    connect(hostLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(enableGetFortuneButton()));
    connect(portLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(enableGetFortuneButton()));
//! [0]
    connect(&thread, SIGNAL(newFortune(QString)),
            this, SLOT(showFortune(QString)));
//! [0] //! [1]
    connect(&thread, SIGNAL(error(int,QString)),
            this, SLOT(displayError(int,QString)));
//! [1]

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(hostLabel, 0, 0);
    mainLayout->addWidget(hostLineEdit, 0, 1);
    mainLayout->addWidget(portLabel, 1, 0);
    mainLayout->addWidget(portLineEdit, 1, 1);
    mainLayout->addWidget(statusLabel, 2, 0, 1, 2);
    mainLayout->addWidget(buttonBox, 3, 0, 1, 2);
    setLayout(mainLayout);

    setWindowTitle(tr("Blocking Fortune Client"));
    portLineEdit->setFocus();
}

//! [2]
void PickleFishClient::requestNewFortune()
{
    getFortuneButton->setEnabled(false);
    thread.requestNewFortune(hostLineEdit->text(),
                             portLineEdit->text().toInt());
}
//! [2]

//! [3]
void PickleFishClient::showFortune(const QString &nextFortune)
{
    if (nextFortune == currentFortune) {
        requestNewFortune();
        return;
    }
//! [3]

//! [4]
    currentFortune = nextFortune;
    statusLabel->setText(currentFortune);
    getFortuneButton->setEnabled(true);
#endif
}
//! [4]

void PickleFishClient::displayError(int socketError, const QString &message)
{
    switch (socketError) {
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this, tr("PickleFish"),
                                 tr("The host was not found. Please check the "
                                    "host and port settings."));
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this, tr("PickleFish"),
                                 tr("The connection was refused by the PickleFish server "));
        break;
    default:
        QMessageBox::information(this, tr("PickleFish"),
                                 tr("The following error occurred: %1.")
                                 .arg(message));
    }

    getFortuneButton->setEnabled(true);
}





