[Variables]
TweenTime1=(1250*#AniSpeedModifier#)
TweenTime2=(450*#AniSpeedModifier#)


[mTween]
Measure=Script
ScriptFile=#@#LuaTween/Main.lua
TweenGroup=Tweenable
Tween0=Single | Variable | TweenNode1 | 0 | 1 | #TweenTime1#
Tween1=Single | Variable | TweenNode2 | 0 | 1 | #TweenTime2#
Optional0=Easing InOutExpo
Optional1=Easing InOutExpo
UpdateDivider=1




[Image2]
MEter=Image
X=(#SCREENAREAWIDTH#/2-300*#TweenNode1#/2-[String:W]/2)
Y=(#SCREENAREAHEIGHT#/2-300*#TweenNode1#/2)
W=(300*#TweenNode1#)
H=(300*#TweenNode1#)
ImageAlpha=(50*(1-#TweenNode2#))
DynamicVariables=1
TransformationMatrix=(Cos(Rad(#TweenNode1#*360)));(-Sin(Rad(#TweenNode1#*360)));(Sin(Rad(#TweenNode1#*360)));(Cos(Rad(#TweenNode1#*360)));(([#CURRENTSECTION#:W]*0.5+[#CURRENTSECTION#:X])-([#CURRENTSECTION#:W]*0.5+[#CURRENTSECTION#:X])*Cos(Rad(#TweenNode1#*360))-([#CURRENTSECTION#:H]*0.5+[#CURRENTSECTION#:Y])*Sin(Rad(#TweenNode1#*360)));(([#CURRENTSECTION#:H]*0.5+[#CURRENTSECTION#:Y])+([#CURRENTSECTION#:W]*0.5+[#CURRENTSECTION#:X])*Sin(Rad(#TweenNode1#*360))-([#CURRENTSECTION#:H]*0.5+[#CURRENTSECTION#:Y])*Cos(Rad(#TweenNode1#*360)))
ImageName=#@#IconCache\#Sec.Icon#.png

[Image]
MEter=Image
X=(#SCREENAREAWIDTH#/2-256*#TweenNode1#/2-[String:W]/2)
Y=(#SCREENAREAHEIGHT#/2-256*#TweenNode1#/2)
W=(256*#TweenNode1#)
H=(256*#TweenNode1#)
ImageAlpha=(255*(1-#TweenNode2#))
DynamicVariables=1
TransformationMatrix=(Cos(Rad(#TweenNode1#*360)));(-Sin(Rad(#TweenNode1#*360)));(Sin(Rad(#TweenNode1#*360)));(Cos(Rad(#TweenNode1#*360)));(([#CURRENTSECTION#:W]*0.5+[#CURRENTSECTION#:X])-([#CURRENTSECTION#:W]*0.5+[#CURRENTSECTION#:X])*Cos(Rad(#TweenNode1#*360))-([#CURRENTSECTION#:H]*0.5+[#CURRENTSECTION#:Y])*Sin(Rad(#TweenNode1#*360)));(([#CURRENTSECTION#:H]*0.5+[#CURRENTSECTION#:Y])+([#CURRENTSECTION#:W]*0.5+[#CURRENTSECTION#:X])*Sin(Rad(#TweenNode1#*360))-([#CURRENTSECTION#:H]*0.5+[#CURRENTSECTION#:Y])*Cos(Rad(#TweenNode1#*360)))
ImageName=#@#IconCache\#Sec.Icon#.png


[String]
Meter=String
FontSize=(50*#FontSizeModifier#)
X=(256+#CircSize#-128+10-300*(1-#TweenNode1#))r
Y=(#SCREENAREAHEIGHT#/2)
FontColor=#FontColor#,(255*(#TweenNode1#-0.5)/0.5-255*#TweenNode2#)
FontFace=#GlobalFont#
Text=#Sec.Name#
AntiAlias=1
StringAlign=LeftCenter
DynamicVariables=1
InlineSetting=Shadow | 0 | 0 | #Blur# | #Glowcolor#,#GlowOpacity#