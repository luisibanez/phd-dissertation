#
#
#	Plot de la gaussien bidimensionel
#
#
# set output "LoG2DL.eps"
# set terminal postscript eps "Times-Roman" 18
g(x,y,s) = exp( -(x*x+y*y)/(2*s*s) )
dg(x,y,s) = -x*g(x,y,s)/(s*s)
lg(x,y,s) = (x*x+y*y-2*s*s)*g(x,y,s)/(s**4)
set xrange [-4:4]
set yrange [-4:4]
set cntrparam bspline
set isosamples 40
set surface
set hidden3d
set nokey
splot lg(x,y,1)
