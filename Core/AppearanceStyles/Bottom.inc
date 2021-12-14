[Option01]
Meter=String
Text=Application name font size
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1913s138]
Meter=Shape
MeterStyle=Set.Div:S
[Option02]
Meter=String
Text=Notif box padding from bottom of screen
MeterStyle=Set.String:S | Set.OptionName:S

[AnimationDurationTitle]
Meter=String
Text=Animation duration
MeterStyle=Set.String:S | Set.OptionCat:S

[Option11]
Meter=String
Text=Notif show / hide duration (ms)
MeterStyle=Set.String:S | Set.OptionName:S

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

[Style.Pad]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option02:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value02]
Meter=String
Text=#Style.Pad#
MeterStyle=Set.String:S | Set.Value:S

[Style.Time1]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option11:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value11]
Meter=String
Text=#Style.Time1#
MeterStyle=Set.String:S | Set.Value:S