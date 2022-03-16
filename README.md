											PROIECT_POO

Am creat doua clase(buget si persoana) prin agregare(obiectul buget face parte din obiectul persoana).
Ambele clase au functii set si get pentru a seta sau returna un element din obiect si constructori/destructori.
Am supraincarcat la ambele clase urmatorii operatori: +,-,+=,-=,==,!=,<<,>>.

La clasa buget am supraincarcat si operatorii de comparatie < si >. Am creat functia buget_total care calculeaza suma dintre nevoi si dorinte.

La clasa persoana avem urmatoarele functii: ordonare_salariu, ordonare_buget, castigator_loto.
ordonare_salariu ordoneaza crescator obiectele persoana dintr-un vector in functie de variabila salariu.
ordoneaza_buget ordoneaza crescator obiectele persoana in functie de buget_total(b).
castigator_loto alege la intamplare o persoana din vector careia ii seteaza b.dorinte la 1000000 si salariul la 0(presupunem ca demisioneaza).


TESTARE

Ne dam un vector care retine 5 obiecte persoana.
Acesta este ordonat prima data dupa salariu si afisam persoana cu salariul maxim/salariul minim si salariul maxim/minim.
Apoi ordonam dupa buget si afisam persoana cu bugetul maxim/minim si bugetul maxim/minim(folosim functia buget_total pentru a determina bugetul).
Folosim functia castigator_loto pentru a alege un castigator caruia ii vom compara bugetul actual cu bugetul celorlalti(fara a folosi functia buget_total).

Datele de intrate folosite pentru acest test au fost


3500 7680 rares 10000
1200 5000 mircea 6000
3456 2300 ema 5600
1500 1000 radu 3000
1000 1000 ana 2000


230 450 rares 1500
345 234 teo 2700
320 454 mihai 2345
210 500 ion 3000
500 5400 Maria 9090

A doua parte a testului consta in cateva operatii simple care sa arate functionalitatea tutror lucrurilor implementate:
constructori
supraincarcarea operatorilor:+,=.+=,-=
set-eri
destructori


