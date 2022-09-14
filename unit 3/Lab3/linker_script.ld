MEMORY {
    flash(rw) : ORIGIN = 0x08000000 , LENGTH = 128K
    sram(rwx) : ORIGIN = 0x20000000 , LENGTH = 20K
}


SECTIONS 
{
    .text :
    {
        *(.vectors*)
        *(.text*)
        E_TEXT = . ; 
    }>flash
    
    .data :
    {
        S_DATA = . ;
        *(.data*)
        E_DATA = . ;
    }> sram AT >flash

    . = 0x20000000 ;
    .bss . :
    {   
        S_BSS = . ;
        *(.bss*)
        E_BSS = . ;
    }>sram
    
    . = . + 0x1000;
    _stack_pointer = . ; 

}