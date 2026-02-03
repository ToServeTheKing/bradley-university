.data
    start:  .asciiz "------ START Program Question 3 ------\n"
    end:    .asciiz "\n------  END Program Question 3  ------\n"
    id:     .asciiz "Student: Austin Bennett   (CS 220, id: 324855)\n"
    val:    .word   65

.text
.globl main
.ent main
main:
    li $v0, 4
    la $a0, start
    syscall

    li $v0, 4
    la $a0, id
    syscall

    lw $t0, val
    

    move $t1, $t0
    

    li $v0, 4
    la $a0, end
    syscall 

    li $v0, 10
    syscall
.end main