host_build {
    QT_CPU_FEATURES.x86_64 = mmx sse sse2
} else {
    QT_CPU_FEATURES.arm = neon
}
QT.global_private.enabled_features = alloca_h alloca dbus dbus-linked gui network posix_fallocate reduce_exports sql system-zlib testlib widgets xml
QT.global_private.disabled_features = alloca_malloc_h android-style-assets private_tests libudev qml-debug reduce_relocations release_tools sse2 stack-protector-strong
PKG_CONFIG_EXECUTABLE = /home/wangyaliang/workspace/vecoo/out/host/bin/pkg-config
QMAKE_LIBS_DBUS = -L//home/wangyaliang/workspace/vecoo/out/azalea-aiworld/staging_dir/target/usr/lib -ldbus-1
QMAKE_INCDIR_DBUS = //home/wangyaliang/workspace/vecoo/out/azalea-aiworld/staging_dir/target/usr/include/dbus-1.0 //home/wangyaliang/workspace/vecoo/out/azalea-aiworld/staging_dir/target/usr/lib/dbus-1.0/include
QT_COORD_TYPE = double
QMAKE_LIBS_ZLIB = -lz
CONFIG -= precompile_header
CONFIG += cross_compile compile_examples enable_new_dtags largefile neon optimize_size silent
QT_BUILD_PARTS += libs examples
QT_HOST_CFLAGS_DBUS += -I//home/wangyaliang/workspace/vecoo/out/azalea-aiworld/staging_dir/target/usr/include/dbus-1.0 -I//home/wangyaliang/workspace/vecoo/out/azalea-aiworld/staging_dir/target/usr/lib/dbus-1.0/include
