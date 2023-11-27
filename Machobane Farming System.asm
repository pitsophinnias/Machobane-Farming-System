	.data
#Declare strings to be used
welcome: .asciiz "Welcome to Machobane Farming System"
select: .asciiz "Please select an option"
season: .asciiz "1. Summer 2. Winter"
exit: .asciiz "Congratulations!! You have successfully used Machobane Farming System to produce your produce"
plant: .asciiz "Now that your soil..."
soilprep: .asciiz "1.Turn soil only 2.Turn soil and add manure"
plotlength: .asciiz "Please give the length of each plot"
plotwidth: .asciiz "Please give the width of each plot"
plotnum: .asciiz "Please give the number of plots..."
cropnum: .asciiz "Please give the number of crops"
manage: .asciiz "Now that the crops have been sown..."
weeds: .asciiz "Weeds should be ..."
yield: .asciiz "The expected yield..."
rain: .asciiz "Are there any chances of ..." 
harvest: .asciiz "Now it is time to wait for harvesting"
summer: .asciiz "1. Maize 2.Beans 3. Pumpkins 4. Sorghum"
winter: .asciiz "1.Wheat 2.Rape 3.Peas"
planted: .asciiz "The crops to be planted..."

#Declare comparisons
moisture: .word 3
sfertility: .word 4
numplot: .word 0
plot: .space 8
string_Y: .asciiz "Y"
plantnum: .word 0



	

	.globl main
	.globl expyield
	.globl harvestTime
	.globl fertility
	.globl rained
	.globl option
	.text
#Option function
option:
		
    addi $sp, $sp, -4
    sw $fp, 4($sp)
    sw $ra, 0($sp)
    move $fp, $sp

    
    lw $a0, 0($a0)               # Load the address of the string into $a0

    
    la $t0, string_Y             # Load the address of the string "Y" into $t0
    li $t1, 0                    # Initialize $t1 to 0 (false)

compare_loop:
    lb $t2, 0($a0)               # Load a byte from the user's string
    lb $t3, 0($t0)               # Load a byte from the string "Y"

    beq $t2, $t3, continue_loop  # If characters are equal, continue checking
    j end_option                 # If characters are not equal, jump to end_option

continue_loop:
    beqz $t2, end_option         # If the current character is null (end of string), jump to end_option
    addi $a0, $a0, 1             # Move to the next character in the user's string
    addi $t0, $t0, 1             # Move to the next character in the string "Y"
    j compare_loop               # Repeat the loop

end_option:
    beqz $t2, set_result_1       # If the loop ended due to the null character, set the result to 1

    
    li $v0, 0                    # Set $v0 to 0 (false)
    j end_function

set_result_1:
    li $v0, 1                    # Set $v0 to 1 (true)

end_function:
    
    lw $ra, 0($fp)
    lw $fp, 4($fp)
    addi $sp, $sp, 4
    jr $ra

#rained function
rained:
	#change stack pointer
    addi $sp, $sp, -4
    sw $fp, 4($sp)
    sw $ra, 0($sp)
    move $fp, $sp
    
    
    lw $t0, 0($a0)       # Load 'choice' parameter into $t0
    lw $t1, 4($a0)       # Load 'moisture' parameter into $t1
    
    beq $t0, 1, if_true   # Branch to if_true if choice equals 1
    
    
    addi $t1, $t1, 4      # moisture = moisture + 4
    j end_rained
    
if_true:
    
    addi $t1, $t1, 5      # moisture = moisture + 5

end_rained:
    mtc1 $t1, $f0         # Convert integer to double in $f0
    mov.d $f12, $f0       # Move double to $f12 for return
    mov.d $f13, $f0       # Secondary register for double precision
    mov.d $f14, $f0       # Tertiary register for double precision
    
    #return stack pointer to original position
    lw $ra, 0($fp)
    lw $fp, 4($fp)
    addi $sp, $sp, 4
    jr $ra

#Fertility function
fertility: 
	
    addi $sp, $sp, -4
    sw $fp, 4($sp)
    sw $ra, 0($sp)
    move $fp, $sp
    
    
    lw $t0, 0($a0)       # Load 'option' parameter into $t0
    lw $t1, 4($a0)       # Load 'sfertility' parameter into $t1
    
    beq $t0, 1, if_option1   # Branch to if_option1 if option equals 1
    beq $t0, 2, if_option2   # Branch to if_option2 if option equals 2
    
    
    addi $t1, $t1, 0       # sfertility = sfertility + 0
    j end_fertility
    
if_option1:
    
    addi $t1, $t1, 4      # sfertility = sfertility + 4
    j end_fertility
    
if_option2:
    
    addi $t1, $t1, 5      # sfertility = sfertility + 5

end_fertility:
    move $v0, $t1        # Move the result to $v0 for return
    
    
    lw $ra, 0($fp)
    lw $fp, 4($fp)
    addi $sp, $sp, 4
    jr $ra
  #Harvest time function  
harvestTime:
	addi $sp, $sp, -4
    sw $fp, 4($sp)
    sw $ra, 0($sp)
    move $fp, $sp
    
   
    lw $t0, 0($a0)       # Load 'time' parameter into $t0
    li $t1, 30           # Divide by 30
    div $t0, $t1         # Result in $t0 (quotient), $t1 (remainder)
    mflo $t2             # Move quotient to $t2
    lw $t3, 4($a0)       # Load 'month' parameter into $t3
    add $t4, $t2, $t3    # Add 'month' and the quotient
    move $v0, $t4        # Move the result to $v0 for return
    

    lw $ra, 0($fp)
    lw $fp, 4($fp)
    addi $sp, $sp, 4
    jr $ra
	
#Expected yield function
expyield:
	addi $sp,$sp,-4 		#Adjust stack pointer to create space for the yield variable
	sw $t0, 0($sp)
	 
	li $t0,0   				#yield=0
	#Assume $a0=num, $a1=fertility/10,$a2=rained /10
	mul $t1,$a1,$a2 	    #$t1=$a1*$a2
	mul $t2,$t1,$a0  		#$t2=$t1*$a0
	mul $t0,$t2,100   		#yield=$t0=$t2*100
	
	addi $sp, $sp, 4		#restore stack pointer	
	jr $ra
main:

	li $v0,4
	la $a0, welcome
	syscall
	
	li $v0,4
	la $a0,select
	syscall
	
	li $v0,4
	la $a0,season
	syscall
	li $v0,5
	syscall
	move $t0,$v0
	bne $t0, $8 , other		#if $t0!=1 go to menu oa winter

	li $v0,4
	la $a0, summer
	syscall
	li $v0,5				#crop1
	syscall
	move $t0,$v0
	li $v0,4
	la $a0, summer
	syscall
	li $v0,5				#crop2
	syscall
	move $t1,$v0
	
	li $v0,4
	la $a1,planted
	syscall
	li $v0,4
	la $a1,select
	syscall
	li $v0,4
	la $a1,soilprep
	syscall
	li $v0,5
	syscall
	move $t2,$v0			#choice
	
	li $v0,4
	la $a1, plant
	syscall
	
	li $v0,4
	la $a1,cropnum
	syscall
	li $v0,5
	syscall
	move $t3,$v0			#numcrop1
	
	li $v0,4
	la $a1,cropnum
	syscall
	li $v0,5
	syscall
	move $t4,$v0			#numcrop2
	
	li $v0,4
	la $a1, plotnum
	syscall
	li $v0,5
	syscall
	move $t5,$v0
	li $v0,4
	la $a1, plotwidth
	syscall
	li $v0,5
	syscall
	move $t6,$v0
	bne $t6, 1, many
	
many:
	
	
	li $v0,4
	la $a1,rain
	syscall
	
	
	
	
	
	
	
	
other:
	li $v0, 4
    la $a0, winter
    syscall
	
	

