// test.cpp
// QXlsx // MIT License // https://github.com/j2doll/QXlsx

#include <QtGlobal>
#include <QCoreApplication>
#include <QtCore>
#include <QVector>
#include <QVariant>
#include <QDebug> 
#include <QDir>

#include <iostream>
using namespace std;

#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"

int test( QVector<QVariant> params )
{
    qDebug() << " current path : " << QDir::currentPath();

    using namespace QXlsx;

    Document output;

    QString strSheet = "c-sheet1";
    output.addSheet(strSheet);
    output.selectSheet(strSheet);

    output.write( 1, 1, QVariant(11) );
    output.write( 1, 2, QVariant(12) );
    output.write( 1, 3, QVariant(13) );
    output.write( 2, 1, QVariant(21) );
    output.write( 2, 2, QVariant(22) );
    output.write( 2, 3, QVariant(23) );

    Chart* ptrChart = output.insertChart( 3, 5, QSize(600, 500) );
    ptrChart->setChartType( Chart::CT_Scatter );
    ptrChart->addSeries( CellRange("A1:B3") );
    ptrChart->setAxisTitle( Chart::Left, QString("left title") );
    ptrChart->setAxisTitle( Chart::Bottom, QString("bottom title") );
    ptrChart->setChartTitle( QString("hello chart") );

    output.saveAs("test2.xlsx");

    return 0;
}

