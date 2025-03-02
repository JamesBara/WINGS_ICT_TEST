OUTPUT_FORMAT("elf32-littlearm")
ENTRY(Reset_Handler)

__FLASH_BASE = 0x8000000;
__FLASH_SIZE = 0x10000;

__SRAM_BASE = 0x20000000;
__SRAM_SIZE = 0xA000;

MEMORY
{
  rom (rx)  : ORIGIN = __FLASH_BASE, LENGTH = __FLASH_SIZE
  ram   (rwx) : ORIGIN = __SRAM_BASE, LENGTH = __SRAM_SIZE
}

SECTIONS
{
  .text :
  {   
    . = ALIGN(4);
    KEEP(*(.isr_vector))
    *(.text)
    *(.text*)
    *(.rodata)     
    *(.rodata*)
    . = ALIGN(4);
  } > rom

  .data :
  {
    . = ALIGN(4);	  
    *(.data)
    *(.data.*)
    . = ALIGN(4);
  } > ram AT > rom

  .bss (NOLOAD):
  {
    . = ALIGN(4);
    *(.bss)
    *(.bss.*)
    *(COMMON)
    . = ALIGN(4);
  } > ram

  .stack (NOLOAD):
  {
    . = ALIGN(8);
    . = DEFINED(__stack_size__) ? . + __stack_size__ : ORIGIN(ram) + LENGTH(ram);
    __stack_top__ = .;
    . = ALIGN(8);
  } > ram
}

__rom_data_start__ = LOADADDR(.data);
__data_start__ = ADDR(.data);
__data_end__ = __data_start__ + SIZEOF(.data);

__bss_start__ = ADDR(.bss);
__bss_end__ = __bss_start__ + SIZEOF(.bss);
