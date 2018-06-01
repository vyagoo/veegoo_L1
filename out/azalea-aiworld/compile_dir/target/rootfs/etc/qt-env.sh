#!/bin/sh

export QT_QPA_PLATFORM=eglfs:size=1280x720
export QT_QPA_PLATFORM_PLUGIN_PATH=/usr/lib/qt5/plugins
export QT_QPA_FONTDIR=/usr/share/fonts
export QT_QPA_GENERIC_PLUGINS=evdevtouch,evdevmouse:/dev/input/event2,evdevkeyboard:/dev/input/event3
export QT_QPA_EGLFS_PHYSICAL_WIDTH=174
export QT_QPA_EGLFS_PHYSICAL_HEIGHT=309
export QT_QPA_EVDEV_KEYBOARD_PARAMETERS='grab=1'
export QT_QPA_LINUXFB_USE=fb0
