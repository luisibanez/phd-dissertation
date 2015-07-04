#
#
#	Plot de la gaussien
#
#
#set output "LoG1D.eps"
#set terminal postscript eps "Times-Roman" 18
g(x,s) = exp( -x*x/(2*s*s) )
dg(x,s) = -x*g(x,s)/(s*s)
lg(x,s) = (x**2-s**2)*g(x,s)/(s**4)
set xlabel "Distance radiale"
set xrange [-5:5]
plot g(x,1) title 'Gaussienne' with lines 1, dg(x,1) title 'Derivee' with lines 2, lg(x,1) title 'Laplacien' with lines 3