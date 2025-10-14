; 长的整型转换成短的整型     trunc .. to 
; zext .. to 零扩展
; sext .. to 符号扩展

define i8 @main() {
    %trunc_integer = trunc i32 257 to i8 ; Trunc 32 bit 100000001 to 8 bit, get 1
    ret i8 %trunc_integer
}