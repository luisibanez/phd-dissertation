########################################
#
#	Plotting Shen Castan
#   characteristics
#
########################################

set nokey
set ylabel "millimetres"
set xlabel "Rayon"
set xrange [0.5:6]
#set term postscript eps
#set output "EstimationRayon.eps"
plot "Radius.dat" with errorbars, "Radius.dat" using 1:2 with lines


