.section .text
.global store_prod_asm1
.global store_prod_asm2

store_prod_asm1:
  movq %rdx, %rax
  cqto          
  movq %rsi, %rcx
  sarq $63, %rcx 
  imulq %rax, %rcx 
  imulq %rsi, %rdx 
  addq %rdx, %rcx 
  mulq %rsi      
  addq %rcx, %rdx
  movq %rax, (%rdi)
  movq %rdx, 8(%rdi)
  ret

store_prod_asm2:
  movq %rsi, %rax
  imulq %rdx
  movq %rax, (%rdi)
  movq %rdx, 8(%rdi)
  ret 
