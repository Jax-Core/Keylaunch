[mTween]
Measure=Script
ScriptFile=#@#LuaTween/Main.lua
TweenGroup=Tweenable
Tween0=Single | Variable | TweenNode1 | 0 | 1 | #Style.Time1#
Tween1=Single | Variable | TweenNode2 | 0 | 1 | #Style.Time2#
Optional0=Easing InOutExpo
Optional1=Easing InOutExpo
UpdateDivider=1

; [Fader]
; MEter=String
; W=#SCREENAREAWIDTH#
; H=#SCREENAREAHEIGHT#
; SolidColor=#MainCColor#,(#MainCOpacity#*(#TweenNode1#-0.5)/0.5-#MainCOpacity#*#TweenNode2#)
; DynamicVariables=1

[Image]
MEter=Image
X=(#SCREENAREAWIDTH#/2-350*#TweenNode1#/2)
Y=(#SCREENAREAHEIGHT#/2-350*#TweenNode1#/2)
W=(350*#TweenNode1#)
H=(350*#TweenNode1#)
ImageAlpha=(50*(#TweenNode1#))
DynamicVariables=1
ImageName=#SKINSPATH#..\CoreData\Keylaunch\IconCache\#Sec.Icon#.png
Greyscale=#Greyscale#

[String]
Meter=String
FontSize=(#Style.FontSize#)
X=(#SCREENAREAWIDTH#/2-#Style.CharacterSpacing#/2*#TweenNode1#)
Y=(#SCREENAREAHEIGHT#/2)
FontColor=#FontColor#,(255*(#TweenNode1#))
FontFace=#GlobalFont#
Text=#Sec.Name#
AntiAlias=1
StringAlign=CenterCenter
DynamicVariables=1
InlineSetting=Shadow | 0 | 0 | #Blur# | #Glowcolor#,#GlowOpacity#
InlineSetting2=CharacterSpacing | (#TweenNode1#*#Style.CharacterSpacing#)