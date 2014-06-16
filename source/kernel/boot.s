# Declare constants used for creating multiboot header. 
.set ALIGN,     1<<0              # align loaded modules on page boundaries
.set MEMINFO,   1<<1              # provide memory map
.set FLAGS,     ALIGN  |  MEMINFO 
.set MAGIC,     0x1BADB002        # allows bootloader to find header
.set CHECKSUM,  -(MAGIC + FLAGS)  # checksum of above. Multiboot. 

# Declare a header as Multiboot Standard. 
.section  .multiboot
.align    4
.long     MAGIC
.long     FLAGS
.long     CHECKSUM

# Provide our own stack for safety reasons. 
.section .bootstrap_stack, "aw", @nobits
stack_bottom:
.skip 16384 # 16 KiB
stack_top:

# Declare start position for when kernel is loaded: 
.section  .text
.global   _start
.type     _start, @function
_start:

    # Now inside Kernel. 
    # Setup stack by setting esp register to point to the top of the stack. 
    movl $stack_top, %esp

    # External Kernel Call: 
    call kernel_main

    # Function catch should the kernel fail, re-run kernel. Infinite-loop style. 
    cli     # Clear Interrupt Call to disable interrupts 
    hlt     # Halts CPU until next interrupt
.Lhang:
    jmp .Lhang

# Sets the size of the _start symbol to the current location '.' minus its start. 
.size _start, . - _start
