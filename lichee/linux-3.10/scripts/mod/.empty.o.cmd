cmd_scripts/mod/empty.o := arm-openwrt-linux-muslgnueabi-gcc -Wp,-MD,scripts/mod/.empty.o.d  -nostdinc -isystem /home/laiyandong/v40_veegoo_20180531/prebuilt/gcc/linux-x86/arm/toolchain-sunxi-musl/toolchain/bin/../lib/gcc/arm-openwrt-linux-muslgnueabi/5.2.1/include -I/home/laiyandong/v40_veegoo_20180531/lichee/linux-3.10/arch/arm/include -Iarch/arm/include/generated  -Iinclude -I/home/laiyandong/v40_veegoo_20180531/lichee/linux-3.10/arch/arm/include/uapi -Iarch/arm/include/generated/uapi -I/home/laiyandong/v40_veegoo_20180531/lichee/linux-3.10/include/uapi -Iinclude/generated/uapi -include /home/laiyandong/v40_veegoo_20180531/lichee/linux-3.10/include/linux/kconfig.h -D__KERNEL__ -mlittle-endian -Iarch/arm/mach-sunxi/include -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -fno-delete-null-pointer-checks -Os -Wno-maybe-uninitialized -fno-dwarf2-cfi-asm -mabi=aapcs-linux -mno-thumb-interwork -funwind-tables -marm -D__LINUX_ARM_ARCH__=7 -march=armv7-a -msoft-float -Uarm -Wframe-larger-than=2048 -fno-stack-protector -Wno-unused-but-set-variable -fomit-frame-pointer -fno-var-tracking-assignments -g -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fconserve-stack -DCC_HAVE_ASM_GOTO    -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(empty)"  -D"KBUILD_MODNAME=KBUILD_STR(empty)" -c -o scripts/mod/empty.o scripts/mod/empty.c

source_scripts/mod/empty.o := scripts/mod/empty.c

deps_scripts/mod/empty.o := \

scripts/mod/empty.o: $(deps_scripts/mod/empty.o)

$(deps_scripts/mod/empty.o):
