#ifndef EASESSION_H
#define EASESSION_H

#include <qobject.h>
#include <QQuickPaintedItem>
#include <QQmlApplicationEngine>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QSettings>
#include <QVector3D>
#include <QProcess>

class EaSession : public QObject
{
    Q_OBJECT
public:
    static EaSession *getInstance() {
        if (!instance) {
            instance = new EaSession();
        }

        return instance;
    }

    ~EaSession();// {}

    bool hasValidLicense();
    void checkLicense();
    void verifyLicense();
    QString getSettingsFilePath();
    void ensureSettingsDirectory();

private:
    EaSession(QObject *parent = nullptr);

private:
    static EaSession* instance;
    QNetworkAccessManager m_networkMgr;
    QSettings* m_settings;

    QString m_settingsFilePath;
    QString m_license;
};

#endif // EASESSION_H
