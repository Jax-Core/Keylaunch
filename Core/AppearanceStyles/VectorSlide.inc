[Option01]
Meter=String
Text=Application name font size
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:2]
Meter=Shape
MeterStyle=Set.Div:S
[Option02]
Meter=String
Text=Y position of the banner
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3]
Meter=Shape
MeterStyle=Set.Div:S
[Option03]
Meter=String
Text=Left and right padding for elements
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:4]
Meter=Shape
MeterStyle=Set.Div:S
[Option04]
Meter=String
Text=Background color
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:5]
Meter=Shape
MeterStyle=Set.Div:S
[Option05]
Meter=String
Text=Accent color
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:6]
Meter=Shape
MeterStyle=Set.Div:S
[Option06]
Meter=String
Text=Progress bar color
MeterStyle=Set.String:S | Set.OptionName:S

[AnimationDurationTitle]
Meter=String
Text=Animation duration
MeterStyle=Set.String:S | Set.OptionCat:S

[Option11]
Meter=String
Text=Slide duration
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:11]
Meter=Shape
MeterStyle=Set.Div:S

[Option12]
Meter=String
Text=Delay before vector slide starts
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:12]
Meter=Shape
MeterStyle=Set.Div:S

[Option13]
Meter=String
Text=Vector slide duration
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:13]
Meter=Shape
MeterStyle=Set.Div:S

[Option14]
Meter=String
Text=Idle duration before retracting banner
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:14]
Meter=Shape
MeterStyle=Set.Div:S

; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;

[Style.FontSize]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value01]
Meter=String
Text=#Style.FontSize#
MeterStyle=Set.String:S | Set.Value:S

[Style.YPos]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option02:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value02]
Meter=String
Text=#Style.YPos#
MeterStyle=Set.String:S | Set.Value:S

[Style.Pad]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option03:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value03]
Meter=String
Text=#Style.Pad#
MeterStyle=Set.String:S | Set.Value:S

[Style.Pri_Color]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option04:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Style.Accent_Color]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option05:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Style.Prog_Color]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option06:Y]-#Set.P#+(-30/2+8)*[Set.S])

[Style.Time1]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option11:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value11]
Meter=String
Text=#Style.Time1# ms
MeterStyle=Set.String:S | Set.Value:S

[Style.VectorWait]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option12:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value12]
Meter=String
Text=#Style.VectorWait# ms
MeterStyle=Set.String:S | Set.Value:S

[Style.VectorTime]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option13:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value13]
Meter=String
Text=#Style.VectorTime# ms
MeterStyle=Set.String:S | Set.Value:S

[Style.WaitTime]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option14:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value14]
Meter=String
Text=#Style.WaitTime# ms
MeterStyle=Set.String:S | Set.Value:S


; ---------------------------------------------------------------------------- ;
;                                    Anchor                                    ;
; ---------------------------------------------------------------------------- ;


[AnchorSuppli]
Meter=String
Container=ContentContainer
x=r
Y=R