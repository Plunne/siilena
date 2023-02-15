#!/usr/bin/sh

# Pour rendre executable : sudo chmod +x photo_move.sh
# PS1=<configuration du prompt>

echo "All args: $@"     # Affiche tous les arguments
echo "Nb args: $#"      # Affiche le nombre d'arguments
echo "All 1: $1"        # Affiche l'argument 1

#
# Tester si on a 2 args
#

if [ "$#" -ne 2 ] ; then # Si le nombre d'args != 2
    echo "Wrong number of args"
    exit 1
else
    echo "Done succesfully!"
fi

#
# Tester si arg1 est un repertoire
#

if [ ! -d "$1" ] ; then # Si arg1 est un dossier
    echo "$1 is not a dir!" # Affiche : arg2 is not a dir!
    exit 2
fi

#
# Creer les variable de dossiers
#

SRC_DIR=$1
DEST_DIR=$2

#
# Deplacer les fichiers dans le repertoire de dstination
#

for PHOTO in $SRC_DIR/*.jpg ; do # Pour chaque PHOTO dans le dossier
    if [ ! ${PHOTO#$SRC_DIR/} =~ ^IMG_[0-9]{8}_.*$ ] # ${PHOTO#$SRC_DIR} Effacer le contenu de SRC_DIR dans la variable PHOTO et si ca match avec l'expression reguliere IMG_[0-9]{8}
    echo "Photo to move: $PHOTO"
    START=${#SRC_DIR}           # ${#SRC_DIR} : Nombre de lettres du dossier
    ((START += 5))              # Rajouter 6 au nombre de caracteres a se deplacer pour recuperer le filtre de l'image  
    DATE_TAG=${PHOTO:$START:8}  # Coupe $PHOTO jusqu'au premier caractere de la date (5+8=13, on enleve 13 caracteres)
    echo "$DATE_TAG"            # Affiche $DATE_TAG qui contient la slice realisee ci-dessus ne gardant que le nom de l'image
    PHOTO_FOLDER=$DEST_DIR/$DATE_TAG    # Stocker le chemin de destination $DEST_DIR + nom image $DATE_TAG
    mkdir -p $PHOTO_FOLDER      # Creer le dossier de destination
    echo "Will move $PHOTO in $PHOTO_FOLDER" # Affiche avant de move pour s'arrurer que tout se comportera comme il faut
    mv $PHOTO $PHOTO_FOLDER/    # Move : Deplacer l'images dans le dossier de destination
done
