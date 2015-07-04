########################################
#
#	Plotting Laplacian of Gaussian
#   characteristics
#
########################################

set nokey
set ylabel "millimetres"
set xlabel "Sigma"
#set term postscript eps
#set output "EstimationRayon.eps"
plot "Sigma.dat" with errorbars, "Sigma.dat" using 1:2 with lines


