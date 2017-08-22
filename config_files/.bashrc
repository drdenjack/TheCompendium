# /etc/bashrc
STANDARD_PKGS="${OSTYPE%%[-0-9]*} user shell term lang man options"
OPTIONAL_PKGS=
BASE_PATH="/usr/bin:/bin"
PKGS_PATH=
LOCAL_PATH="/usr/local/bin:"
USER_PATH=
TEMP_VARS="TEMP_VARS STANDARD_PKGS OPTIONAL_PKGS PKG BASE_PATH PKGS_PATH LOCAL_PATH USER_PATH"
PATH="$LOCAL_PATH$BASE_PATH"
for PKG in $STANDARD_PKGS ; do
    if [ -r "/etc/profile.d/$PKG.sh" ] ; then
       . "/etc/profile.d/$PKG.sh"
    fi
    if [ -r "$HOME/.profile.d/$PKG.sh" ] ; then
       . "$HOME/.profile.d/$PKG.sh"
    fi
done
for PKG in $OPTIONAL_PKGS ; do
    if [ -r "/etc/profile.d/$PKG.sh" ] ; then
       . "/etc/profile.d/$PKG.sh"
        fi
    if [ -r "$HOME/.profile.d/$PKG.sh" ] ; then
       . "$HOME/.profile.d/$PKG.sh"
    fi
done
PATH="$USER_PATH$LOCAL_PATH$PKGS_PATH$BASE_PATH"
unset $TEMP_VARS
