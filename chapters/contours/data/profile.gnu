#
#
#	GnuPlot command file
#
#   Graphic of volume data profile
#
#
set output "profile3.eps"
set terminal postscript eps "Times-Roman" 18
clear
set xlabel 'Longeur'
set ylabel 'Niveau de Gris'
plot "profile3" title 'Profil de niveau de gris' with steps 

