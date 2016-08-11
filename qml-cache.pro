TEMPLATE = lib
TARGET = qmlcacheplugin

CONFIG += qt plugin c++11
CONFIG -= android_install

QT += qml quick

QMAKE_CXXFLAGS -= -O2
QMAKE_CXXFLAGS_RELEASE -= -O2

QMAKE_CXXFLAGS += -O3
QMAKE_CXXFLAGS_RELEASE += -O3

TARGET = $$qtLibraryTarget($$TARGET)
uri = QMLCache

HEADERS += \
    src/QMLCachePlugin.h \
    src/QMLCache.h

SOURCES += \
    src/QMLCachePlugin.cpp \
    src/QMLCache.cpp

OTHER_FILES += qmldir

#Install plugin library, qmldir
qmldir.files = qmldir
unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += target qmldir
}
