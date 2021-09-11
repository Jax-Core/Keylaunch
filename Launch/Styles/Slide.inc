[Variables]
Sec.Skew=50
Sec.W=500


[mTween]
Measure=Script
ScriptFile=#@#LuaTween/Main.lua
TweenGroup=Tweenable
Tween0=Single | Variable | TweenNode1 | 0 | 1 | #LongDelay#
Tween1=Single | Variable | TweenNode2 | 0 | 1 | #ShortDelay#
Optional0=Easing InOutExpo
Optional1=Easing InOutExpo
UpdateDivider=1

[Shape]
Meter=Shape
X=(#SCREENAREAWIDTH#/2-(#Sec.Skew#+#Sec.W#)/2)
DynamicVariables=1
Shape=Path This | StrokeWidth 0 | Fill Color #MainCColor#,#MainCOpacity#
Shape2=Rectangle 0,(#SCREENAREAHEIGHT#*#TweenNode2#),(#Sec.W#+#Sec.Skew#),(#SCREENAREAHEIGHT#*#TweenNode1#) | StrokeWidth 0 | Fill Color 0,0,0
Shape3=Combine Shape | Intersect Shape2
This=#Sec.Skew#,0 | LineTo (#Sec.W#+#Sec.Skew#),0 | LineTo #Sec.W#,#SCREENAREAHEIGHT# | LineTo 0,#SCREENAREAHEIGHT#

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
FontSize=(50*#FontSizeModifier#)
X=(256/2)r
Y=(30)R
FontColor=#FontColor#,(255*#TweenNode1#*(1-#TweenNode2#))
FontFace=#GlobalFont#
Text=#Sec.Name#
AntiAlias=1
StringAlign=CenterTop
DynamicVariables=1
InlineSetting=Shadow | 0 | 0 | #Blur# | 255,255,255,150