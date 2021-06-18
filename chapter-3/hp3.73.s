.section .text
.global find_range_book
.global my_find_range
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

my_find_range:
  vxorps %xmm1, %xmm1, %xmm1
  vucomiss %xmm0, %xmm1		# this will be the one floating point comparison
  jp .L1			# if x == NaN, goto .L1
  ja .L2			# if x < 0, goto .L2
  je .L4			# if x == 0, goto .L4
  jb .L6			# if x > 0, goto .L6
.L1:
  movl $3, %eax
  rep; ret
.L2:
  movl $0, %eax
  rep; ret
.L4:
  movl $1, %eax
  rep; ret
.L6:
  movl $2, %eax
  rep; ret
