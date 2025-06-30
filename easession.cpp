#include "easession.h"

#include <QStandardPaths>
#include <QDir>

EaSession* EaSession::instance = nullptr;

EaSession::EaSession(QObject* parent)
    : QObject(parent)
{
    m_settingsFilePath = getSettingsFilePath();
    ensureSettingsDirectory();

    m_settings = new QSettings(m_settingsFilePath, QSettings::IniFormat, this);
    checkLicense();
}

EaSession::~EaSession() {

}

bool EaSession::hasValidLicense() {
    if (!m_settings || !m_settings->contains("auth/license")) {
        return false;
    }

    m_license = m_settings->value("auth/license").toString();
    if (m_license.isEmpty()) {
        return false;
    }

    return true;
}

void EaSession::checkLicense() {
    if (hasValidLicense()) {
        verifyLicense();
    }
}

void EaSession::verifyLicense() {
    if (m_license.isEmpty()) {
        qDebug() << "illegal software, please purchurse!";
        return;
    }

    QString keyName = m_settings->value("auth/key").toString();
    // 调用licensecc客户端api


}

QString EaSession::getSettingsFilePath() {
    QString appDataPath = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);
    return QDir(appDataPath).absoluteFilePath("settings.ini");
}

void EaSession::ensureSettingsDirectory() {
    QString appDataPath = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);
    QDir dir;
    if (!dir.exists(appDataPath)) {
        dir.mkpath(appDataPath);
        qDebug() << "Created settings directory:" << appDataPath;
    }
}
