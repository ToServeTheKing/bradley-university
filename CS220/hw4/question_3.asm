# Write a program in MIPS that takes two values from the user and perform
# subtraction between them and then print the subtraction result. 

.data
    start:  .asciiz "------ START Program Question 3 ------\n"
    end:    .asciiz "\n------  END Program Question 3  ------\n"
    id:     .asciiz "Student: Austin Bennett   (CS 220, id: 324855)\n"
    val1:   .asciiz "First Value: "
    val2:   .asciiz "Second Value: "
    tag:    .asciiz "Result: "
    value:  .word 0

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

    # Print 1
    li $v0,4 
    la $a0,val1
    syscall

    # Read 1
    li $v0, 5
    syscall
    move $t0,$v0

    # Print 2
    li $v0,4
    la $a0,val2
    syscall

    # Read 2
    li $v0,5
    syscall
    move $t1,$v0
    
    sub $t0,$t0,$t1
    sw $t0, value

    li $v0,4
    la $a0,tag 
    syscall

    li $v0,1
    lw $a0, value
    syscall

    li $v0, 4
    la $a0, end
    syscall

    li $v0,10
    syscall
.end main