[Variables]
Sec.AnchorName=AnchorSuppli
Sec.SaveLocation=#SKINSPATH##Skin.Name#\Launch\Vars\#Style#.inc
@includeSaveLocation=#SKINSPATH##Skin.Name#\Launch\Vars\#Style#.inc
Sec.ForceWriteVariables=0

[Auto_Refresh:M]
Measure=


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
ImageName=#SKINSPATH##Skin.Name#\Core\Animation\#Style#.png
DynamicVariables=1
Container=ContentContainer
[Animation.String:S]
X=(10*[Set.s])r
Y=(-10*[SEt.s])R
Text=#Style#
StringAlign=LeftBottom
Fontsize=(20*[Set.S])
FontWeight=650
Container=ContentContainer
[Animation.Button1.Shape:S]
X=(-5*[Set.S])r
Y=(30*[Set.S])r
Shape=Rectangle 0,0,([ContentContainer:W]-#Set.P#-40*[Set.s]),(30*[Set.S]),(5*[Set.S]) | StrokeWidth 2 | Extend Stroke
Stroke=Stroke Color 0,0,0,1 | Fill Color 0,0,0,1
MouseOverAction=[!SetOption #CURRENTSECTION# Stroke "Stroke Color #Set.Subtext_Color#,25 | Fill Color #Set.Subtext_Color#,25"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Stroke "Stroke Color 0,0,0,1 | Fill Color 0,0,0,1"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[!WriteKeyValue Variables Sec.Name "Keylaunch" "#SKINSPATH##SKin.Name#\Launch\Main.ini"][!WriteKeyValue Variables Sec.Icon "folder_png" "#SKINSPATH##SKin.Name#\Launch\Main.ini"][!WriteKeyValue Variables Sec.Action "" "#SKINSPATH##SKin.Name#\Launch\Main.ini"][!ActivateConfig "Keylaunch\Launch" "Main.ini"]
DynamicVariables=1
Container=ContentContainer
[Animation.Button1.String:S]
X=(([ContentContainer:W]-#Set.P#-40*[Set.s])/2)r
Y=(30*[Set.S]/2)r
StringAlign=CenterCenter
Text=[\xe8f4]  Preview
Inlinepattern=^.
InlineSetting=Face | Material Icons Round
Inlinepattern2=^.
InlineSetting2=Size  | (10*[Set.S])
Container=ContentContainer

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Item1.Shape]
Meter=Shape
Y=(30*[Set.S])R
MeterStyle=Item.Shape:S
[Item1.StringIcon]
Meter=String
Text=[\xe161]
MeterStyle=Set.String:S | Item.StringIcon:S
[Item1.String]
Meter=String
Text=You're changing settings for this style only!
MeterStyle=Set.String:S | Item.String:S

[Animation1.Shape]
Meter=Shape
MeterStyle=Animation.Shape:S
[Animation1.Image]
Meter=Image
MeterStyle=Animation.Image:S
[Animation1.String]
Meter=String
MEterStyle=Set.String:S | Animation.STring:S
[Animation1.Button1.Shape]
Meter=Shape
MeterStyle=Animation.Button1.Shape:S
[Animation1.Button1.String]
Meter=String
MEterStyle=Set.String:S | Animation.Button1.STring:S

[HotkeysTitle]
Meter=String
Text=Customization
MeterStyle=Set.String:S | Set.OptionCat:S

[Option00]
Meter=String
Text=Animation scale
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:38]
Meter=Shape
MeterStyle=Set.Div:S

@includeCoreAppearanceStyles=#SKINSPATH##SKin.Name#\Core\AppearanceStyles\#Style#.inc

[Style.Scale]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option00:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value00]
Meter=String
Text=#Style.Scale#x
MeterStyle=Set.String:S | Set.Value:S
