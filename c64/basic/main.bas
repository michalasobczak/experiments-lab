1 rem *** start ***
2 t1=ticks: t2=0
3 goto 100

20 rem *** data ***
21 v=0: f=0: ne=0

50 rem *** gt *** 
51 if f=0 then
52   ne=sin(v)
53 : 
60 if f=1 then
61   ne=cos(v)
62 :
70 return

100 rem *** main ***
101 ? "=> starting"
102 v=0: f=1: gosub 50

900 t2 = ticks
901 ? "took:" int((t2-t1)/60*100) " ms"
999 end
