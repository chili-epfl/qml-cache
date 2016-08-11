/*
 * Copyright (C) 2016 EPFL
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/.
 */

/**
 * @file QMLCache.cpp
 * @brief Persistent key-value cache accesible from QML
 * @author Ayberk Özgür
 * @date 2016-08-11
 */

#include "QMLCache.h"

#include <QDir>
#include <QStandardPaths>
#include <QFile>

QMLCache::QMLCache(QQuickItem* parent) : QQuickItem(parent){
    cacheDir = QStandardPaths::writableLocation(QStandardPaths::StandardLocation::CacheLocation);
    if(cacheDir.isEmpty())
        qCritical() << "QMLCache::QMLCache(): Cache location could not be determined, QMLCache will not work.";
    else{
        if(!QDir::root().mkpath(cacheDir))
            qCritical() << "QMLCache::QMLCache(): Cache directory could not be created, QMLCache will not work.";
    }
}

QMLCache::~QMLCache(){}

void QMLCache::write(const QString& key, const QString& value){
    if(key.isEmpty()){
        qCritical() << "QMLCache::write(): Key cannot be empty.";
        return;
    }
    QDir::setCurrent(cacheDir);
    QFile cacheFile(key);
    if(!cacheFile.open(QIODevice::WriteOnly | QIODevice::Truncate)){
        qCritical() << "QMLCache::write(): Could not open cache file, value not written.";
        return;
    }
    QByteArray bytes = value.toUtf8();
    if(cacheFile.write(bytes) < bytes.length())
        qCritical() << "QMLCache::write(): Could not write entire value.";
    cacheFile.flush();
    cacheFile.close();
}

QString QMLCache::read(const QString& key){
    if(key.isEmpty()){
        qCritical() << "QMLCache::read(): Key cannot be empty.";
        return QString();
    }
    QDir::setCurrent(cacheDir);
    QFile cacheFile(key);
    if(!cacheFile.open(QIODevice::ReadOnly)){
        qCritical() << "QMLCache::read(): Could not open cache file.";
        return QString();
    }
    QString value = QString::fromUtf8(cacheFile.readAll());
    cacheFile.close();
    return value;
}
