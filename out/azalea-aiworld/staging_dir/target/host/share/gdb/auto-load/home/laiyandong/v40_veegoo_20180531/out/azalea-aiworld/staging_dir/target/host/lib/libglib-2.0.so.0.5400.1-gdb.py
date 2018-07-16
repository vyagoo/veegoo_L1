import sys
import gdb

# Update module path.
dir_ = '/home/laiyandong/v40_veegoo_20180531/out/azalea-aiworld/staging_dir/target/host/share/glib-2.0/gdb'
if not dir_ in sys.path:
    sys.path.insert(0, dir_)

from glib_gdb import register
register (gdb.current_objfile ())
