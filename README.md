Kernel_Mixer v. 0.1
=============================================

Kernel_Mixer is a teaching tool designed to enable a user to compile, write, and test custom kernel architectures inside a protected test environment. By developing a custom kernel inside of a Vagrant box, the risk of ruining a user's local development machine is mitigated. Future plans are to incorporate a test-kitchen-esque test harness that will provision a new Vagrant Box that will boot a locally developed kernel before running a full test suite. 
 
Currently still in development. Currently only builds local toolchain for the i686-elf
architecture. Will be adding in kernel source shortly. 

**NOTE**: Because of the source libraries included, the repository is currently ~1.6GB in
size. Repository _will_ be slow. Perhaps in the future this can all be included in a
community Vagrant Box and slim the size of the repository down considerably. As the
repository is currently only holding the toolchain, no kernel included. 

Needs:
	* Vagrant Provision System to setup environment variables and dependant packages
	* A kernel
	* Compile Instructions


Current Development Process:

Provision Vagrant Box:
```bash
vagrant up
```

Install required packages (Should be provisioned in the future. And yes, ViM is a
		**REQUIRED** package. ):
```bash
sudo apt-get update
sudo apt-get install -y libgmp3-dev libmpfr-dev libisl-dev libcloog-isl-dev libmpc-dev vim
```

Set Environment Variables
```bash
export PREFIX="/usr/local/src/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"
```

Then start to compile the toolchain for the kernel.
Start with binutils-2.22:
```bash
cd /usr/local/src/build-binutils
../binutils-2.22/configure --target=$TARGET --prefix="$PREFIX" --disable-nls
--disable-werror
make
make install
```

Then compile the GCC toolchain:
```bash
../gcc-4.6.3/configure --target=$TARGET --prefix="$PREFIX" --disable-nls
--enable-languages=c,c++ --without-headers
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
To ensure the path is set to ```/usr/local/src/cross/bin/``` as expected. 

< Kernel Notes To Be Added > 
