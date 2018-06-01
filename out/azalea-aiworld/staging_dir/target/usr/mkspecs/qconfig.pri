!host_build {
    QMAKE_CFLAGS    += --sysroot=$$[QT_SYSROOT]
    QMAKE_CXXFLAGS  += --sysroot=$$[QT_SYSROOT]
    QMAKE_LFLAGS    += --sysroot=$$[QT_SYSROOT]
}
host_build {
    QT_ARCH = x86_64
    QT_BUILDABI = x86_64-little_endian-lp64
    QT_TARGET_ARCH = arm
    QT_TARGET_BUILDABI = arm-little_endian-ilp32-eabi-hardfloat
} else {
    QT_ARCH = arm
    QT_BUILDABI = arm-little_endian-ilp32-eabi-hardfloat
}
QT.global.enabled_features = cross_compile shared rpath c++11 concurrent pkg-config
QT.global.disabled_features = framework appstore-compliant debug_and_release simulator_and_device build_all c++14 c++1z force_asserts separate_debug_info static
PKG_CONFIG_SYSROOT_DIR = /
PKG_CONFIG_LIBDIR = /home/wangyaliang/workspace/vecoo/out/azalea-aiworld/staging_dir/target/usr/lib/pkgconfig:/home/wangyaliang/workspace/vecoo/out/azalea-aiworld/staging_dir/target/usr/share/pkgconfig
CONFIG += cross_compile shared release
QT_CONFIG += shared rpath release c++11 concurrent dbus mremap no-qml-debug reduce_exports stl
QT_VERSION = 5.9.1
QT_MAJOR_VERSION = 5
QT_MINOR_VERSION = 9
QT_PATCH_VERSION = 1
QT_GCC_MAJOR_VERSION = 5
QT_GCC_MINOR_VERSION = 2
QT_GCC_PATCH_VERSION = 1
QT_EDITION = OpenSource
