# Write A MIPS Assembly Program to ADD the Numbers: 4, 6, 8

.data
    start:  .asciiz "------ START Program Question 2 ------\n"
    end:    .asciiz "\n------  END Program Question 2  ------\n"
    id:     .asciiz "Student: Austin Bennett   (CS 220, id: 324855)\n"
    tag:    .ascii "4 + 6 + 8 = "

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

    li $v0, 4
    la $a0, tag
    syscall

    li $t0,4
    add $t1,$t1,$t0
    li $t0,6
    add $t1,$t1,$t0
    li $t0,8
    add $t1,$t1,$t0
    
    li $v0, 1
    add $a0,$0,$t1
    syscall

    li $v0, 4
    la $a0, end
    syscall

    li $v0, 10
    syscall
.end main