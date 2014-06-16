/* Bootloader looks at this image and starts execution at the symbol designated as the entry point. */ 

ENTRY(_start)

SECTIONS
{
  . = 1M;

  .text BLOCK(4K) : ALIGN(4K)
  {
    *(.multiboot)
    *(.text)
  }

  .rodata BLOCK(4K) : ALIGN(4K)
  {
    *(.rodata)
  }

  .data BLOCK(4K) : ALIGN(4K)
  {
    *(.data)
  }

  .bss BLOCK(4K)  : ALIGN(4K)
  {
    *(.data)
  } 
}