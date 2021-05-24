Do{
    Add-Content 'input.txt' '1' 
    for($i=0;$i -lt 3;$i++){
        for($j=0;$j -lt 3;$j++){
            [int] $temp=Get-Random -Minimum 0 -Maximum 3
            [char] $var='_'
            if($temp -eq 0){
                $var='X'
            }
            elseif ($temp -eq 1) {
                $var='O'
            }
            Add-Content 'input.txt' $var -NoNewline 
        }
        Add-Content 'input.txt' ''
    }
    g++ 'sol.cpp'
    $ans=Get-Content 'input.txt' | .\a.exe
    if($ans -eq 1){
        Get-Content 'input.txt'
        Write-Host $ans
    }
    Remove-Item 'input.txt'
} While($ans -ne 1)