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
 * @file QMLCachePlugin.cpp
 * @brief Object that exposes the QMLCache plugin components as QML objects
 * @author Ayberk Özgür
 * @date 2016-08-11
 */

#include "QMLCachePlugin.h"

#include "QMLCache.h"

/**
 * @brief Persistent app-exclusive key-value store plugin, accessible from QML
 */
namespace QMLCachePlugin{

void QMLCachePlugin::registerTypes(const char* uri){
    qmlRegisterSingletonType<QMLCache>(uri, 1, 0, "QMLCache",
                                               [] (QQmlEngine* qmlEngine, QJSEngine* jsEngine)->QObject* {
                                                   Q_UNUSED(qmlEngine)
                                                   Q_UNUSED(jsEngine)
                                                   return new QMLCache();
                                               });
}

}
