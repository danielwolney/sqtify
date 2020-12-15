#ifndef SPOTIFYWEBAPICLIENT_H
#define SPOTIFYWEBAPICLIENT_H

#include <QObject>
#include "httprequestmanager.h"
#include <QQueue>
#include <QPair>

class SpotifyWebApiClient : public QObject
{
    Q_OBJECT
public:
    explicit SpotifyWebApiClient(QObject *parent = nullptr);
    void setAccesToken(QString accessToken);
    void get(QString apiResource, HttpRequestManager::OnFinished onResponse);
    void get(QString apiResource, HttpRequest::RawHeaders headers,
             HttpRequestManager::OnFinished onResponse);

signals:
    void accessTokenChanged();
    void expiredToken();
private:
    void requestThenCheckAuth(HttpRequest httpRequest, HttpRequestManager::OnFinished onResponse);
    Q_INVOKABLE void request(HttpRequest request,
                 HttpRequestManager::OnFinished onResponse);
    void addPendingRequest(HttpRequest httpRequest, HttpRequestManager::OnFinished onResponse);
    void dequeuePendingRequests();

    HttpRequestManager *m_httpManager;
    QString m_accessToken;
    QQueue<QPair<HttpRequest, HttpRequestManager::OnFinished> > m_pendingsRequests;
};

#endif // SPOTIFYWEBAPICLIENT_H
