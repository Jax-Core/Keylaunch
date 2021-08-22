function Initialize()
    root = SKIN:GetVariable('ROOTCONFIGPATH')
    local t = tonumber(SKIN:GetVariable('Total'))
    for i=1,t do
        _G["Name"..i] = SKIN:GetVariable(i..'Name')
        _G["Icon"..i] = SKIN:GetVariable(i..'Icon')
        _G["Action"..i] = SKIN:GetVariable(i..'Action')
        print("Loaded:   " .. _G["Name"..i])
    end
    -- 
    -- Item1Name = SKIN:GetVariable('1Name')
    -- Item1Name = SKIN:GetVariable('1Name')
end

function Launch(index)
    SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.Name', _G["Name"..index], root..'Launch\\Main.ini')
    SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.Icon', _G["Icon"..index], root..'Launch\\Main.ini')
    SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.Action', _G["Action"..index], root..'Launch\\Main.ini')
    SKIN:Bang('!ActivateConfig', 'Keylaunch\\Launch')
end