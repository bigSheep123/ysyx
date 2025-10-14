target triple = "x86_64-pc-linux-gnu"
; main.ll
define i32 @main() {
    ret i32 0
}

@global_variable = global i32 0
; 只读的全局变量，也就是常量
@global_constant = constant i32 0
