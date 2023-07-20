################################################################################
# System Information
################################################################################
alias sysinfo='sudo inxi -Fxz'
alias sysinfo2="neofetch"
alias driverinfo='sudo lshw -c video'
alias drives='df -h | grep -v tmpfs'
function userinfo() {
   for user in `ls /home`; do 
      echo -n "$user "; 
      last $user | head -1 | awk '{print substr($0,40)}'; 
      done
}

################################################################################
# Quality of Life
################################################################################
alias cl='clear; echo -e '\''\033[1;33mCurrent Working Directory: \033[0;37m'\''; pwd \033[0m; echo ; ls; echo '
alias mystuff="cd /media/jonathan/'2TB Storage and Game Drive'/Jon"
alias lock="xset dpms force off; xdg-screensaver lock; exit"
alias say="espeak -vf5 -s130"it
alias firewall="gufw"
alias firewallon="sudo ufw enable"
alias firewalloff="sudo ufw disable"
alias quickreboot="sudo systemctl restart gdm"

################################################################################
# System Modifications
################################################################################
PATH="$PATH:."
PS1="\[\e]0;\u@\h: \w\a\]\[\033[01;32m\]\u@\h\[\033[00m\]:$ "
alias rm='rmtrash'
alias rmdir='rmdirtrash'

################################################################################
# Bash colors - Example:  echo "Hello $(green)world!"
################################################################################
alias default="echo -e '\e[39m$1'"
alias black="echo -e '\e[30m$1'"
alias red="echo -e '\e[31m$1'"
alias green="echo -e '\e[32m$1'"
alias yellow="echo -e '\e[33m$1'"
alias blue="echo -e '\e[34m$1'"
alias magenta="echo -e '\e[35m$1'"
alias cyan="echo -e '\e[36m$1'"
alias lightgray="echo -e '\e[37m$1'"
alias darkgray="echo -e '\e[90m$1'"
alias lightred="echo -e '\e[91m$1'"
alias lightgreen="echo -e '\e[92m$1'"
alias lightyellow="echo -e '\e[93m$1'"
alias lightblue="echo -e '\e[94m$1'"
alias lightmagenta="echo -e '\e[95m$1'"
alias lightcyan="echo -e '\e[96m$1'"
alias white="echo -e '\e[97m$1'"