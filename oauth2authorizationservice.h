#ifndef OAUTH2AUTHORIZATIONSERVICE_H
#define OAUTH2AUTHORIZATIONSERVICE_H

#include <QObject>

class QOAuth2AuthorizationCodeFlow;

class OAuth2AuthorizationService : public QObject
{
    Q_OBJECT
public:
    explicit OAuth2AuthorizationService(QObject *parent = nullptr);
    bool hasAccess();
    QString accessToken();

public slots:
    void grantAccess();
    void refreshAccessToken();

signals:
    void accessGranted(QString accessToken);

private:
    QString readAccessToken();
    void saveAccessToken(QString token);
    QString readRefreshToken();
    void saveRefreshToken(QString token);

    void saveVar(QString varName, QString value);
    QString getVar(QString varName);

    QOAuth2AuthorizationCodeFlow *m_oAuthFlow;
};

#endif // OAUTH2AUTHORIZATIONSERVICE_H
