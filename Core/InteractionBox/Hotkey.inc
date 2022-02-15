[Rainmeter]
SkinWidth=0
SkinHeight=0

[Variables]
Sec.W=0
Sec.H=0
@includeSecVar=#@#SecVar.inc
@includeSkinHotkeys=#SKINSPATH#..\CoreData\#Skin.Name#\HotKeys.inc

[moveX]
Formula=0
[moveY]
Formula=0
[anchorX]
Formula=0
[anchorY]
Formula=0

[B]
Hidden=1

[ActionTimer]
ActionList1=Custom1 | Hide
Custom1=[!CommandMeasure mSet "Start()"]

; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;

[mSet]
Measure=Script
ScriptFile=#SKINSPATH##Skin.Name#\Core\SetHotkey.lua