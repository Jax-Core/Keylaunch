function Set(hotkey, useWin)
    if hotkey ~= nil then
        local SecNum = SKIN:GetVariable('Sec.arg1')
        if useWin == 1 then
            hotkey = '#'..hotkey
        end
        local matchArray = {'%#', '%!', '%^', '%+'}
        local replaceArray = {'Win ', 'Alt ', 'Ctrl ', 'Shift '}
        local hotkeyString = hotkey
        for i = 1, 4 do
            hotkeyString = hotkeyString:gsub(matchArray[i], replaceArray[i])
        end
        hotkeyString = hotkeyString:gsub('.$', hotkeyString:sub(-1):upper())
        SKIN:Bang('[!CommandMeasure GenPs1 """WriteHotkey -SecNum "'..SecNum..'" -hotkey "'..hotkey..'" -hotkeyString "'..hotkeyString..'"""" "#JaxCore\\Main"]')
    end
    SKIN:Bang('[!DeactivateConfig]')
end

function Start()
    local bang = ''
    local winbool = 0
    local currentKey = SKIN:GetVariable('Key'..SKIN:GetVariable('Sec.arg1'))
    if currentKey:find('#') then
        currentKey = currentKey:gsub('#', '')
        winbool = 1
    end
    local saveLocation = [[#@#Actions\\AHKCacheVariables.inc]]
    bang = bang .. '[!WriteKeyvalue Variables CurrentKey "'..currentKey..'" "'..saveLocation..'"]'
    bang = bang .. '[!WriteKeyvalue Variables WinBool "'..winbool..'" "'..saveLocation..'"]'
    bang = bang .. '[!WriteKeyvalue Variables RMPATH "#PROGRAMPATH#Rainmeter.exe" "'..saveLocation..'"]'
    bang = bang .. '[!WriteKeyvalue Variables Config "#CURRENTCONFIG#" "'..saveLocation..'"]'
    bang = bang .. '["#@#Actions\\AHKv1.exe" "#@#Actions\\Hotkey.AHK"]'
    SKIN:Bang(bang)
end