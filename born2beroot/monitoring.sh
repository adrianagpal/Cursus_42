#!/bin/bash

# Arquitecture of OS and kernel version
arquitecture=$(uname -a)

# Number of physical processors
physical_CPU=$(grep -c "physical id" /proc/cpuinfo) 

# Number of virtual processors
vCPU=$(grep -c "processor" /proc/cpuinfo)

# Memory usage
total_RAM=$(free --mega | grep Mem | awk '{print $2}')
used_RAM=$(free --mega | grep Mem | awk '{print $3}')
perc_RAM=$(free --mega | grep Mem | awk '{printf("%.2f"), $3 * 100/$2}')

# CPU load (total - idle)
cpu_load=$(top -n1 | grep '%Cpu' | awk '{printf("%.1f"), 100 - $5}')

# Last boot
last_boot=$(who -b | awk '{print $3, $4}')

# LVM use
lvm_use=$(if grep -q '^/dev/mapper/' /etc/fstab; then echo "yes"; else echo "no"; fi)

# TCP connections
tcp_con=$(ss -ta | grep ESTAB | wc -l)

# User log
user_log=$(users | wc -l)

# Network
ip=$(hostname -I)
mac=$(ip link | grep link/ether | awk '{print $2}')

# Sudo
sudo_com=$(journalctl _COMM=sudo | grep -c COMMAND)

wall "  #Architecture : $arquitecture 
        #CPU physical : $physical_CPU 
        #vCPU : $vCPU
        #Memory Usage : $used_RAM/${total_RAM}MB ($perc_RAM%)
        #Disk Usage :
        #CPU load : $cpu_load%
        #Last boot : $last_boot
        #LVM use : $lvm_use
        #Connections TCP : $tcp_con ESTABLISHED
        #User log : $user_log
        #Network : IP $ip ($mac)
        #Sudo : $sudo_com cmd

"




