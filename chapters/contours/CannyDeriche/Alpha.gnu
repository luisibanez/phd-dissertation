########################################
#
#	Plotting Canny Deriche
#   characteristics
#
########################################

set nokey
set ylabel "millimetres"
set xlabel "Alpha"
set xrange [0:8.5]
#set term postscript eps
#set output "EstimationRayon.eps"
plot "Alpha.dat" with errorbars, "Alpha.dat" using 1:2 with lines

