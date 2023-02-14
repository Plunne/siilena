import sys
from pathlib import Path
import re

#############
# Fonctions #
#############

def checkIsDirectory(dirPath: Path) -> None:
    if not dirPath.is_dir():
        print(dirPath, "is not a directory")
        sys.exit(2)

#############
# Arguments #
#############

# Get arguments
if len(sys.argv) != 3:
    print("Error: wrong number of args")
    sys.exit(1)

########
# Path #
########

# Create Path instances
srcDirPath = Path(sys.argv[1])
destDirPath = Path(sys.argv[2])

# Input feedback
print(f"Will scan <{srcDirPath}> for photos to store in <{destDirPath}>")

# Check if is directory
checkIsDirectory(srcDirPath)
checkIsDirectory(destDirPath)

####################
# Scan Directories #
####################

# List all photos
for photoPath in srcDirPath.glob("*.jpg"):
    # Check if the photo name match as expected
    if not re.match(r"IMG_[0-9]{8}", photoPath.name)
        print(f"Warning: {photoPath.name} doesn't match with format")
        continue
    # Create photo dest directory
    print(photoPath)
    dateTag = photoPath.name[4:12]
    photoFolderPath = destDirPath / dateTag
    photoFolderPath.mkdir(exist_ok=True)
    # Move photos in dest directory
    print(f"Move {photoPath} to {photoFolderPath / photoPath.name}")
    photoPath.rename(photoFolderPath / photoPath.name)

########
# Done #
########

print('Done')