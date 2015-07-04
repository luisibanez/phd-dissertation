########################################
#
#	Plotting Biais characteristics
#
########################################

set key
set ylabel "Erreur (millimetres)"
set xlabel "Rayon de Courbure (millimetres)"
set xrange [0:55]
#set term postscript eps
#set output "BiaisCourbure.eps"
plot "BiaisCourbure.dat" using 1:2 title "Gaussian" with linesp, \
     "BiaisCourbure.dat" using 1:3 title "Canny Deriche" with linesp, \
     "BiaisCourbure.dat" using 1:4 title "Shen Castan" with linesp, \
     "BiaisCourbure.dat" using 1:5 title "Moments" with linesp


