[LoadActions]
ActionList1=Start0 | Wait #Style.Time1# | Start1 | Wait #Style.Time1# | Deactivate
ActionList3=Wait #Style.Time1# | Action

[mTween]
Measure=Script
ScriptFile=#@#LuaTween/Main.lua
TweenGroup=Tweenable
Tween0=Single | Variable | TweenNode1 | 0 | 1 | #Style.Time1#
Tween1=Single | Variable | TweenNode1 | 1 | 0 | #Style.Time1#
Optional0=Easing InOutExpo
Optional1=Easing InOutExpo
UpdateDivider=1

[Shape]
Meter=Shape
X=(#SCREENAREAWIDTH#/2-([String:W]+32+#Style.Pad#*2)/2)
Y=(#SCREENAREAHEIGHT#-60*#TweenNode1#-60*#TweenNode2#)
DynamicVariables=1
Shape=Rectangle 0,0,([String:W]+32+#Style.Pad#*2),50,10 | StrokeWidth 0 | Fill Color #MainCColor#,(#MainCOpacity#-#MainCOpacity#*#TweenNode2#)

[Image]
MEter=Image
X=(#Style.Pad#)r
Y=(50/2-32/2)r
W=(32)
H=(32)
ImageAlpha=(255*(1-#TweenNode2#))
DynamicVariables=1
ImageName=#SKINSPATH#..\CoreData\Keylaunch\IconCache\#Sec.Icon#.png
Greyscale=#Greyscale#

[String]
Meter=String
FontSize=(#Style.FontSize#)
X=5R
Y=(32/2)r
FontColor=#FontColor#,(255*(1-#TweenNode2#))
FontFace=#GlobalFont#
Text=#Sec.Name#
AntiAlias=1
StringAlign=LeftCenter
DynamicVariables=1
InlineSetting=Shadow | 0 | 0 | #Blur# | 255,255,255,150