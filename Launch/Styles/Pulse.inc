[Variables]
TweenTime1=125
TweenTime2=500

Sec.pad=5

[LoadActions]
OnUpdateAction=[!FadeDuration #TweenTime1#][!Delay (#TweenTime1#*2)][!DeactivateConfig]

[Shape]
Meter=Shape
Shape=Rectangle 0,0,#SCREENAREAWIDTH#,#SCREENAREAHEIGHT# | StrokeWidth 0 | Fill Color 255,255,255
Shape2=Rectangle #Sec.pad#,#Sec.pad#,(#SCREENAREAWIDTH#-#Sec.Pad#*2),(#SCREENAREAHEIGHT#-#Sec.Pad#*2) | StrokeWidth 0 | Fill Color 255,255,255
Shape3=COmbine Shape | XOR Shape2