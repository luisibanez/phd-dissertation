########################################
#
#	Plotting the inflexion circle of a
#   Cycloid mouvement
#
########################################

set nokey
set ylabel "Pole-Normal"
set xlabel "Pole-Tangent"
set parametric
set samples 400
set yrange [-1.2:1.2]
set xrange [-4:4]
# set term fig
# set output "Vis_Gnuplot.fig"

gx(p,t) = (p*t+cos(2*t))
gy(p,t) = (    sin(2*t))
p=0.17
plot t,0,gx(p,t),gy(p,t)

