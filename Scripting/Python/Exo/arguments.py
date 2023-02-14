import sys

print("Hello World!")

def getArgs():
    for arg in sys.argv[1:]:        # Pour chaque arguments en commencant par le 2eme
        match arg:                  # Si l'argument match avec?
            case "-a":              # -a
                print("Lettre A")   # Afficher lettre A
            case "-b":              # -b
                print("Lettre B")   # Afficher lettre B
            case "-c":              # -c
                print("Lettre C")   # Afficher lettre C
            case _:                 # Autrement
                break               # Sortir de la boucle

getArgs()    