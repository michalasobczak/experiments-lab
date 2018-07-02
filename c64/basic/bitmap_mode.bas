5 base=2*4096
9 poke 53272,peek(53272)or8
10 poke 53265,peek(53265)or32
15 co = 3
20 for i = base to base+7999: poke i,0: next
30 for i = 1024 to 2023: poke i, co: next
35 co = co + 1
40 goto 20
run
