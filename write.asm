
section .text
    global  _m_write

_m_write:
    movl    rax, 1
    int     0x80
    ret
