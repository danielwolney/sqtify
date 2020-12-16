#ifndef TRACKSEARCHRESULTMODEL_H
#define TRACKSEARCHRESULTMODEL_H

#include <QAbstractListModel>
#include <QJsonArray>

class SearchResult;

class TrackSearchResultModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit TrackSearchResultModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool canFetchMore(const QModelIndex &parent) const override;
    void fetchMore(const QModelIndex &parent) override;

    SearchResult *searchResult() const;
    void setSearchResult(SearchResult *searchResult);

    int pageSize() const;
    void setPageSize(int pageSize);
signals:
    void loading();
    void loaded();

private:
    void clear();
    void appendItems(QJsonArray items);

    SearchResult *m_searchResult;
    QList<QJsonArray> *m_itens;
    int m_count;
    int m_total;
    int m_pageSize;
};

#endif // TRACKSEARCHRESULTMODEL_H
