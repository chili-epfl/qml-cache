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
 * @file QMLCache.h
 * @brief Persistent key-value cache accesible from QML
 * @author Ayberk Özgür
 * @date 2016-08-11
 */

#ifndef QMLCACHE_H
#define QMLCACHE_H

#include <QQuickItem>
#include <QString>

class QMLCache : public QQuickItem {
    /* *INDENT-OFF* */
    Q_OBJECT
    /* *INDENT-ON* */

public:

    /**
     * @brief Creates a new QMLCache with the given QML parent
     *
     * @param parent The QML parent
     */
    QMLCache(QQuickItem* parent = 0);

    /**
     * @brief Destroys this QMLCache
     */
    ~QMLCache();

public slots:

    /**
     * @brief Writes a new key-value pair to the app's cache
     *
     * @param key Key, must not be empty and must be a valid filename
     * @param value Value
     */
    void write(const QString& key, const QString& value);

    /**
     * @brief Reads a key-value pair from the app's cache
     *
     * @param key Key, must not be empty and must be a valid filename
     * @return The value, empty string if key doesn't exist yet
     */
    QString read(const QString& key);

private:

    QString cacheDir;   ///< Cache directory for this app

};

#endif /* QMLCACHE_H */
