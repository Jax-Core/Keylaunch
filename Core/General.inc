[HotkeysTitle]
Meter=String
Text=Behavior
MeterStyle=Set.String:S | Set.OptionCat:S

[Option01]
Meter=String
Text=Show application after animation
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:38]
Meter=Shape
MeterStyle=Set.Div:S
[Option02]
Meter=String
Text=Full capital letter names
MeterStyle=Set.String:S | Set.OptionName:S

[CoTitle]
Meter=String
Text=Global appearance
MeterStyle=Set.String:S | Set.OptionCat:S
[Option11]
Meter=String
Text=Text glow sigma
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1913s138]
Meter=Shape
MeterStyle=Set.Div:S
[Option12]
Meter=String
Text=Text font
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:Sasdasd1913s138]
Meter=Shape
MeterStyle=Set.Div:S
[Option13]
Meter=String
Text=Background color
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:Sas]
Meter=Shape
MeterStyle=Set.Div:S
[Option14]
Meter=String
Text=Font color
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:Sus]
Meter=Shape
MeterStyle=Set.Div:S
[Option15]
Meter=String
Text=Glow color
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:SussyBaka]
Meter=Shape
MeterStyle=Set.Div:S
[Option16]
Meter=String
Text=Greyscale Icon
MeterStyle=Set.String:S | Set.OptionName:S

[AniTitle]
Meter=String
Text=Animation configuration
MeterStyle=Set.String:S | Set.OptionCat:S
[Option21]
Meter=String
Text=Start animations before launching application
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1913sadsas138]
Meter=Shape
MeterStyle=Set.Div:S
[Option26]
Meter=String
Text=Animation display monitor index
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:dsas138]
Meter=Shape
MeterStyle=Set.Div:S
[Option22]
Meter=String
Text=Animation frame interval (0 for true 60fps)
MeterStyle=Set.String:S | Set.OptionName:S

; ---------------------------------------------------------------------------- ;
;                                     Input                                    ;
; ---------------------------------------------------------------------------- ;

[ExecuteAt]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option01:Y]-#Set.P#+(-20/2+8)*[Set.S])
[Caps]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option02:Y]-#Set.P#+(-20/2+8)*[Set.S])

[Blur]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option11:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value11]
Meter=String
Text=#Blur#
MeterStyle=Set.String:S | Set.Value:S
[GlobalFont]
Meter=Shape
MeterStyle=Set.FontBox:S
Y=([Option12:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value12]
Meter=String
Text=#GlobalFont#
MeterStyle=Set.String:S | Set.Value:S
[MainC]
Meter=Shape
MeterStyle=Set.ColorPacity:S
Y=([Option13:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value13]
Meter=String
Text=#MainCOpacity#
MeterStyle=Set.String:S | Set.Pacity:S
[FontColor]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option14:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Glow]
Meter=Shape
MeterStyle=Set.ColorPacity:S
Y=([Option15:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value15]
Meter=String
Text=#GlowOpacity#
MeterStyle=Set.String:S | Set.Pacity:S
[Greyscale]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option16:Y]-#Set.P#+(-20/2+8)*[Set.S])


[ShowAni]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option21:Y]-#Set.P#+(-20/2+8)*[Set.S])
[LaunchAt]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option26:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value26]
Meter=String
Text=#LaunchAt#
MeterStyle=Set.String:S | Set.Value:S
[UpdateRate]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option22:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value22]
Meter=String
Text=#UpdateRate#
MeterStyle=Set.String:S | Set.Value:S