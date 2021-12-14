[Variables]
Sec.W=(Clamp([String:W]+20,500,(#SCREENAREAWIDTH#-#Style.Skew#)))


[mTween]
Measure=Script
ScriptFile=#@#LuaTween/Main.lua
TweenGroup=Tweenable
Tween0=Single | Variable | TweenNode1 | 0 | 1 | #Style.Time1#
Tween1=Single | Variable | TweenNode2 | 0 | 1 | #Style.Time2#
Optional0=Easing InOutExpo
Optional1=Easing InOutExpo
UpdateDivider=1

[Shape]
Meter=Shape
X=(#SCREENAREAWIDTH#/2-(#Style.Skew#+#Sec.W#)/2)
DynamicVariables=1
Shape=Path This | StrokeWidth 0 | Fill Color #MainCColor#,#MainCOpacity#
Shape2=Rectangle 0,(#SCREENAREAHEIGHT#*#TweenNode2#),(#Sec.W#+#Style.Skew#),(#SCREENAREAHEIGHT#*#TweenNode1#) | StrokeWidth 0 | Fill Color 0,0,0
Shape3=Combine Shape | Intersect Shape2
This=#Style.Skew#,0 | LineTo (#Sec.W#+#Style.Skew#),0 | LineTo #Sec.W#,#SCREENAREAHEIGHT# | LineTo 0,#SCREENAREAHEIGHT#

[Image]
MEter=Image
X=(#SCREENAREAWIDTH#/2-256/2)
Y=(#SCREENAREAHEIGHT#/2-256/2)
W=(256)
H=(256)
ImageAlpha=(255*#TweenNode1#*(1-#TweenNode2#))
DynamicVariables=1
ImageName=#SKINSPATH#..\CoreData\Keylaunch\IconCache\#Sec.Icon#.png
Greyscale=#Greyscale#

[String]
Meter=String
FontSize=(#Style.FontSize#)
X=(256/2)r
Y=(30)R
FontColor=#FontColor#,(255*#TweenNode1#*(1-#TweenNode2#))
FontFace=#GlobalFont#
Text=#Sec.Name#
AntiAlias=1
StringAlign=CenterTop
DynamicVariables=1
InlineSetting=Shadow | 0 | 0 | #Blur# | #Glowcolor#,#GlowOpacity#