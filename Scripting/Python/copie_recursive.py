import sys
from pathlib import Path
import shutil

#############
# Arguments #
#############

# Get arguments
match sys.argv[1:]:
    case [installdir, app]:
        recursive = False
    case ["-r", installdir, app]:
        recursive = True
    case _:
        print("Error: wrong usage")

# Input feedback
print(f"Will install <{app}> in <{installdir}> (recursive mode: {recursive})")

########
# Path #
########

# Create Path instances
installDirPath = Path(installdir)
appPath = Path(app)

#####################
# Install Directory #
#####################

# Create Install Directory if doesn't exist
if not installDirPath.exists():
    installDirPath.mkdir(parents=True, exist_ok=True)

# If it's not a directory
elif not installDirPath.is_dir():
    print(f"Error: {installdir} n'est pas un répertoire")

####################
# Copy : option -r #
####################

# Copy app into dir if it's a file
if appPath.is_file():
    print('File will be deploy:', appPath)
    shutil.copy(appPath, installdir)

# If it's not an app but recursive dir, copy the entire content into install dir
elif appPath.is_dir() and recursive:
    print('Directory will be deploy recursively:', appPath)
    shutil.copytree(appPath, installdir, dirs_exist_ok=True)

# Else error
else:
    print(f"Error: {appPath} n'est pas un fichier ou répertoire en mode récursif")

########
# Done #
########

print('Done')