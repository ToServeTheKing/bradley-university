# Example program to display a string and an integer.
# Demonstrates use of QtSpim system service calls.
# -----------------------------------------------------
# Data Declarations
.data
start:  .asciiz "------ START Program Example 9.2.1 ------\n"
end:    .asciiz "\n------ END Program Example 9.2.1 ------\n"
id:     .ascii "Student: Austin Bennett   (CS 220, id: 324855)\n"
hdr:    .ascii "Example\n"
        .asciiz "The meaning of life is: "
number: .word 42
# -----------------------------------------------------
# text/code section
.text
.globl  main
.ent    main
main:
    la $a0,     start
    li $v0,     4
    syscall

    la  $a0,    id
    li  $v0,    4       # call code, print string
    syscall             # system call
    
    la $a0,     hdr
    li $v0,     4

    li  $v0,    1       # call code, print int
    lw  $a0,    number  # value for int to print
    syscall             # system call
                        # ----
    la $a0,     end
    li $v0,     4
    syscall   
                        # Done, terminate program.
    li $v0, 10          # terminate
    syscall             # system call
.end main