Kernel_Mixer v. 0.1
=============================================

Kernel_Mixer is a teaching tool designed to enable a user to compile, write, and test custom kernel architectures inside a protected test environment. By developing a custom kernel inside of a Vagrant box, the risk of ruining a user's local development machine is mitigated. Future plans are to incorporate a test-kitchen-esque test harness that will provision a new Vagrant Box that will boot a locally developed kernel before running a full test suite. 
 
Currently still in development. Currently only builds local toolchain for the i686-elf
architecture. Will be adding in kernel source shortly. 

Needs:
 * ~~Vagrant Provision System to setup environment variables and dependant packages~~
 * A kernel
 * ~~Compile Instructions~~
 * Auto-Compile Shell Script

Current Development Process:

**NOTE**: You only need to compile the toolchain if you **NEED** to, or want to. The provisioned Vagrant box will have the correct binaries to compile the kernel specified in the $PATH environment variable. Follow instructions below for compiling your own cross compiler if you wish.

Provision Vagrant Box:
```bash
vagrant up
vagrant ssh
```

**Provisioned. 6/13.** ~~Install required packages (Should be provisioned in the future.~~ :
```bash
sudo apt-get update
sudo apt-get install -y libgmp3-dev libmpfr-dev libisl-dev libcloog-isl-dev libmpc-dev vim
```

**Provisioned. 6/13.** ~~Set Environment Variables~~
```bash
export PREFIX="/usr/local/src/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"
```

Compile Toolchain and GCC Cross Compiler
----------------------------------------

To Compile your own toolchain and gcc-cross compiler, first ensure environment variables are set correctly. 
```bash
echo $PREFIX
echo $TARGET
```
Should return: 
```bash
/home/vagrant/opt/cross"
i686-elf
```
**NOTE:** If you plan on compiling a toolchain and cross compiler for a different architecture, substitute that architecture in the $TARGET environment variable. 

You will need to retrieve a couple tarballs of GNU source projects. 
```bash
cd /home/vagrant/opt/src
# Retrieve GNU Binutils-2.22
wget http://ftp.gnu.org/gnu/binutils/binutils-2.22.tar.bz2
# Retrieve GNU GCC
wget http://www.netgull.com/gcc/releases/gcc-4.6.3/gcc-4.6.3.tar.bz2
# Extract Tarballs + Remove Tarballs
tar -xjvf binutils-2.22.tar.bz2
rm binutils-2.22.tar.bz2
tar -xjvf gcc-4.6.3.tar.bz2
rm gcc-4.6.3.tar.bz2
```
Now that you have the source code for both binutils-2.22 and gcc-4.6.3 inside ```/home/vagrant/opt/src/``` you should be ready to start compiling your toolchain. 

Start with binutils-2.22:
```bash
cd $HOME/opt/src
mkdir build-binutils
cd build-binutils
../binutils-2.22/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --disable-werror
make
make install
```
Then compile the GCC Cross Compiler:
```bash
cd $HOME/opt/src
mkdir build-gcc
cd build-gcc
../gcc-4.6.3/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --without-headers
make all-gcc
make all-target-libgcc
make install-gcc
make install-target-libgcc
```
You should now have a working compiled toolchain for the bare-kernel. Test your
toolchain's version by running:
```bash
i686-elf-gcc --version
```
The GCC Compiler should be at version 4.6.3, and you can verify its correct location by: 
```bash
which i686-elf-gcc
```
To ensure the path is set to ```/home/vagrant/opt/src/cross/bin/``` as expected. 

< Kernel Notes To Be Added > 
