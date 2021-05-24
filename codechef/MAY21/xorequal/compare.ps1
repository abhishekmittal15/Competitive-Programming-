$testcases=Get-Random -Minimum 1 -Maximum 3
Add-Content 'input.txt' $testcases
for ($num=0;$num -lt $testcases;$num+=1){
    [int] $max_value=100*1000+5
    $new_value=Get-Random -Maximum $max_value
    Add-Content 'input.txt' $new_value
}
# Get-Content 'input.txt'
g++ sol.cpp
Get-Content 'input.txt' | .\a.exe > 'myout.txt'
g++ actual.cpp
Get-Content 'input.txt' | .\a.exe > 'exp.txt'

Compare-Object (Get-Content 'myout.txt') (Get-Content 'exp.txt') -CaseSensitive > 'diff.txt'
[bool] $val=[string]::IsNullOrWhiteSpace((Get-Content 'diff.txt'))
if($val -eq $false){
    Write-Host "There are differences" -ForegroundColor Red
    Write-Host "Here is the input"
    Get-Content 'input.txt'
    Write-Host "-------------"
    Write-Host "Here is my output"
    Get-Content 'myout.txt'
    Write-Host "-------------"
    Write-Host "Here is the expected output"
    Get-Content 'exp.txt'
}
else{
    Write-Host "The outputs match" -ForegroundColor Green
}
Remove-Item 'input.txt'
Remove-Item 'myout.txt'
Remove-Item 'diff.txt'
Remove-Item 'exp.txt'
Remove-Item 'a.exe'