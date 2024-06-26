#ifndef SHARES_H
#define SHARES_H

#include "investapiclient.h"
#include "sandboxservice.h"
#include "marketdataservice.h"
#include <QTimer>
#include <QDialog>
#include <QtCharts>
#include <QtSql>
#include <QMessageBox>
#include <QFile>
#include <QSqlError>
#include <QSqlQuery>
#include <QDateTime>
#include <QVBoxLayout>

#include <sqlite3.h>

namespace Ui {
class shares;
}

class shares : public QDialog
{
    Q_OBJECT

public:
    explicit shares(QWidget *parent = nullptr, const std::string& figi = "", const std::string& stockName = "", const QString& token = "");
    ~shares();

private slots:
    void updateDateTime();
    void clearChart();
    void clearDatabase();
    void fetchCandlestickData();
    void updateCandleChart();
    void updateLineChart();
    void showTooltip(const QPointF &point, bool state);
    void showTooltipCandle(bool status, QCandlestickSet *set);
    
private:
    Ui::shares *ui;
    QTimer *timer;
    std::string figi;
    std::string stockName;
    QString token;
    QLineSeries *smaSeries;
    QLineSeries *emaSeries;
};

#endif // SHARES_H
