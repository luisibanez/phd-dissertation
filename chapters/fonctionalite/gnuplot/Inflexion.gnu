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
set yrange [-1.0:4.0]
set xrange [-4:4]
set term postscript eps
set output "InflexionCircle.eps"

gx(r,t) = (t-r*sin(t))
gy(r,t) = (1-r*cos(t))

plot t,0,gx(0.0,t),gy(0.0,t),gx(0.1,t),gy(0.1,t),gx(0.2,t),gy(0.2,t),gx(0.3,t),gy(0.3,t),gx(0.4,t),gy(0.4,t),gx(0.5,t),gy(0.5,t),gx(0.6,t),gy(0.6,t),gx(0.7,t),gy(0.7,t),gx(0.8,t),gy(0.8,t),gx(0.9,t),gy(0.9,t),gx(1.0,t),gy(1.0,t),gx(1.1,t),gy(1.1,t),gx(-0.1,t),gy(-0.1,t),gx(-0.2,t),gy(-0.2,t),gx(-0.3,t),gy(-0.3,t),gx(-0.4,t),gy(-0.4,t),gx(-0.5,t),gy(-0.5,t),gx(-0.6,t),gy(-0.6,t),gx(-0.7,t),gy(-0.7,t),gx(-0.8,t),gy(-0.8,t),gx(-0.9,t),gy(-0.9,t),gx(-1.0,t),gy(-1.0,t),0.5*cos(t),0.5*(1+sin(t)),cos(t),(1+sin(t)),gx(1.2,t),gy(1.2,t),gx(1.3,t),gy(1.3,t),gx(1.4,t),gy(1.4,t),gx(1.5,t),gy(1.5,t)


