function digtochar($digit) {
    if($digit -eq 1){
        return 'o'
    }
    elseif($digit -eq 2){
        return 'x'
    }
    else{
        return '?'
    }
}
function exp($base,$exponent){
    [int] $ans=1
    for($num=0;$num -lt $exponent;$num++){
        $ans=$ans*$base
    }
    return $ans
}

g++ 'actual.cpp' -o 'exp.exe'
g++ 'sol.cpp' -o 'my.exe'

[int] $maxcnt=27*27*27*3
for($num=0;$num -lt $maxcnt;$num++){
    $temp=$num
    [string] $testcase=''
    [int] $i=0;
    while ($temp -gt 0 -or $i -lt 10) {
        $var=$temp%3
        [char] $ch=digtochar($var)
        $testcase=$testcase+$ch
        $temp=[math]::truncate($temp/3)
        $i++
    }
    Write-Output $testcase | .\exp.exe > 'exp.txt'
    Write-Output $testcase | .\my.exe > 'myout.txt '
    Compare-Object (Get-Content 'myout.txt') (Get-Content 'exp.txt') > 'diff.txt'
    $flag=[String]::IsNullorWhiteSpace((Get-Content 'diff.txt'))
    if($flag -ne $true){
        Write-Host ("It fails on testcase: "+$testcase)
        Write-Host ("----------------")
        Write-Host ("The expected output is ")
        Get-content 'exp.txt'
        Write-Host ("----------------")
        Write-Host ("Your output is ")
        Get-content 'myout.txt'
        break
    }
    # Write-Host ("Working on it")
}
Write-Host "It worked for all testcases"
Remove-Item 'my.exe','exp.exe'