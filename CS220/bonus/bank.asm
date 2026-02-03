

.data
start:	        .asciiz "---> Start of Bank Program <---\nAuthor information: CS 220 | #324855 | Austin Bennett\n--->  Welcome to the Interest Calculator! <--- \n2%: saving years < 7 years\n5%: saving years >= 7 years\n"	
promptMsg1: 	.asciiz "==> Enter the principal:$ \n"			
promptMsg2: 	.asciiz "==> Enter the years of savings: \n"	
resultLine:	    .asciiz	"----------------> Result <----------------\n---> Your principal is: "			
resultLine2: 	.asciiz "\n---> Your interest rate is: "
yrLbl:		    .asciiz "\nYear "						
balanceRet:		.asciiz ": your balance is $"			
balLbl:		    .asciiz "\n---> Your balance after "		
yearsRet:		.asciiz " years: $ "						
finalLine: 	    .asciiz "\n----------------> End of Interest Calculator <---------------- "	
newLine:	    .asciiz "\n"							
principal: 	    .float 0.0	
years: 		    .word 0 	
yearsDiv:	    .word 7								
rate1:		    .float 0.02							
rate2:		    .float 0.05							
interestRate:	.float 0.0						
balance: 	    .float 0.0							

.text
.globl main #entrance of program
.ent main

main:
	la      $a0,    start 	
	li      $v0,    4		
    syscall

	la      $a0,    promptMsg1	
	li      $v0,    4		
	syscall
	
	li      $v0,    6		
	syscall			
	
    s.s     $f0,    principal	
	la      $a0,    promptMsg2	
	li      $v0,    4		
	syscall			
	
	li      $v0,    5		
	syscall

	sw      $v0,    years	
	la      $a0,    resultLine 	
	li      $v0,    4		
	syscall			

	l.s     $f12,   principal	
	li      $v0,    2		
	syscall

	la      $a0,    resultLine2	
	li      $v0,    4		
	syscall			

	lw      $t1,    years		
	lw      $t2,    yearsDiv	
	blt     $t1,    $t2,        lessThan	
	l.s     $f1,    rate2		
	s.s     $f1,    interestRate	
	l.s     $f12,   interestRate	
	li      $v0,    2		
	syscall		
	
	li      $t3,    1	
	
	while:		
        bgt     $t3,    $t1,    exit
        la      $a0,    yrLbl		
        li      $v0,    4		
        syscall			
            
        move    $a0,    $t3	
        li      $v0,    1		
        syscall			

        la      $a0,    balanceRet	
        li      $v0,    4		
        syscall			

        l.s     $f3,    principal
        l.s     $f4,    interestRate
        mul.s   $f2,    $f3,    $f4	
        add.s   $f5,    $f3,    $f2	
        s.s     $f5,    principal	
        s.s     $f5,    balance	
        l.s     $f12,   balance	
        li      $v0,    2		
        syscall 	
        
        addi    $t3,    $t3,    1
        j       while			

	exit:	
        la      $a0,    balLbl	
        li      $v0,    4		
        syscall			
        
        lw      $a0,    years	
        li      $v0,    1		
        syscall			
            
        la      $a0,    yearsRet	
        li      $v0,    4		
        syscall			
        
        l.s     $f12,   balance
        li      $v0,    2		
        syscall			

        la      $a0,    finalLine
        li      $v0,    4		
        syscall			

        li      $v0,    10		
        syscall			

	lessThan:		
        l.s     $f1,    rate1		
        s.s     $f1,    interestRate
        
        
        l.s     $f12,   interestRate	
        li      $v0,    2	
        syscall			
        
        li      $t3,    1 		
	
	logic:			
        bgt     $t3,    $t1,    exit
        la      $a0,    yrLbl		
        li      $v0,    4		
        syscall			
        
        move    $a0,    $t3		
        li      $v0,    1		
        syscall			

        la      $a0,    balanceRet		
        li      $v0,    4		
        syscall			
        
        l.s     $f3,    principal	
        l.s     $f4,    interestRate
        mul.s   $f2,    $f3,    $f4	
        add.s   $f5,    $f3,    $f2	
        s.s     $f5,    principal	
        s.s     $f5,    balance
        l.s     $f12,   balance
        li      $v0,    2		
        syscall 		
        
        addi    $t3,    $t3,    1	
        j       logic	