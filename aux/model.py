from django.db import models
import datetime

# Choice array declaration
CHOICES_YEAR = []
CHOICES_CPU = []

# Populate the year choice list
for r in range(2008, (datetime.datetime.now().year)):
    CHOICES_YEAR.append((r,r))

class CPU(models.Model):
    brand = models.CharField(max_length=5, choices=CHOICES_CPU)
    line = models.CharField()
    model = models.CharField()
    year = models.IntegerField(choices=CHOICES_YEAR)
    core_count = models.SmallIntegerField()
    thread_count = models.SmallIntegerField()
    consumption = models.SmallIntegerField()
    base_freq = models.FloatField()
    turbo_freq = models.FloatField()
    ram_type = models.CharField()
    ram_channels = models.SmallIntegerField()
    pcie_rev = models.SmallIntegerField()
    pcie_lanes = models.SmallIntegerField()
    url = models.CharField(max_length=256)
    models.UniqueConstraint(fields=['line','model'], name='unique_cpu_model')
    
    def __str__(self):
        return self.brand +" "+ self.line +" "+ self.model #+ "["+self.core_count+"C-"+self.thread_count+"T]"+" @ "+ self.base_freq + "GHz"
