.section .text
.global find_range
decode2_asm:
  vxorps %xmm1, %xmm1, %xmm1
  vucomiss %xmm0, %xmm1
  ja .L5
  vucomiss %xmm1, %xmm0
  jp .L8
  movl $1, %eax
  je .L3
.L8:
  vucomiss LC0(%rip), %xmm0
  setbe %al
  movzbl %al, %eax
  addl $2, %eax
  ret
.L5:
  movl $0, %eax
.L3:
  rep; ret
