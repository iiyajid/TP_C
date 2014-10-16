#
#  Exemple de Makefile
#  Cree l'executable 'myprog' a partir des fichiers 'personne.c' et 'main.c'
#  Eric Lecolinet - Reda Dehak - Telecom ParisTech
#  INF720 - TP C - http://www.telecom-paristech.fr/~elc


# Nom de l'executable a creer
PROG= prog

# Fichiers source (NE PAS METTRE les .h ni les .o, SEULEMENT les .c)
SOURCES= scanfetlignedecmd.c

# Fichiers objets (ne pas modifier, sauf si l'extension n'est pas .c)
OBJETS=${SOURCES:%.c=%.o}

# Compilateur C
CC= gcc

# Options du compilateur C
# -g permet de debugger, -O optimise, -Wall affiche les erreurs
# Exemple pour Qt: CFLAGS= -g -Wall -I/usr/local/qt/include
CFLAGS= -g -Wall

# Editeur de lien
LD=gcc

# Options de l'editeur de liens
LDFLAGS= 

# Librairies a utiliser
# Exemple pour Qt: LDLIBS = -L/usr/local/qt/lib -lqt
LDLIBS=
##########################################

# Regles de construction/destruction des .o et de l'executable
# (depend sera un fichier contenant les dependances)

all: ${PROG}

${PROG}: depend ${OBJETS}
	${LD} -o ${PROG} ${LDFLAGS} ${OBJETS} ${LDLIBS}

clean:
	-@$(RM) $(PROG) *.o depend core 1>/dev/null 2>&1

# Gestion des dependances : creation automatique des dependances en utilisant 
# l'option -MM de gcc (attention certains compilos n'ont pas cette option)

depend:
	${CC} -MM ${SOURCES} > depend

###########################################

# Regles implicites

.SUFFIXES: .cpp .cxx .cc .C .c

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o $@ $<

#############################################

# Inclusion du fichier des dependances
-include depend
