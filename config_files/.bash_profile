
if [ -f ~/.bashrc ]; then
   source ~/.bashrc
fi

#MY_PATH="/c/Users/jackson.dennis/shell_scripts:"
MY_PATH="/c/Users/jackson.dennis/shell_scripts://server/Users/shared/dev_tools:/c/Users/jackson.dennis/vc_tools/bin:"
PATH="$MY_PATH$PATH"

alias ls='ls --color=auto'
alias grep='grep -n --color=auto'

alias gr='grep -r -n --color=auto'

alias ll='ls --color=auto -ltr'

alias ddiff='diff -w -B -y'
alias rddiff='rdiff -w -B -y'


function sdat()
{
    if [ $# -gt 0 ] ; then
        echo "Denny Says Hi!"
        find . -name "*.dat" | xargs grep -n --color -i "$@"
    fi
}

function sfile()
{
    if [ $# -gt 0 ] ; then
        echo "Denny Says Hi!"
        find . -name "*$1*"
    fi
}

function Sdat()
{
    if [ $# -gt 0 ] ; then
        echo "Denny Says Hi! (case sensitive)"
        find . -name "*.dat" | xargs grep -n --color "$@"
    fi
}

function spls()
{
    if [ $# -gt 0 ] ; then
        echo "Denny Says Hi!"
        find . -name "*.pls" | xargs grep -n --color=auto "$@"
    fi
}

function shcpp()
{
    if [ $# -gt 0 ] ; then
        echo "Denny Says Hi!"
        # find . -name "*.h" | xargs grep -n --color -i "$@"
        # find . -name "*.cpp" | xargs grep -n --color -i "$@"
        find . -name "*.h" -o -name "*.cpp" | xargs grep -n --color -i "$@"
    fi
}

function greph()
{
    if [ $# -gt 0 ] ; then
        echo "Denny Says Hi!"
        find . -name "*.h" | xargs grep -n --color -i "$@"
    fi
}

function grepcpp()
{
    if [ $# -gt 0 ] ; then
        echo "Denny Says Hi!"
        find . -name "*.cpp" | xargs grep -n --color -i "$@"
    fi
}

function Shcpp()
{
    if [ $# -gt 0 ] ; then
        echo "Denny Says Hi! (case sensitive)"
        find . -name "*.h" | xargs grep -n --color "$@"
        find . -name "*.cpp" | xargs grep -n --color "$@"
    fi
}

function grepdat()
{
    if [ $# -gt 0 ] ; then
        echo "Denny Says Hello!"
        grep -n --color "$@" *.dat
    fi
}

function greplocks()
{
    # look through the current directory recursively and check locks
    rlocks -r | grep "dennis" | grep -B1 "dennis "
}


function rlocksf()
{
    # determine if a particular file is locked (or multiple files)
    rlocks | grep "$@"
}


# BG;FGm
# BG;FG;1m -- for bold
# 1;FGm -- for bold, plain background

BLACKONYELLOW='\e[43;30m'
BOLDBLUEONYELLOW='\e[43;34;1m'
BOLDBLUEONGREEN='\e[42;34;1m'
BLUEONYELLOW='\e[43;34m'
BOLDYELLOWONGREEN='\e[42;33;1m'
BOLDYELLOWONBLUE='\e[44;33;1m'
BOLDWHITEONGREEN='\e[42;37;1m'
BOLDPURPLEONGREEN='\e[42;35;1m'
PURPLEONGREEN='\e[42;35m'
BLUEONGREEN='\e[42;34m'
RED='\e[0;31m'
GREEN='\e[0;32m'
YELLOW='\e[0;33m'
BLUE='\e[0;34m'
PURPLE='\e[0;35m'
CYAN='\e[0;36m'
WHITE='\e[0;37m'
COLOR_OCHRE='\e[38;5;95m'


#no color / reset to normal
NC='\e[0m'

function git_color {
  local git_status="$(git status 2> /dev/null)"

  if [[ ! $git_status =~ "working tree clean" ]]; then
      printf $RED
  elif [[ $git_status =~ "Your branch is ahead of" ]]; then
      printf $YELLOW
  elif [[ $git_status =~ "nothing to commit" ]]; then
      printf $GREEN
  else
      printf $BLUE
  fi
  # printf "$git_status\n"
}

function git_branch {
  local git_status="$(git status 2> /dev/null)"
  local on_branch="On branch ([^${IFS}]*)"
  local on_commit="HEAD detached at ([^${IFS}]*)"

  if [[ $git_status =~ $on_branch ]]; then
    local branch=${BASH_REMATCH[1]}
    echo "($branch)"
  elif [[ $git_status =~ $on_commit ]]; then
    local commit=${BASH_REMATCH[1]}
    echo "($commit)"
  fi
}



PS1="\[$YELLOW\]\u@\h: \[$CYAN\] \w\[$NC\]\n"
# PS1+="\$(git_color)"
# PS1+="\$(git_branch)\[$NC\]\n"
PS1+="\[$PURPLEONGREEN\]  \$ \[$NC\] "
export PS1 


# PS1="\[$COLOR_WHITE\]\n[\W]"          # basename of pwd
# PS1+="\[\$(git_color)\]"        # colors git status
# PS1+="\$(git_branch)"           # prints current branch
# PS1+="\[$COLOR_BLUE\]\$\[$COLOR_RESET\] "   # '#' for root, else '$'
