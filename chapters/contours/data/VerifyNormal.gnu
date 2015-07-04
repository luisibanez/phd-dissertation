########################################
#
#	Plotting Normal verification 
#
########################################

set key
set ylabel "Erreur (degres)"
set xlabel "Rayon de Courbure (millimetres)"
set xrange [0:55]
set yrange [0:14]
#set term postscript eps
#set output "VerifyNormal.eps"
plot "VerifyNormal.dat" using 1:2 title "Moments" with linesp, \
     "VerifyNormal.dat" using 1:3 title "Gaussian" with linesp, \
     "VerifyNormal.dat" using 1:4 title "Shen Castan" with linesp, \
     "VerifyNormal.dat" using 1:5 title "Canny Deriche" with linesp

