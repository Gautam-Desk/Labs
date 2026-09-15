# PowerShell script to compile and run all Data Structures algorithms across Units 1 to 5

Write-Host "========================================================" -ForegroundColor Cyan
Write-Host "   Compiling and Running All Data Structures Algorithms " -ForegroundColor Cyan
Write-Host "========================================================" -ForegroundColor Cyan

$Units = @("unit1_arrays_linked_lists", "unit2_stacks_queues", "unit3_searching_hashing_sorting", "unit4_trees", "unit5_graphs")
$TotalPassed = 0
$TotalFailed = 0

foreach ($Unit in $Units) {
    Write-Host "`n>>> Scanning Directory: $Unit <<<" -ForegroundColor Yellow
    $Files = Get-ChildItem -Path $Unit -Filter *.c | Sort-Object Name
    foreach ($File in $Files) {
        $ExeName = $File.FullName -replace '\.c$', '.exe'
        Write-Host "Compiling: $($File.Name)..." -NoNewline
        & gcc -Wall -Wextra -O2 $File.FullName -o $ExeName
        if ($LASTEXITCODE -eq 0) {
            Write-Host " [OK]" -ForegroundColor Green
            Write-Host "Running: $($File.Name)..." -ForegroundColor Magenta
            & $ExeName
            if ($LASTEXITCODE -eq 0) {
                $TotalPassed++
            } else {
                Write-Host "Execution Failed: $($File.Name)" -ForegroundColor Red
                $TotalFailed++
            }
            Remove-Item $ExeName -Force -ErrorAction SilentlyContinue
        } else {
            Write-Host " [COMPILE ERROR]" -ForegroundColor Red
            $TotalFailed++
        }
    }
}

Write-Host "`n========================================================" -ForegroundColor Cyan
Write-Host " Summary: $TotalPassed Passed, $TotalFailed Failed" -ForegroundColor $(if ($TotalFailed -eq 0) { "Green" } else { "Red" })
Write-Host "========================================================" -ForegroundColor Cyan
