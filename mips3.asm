.data
    buffer:         .space 80
    prompt_season:  .asciiz "Please select the current season (1. Summer, 2. Winter): "
    message_crops:  .asciiz "The crops to be planted this season are: "
    soil_manage_prompt: .asciiz "Now that the crops have been sown, it is time to manage them properly.\n"
    expected_yield_prompt: .asciiz "The expected yield for these crops will be:\n"
    wait_harvest_prompt: .asciiz "Now it is time to wait for harvesting.\n"
    sown1_day_prompt: .asciiz "Give the day that the first crop was sown into the soil (DD): "
    sown1_month_prompt: .asciiz "Give the month that the first crop was sown into the soil (MM): "
    congrats_message: .asciiz "Congratulations!! You have successfully used the Machobane Farming System to produce your produce!\n"
    months_per_day:    .word   30
    prompt_crop1:   .asciiz "Please select the stalk crop (1. Maize, 2. Beans, 3. Pumpkins, 4. Sorghum): "
    prompt_crop2:   .asciiz "Please select the running crop (1. Maize, 2. Beans, 3. Pumpkins, 4. Sorghum): "
    prompt_soil:    .asciiz "Select soil preparation option (1. Turn soil only, 2. Turn soil and add manure): "
    prompt_num1:    .asciiz "Enter the number of crop1's to plant: "
    prompt_num2:    .asciiz "Enter the number of crop2's to plant: "
    prompt_plots:   .asciiz "Enter the number of plots to plant on: "
    prompt_length:  .asciiz "Enter the length of each plot: "
    prompt_width:   .asciiz "Enter the width of each plot: "
    message_prep:   .asciiz "The first step is to prepare the soil appropriately for "
    message_options:.asciiz "1. Turn soil only\n2. Turn soil and add manure\n"

    newline:        .asciiz "\n"
    # Add any additional data if needed


.text
    .globl main

main:
      # Display season prompt
    li $v0, 4                    # system call for print_str
    la $a0, prompt_season
    syscall

    # Read season choice
    li $v0, 5                    # system call for read_int
    syscall
    move $t0, $v0                 # $t0 contains the user's season choice (1 or 2)

    # Display crop information based on season
    beq $t0, 1, summer_season
    beq $t0, 2, winter_season
    j exit_program

summer_season:
    # Display crop options for summer
    la $a0, prompt_crop1
    syscall

    # Read user's choice for crop1
    # ...

    la $a0, prompt_crop2
    syscall

    # Read user's choice for crop2

    # Display message about the number of plots
    la $a0, prompt_plots
    syscall

    # Read user's choice for plotnum

    # Display plot information
    beq $t1, 1, summer_one_plot
    bne $t1, 1, summer_multiple_plots
    j exit_program

summer_one_plot:
    # Display message for one plot
    la $a0, prompt_length
    syscall

    # Read user's choice for plot length

    la $a0, prompt_width
    syscall

    # Read user's choice for plot width

    # Display message about soil preparation
    la $a0, message_prep

summer_multiple_plots:
    # Display message for multiple plots
    # ...
winter_season:
    # Similar logic for the winter season

exit_program:
    li $v0, 10                   # system call for exit
    syscall
