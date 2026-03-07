*This project has been created as part of the 42 curriculum by adrianag.*

# Description
Goal and brief overview
The goal of this project is to create and configure a virtual machine. 

An Operating System (OS) is a group of programs that allow to execute and control a machine. 

The benefit of having a VM is better data recovery than when the physical machine crashes, becuase with a snapshot it's possible to have the current state of the machine and data can be recovered more easily. 

Furthermore, virtualization offers an extra layer of safety for data, because each server is isolated from each other and it's safer in case there is malware. 

Grub-PC: *Grub boot loader* loads the OS. It's a program between the OS and BIOS (essential firmware sthat tells your computer's OS how to work properly). 

# Instructions
Relevant info about compilation, installation and/or execution

I installed a virtual machine using Debian AMD64 13, the latest stable version. During setup, I created two to three physical partitions and one logical partition. When configuring the logical partition, it is important to set up all the space at once. No graphical user interface (GUI) was installed, and no additional software was included.

# Resources

# Project description
## Debian vs Rocky Linux: Choice of operating system
Debian is a widely used general-purpose distribution, with more packages available by default, a strong open-source focus, and extensive documentation. Its more frequent updates can be inconvenient for enterprises. 

Rocky Linux, on the other hand, is enterprise-focused, designed for server stability, with long-term security support and better compatibility with commercial software. Its updates are slower, making it less suited for general-purpose use.

## AppArmor vs SELinux

## UFW vs firewalld
The firewall manages ip tables and controls access to the machine. An ip is the address of a device, so it's possible to connect with. Without a firewall, the VM is directly exposed to unathorized access, malware and network attacks and the VM would accept incoming connections to open ports. 

UFW (Uncomplicated Firewall) is a simple and easy-to-use firewall, ideal for Ubuntu or Debian users who want to quickly allow or block ports. It uses global rules with straightforward commands like *ufw allow 22*.

Firewalld, on the other hand, is more flexible and modern, designed for servers and dynamic networks (RHEL, Fedora, CentOS). It supports zones of trust, allows rule changes without restarting the firewall, and offers more detailed service configuration using *firewall-cmd*.

To install UFW:
> sudo apt install ufw

To enable UFW:
> sudo ufw enable

To check if UFW is active:
> sudo ufw status

To allow traffic on a certain port:
> sudo ufw allow 4242

To connect from the host to the VM, first configure it in VirtualBox in Settings > Firewall, the equivalence between the ports in the host and VM. This is required because port 4242 is not allowed. Then, you can connect with:
> ssh adrianag@localhost -p 4243

## VirtualBox vs UTM
The hypervisor or VMM (Virtual Machine Monitor) is the software that allows to create and execute one or more VMs simultaneously. The hypervisor controls the resources of the host and allocates them to each VM. In our case, VirtualBox will be the hypervisor. There are 2 types of hypervisors: bare-metal (it is executed in the same host malware and it's used for servers) and hosted (executed as a program, used for PCs).

VirtualBox offers a broad compatibility with various Linux distributions, while UTM supports fewer options and it's more limited to macOS.

## Design choices & services installed
security policies, user management

The size you allocate to the virtual machine should be sufficient to support the operating system you plan to install, along with any required services. 

LVM (Logical Volume Manager) is an abstraction layer between the physical hard disk and the system. It allows the assigned memory to the partitions to be dynamic and can be adjusted without rebooting. With *standard partitions*, only the last created partition can be resized.  

### Partitions
When space is allocated to a partition with a file system (for example, ext4), it contains a special file that defines how the storage space is organized. This file is interpreted by the operating system. It occupies actual physical space on the hard disk.

The journaling file system controls the organization and access of files, and avoids that applications access to the storage producing potential data corruption or incompatibilities. 

A logical partition is useful if you want to bypass the limit of 4 partitions and create additional subdivisions, such as /home, /var, /temp. There is also a partition called *swap*, which the system uses as virtual memory when the RAM is full, allowing programs to continue running without problems.

To check partitions (*list block devices*): 
> lsblk

### Apt
Apt (advanced package tool) manages Linux software packages. It works with the libraries to manage the installation and removal of software in Debian and Debian-based distributions. 

### Sudo
Sudo (substitute user do) is a command for Unix-like operating systems that allows an user to execute commands as another user, like the administrator or root user, without needing to log. Sometimes you cannot use *sudo* logged as your user. In that case, you are not included in the */etc/sudoers* file, but you might belong to a group that has sudo privileges on that file. 

To install sudo:
> apt install sudo

To reset the machine and apply changes:
> sudo reboot

To check if a service (runs in the background) is active:
> sudo service \<service\> status

To check if a program is installed:
> sudo systemctl status \<program\>

#### Configuration of sudo password policy
To configure the *sudo*, create a file *sudo_config* in the folder */etc/sudoers.d*. 

To create a log file to save all sudo commands' input and output, create the directory before editing the *sudo_config* file:
> mkdir /var/log/sudo

tty: when tty is required, sudo must be run from a logged-in terminal session. 

There are other requirements for the password that are specified in: 
- /etc/login.defs: for example, configure maximum of days for changing the password, etc.
- /etc/pam.d/common-password: additional password security.

### SSH
SSH is a protocol and program for access to servers. It establishes a safe channel between the client (host) and the server (VM), through encrypting. 

To install SSH:
> sudo apt install openssh-server

To avoid SSH root login, open the configuration file \<sshd_config\> and set *PermitRootLogin* to no. In this file, you can configure which ports you can connect to the VM with (also change this in the file \<ssh_config\>). 

Then restart or reload (reload recommended not to interrupt the connection) the service with:
> sudo systemctl restart/reload sshd
or
> sudo service ssh restart

# Notes
Groups are helpful to manage resources and permissions. 
Check groups (with getent *get entity*):
> getent group
> cat /etc/group

Check users in a group:
> getent group user42

Add an user to a group:
> sudo adduser \<username\> \<groupname\>

Create a new user or new group:
> sudo adduser \<username\>
> sudo addgroup \<groupname\>

How to change hostname:
> nano /etc/hostname
Then later reboot with sudo.


