# Unified Test Runner for Labs Repository
# Scans and executes all C labs across DS_algos, DS_lab, PSD_lab, and skill_based

$ErrorActionPreference = "Continue"

Write-Host "========================================================" -ForegroundColor Cyan
Write-Host "         Running All Academic Labs Verification         " -ForegroundColor Cyan
Write-Host "========================================================" -ForegroundColor Cyan

$Folders = @(
    "DS_algos/unit1_arrays_linked_lists",
    "DS_algos/unit2_stacks_queues",
    "DS_algos/unit3_searching_hashing_sorting",
    "DS_algos/unit4_trees",
    "DS_algos/unit5_graphs",
    "DS_lab",
    "PSD_lab",
    "skill_based"
)

$TotalPassed = 0
$TotalFailed = 0
$Results = @()

foreach ($Folder in $Folders) {
    if (-not (Test-Path $Folder)) { continue }
    Write-Host "`n>>> Module: $Folder <<<" -ForegroundColor Yellow

    $Files = Get-ChildItem -Path $Folder -Filter *.c | Sort-Object Name

    foreach ($File in $Files) {
        $ExeName = $File.FullName -replace '\.c$', '.exe'
        Write-Host "  Compiling: $($File.Name)..." -NoNewline

        & gcc -Wall -Wextra -O2 -std=c11 $File.FullName -o $ExeName 2>$null

        if ($LASTEXITCODE -eq 0) {
            Write-Host " [OK]" -ForegroundColor Green
            Write-Host "  Executing: $($File.Name)..." -NoNewline
            
            # Pipe sample newline/inputs in case of interactive scanf
            "5`n4`n2`n5`n1`n3`n" | & $ExeName >$null 2>&1

            if ($LASTEXITCODE -eq 0) {
                Write-Host " [PASS]" -ForegroundColor Green
                $TotalPassed++
                $Results += [PSCustomObject]@{ File = "$Folder/$($File.Name)"; Status = "PASS" }
            } else {
                Write-Host " [RUNTIME FAIL]" -ForegroundColor Red
                $TotalFailed++
                $Results += [PSCustomObject]@{ File = "$Folder/$($File.Name)"; Status = "RUNTIME FAIL" }
            }
            Remove-Item $ExeName -Force -ErrorAction SilentlyContinue
        } else {
            Write-Host " [COMPILE ERROR]" -ForegroundColor Red
            $TotalFailed++
            $Results += [PSCustomObject]@{ File = "$Folder/$($File.Name)"; Status = "COMPILE ERROR" }
        }
    }
}

Write-Host "`n========================================================" -ForegroundColor Cyan
Write-Host "                      FINAL SUMMARY                     " -ForegroundColor Cyan
Write-Host "========================================================" -ForegroundColor Cyan
Write-Host "Total Verified Programs: $($TotalPassed + $TotalFailed)"
Write-Host "Passed:                  $TotalPassed" -ForegroundColor Green
Write-Host "Failed:                  $TotalFailed" -ForegroundColor $(if ($TotalFailed -eq 0) { "Green" } else { "Red" })
Write-Host "========================================================" -ForegroundColor Cyan

if ($TotalFailed -ne 0) {
    exit 1
} else {
    exit 0
}
