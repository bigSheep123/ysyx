 #!/usr/bin/env bash
 count=0
 ./buggy.sh &>> out.log
 until [[ "$?" -ne 0 ]];
 do
     count=$((count+1))
     ./buggy.sh &>> out.log
 done

 echo "failed after $count runs"