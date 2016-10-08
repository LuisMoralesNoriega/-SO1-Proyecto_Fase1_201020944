#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/mm.h>
#include <linux/sched.h>

void __attribute__((weak)) arch_report_meminfo(struct seq_file *m)
{
}

static int meminfo_proc_show(struct seq_file *m, void *v)
{
	struct task_struct *i;

	seq_printf(m,"201020944 \nLuis Aroldo Morales Noriega \n\nDebian 8 \n\n");
	seq_printf(m,"Procesos\n\n");
	seq_printf(m,"Nombre       Id_Proceso       Estado\n");
 	#define K(x) ((x) << (PAGE_SHIFT - 10))
	for_each_process(i){
		char *estado = "";
		if(i->state == 0){
			estado = "Corriendo";
		}else if(i->state == 1){
			estado = "Durmiendo";
		}else if(i->state == 2){
			estado = "Disco Durmiendo";
		}else if(i->state == 4){
			estado = "Detenido";
		}else if(i->state == 8){
			estado = "Detener Seguimiento";
		}else if(i->state == 16){
			estado = "Muerto";
		}else if(i->state == 32){
			estado = "Zombie";
		}
		seq_printf(m,"%s         %d            %s\n",i->comm, i->pid, estado);
	}
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
	printk(KERN_INFO "Hola mi carnet es 201020944 modulo de procesos");
	proc_create("LAMN_Procesos", 0, NULL, &meminfo_proc_fops);
	return 0;
}

static void proc_meminfo_exit(void)
{
    remove_proc_entry("LAMN_Procesos", NULL);
    printk(KERN_INFO "Adios mi carnet es 201020944 modulo de procesos");
}

module_init(proc_meminfo_init);
module_exit(proc_meminfo_exit);
