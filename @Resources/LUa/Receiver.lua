function Initialize()
    root = SKIN:GetVariable('ROOTCONFIGPATH')
    local t = tonumber(SKIN:GetVariable('Total'))
    for i=1,t do
        _G["Name"..i] = SKIN:GetVariable(i..'Name')
        _G["Icon"..i] = SKIN:GetVariable(i..'Icon')
        _G["Action"..i] = SKIN:GetVariable(i..'Action')
    end
    -- 
    -- Item1Name = SKIN:GetVariable('1Name')
    -- Item1Name = SKIN:GetVariable('1Name')
end

function Launch(index)
    if tonumber(SKIN:GetVariable('ShowAni')) == 0 then
        SKIN:Bang('!SetOption', 'Executer:M', 'OnUpdateAction', _G["Action"..index])
        SKIN:Bang('!UpdateMeasure', 'Executer:M')
    else
        if tonumber(SKIN:GetVariable('Caps')) == 1 then _G["Name"..index] = string.upper(_G["Name"..index]) end
        SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.Name', _G["Name"..index], root..'Launch\\Main.ini')
        SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.Icon', _G["Icon"..index], root..'Launch\\Main.ini')
        SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.Action', _G["Action"..index], root..'Launch\\Main.ini')
        SKIN:Bang('!ActivateConfig', 'Keylaunch\\Launch')
    end
end