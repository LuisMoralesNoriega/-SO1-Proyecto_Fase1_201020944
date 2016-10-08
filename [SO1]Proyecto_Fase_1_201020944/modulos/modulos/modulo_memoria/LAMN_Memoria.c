#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/mm.h>

void __attribute__((weak)) arch_report_meminfo(struct seq_file *m)
{
}

static int meminfo_proc_show(struct seq_file *m, void *v)
{
	struct sysinfo i;

	seq_printf(m,"201020944 \nLuis Aroldo Morales Noriega \n\nDebian 8 \n\n");
 	#define K(x) ((x) << (PAGE_SHIFT - 10))
    	si_meminfo(&i);
    	seq_printf(m,"MemTotal: %8lu kB\n",K(i.totalram));
    	seq_printf(m,"MemFree: %8lu kB\n",K(i.freeram));
    	#undef K

	return 0;
}

static int meminfo_proc_open(struct inode *inode, struct file *file)
{
	return single_open(file, meminfo_proc_show, NULL);
}

static const struct file_operations meminfo_proc_fops = {
	.open		= meminfo_proc_open,
	.read		= seq_read,
	.llseek		= seq_lseek,
	.release	= single_release,
};

static int __init proc_meminfo_init(void)
{
	printk(KERN_INFO "Hola mi carnet es 201020944 modulo de memoria");
	proc_create("LAMN_Memoria", 0, NULL, &meminfo_proc_fops);
	return 0;
}

static void proc_meminfo_exit(void)
{
    remove_proc_entry("LAMN_Memoria", NULL);
    printk(KERN_INFO "Adios mi carnet es 201020944 modulo de memoria");
}

module_init(proc_meminfo_init);
module_exit(proc_meminfo_exit);
