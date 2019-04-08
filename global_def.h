#ifndef GLOBAL_DEF_H
#define GLOBAL_DEF_H


#include <QtCore/QtCore>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QList>

#include <QDateTime>

#include <QPixmap>
#include <QTimer>

#include <QtCharts>
#include "../inc/bdaqctrl.h"

using namespace Automation::BDaq;
QT_CHARTS_USE_NAMESPACE

typedef struct DAQINFO{
    quint32 channel;
    quint32 used;
    QString name;
    QString unit;
    quint32 type;
    float scopemin;
    float scopemax;
    quint32 freq;
    quint32 alarm_h;
    float limit_h;
    quint32 alarm_l;
    float limit_l;
    QString remark;
    quint32 value;
    float fvalue;
} stDaqInfo;

struct ConfigureParameter
{
    QString deviceName;
    int channelCount;
    int channelStart;
    ValueRange valueRange;
    QString profilePath;
};

#endif // GLOBAL_DEF_H
