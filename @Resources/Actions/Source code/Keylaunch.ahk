#SingleInstance Force
#NoTrayIcon
IniRead, Key1, Hotkeys.ini, Variables, Key1
IniRead, Key2, Hotkeys.ini, Variables, Key2
IniRead, Key3, Hotkeys.ini, Variables, Key3
IniRead, Key4, Hotkeys.ini, Variables, Key4
IniRead, Key5, Hotkeys.ini, Variables, Key5
IniRead, Key6, Hotkeys.ini, Variables, Key6
IniRead, Key7, Hotkeys.ini, Variables, Key7
IniRead, Key8, Hotkeys.ini, Variables, Key8
Try Hotkey, %Key1%, Action1
Try Hotkey, %Key2%, Action2
Try Hotkey, %Key3%, Action3
Try Hotkey, %Key4%, Action4
Try Hotkey, %Key5%, Action5
Try Hotkey, %Key6%, Action6
Try Hotkey, %Key7%, Action7
Try Hotkey, %Key8%, Action8
Return
Action1:
	SendToReceiver(1)
	Return
Action2:
	SendToReceiver(2)
	Return
Action3:
	SendToReceiver(3)
	Return
Action4:
	SendToReceiver(4)
	Return
Action5:
	SendToReceiver(5)
	Return
Action6:
	SendToReceiver(6)
	Return
Action7:
	SendToReceiver(7)
	Return
Action8:
	SendToReceiver(8)
	Return
SendToReceiver(index)
{
	IniRead, RainmeterPath, Hotkeys.ini, Variables, RMPATH
	Run "%RainmeterPath% "!CommandMEasure "Receiver:M" "Launch(%index%)" "Keylaunch\Main" " "
}
