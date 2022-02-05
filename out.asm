    .data
    _false_str: .asciiz "false"
    _true_str: .asciiz "true"
    #x
    ab_: .word 0

    #y
    ac_: .word 0

    #i
    ad_: .word 0

    #j
    ae_: .word 0

    #10
    af_: .word 10
    ag_: .word 0
    #0
    ai_: .word 0
    #1
    ak_: .word 1
    al_: .word 0
    #10
    an_: .word 10
    ao_: .word 0
    #0
    ar_: .word 0
    at_: .word 0
    #2
    ay_: .word 2
    az_: .word 0
    ba_: .word 0
    #1
    av_: .word 1
    aw_: .word 0
    bb_: .word 0
    #"Result is "
    bd_: .asciiz "Result is "
    #0
    be_: .word 0

    .text
    .globl main
main:

    # doing the <
    lw $t0, af_
    lw $t1, ab_
    bge $t1, $t0, _label_aa
    li $t0, 1
    b _label_ab
_label_aa:
    li $t0, 0
_label_ab:
    sw $t0, ag_

    #begin ifsmtm
    lw $t0, ag_
    beqz $t0, ENDIFLABEL_ah_

    #assigning ai_ to ab_
    lw $t0, ai_
    la $t1, ab_
    sw $t0, 0($t1) 
    j ENDELSELABELaj_
ENDIFLABEL_ah_:

    # doing the +
    lw $t0, ak_
    lw $t1, ab_
    addu $t0, $t0, $t1
    sw $t0, al_

    #assigning al_ to ab_
    lw $t0, al_
    la $t1, ab_
    sw $t0, 0($t1) 
ENDELSELABELaj_:
while_loop_am_:
    # doing the <
    lw $t0, an_
    lw $t1, ab_
    bge $t1, $t0, _label_ac
    li $t0, 1
    b _label_ad
_label_ac:
    li $t0, 0
_label_ad:
    sw $t0, ao_

    lw $t0, ao_
    beqz $t0, endwhile_ap_

    #assigning ar_ to ad_
    lw $t0, ar_
    la $t1, ad_
    sw $t0, 0($t1) 
    # begin for loop of BEGINFOR_as_
BEGINFOR_as_:
    # doing the >=
    lw $t0, ab_
    lw $t1, ad_
    blt $t1, $t0, _label_ae
    li $t0, 1
    b _label_af
_label_ae:
    li $t0, 0
_label_af:
    sw $t0, at_

    lw $t0, at_
    beqz $t0, ENDFOR_au_

    # doing the *
    lw $t0, ay_
    lw $t1, ab_
    mult $t0, $t1
    mflo $t0
    sw $t0, az_

    # doing the -
    lw $t0, az_
    lw $t1, ac_
    subu $t0, $t1, $t0
    sw $t0, ba_

    #assigning ba_ to ac_
    lw $t0, ba_
    la $t1, ac_
    sw $t0, 0($t1) 

    # doing the +
    lw $t0, av_
    lw $t1, ad_
    addu $t0, $t0, $t1
    sw $t0, aw_

    #assigning aw_ to ad_
    lw $t0, aw_
    la $t1, ad_
    sw $t0, 0($t1) 
    j BEGINFOR_as_
ENDFOR_au_:

    # doing the !=
    lw $t0, ab_
    lw $t1, ac_
    beq $t0, $t1, _label_ag
    li $t0, 1
    b _label_ah
_label_ag:
    li $t0, 0
_label_ah:
    sw $t0, bb_

    #begin ifsmtm
    lw $t0, bb_
    beqz $t0, ENDIFLABEL_bc_
ENDIFLABEL_bc_:
    j while_loop_am_
endwhile_ap_:


    # print bd_...
    li $v0, 4
    la $a0, bd_
    syscall

    # print ac_...
    li $v0, 1
    lw $a0, ac_
    syscall

    # Printing new line
    li $a0, 0xA
    li $v0, 0xB
    syscall


    # exit
    li $v0, 10
    syscall

