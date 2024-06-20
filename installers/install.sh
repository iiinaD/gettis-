#!/bin/sh

recompile() {
  dirPath="./build"
    if [ -d "$dirPath" ]; then
        rm -r "$dirPath"
    fi

    ## Compile
    mkdir build #Creating build directory
    #Build and compile the project
    cmake -Bbuild -DCMAKE_BUILD_TYPE=Release
    cmake --build build --config Release
    #Move the executable to location
    cp ./build/gettisXX /usr/local/bin/gettis
}

#Check if program is installed
# Get the installation location of the program (e.g., gettis)
installedLocation=$(whereis gettis)

# Get the home directory of the invoking user
userHome=$(eval echo ~"${SUDO_USER}")

# Split the output of `whereis` using IFS
IFS=":" read -ra ADDR <<< "$installedLocation"

# Trim leading and trailing whitespace from ADDR[1]
trimmedLocation=$(echo "${ADDR[1]}" | sed 's/^[[:space:]]*//;s/[[:space:]]*$//')

# Check if the first element after the split is not empty
if [ -n "$trimmedLocation" ]; then
    installed=true
else
    installed=false
fi

#If installed, ask if remove or update

if $installed; then
  echo "gettis is already installed do you want to update (u) or remove (r) it? [u/r/N]"
  read answer
  case "$answer" in
    # Update
    [uU])
      #If update rebuild and replace file binary file
      recompile
      echo "gettis has been updated."
      ;;
    # Remove
    [rR])
      #If remove, find location (whereis) and delete file and config file
      rm "$trimmedLocation"
      rm -r "$userHome/.config/gettis"
      echo "gettis has been removed."
      ;;
    # Exit installer
    *)
      echo "Not doing anything.."
      exit
      ;;
  esac
else #If not installed
  recompile

  ## Make config
  mkdir "$userHome/.config/gettis"
  touch "$userHome/.config/gettis/gettis.conf"

  ## Default language
  echo "What do you want your default language to be"
  printf "default_lang=java\n" > $userHome/.config/gettis/gettis.conf
  echo "Setting default language to java"
  ## Ask if want to be able to submit
  echo "Do you want to be able to submit? [Y/n]"
  #read answer
  echo "Not implemented"
  ###Ask for login details

fi



