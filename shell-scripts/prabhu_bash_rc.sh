###################################
# sets you tab name to first argument.
# on KDE konsole, change the following
# Top Menu Bar -> Settings -> Configure Konsole -> General -> Show Window Title on the Title Bar (Enable it) and Remove  window title Bar (Disable it if not diabled)
#  Top Menu Bar -> Settings -> Edit Current Profile -> Tabs -> Tab Titles -> Insert for both Text input .. .click insert Drop Down and select "Window Title SEt by Shell"... do this for both input in the same window

# source this file into the ~/.bashrc
function title 
{
    echo -ne "\033]0;$1\007"
}

#################################
export PS1='VM$'
alias 1='ssh cinscplp114'
alias 2='sudo sshfs -o allow_other,IdentityFile=/home/pullagad/.ssh/id_rsa pullagad@cinscplp114:/data /data/'
#alias 1='python3 ~/1.py'
#alias 2='python3 ~/2.py'


