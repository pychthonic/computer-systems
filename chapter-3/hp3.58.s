.section .text
.global decode2_asm
decode2_asm:
  subq %rdx, %rsi
  imulq %rsi, %rdi
  movq %rsi, %rax
  salq $63, %rax
  sarq $63, %rax
  xorq %rdi, %rax
  ret
