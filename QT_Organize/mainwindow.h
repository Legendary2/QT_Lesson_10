#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QAbstractTableModel>
#include <QVector>

class MainWindow : public QAbstractTableModel
{
    Q_OBJECT
    enum TableRoles {
        TableDataRole = Qt::UserRole + 1,
        HeadingRole

    };

private:
            void Init();
            void LoadData();
            void SaveData();

        public:
            MainWindow(QObject* parent = nullptr);
            int rowCount(const QModelIndex & = QModelIndex()) const override;
            int columnCount(const QModelIndex & = QModelIndex()) const override;
            QVariant data(const QModelIndex &index, int role) const override;
            QHash<int, QByteArray> roleNames() const override;
            Q_INVOKABLE void onClear();
            Q_INVOKABLE void onSave();
            Q_INVOKABLE void onRemove(int index);
            Q_INVOKABLE void onAdd(const QString& task, const QString& date, const QString& priority);
            Q_INVOKABLE int entriesCount() const;
            Q_INVOKABLE bool checkDate(const QString&);
            QStringList parseEntry(const QString& line) const;
            QStringList getRow(int index) const;
            bool findTask(const QString& task) const;

        private:
            QVector<QStringList> entries;
  };

#endif // MAINWINDOW_H
