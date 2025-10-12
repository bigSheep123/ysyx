#!/bin/bash
marco() {
    echo "$(pwd)" > $HOME/maro_history.log
    echo "save pwd $(pwd)"
}

polo 
{
    echo "($cat)"
    echo "cd $HOME/marco_history.log "
    cd "$(cat "$HOME/marco_history.log")"
}