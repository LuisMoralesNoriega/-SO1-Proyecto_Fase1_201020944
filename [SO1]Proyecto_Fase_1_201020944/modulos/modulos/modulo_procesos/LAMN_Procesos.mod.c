#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x9e53a3af, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x504a6cda, __VMLINUX_SYMBOL_STR(single_release) },
	{ 0xcce0dba7, __VMLINUX_SYMBOL_STR(seq_read) },
	{ 0x7fbb50bf, __VMLINUX_SYMBOL_STR(seq_lseek) },
	{ 0x8ea51aac, __VMLINUX_SYMBOL_STR(remove_proc_entry) },
	{ 0xef82728f, __VMLINUX_SYMBOL_STR(proc_create_data) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xc52b70c8, __VMLINUX_SYMBOL_STR(init_task) },
	{ 0x90930db, __VMLINUX_SYMBOL_STR(seq_printf) },
	{ 0xf38cc1b3, __VMLINUX_SYMBOL_STR(single_open) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

