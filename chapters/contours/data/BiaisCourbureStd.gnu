########################################
#
#	Plotting Biais characteristics
#
########################################

set key
set ylabel "Ecart type (millimetres)"
set xlabel "Rayon de Courbure (millimetres)"
set xrange [0:55]
#set term postscript eps
#set output "BiaisCourbureStd.eps"
plot "BiaisCourbureStd.dat" using 1:2 title "Gaussian" with linesp, \
     "BiaisCourbureStd.dat" using 1:3 title "Canny Deriche" with linesp, \
     "BiaisCourbureStd.dat" using 1:4 title "Shen Castan" with linesp, \
     "BiaisCourbureStd.dat" using 1:5 title "Moments" with linesp

