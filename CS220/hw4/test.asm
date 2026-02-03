.data
  x: .word 30
  y: .word 24

  sum: .word 0
  subt: .word 0

  promptAdd: .asciiz "The sum of X and Y is : "
  promptSub: .asciiz "\nThe difference of X and Y is : "

.text
.globl main
.ent main

main:

lw $a0, x
lw $a1, y

jal Addition
sw $v0, sum

jal Subtraction
sw $v0, subt

la $a0, promptAdd
li $v0, 4
syscall

lw $a0, sum
li $v0, 1
syscall

la $a0, promptSub
li $v0, 4
syscall

lw $a0, subt
li $v0, 1
syscall

li $v0, 10
syscall

.end main

.globl Addition
.ent Addition

Addition:

li $v0, 0

add $v0, $a0, $a1

jr $ra

.end Addition

.globl Subtraction
.ent Subtraction

Subtraction:

li $v0, 0

sub $v0, $a0, $a1

jr $ra

.end Subtraction