[Variables]
TweenTime1=700
TweenTime2=0

Sec.Pad=10

[LoadActions]
Measure=String
UpdateDivider=-1
OnUpdateAction=[!FadeDuration 200][!Delay #TweenTime1#][!DeactivateConfig]

[MeasureLoop]
Measure=Loop
StartValue=0
EndValue=100
Increment=15
LoopCount=0
IfCondition=MeasureLoop >= 100
IfTrueAction=[!SetOption MeasureLoop InvertMeasure 1][!UpdateMeasure MeasureLoop]
IfCondition2=MeasureLoop <= 0
IfTrueAction2=[!SetOption MeasureLoop InvertMeasure 0][!UpdateMeasure MeasureLoop]

[Image]
MEter=Image
X=(#SCREENAREAWIDTH#/2-64/2)
Y=(#SCREENAREAHEIGHT#-64-#Sec.Pad#-[MeasureLoop]/100*20)
W=(64)
H=(64)
ImageAlpha=255
DynamicVariables=1
ImageName=#@#IconCache\#Sec.Icon#.png