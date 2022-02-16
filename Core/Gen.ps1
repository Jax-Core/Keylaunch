function Update {
    $global:t = [int]$RmAPI.VariableStr('Total')
    $global:skinsPath = $RmAPI.VariableStr('SKINSPATH')
    $global:coreDataDir = "$($global:skinsPath.Replace('Skins\',''))CoreData\"
    $global:file1 = "$global:coreDataDir"+"Keylaunch\Include.inc"
    $global:file2 = "$global:coreDataDir"+"Keylaunch\Act.inc"
    $global:file3 = "$global:coreDataDir"+"Keylaunch\Hotkeys.inc"
    $global:file4 = "$global:coreDataDir"+"Keylaunch\Keylaunch.ahk"
    $global:arrayName = New-Object System.Collections.Generic.List[System.Object]
    $global:arrayAction = New-Object System.Collections.Generic.List[System.Object]
    $global:arrayIcon = New-Object System.Collections.Generic.List[System.Object]
    $global:arrayKey = New-Object System.Collections.Generic.List[System.Object]
    $global:arrayKeyS = New-Object System.Collections.Generic.List[System.Object]
    WriteToMemory
}

function WriteToMemory {
    for ($i=1 ; $i -le $global:t ; $i++) {
        $global:arrayName.Add($RmAPI.VariableStr("$($i)Name"))
        $global:arrayAction.Add($RmAPI.VariableStr("$($i)Action"))
        $global:arrayIcon.Add($RmAPI.VariableStr("$($i)Icon"))
        $global:arrayKey.Add($RmAPI.VariableStr("Key$($i)"))
        $global:arrayKeyS.Add($RmAPI.VariableStr("Key$($i)InString"))
    }
}

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
        $global:file1content += @"
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
    $global:file2content += @"
[Variables]
Total=$($arg1)

"@
    if ($arg1 -gt $global:t) {
        $l = $global:t
     } else {
        $l = $arg1
     }
     
    for ($i=1 ; $i -le $arg1 ; $i++) {
        $global:file2content += @"
$($i)Name=$($global:arrayName[$i-1])
$($i)Action=$($global:arrayAction[$i-1])
$($i)Icon=$($global:arrayIcon[$i-1])

"@
    }

    # ---------------------------------------------------------------------------- #
    #                              write ahk variables                             #
    # ---------------------------------------------------------------------------- #
    $global:file3content += @"
[Variables]
RMPATH=$($RmAPI.VariableStr('RMPATH'))

"@

    for ($i=1 ; $i -le $arg1 ; $i++) {
        $global:file3content += @"
Key$($i)=$($global:arrayKey[$i-1])
Key$($i)InString=$($global:arrayKeyS[$i-1])

"@
    }

    # ---------------------------------------------------------------------------- #
    #                                   write ahk                                  #
    # ---------------------------------------------------------------------------- #
    $global:file4content += @"
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
        $global:file4content += @"
IniRead, Key$($i), $file3, Variables, Key$($i)

"@
    }
    for ($i=1 ; $i -le $arg1 ; $i++) {
        $global:file4content += @"
Try Hotkey, %Key$($i)%, Action$($i)

"@
    }
    $global:file4content += @"
Return

"@
    for ($i=1 ; $i -le $arg1 ; $i++) {
        $global:file4content += @"
Action$($i):
    SendToReceiver($($i))
Return

"@
    }
    $global:file4content += @"
SendToReceiver(index)
{
    IniRead, RainmeterPath, $file3, Variables, RMPATH
    Run "%RainmeterPath% "!CommandMEasure "Receiver:M" "Launch(%index%)" "Keylaunch\Main" " "
}

"@

    $global:file1content | Out-File -FilePath $global:file1 -Encoding unicode
    $global:file2content | Out-File -FilePath $global:file2 -Encoding unicode
    $global:file3Content | Out-File -FilePath $global:file3 -Encoding unicode
    $global:file4Content | Out-File -FilePath $global:file4 -Encoding unicode

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
        if (!($($InputObject[$i].GetType().Name) -eq “Hashtable”))
        {
            #No Sections
            Add-Content -Path $outFile -Value “$i=$($InputObject[$i])”
        } else {
            #Sections
            Add-Content -Path $outFile -Value “[$i]”
            Foreach ($j in ($InputObject[$i].keys | Sort-Object))
            {
                if ($j -match “^Comment[\d]+”) {
                    Add-Content -Path $outFile -Value “$($InputObject[$i][$j])”
                } else {
                    Add-Content -Path $outFile -Value “$j=$($InputObject[$i][$j])”
                }

            }
            Add-Content -Path $outFile -Value “”
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
        $global:arrayName[$index-1] = $param1
    }
    if ($PSBoundParameters.ContainsKey('param2')) {
        $global:arrayAction[$index-1] = $param2
    }
    if ($PSBoundParameters.ContainsKey('param3')) {
        $global:arrayIcon[$index-1] = $param3
    }
    WriteAll -arg1 $global:t -arg2 ($global:t+1) -arg3 ($global:t+2)

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
    $global:arrayKeyS[$SecNum-1] = $hotkeyString
    $global:arrayKey[$SecNum-1] = $hotkey

    Set-IniContent -ini $Ini -filePath $file3
    WriteAll -arg1 $global:t -arg2 ($global:t+1) -arg3 ($global:t+2)

    # $RmAPI.Bang('[!UpdateMeasure Auto_Refresh:M "#JaxCore\Main"][!Refresh "#JaxCore\Main"]')
}

function WriteAdd {
    $global:t++

    $global:arrayName.Add("Blank action")
    $global:arrayAction.Add("[!Log `"This is a blank action`"]")
    $global:arrayIcon.Add("folder_png")
    $global:arrayKey.Add("")
    $global:arrayKeyS.Add("Edit Hotkey")
    
    WriteAll -arg1 $global:t -arg2 ($global:t+1) -arg3 ($global:t+2)
}

function WriteRemove {
    param(
        [Parameter()]
        $startingIndex
    )
    
    for ($i=$startingIndex;$i -le ($global:t-1);$i++) {
        $RmAPI.Log("$($global:arrayName[$i-1]) -> $($global:arrayName[$i])")
        $global:arrayName[$i-1] = $global:arrayName[$i]
        $global:arrayAction[$i-1] = $global:arrayAction[$i]
        $global:arrayIcon[$i-1] =  $global:arrayIcon[$i]
        $global:arrayKey[$i-1] = $global:arrayKey[$i]
        $global:arrayKeyS[$i-1] = $global:arrayKeyS[$i]
    }
    $global:t = $global:t - 1
    WriteAll -arg1 $global:t -arg2 ($global:t+1) -arg3 ($global:t+2)
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
    
    $RmAPI.Log("$($global:arrayName[$i1]) <-> $($global:arrayName[$i2])")
    $global:arrayName[$i1], $global:arrayAction[$i1], $global:arrayIcon[$i1], $global:arrayKey[$i1], $global:arrayKeyS[$i1], $global:arrayName[$i2], $global:arrayAction[$i2], $global:arrayIcon[$i2], $global:arrayKey[$i2], $global:arrayKeyS[$i2] = $global:arrayName[$i2], $global:arrayAction[$i2], $global:arrayIcon[$i2], $global:arrayKey[$i2], $global:arrayKeyS[$i2], $global:arrayName[$i1], $global:arrayAction[$i1], $global:arrayIcon[$i1], $global:arrayKey[$i1], $global:arrayKeyS[$i1]
    WriteAll -arg1 $global:t -arg2 ($global:t+1) -arg3 ($global:t+2)
    $RmAPI.Bang('[!Refresh]')
}