[Variables]
@includeAct=#SKINSPATH##Skin.Name#\@Resources\Act.inc
Sec.SaveLocation=#SKINSPATH##Skin.Name#\@Resources\Act.inc
Sec.ForceWriteVariables=0
Sec.AnchorName=AnchorSuppli

[HotkeysTitle]
Meter=String
Text=List of actions (#Total#)
; / tip: right click to select folders instaed of files
InlinePattern=/.*
inlinesetting=Size | (8*[Set.S])
InlinePattern2=/.*
inlinesetting2=Color | #Set.Subtext_Color#
MeterStyle=Set.String:S | Set.OptionCat:S

[Script:M]
Measure=Script
ScriptFile="#SKINSPATH##Skin.name#\Core\GenKeylaunchKey.lua"

[CheckForDataFolder]
MEasure=Plugin
Plugin=PowershellRM
DynamicVariables=1
OnUpdateAction=[!Delay 100][!CommandMeasure CheckForDataFolder "Check-Data"]
ScriptFile=#@#Powershell\CheckData.ps1

; ---------------------------------------------------------------------------- ;
;                                    Styles                                    ;
; ---------------------------------------------------------------------------- ;

[Sec.Edit:S]
Fill=Fill Color 0,255,50,100
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 0,255,50,200"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 0,255,50,100"][!UpdateMeter #CURRENTSECTION#][!Redraw]
X=(#Set.W#-#Set.L#-#Set.P#*2-190*[Set.S])
Shape=Rectangle (160*[Set.S]),0,(30*[Set.S]),(30*[Set.S]),3,3 | StrokeWidth 0 | Extend Fill
Act=[!CommandMeasure Script:M "Edit(0, 0, '#CURRENTSECTION#')"]

[Sec.Delete:S]
Fill=Fill Color 255,0,0,100
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,0,0,200"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,0,0,100"][!UpdateMeter #CURRENTSECTION#][!Redraw]
X=(#Set.W#-#Set.L#-#Set.P#*2-190*[Set.S])
Shape=Rectangle (160*[Set.S]),0,(30*[Set.S]),(30*[Set.S]),3,3 | StrokeWidth 0 | Extend Fill
Act=[!CommandMeasure Script:M "Remove(0, '#CURRENTSECTION#')"]

[Sec.KeyInString:S]
X=(-10*[Set.S])R

[Sec.RowButton:S]
X=(#Set.W#-#Set.L#-#Set.P#*2-151*[Set.S])
Shape=Rectangle 0,0,150,30,3,3 | StrokeWidth 0 | Extend Fill | Scale [Set.S],[Set.S],0,0

; ---------------------------------------------------------------------------- ;
;                                   Includes                                   ;
; ---------------------------------------------------------------------------- ;



@includeInclude=#SKINSPATH#..\CoreData\Keylaunch\Include.inc


; ---------------------------------------------------------------------------- ;
;                                    Anchor                                    ;
; ---------------------------------------------------------------------------- ;
[ResetTitle]
Meter=String
Text=Danger Zone
MeterStyle=Set.String:S | Set.OptionCat:S
[Option91]
Meter=String
Text=Reset & clear application list
MeterStyle=Set.String:S | Set.OptionName:S

[Button91]
Meter=Shape
MeterStyle=Set.Button:S
OverColor=255,0,50,150
LeaveColor=255,0,50,100
Y=([Option91:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!CommandMeasure Script:M "Reset()"]
[Value91]
Meter=String
Text=[\xf053]
FontFace=Material Icons Round
FontSize=(14*[Set.S])
MeterStyle=Set.String:S | Set.Value:S
[Value911]
Meter=String
X=(-25*[Set.S])r
Y=r
Text=Reset
MeterStyle=Set.String:S | Set.Value:S

[AnchorSuppli]
Meter=String
Container=ContentContainer
x=r
Y=R

@includeKeys=#SKINSPATH##Skin.Name#\@Resources\Actions\HotKeys.ini
