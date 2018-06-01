; ---------------------
   processor 6502 
   org    $1000 
; ---------------------
R_PRINT_STRING = $AB1E 
R_SET_CURSOR   = $E50C 
R_CLEAR_SCREEN = $E544
R_PRINT_PNUM   = $BDCD ; 48589, Output positive integer number in accu/X reg
R_SYNTAX_ERROR = $AF08 ; 44808, synerr, Output ?SYNTAX Error
R_POWER_MSG    = $E45F ; 58463	words	Power-Up Message
R_DELAY        = $EEB4 ; eeb3	61107	-	Delay 1 ms
; ---------------------
; -- MACROS
  mac set_cursor
    ldx #{1}  
    ldy #{2}
    jsr R_SET_CURSOR
  endm ; set_cursor
  ;
  mac puts
    lda #<{1}
    ldy #>{1}
    jsr R_PRINT_STRING
  endm
  ;
  mac puts_at
    clear_screen
    set_cursor #{1},#{2}
    puts #{3}
  endm
  ;
  mac clear_screen
    jsr R_CLEAR_SCREEN
  endm
  ;
  mac puts_2_byte
    lda #$00  ; MSB
    ldx #$64  ; LSB
    jsr R_PRINT_PNUM
  endm
  ;
  mac throw_syntax_error
    jsr R_SYNTAX_ERROR
  endm
  ;
  mac stop
    rts
  endm
  ;
  mac square
    ;
  endm
  ;
; ---------------------
; -- MAIN LOOP
ml:    
  puts_at 0,0,text
  throw_syntax_error
  jmp ml

; ---------------------   
; -- DATA
text: .byte "HELLO,WORLD!", 0
; ---------------------
