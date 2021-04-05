from django.db import models
import datetime

# Choice array declaration
CHOICES_YEAR = []
CHOICES_CPU = [('INT', 'Intel'), ('AMD', 'AMD')]
CHOICES_STATUS = [('OFF', 'Disconnected'),('WOR','Working'),('MAN','Maintenance')]
CHOICES_NVIDIA = [('RTX', 'GeForce RTX'), ('QUA', 'Quadro'), ('GTX', 'GeForce GTX'), ('QTX', 'Quadro RTX'), ('DCT', 'DataCenter Line')]
CHOICES_OS = [('LIN', 'Linux'), ('BSD', 'BSD'), ('APL', 'Apple MacOS'), ('WIN', 'Windows')]

# Populate the year choice list
for r in range(2008, (datetime.datetime.now().year)):
    CHOICES_YEAR.append((r,r))

class CPU(models.Model):
    brand = models.CharField(max_length=3, choices=CHOICES_CPU)
    line = models.CharField(max_length=10)
    model = models.CharField(max_length=10)
    year = models.IntegerField(choices=CHOICES_YEAR)
    core_count = models.SmallIntegerField()
    thread_count = models.SmallIntegerField()
    consumption = models.SmallIntegerField()
    base_freq = models.FloatField()
    turbo_freq = models.FloatField()
    ram_type = models.CharField(max_length=9)
    ram_channels = models.SmallIntegerField()
    pcie_rev = models.SmallIntegerField()
    pcie_lanes = models.SmallIntegerField()
    url = models.CharField(max_length=256)
    models.UniqueConstraint(fields=['line','model'], name='unique_cpu_model')
    
    def __str__(self):
        return self.brand +" "+ self.line +" "+ self.model + "["+self.core_count+"C-"+self.thread_count+"T]"+" @ "+ self.base_freq + "GHz"

class NVIDIA(models.Model):
    line = models.CharField(max_length=3,choices=CHOICES_NVIDIA)
    model = models.CharField(max_length=10)
    year = models.IntegerField(choices=CHOICES_YEAR)
    vram = models.SmallIntegerField()
    core_count = models.SmallIntegerField()
    teraflops = models.FloatField()

class OS(models.Model):
    type = models.CharField(max_length=3, choices=CHOICES_OS)
    version = models.CharField(max_length=20)

class Machine(models.Model):
    name = models.CharField(max_length=15)
    ext_ip = models.CharField(max_length=15)
    status = models.CharField(max_length=3, choices=CHOICES_STATUS)
    cpu_model = models.ForeignKey(CPU, on_delete=models.RESTRICT)
    cpu_count = models.SmallIntegerField(max_length=1)
    ram = models.SmallIntegerField(max_length=4)
    os = models.ForeignKey(OS, on_delete=models.RESTRICT)
    gpu_count = models.SmallIntegerField()

class GPU(models.Model):
    model = models.ForeignKey(NVIDIA, on_delete=models.RESTRICT)
    machine = models.ForeignKey(Machine, on_delete=models.RESTRICT)