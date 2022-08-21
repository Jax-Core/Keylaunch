function WriteToMemory {
    for ($i=1 ; $i -le $t ; $i++) {
        $arrayName.Add($RmAPI.VariableStr("$($i)Name"))
        $arrayAction.Add($RmAPI.VariableStr("$($i)Action"))
        $arrayIcon.Add($RmAPI.VariableStr("$($i)Icon"))
        $arrayKey.Add($RmAPI.VariableStr("Key$($i)"))
        $arrayKeyS.Add($RmAPI.VariableStr("Key$($i)InString"))
    }
}

$t = [int]$RmAPI.VariableStr('Total')
$skinsPath = $RmAPI.VariableStr('SKINSPATH')
$coreDataDir = "$skinsPath\..\CoreData\"
$file1 = "$coreDataDir"+"Keylaunch\Include.inc"
$file2 = "$coreDataDir"+"Keylaunch\Act.inc"
$file3 = "$coreDataDir"+"Keylaunch\Hotkeys.inc"
$file4 = "$coreDataDir"+"Keylaunch\Keylaunch.ahk"
$arrayName = New-Object System.Collections.Generic.List[System.Object]
$arrayAction = New-Object System.Collections.Generic.List[System.Object]
$arrayIcon = New-Object System.Collections.Generic.List[System.Object]
$arrayKey = New-Object System.Collections.Generic.List[System.Object]
$arrayKeyS = New-Object System.Collections.Generic.List[System.Object]
$RmAPI.Log($t)
WriteToMemory

function WriteAll {
    param(
        [Parameter()]
        [int]$arg1,
        [Parameter()]
        [int]$arg2,
        [Parameter()]
        [int]$arg3
    )
    
    # ---------------------------------------------------------------------------- #
    #                                 write include                                #
    # ---------------------------------------------------------------------------- #
    for ($i=1 ; $i -le $arg1 ; $i++) {
        $file1content += @"
[$($i).Shape]
Meter=Shape
MeterStyle=Action.Shape:S
[$($i).String]
Meter=String
MeterStyle=Set.String:S | Action.String:S
[$($i).Hotkey.Shape]
Meter=Shape
MeterStyle=Action.Hotkey.Shape:S
[$($i).Hotkey.String]
Meter=String
MeterStyle=Set.String:S | Action.Hotkey.String:S
[$($i).Delete.Shape]
Meter=Shape
MeterStyle=Action.Delete.Shape:S
[$($i).Delete.StringIcon]
Meter=String
MeterStyle=Set.String:S | Action.Delete.StringIcon:S

"@
    }

    # ---------------------------------------------------------------------------- #
    #                                write variables                               #
    # ---------------------------------------------------------------------------- #
    $file2content += @"
[Variables]
Total=$($arg1)

"@
    if ($arg1 -gt $t) {
        $l = $t
     } else {
        $l = $arg1
     }
     
    for ($i=1 ; $i -le $arg1 ; $i++) {
        $file2content += @"
$($i)Name=$($arrayName[$i-1])
$($i)Action=$($arrayAction[$i-1])
$($i)Icon=$($arrayIcon[$i-1])

"@
    }

    # ---------------------------------------------------------------------------- #
    #                              write ahk variables                             #
    # ---------------------------------------------------------------------------- #
    $file3content += @"
[Variables]
RMPATH=$($RmAPI.VariableStr('PROGRAMPATH'))Rainmeter.exe

"@

    for ($i=1 ; $i -le $arg1 ; $i++) {
        $file3content += @"
Key$($i)=$($arrayKey[$i-1])
Key$($i)InString=$($arrayKeyS[$i-1])

"@
    }

    # ---------------------------------------------------------------------------- #
    #                                   write ahk                                  #
    # ---------------------------------------------------------------------------- #
    $file4content += @"
#SingleInstance Force
#Persistent
Menu, Tray, Icon, Keylaunch.ico, 1
Menu, Tray, NoStandard

OnMessage(0x404, "AHK_NOTIFYICON")
AHK_NOTIFYICON(wParam, lParam, uMsg, hWnd)
{
    if (lParam = 0x201) ;WM_LBUTTONDOWN := 0x201
    {
        if(A_IsSuspended){
            Menu, Tray, Icon, Keylaunch.ico, , 1
        } else {
            Menu, Tray, Icon, KeylaunchPaused.ico, , 1
        }
        Suspend
    }
}

"@
    for ($i=1 ; $i -le $arg1 ; $i++) {
        $file4content += @"
IniRead, Key$($i), $file3, Variables, Key$($i)

"@
    }
    for ($i=1 ; $i -le $arg1 ; $i++) {
        $file4content += @"
Try Hotkey, %Key$($i)%, Action$($i)

"@
    }
    $file4content += @"
Return

"@
    for ($i=1 ; $i -le $arg1 ; $i++) {
        $file4content += @"
Action$($i):
    SendToReceiver($($i))
Return

"@
    }
    $file4content += @"
SendToReceiver(index)
{
    IniRead, RainmeterPath, $file3, Variables, RMPATH
    Run "%RainmeterPath% "!CommandMEasure "Receiver:M" "Launch(%index%)" "Keylaunch\Main" " "
}

"@

    $file1content | Out-File -FilePath $file1 -Encoding unicode
    $file2content | Out-File -FilePath $file2 -Encoding unicode
    $file3Content | Out-File -FilePath $file3 -Encoding unicode
    $file4Content | Out-File -FilePath $file4 -Encoding unicode

    $RmAPI.Bang('[!UpdateMEasure Auto_Refresh:M][!Refresh]')
}

function Get-IniContent ($filePath) {
    $ini = [ordered]@{}
    if (![System.IO.File]::Exists($filePath)) {
        throw "$filePath invalid"
    }
    # $section = ';ItIsNotAFuckingSection;'
    # $ini.Add($section, [ordered]@{})

    foreach ($line in [System.IO.File]::ReadLines($filePath)) {
        if ($line -match "^\s*\[(.+?)\]\s*$") {
            $section = $matches[1]
            $secDup = 1
            while ($ini.Keys -contains $section) {
                $section = $section + '||ps' + $secDup
            }
            $ini.Add($section, [ordered]@{})
        }
        elseif ($line -match "^\s*;.*$") {
            $notSectionCount = 0
            while ($ini[$section].Keys -contains ';NotSection' + $notSectionCount) {
                $notSectionCount++
            }
            $ini[$section][';NotSection' + $notSectionCount] = $matches[1]
        }
        elseif ($line -match "^\s*(.+?)\s*=\s*(.+?)$") {
            $key, $value = $matches[1..2]
            $ini[$section][$key] = $value
        }
        else {
            $notSectionCount = 0
            while ($ini[$section].Keys -contains ';NotSection' + $notSectionCount) {
                $notSectionCount++
            }
            $ini[$section][';NotSection' + $notSectionCount] = $line
        }
    }

    return $ini
}

function Set-IniContent($InputObject, $FilePath)
{
    $outFile = New-Item -ItemType file -Path $Filepath
    foreach ($i in $InputObject.keys)
    {
        if (!($($InputObject[$i].GetType().Name) -eq â€œHashtableâ€))
        {
            #No Sections
            Add-Content -Path $outFile -Value â€œ$i=$($InputObject[$i])â€
        } else {
            #Sections
            Add-Content -Path $outFile -Value â€œ[$i]â€
            Foreach ($j in ($InputObject[$i].keys | Sort-Object))
            {
                if ($j -match â€œ^Comment[\d]+â€) {
                    Add-Content -Path $outFile -Value â€œ$($InputObject[$i][$j])â€
                } else {
                    Add-Content -Path $outFile -Value â€œ$j=$($InputObject[$i][$j])â€
                }

            }
            Add-Content -Path $outFile -Value â€œâ€
        }
    }
}

function WriteTo {
    param(
        [Parameter()]
        [int]$index,
        [Parameter()]
        $param1,
        [Parameter()]
        $param2,
        [Parameter()]
        $param3
    )
    if ($PSBoundParameters.ContainsKey('param1')) {
        $arrayName[$index-1] = $param1
    }
    if ($PSBoundParameters.ContainsKey('param2')) {
        $arrayAction[$index-1] = $param2
    }
    if ($PSBoundParameters.ContainsKey('param3')) {
        $arrayIcon[$index-1] = $param3
    }
    WriteAll -arg1 $t -arg2 ($t+1) -arg3 ($t+2)

    $RmAPI.Bang('[!Refresh "#JaxCore\Accessories\GenericInteractionBox"]')
}

function WriteHotkey {
    param(
        [Parameter()]
        $SecNum,
        [Parameter()]
        $hotkey,
        [Parameter()]
        $hotkeyString
    )
    
    # $Ini = Get-IniContent -filePath $file3
    $arrayKeyS[$SecNum-1] = $hotkeyString
    $arrayKey[$SecNum-1] = $hotkey

    Set-IniContent -ini $Ini -filePath $file3
    WriteAll -arg1 $t -arg2 ($t+1) -arg3 ($t+2)

    # $RmAPI.Bang('[!UpdateMeasure Auto_Refresh:M "#JaxCore\Main"][!Refresh "#JaxCore\Main"]')
}

function WriteAdd {
    $t++
    $RmAPI.Log($t)

    $arrayName.Add("Blank action")
    $arrayAction.Add("[!Log `"This is a blank action`"]")
    $arrayIcon.Add("folder_png")
    $arrayKey.Add("")
    $arrayKeyS.Add("Edit Hotkey")
    
    WriteAll -arg1 $t -arg2 ($t+1) -arg3 ($t+2)
}

function WriteRemove {
    param(
        [Parameter()]
        $startingIndex
    )
    
    for ($i=$startingIndex;$i -le ($t-1);$i++) {
        $RmAPI.Log("$($arrayName[$i-1]) -> $($arrayName[$i])")
        $arrayName[$i-1] = $arrayName[$i]
        $arrayAction[$i-1] = $arrayAction[$i]
        $arrayIcon[$i-1] =  $arrayIcon[$i]
        $arrayKey[$i-1] = $arrayKey[$i]
        $arrayKeyS[$i-1] = $arrayKeyS[$i]
    }
    $t = $t - 1
    WriteAll -arg1 $t -arg2 ($t+1) -arg3 ($t+2)
    $RmAPI.Bang('[!Refresh]')
}

function WriteSwap {
    param(
        [Parameter()]
        $i1,
        [Parameter()]
        $i2
    )

    $i1--
    $i2--
    
    $RmAPI.Log("$($arrayName[$i1]) <-> $($arrayName[$i2])")
    $arrayName[$i1], $arrayAction[$i1], $arrayIcon[$i1], $arrayKey[$i1], $arrayKeyS[$i1], $arrayName[$i2], $arrayAction[$i2], $arrayIcon[$i2], $arrayKey[$i2], $arrayKeyS[$i2] = $arrayName[$i2], $arrayAction[$i2], $arrayIcon[$i2], $arrayKey[$i2], $arrayKeyS[$i2], $arrayName[$i1], $arrayAction[$i1], $arrayIcon[$i1], $arrayKey[$i1], $arrayKeyS[$i1]
    WriteAll -arg1 $t -arg2 ($t+1) -arg3 ($t+2)
    $RmAPI.Bang('[!Refresh]')
}