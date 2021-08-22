[Variables]
TweenTime1=600
TweenTime2=600

Sec.H=10
Sec.Pad=10

[mTween]
Measure=Script
ScriptFile=#@#LuaTween/Main.lua
TweenGroup=Tweenable
Tween0=Single | Variable | TweenNode1 | 0 | 1 | #TweenTime1#
Tween1=Single | Variable | TweenNode2 | 0 | 1 | #TweenTime2#
Optional0=Easing InOutExpo
Optional1=Easing InOutExpo
UpdateDivider=1

[Shape]
Meter=Shape
Y=(#SCREENAREAHEIGHT#-#Sec.H#)
DynamicVariables=1
Shape=Rectangle (#SCREENAREAWIDTH#*#TweenNode2#),0,(#SCREENAREAWIDTH#*#TweenNode1#),(#Sec.H#),(#Sec.H#/2) | StrokeWidth 0 | Fill Color 255,255,255

[Image]
MEter=Image
X=(#SCREENAREAWIDTH#/2-256/2)
Y=(#SCREENAREAHEIGHT#/2-256/2)
W=(256)
H=(256)
ImageAlpha=(255*#TweenNode1#*(1-#TweenNode2#))
DynamicVariables=1
ImageName=#@#IconCache\#Sec.Icon#.png

[String]
Meter=String
FontSize=50
X=(256/2)r
Y=(30)R
FontColor=255,255,255,(255*#TweenNode1#*(1-#TweenNode2#))
FontFace=Poppins SemiBold
Text=#Sec.Name#
AntiAlias=1
StringAlign=CenterTop
DynamicVariables=1
InlineSetting=Shadow | 0 | 0 | #Blur# | 255,255,255,150