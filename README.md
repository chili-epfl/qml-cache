qml-cache
=========

qml-cache is a persistent app-exclusive key-value store plugin. It is tested with Qt 5.10.1 on the following:

  - Ubuntu 17.10
  - macOS 10.13.3 with Xcode 9.3
  - Windows 10 (UWP x64 (MSVC 2017)) with Visual Studio 2017 Community (with `Universal Windows Platform development` and `C++ Universal Windows Platform tools`)
  - Android 7.1.2 with Ubuntu 17.10 host with Android API 23, Android SDK Tools 25.2.5 and Android NDK r10e

See [samples/](samples/) for example uses.

See [DOCUMENTATION.md](DOCUMENTATION.md) for the API.

build [Linux & macOS]
---------------------

```
    $ mkdir build && cd build
    $ qt-install-dir/qt-version/target-platform/bin/qmake ..
    $ make install
```

This will install the QML plugin inside the Qt sysroot, which you must have write access to. **Be aware that this is not a sandboxed installation.**

build [Android]
---------------

```
    $ export ANDROID_NDK_ROOT=/path-to-android-ndk/
    $ mkdir build && cd build
    $ qt-install-dir/qt-version/target-platform/bin/qmake ..
    $ make install
```

This will install the QML plugin inside the Qt sysroot, which you must have write access to. **Be aware that this is not a sandboxed installation.**

build [Windows]
---------------

Run the following in the `Developer Command Prompt for VS 2017`:

```
    > "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat" amd64
    > mkdir build
    > cd build
    > qt-install-root\qt-version\target-platform\bin\qmake ..
    > nmake
    > nmake install
```

This will install the QML plugin inside the Qt sysroot, which you must have write access to. **Be aware that this is not a sandboxed installation.**

build documentation
-------------------

Install dependencies:
```
    $ apt install doxygen doxyqml
    $ git clone git@github.com:sourcey/moxygen.git && cd moxygen && npm install -g .
```

Then, generate the documentation:
```
    $ doxygen
    $ moxygen --output DOCUMENTATION.md xml
```
