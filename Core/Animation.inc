[DefaultStartActions]
Custom1=[!SetOption #Style#.Shape MeterStyle "Animation.Shape:S | ANimation.Shape.Selected:S"][!UpdateMeter #Style#.Shape][!Redraw]

; ---------------------------------------------------------------------------- ;
;                                    Styles                                    ;
; ---------------------------------------------------------------------------- ;
[Item.Shape:S]
X=(20*[Set.S])
Y=(40*[SEt.S])r
Shape=Rectangle 0,0,([ContentContainer:W]-#Set.P#),(50*[SEt.S]),(2*[Set.S]) | StrokeWidth 0 | Extend Fill
Fill=Fill Color #Set.Sec_Color#
Stroke=Stroke Color #Set.Ter_Color#
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Ter_Color#"][!SetOption #CURRENTSECTION# Stroke "Stroke Color #Set.Subtext_Color#,50"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Sec_Color#"][!SetOption #CURRENTSECTION# Stroke "Stroke Color #Set.Ter_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
DynamicVariables=1
Container=ContentContainer
[Item.StringIcon:S]
X=(50*[Set.S]/2)r
Y=(50*[Set.S]/2)r
StringAlign=leftCenter
FontFace=Material Icons Round
Container=ContentContainer
[Item.String:S]
X=(#Set.P#/2)R
Y=r
StringAlign=LeftCenter
Container=ContentContainer

[Animation.Shape:S]
X=(20*[Set.S])
Y=(40*[SEt.S])r
Shape=Rectangle 0,0,([ContentContainer:W]-#Set.P#),([ContentContainer:W]/4+50*[Set.S]),(2*[Set.S]) | StrokeWidth 0 | Extend Fill
Shape2=Line (#Set.P#*0.5),([ContentContainer:W]/4),([ContentContainer:W]-#Set.P#*2),([ContentContainer:W]/4) | STrokeWidth 2 | Extend Stroke
Shape3=Line (([ContentContainer:W]-#Set.P#)/2),([ContentContainer:W]/4+45*[SEt.S]),(([ContentContainer:W]-#Set.P#)/2),([ContentContainer:W]/4+5*[Set.s]) | STrokeWidth 1 | Stroke Color #Set.Subtext_Color#
Fill=Fill Color #Set.Sec_Color#
Stroke=Stroke Color #Set.Ter_Color#
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Ter_Color#"][!SetOption #CURRENTSECTION# Stroke "Stroke Color #Set.Subtext_Color#,50"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Sec_Color#"][!SetOption #CURRENTSECTION# Stroke "Stroke Color #Set.Ter_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
DynamicVariables=1
Container=ContentContainer
[Animation.Shape.Selected:S]
Fill=Fill Color #set.Ter_Color#
Stroke=Stroke Color #Set.Positive_Color#
MouseOverAction=
MouseLeaveAction=
[Animation.Image:S]
X=(10*[Set.S])r
Y=(10*[Set.S])r
W=([ContentContainer:W]-#Set.P#-20*[Set.S])
H=([ContentContainer:W]/4-20*[SEt.S])
ImageName=#SKINSPATH##Skin.Name#\Core\Animation\[&Func:trim('#CURRENTSECTIOn#','.Image','')].png
DynamicVariables=1
Container=ContentContainer
[Animation.String:S]
X=(10*[Set.s])r
Y=(-10*[SEt.s])R
Text=[&Func:trim('#CURRENTSECTIOn#','.String','')]
StringAlign=LeftBottom
Fontsize=(20*[Set.S])
FontWeight=650
Container=ContentContainer
[Animation.Button1.Shape:S]
X=(-5*[Set.S])r
Y=(30*[Set.S])r
Shape=Rectangle 0,0,(([ContentContainer:W]-#Set.P#-60*[Set.s])/2),(30*[Set.S]),(5*[Set.S]) | StrokeWidth 2 | Extend Stroke
Stroke=Stroke Color 0,0,0,1 | Fill Color 0,0,0,1
MouseOverAction=[!SetOption #CURRENTSECTION# Stroke "Stroke Color #Set.Subtext_Color#,25 | Fill Color #Set.Subtext_Color#,25"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Stroke "Stroke Color 0,0,0,1 | Fill Color 0,0,0,1"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[!WriteKeyValue Variables Style [&Func:trim('#CURRENTSECTIOn#','.Button1.Shape','')] "#Sec.SaveLocation#"][!Refresh]
DynamicVariables=1
Container=ContentContainer
[Animation.Button1.String:S]
X=(([ContentContainer:W]-#Set.P#-60*[Set.s])/2/2)r
Y=(30*[Set.S]/2)r
StringAlign=CenterCenter
Text=[\xe876]  Select
Inlinepattern=^.
InlineSetting=Face | Material Icons Round
Inlinepattern2=^.
InlineSetting2=Size  | (10*[Set.S])
Container=ContentContainer
[Animation.Button2.Shape:S]
X=(([ContentContainer:W]-#Set.P#-60*[Set.s])/2/2+30*[Set.S])r
Y=(-30*[Set.S]/2)r
LeftMouseUpAction=[!WriteKeyValue Variables Sec.Name "Keylaunch" "#SKINSPATH##SKin.Name#\Launch\Main.ini"][!WriteKeyValue Variables Sec.Icon "folder_png" "#SKINSPATH##SKin.Name#\Launch\Main.ini"][!WriteKeyValue Variables Sec.Action "" "#SKINSPATH##SKin.Name#\Launch\Main.ini"][!WriteKeyValue Variables Style [&Func:trim('#CURRENTSECTIOn#','.Button2.Shape','')] "#Sec.SaveLocation#"][!ActivateConfig "Keylaunch\Launch" "Main.ini"][!Delay 100][!WriteKeyValue Variables Style #Style# "#Sec.SaveLocation#"]
[Animation.Button2.String:S]
Text=[\xe8f4]  Preview

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Item1.Shape]
Meter=Shape
Y=(30*[Set.S])R
MeterStyle=Item.Shape:S
[Item1.StringIcon]
Meter=String
Text=[\xe8f4]
MeterStyle=Set.String:S | Item.StringIcon:S
[Item1.String]
Meter=String
Text=View all the animations at once on the github README.md!
MeterStyle=Set.String:S | Item.String:S

[VectorSlide.Shape]
Meter=Shape
MeterStyle=Animation.Shape:S
[VectorSlide.Image]
Meter=Image
MeterStyle=Animation.Image:S
[VectorSlide.String]
Meter=String
MEterStyle=Set.String:S | Animation.STring:S
[VectorSlide.Button1.Shape]
Meter=Shape
MeterStyle=Animation.Button1.Shape:S
[VectorSlide.Button1.String]
Meter=String
MEterStyle=Set.String:S | Animation.Button1.STring:S
[VectorSlide.Button2.Shape]
Meter=Shape
MeterStyle=Animation.Button1.Shape:S | Animation.Button2.Shape:S
[VectorSlide.Button2.String]
Meter=String
MEterStyle=Set.String:S | Animation.Button1.STring:S | Animation.Button2.STring:S

[Expand.Shape]
Meter=Shape
MeterStyle=Animation.Shape:S
[Expand.Image]
Meter=Image
MeterStyle=Animation.Image:S
[Expand.String]
Meter=String
MEterStyle=Set.String:S | Animation.STring:S
[Expand.Button1.Shape]
Meter=Shape
MeterStyle=Animation.Button1.Shape:S
[Expand.Button1.String]
Meter=String
MEterStyle=Set.String:S | Animation.Button1.STring:S
[Expand.Button2.Shape]
Meter=Shape
MeterStyle=Animation.Button1.Shape:S | Animation.Button2.Shape:S
[Expand.Button2.String]
Meter=String
MEterStyle=Set.String:S | Animation.Button1.STring:S | Animation.Button2.STring:S


[Bottom.Shape]
Meter=Shape
MeterStyle=Animation.Shape:S
[Bottom.Image]
Meter=Image
MeterStyle=Animation.Image:S
[Bottom.String]
Meter=String
MEterStyle=Set.String:S | Animation.STring:S
[Bottom.Button1.Shape]
Meter=Shape
MeterStyle=Animation.Button1.Shape:S
[Bottom.Button1.String]
Meter=String
MEterStyle=Set.String:S | Animation.Button1.STring:S
[Bottom.Button2.Shape]
Meter=Shape
MeterStyle=Animation.Button1.Shape:S | Animation.Button2.Shape:S
[Bottom.Button2.String]
Meter=String
MEterStyle=Set.String:S | Animation.Button1.STring:S | Animation.Button2.STring:S


[Spin.Shape]
Meter=Shape
MeterStyle=Animation.Shape:S
[Spin.Image]
Meter=Image
MeterStyle=Animation.Image:S
[Spin.String]
Meter=String
MEterStyle=Set.String:S | Animation.STring:S
[Spin.Button1.Shape]
Meter=Shape
MeterStyle=Animation.Button1.Shape:S
[Spin.Button1.String]
Meter=String
MEterStyle=Set.String:S | Animation.Button1.STring:S
[Spin.Button2.Shape]
Meter=Shape
MeterStyle=Animation.Button1.Shape:S | Animation.Button2.Shape:S
[Spin.Button2.String]
Meter=String
MEterStyle=Set.String:S | Animation.Button1.STring:S | Animation.Button2.STring:S


[Center.Shape]
Meter=Shape
MeterStyle=Animation.Shape:S
[Center.Image]
Meter=Image
MeterStyle=Animation.Image:S
[Center.String]
Meter=String
MEterStyle=Set.String:S | Animation.STring:S
[Center.Button1.Shape]
Meter=Shape
MeterStyle=Animation.Button1.Shape:S
[Center.Button1.String]
Meter=String
MEterStyle=Set.String:S | Animation.Button1.STring:S
[Center.Button2.Shape]
Meter=Shape
MeterStyle=Animation.Button1.Shape:S | Animation.Button2.Shape:S
[Center.Button2.String]
Meter=String
MEterStyle=Set.String:S | Animation.Button1.STring:S | Animation.Button2.STring:S