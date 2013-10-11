/*
 * Copyright (C) 2007-2012 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef EXTENDED_COMMAND_H
#define EXTENDED_COMMAND_H

#define BM_ROOTDIR "/system/bootmenu"

#ifndef BOOTMODE_CONFIG_FILE
#define BOOTMODE_CONFIG_FILE "/cache/recovery/bootmode.conf"
#endif

static const char *FILE_PRE_MENU  = "/system/bootmenu/script/pre_bootmenu.sh";
static const char *FILE_POST_MENU = "/system/bootmenu/script/post_bootmenu.sh";

static const char *FILE_2NDBOOT   = "/system/bootmenu/script/2nd-boot.sh";
static const char *FILE_2NDBOOT_UART   = "/system/bootmenu/script/2nd-boot-uart.sh";
static const char *FILE_2NDSYSTEM = "/system/bootmenu/script/2nd-system.sh";
static const char *FILE_STOCK     = "/system/bootmenu/script/stock.sh";
static const char *FILE_ADBD      = "/system/bootmenu/script/adbd.sh";
static const char *FILE_SDCARD    = "/system/bootmenu/script/sdcard.sh";
static const char *FILE_CDROM     = "/system/bootmenu/script/cdrom.sh";
static const char *FILE_SYSTEM    = "/system/bootmenu/script/system.sh";
static const char *FILE_DATA      = "/system/bootmenu/script/data.sh";
static const char *FILE_FORMAT_EXT4     = "/system/bootmenu/script/format_ext4.sh";
static const char *FILE_FORMAT_EXT3     = "/system/bootmenu/script/format_ext3.sh";

static const char *FILE_OVERCLOCK       = "/system/bootmenu/script/overclock.sh";
static const char *FILE_OVERCLOCK_CONF  = "/system/bootmenu/config/overclock.conf";

static const char *FILE_RECOVERY  = "/system/bootmenu/script/recovery.sh";
static const char *FILE_BOOTMODE_CLEAN  = "/system/bootmenu/script/bootmode_clean.sh";

static const char *FILE_DEFAULTBOOTMODE = "/system/bootmenu/config/default_bootmode.conf";
static const char *FILE_BOOTMODE        = BOOTMODE_CONFIG_FILE;
static const char *FILE_BYPASS          = "/data/.bootmenu_bypass";

static const char *SYS_POWER_CONNECTED  = "/sys/class/power_supply/ac/online";
static const char *SYS_USB_CONNECTED    = "/sys/class/power_supply/usb/online";
static const char *SYS_BATTERY_LEVEL    = "/sys/class/power_supply/battery/charge_counter"; // content: 0 to 100

int int_mode(char* mode);
const char* str_mode(int mode);

int show_menu_boot(void);
int show_menu_overclock(void);
int show_menu_tools(void);
int show_menu_recovery(void);

int usb_connected(void);
int adb_started(void);
int battery_level(void);

int boot_mode(int ui, const char mode[]);
int snd_boot_uart(int ui);
int snd_system(int ui);

int show_config_bootmode(void);

int get_default_bootmode(void);
int set_default_bootmode(int mode);
int get_bootmode(int clean, int log);

int bootmode_write(const char* str);
int next_bootmode_write(const char* str);

int bypass_sign(const char* mode);
int bypass_check(void);

int exec_and_wait(char** argp);
int exec_script(const char* filename, int ui);
int real_execute(int r_argc, char** r_argv);
int file_exists(char * file);

int snd_exec_script(const char* filename, int ui);

int log_dumpfile(char * file);

int set_usb_device_mode(const char *mode);
int mount_usb_storage(const char *part);

#endif // EXTENDED_COMMAND_H
