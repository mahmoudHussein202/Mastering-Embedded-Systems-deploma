.section .vectors 

.word _stack_top
.word _reset_handler
.word _vector_handler



_reset_handler:
    bl main
    b .

_vector_handler:
    b _reset_handler
    