.section .text
.global find_range_book
.global my_find_range_74
find_range_book:
  vxorps %xmm1, %xmm1, %xmm1  	# xmm1 = 0
  vucomiss %xmm0, %xmm1       	# compare x to 0
  ja .L5			# if x < 0: goto .L5	
  vucomiss %xmm1, %xmm0		# compare 0 to x
  jp .L8			# if x == NaN, goto .L8
  movl $1, %eax			# if x != NaN, rax = 1
  je .L3			# if x == 0, goto .L3
.L8:
  vucomiss %xmm1, %xmm0	        # I changed LC0(%rip) to xmm1
  setbe %al			# if x > 0, al = 1
  movzbl %al, %eax		# eax = al
  addl $2, %eax			# eax += 2
  ret				# return eax
.L5:
  movl $0, %eax			# eax = 0
.L3:
  rep; ret			# return eax

my_find_range_74:
  vxorps %xmm1, %xmm1, %xmm1
  movl $3, %r8d
  movl $0, %r9d
  movl $1, %r10d
  movl $2, %r11d
  vucomiss %xmm0, %xmm1		# this will be the one floating point comparison
  cmova %r9d, %eax
  cmove %r10d, %eax
  cmovb %r11d, %eax
  cmovp %r8d, %eax		# had to put parity check last, since NaN also sets CF and ZF
  rep; ret
