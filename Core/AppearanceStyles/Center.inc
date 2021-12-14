[Option01]
Meter=String
Text=Application name font size
MeterStyle=Set.String:S | Set.OptionName:S

[AnimationDurationTitle]
Meter=String
Text=Animation duration
MeterStyle=Set.String:S | Set.OptionCat:S

[Option11]
Meter=String
Text=Expand duration (ms)
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1913s138]
Meter=Shape
MeterStyle=Set.Div:S
[Option12]
Meter=String
Text=Slide out duration (ms)
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

[Style.Time1]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option11:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value11]
Meter=String
Text=#Style.Time1#
MeterStyle=Set.String:S | Set.Value:S

[Style.Time2]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option12:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value12]
Meter=String
Text=#Style.Time2#
MeterStyle=Set.String:S | Set.Value:S