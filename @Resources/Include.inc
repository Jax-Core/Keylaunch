[Option1]
Meter=String
Text=#1Name#
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:1]
Meter=Shape
MeterStyle=Set.Div:S
[Option2]
Meter=String
Text=#2Name#
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:2]
Meter=Shape
MeterStyle=Set.Div:S
[Option3]
Meter=String
Text=#3Name#
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3]
Meter=Shape
MeterStyle=Set.Div:S
[Option4]
Meter=String
Text=#4Name#
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:4]
Meter=Shape
MeterStyle=Set.Div:S
[Option5]
Meter=String
Text=#5Name#
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:5]
Meter=Shape
MeterStyle=Set.Div:S
[Option6]
Meter=String
Text=#6Name#
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:6]
Meter=Shape
MeterStyle=Set.Div:S
[Option7]
Meter=String
Text=#7Name#
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:7]
Meter=Shape
MeterStyle=Set.Div:S
[Option8]
Meter=String
Text=#8Name#
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:8]
Meter=Shape
MeterStyle=Set.Div:S
[Option9]
Meter=String
Text=
MeterStyle=Set.String:S | Set.OptionName:S
[EditButton1]
Meter=Shape
MeterStyle=Set.Button:S
OverColor=0,255,50,200
LeaveColor=0,255,50,100
X=(#Set.W#-#Set.L#-#Set.P#*2-190*[Set.S])
Shape=Rectangle (160*[Set.S]),0,(30*[Set.S]),(30*[Set.S]),3,3 | StrokeWidth 0 | Extend Fill
Y=([Option1:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!CommandMeasure Script:M "Edit(0, 0, 1)"]
[EditIcon1]
Meter=String
FontFace=Segoe MDL2 Assets
X=(-15*[Set.S])R
Y=(-15*[Set.S])R
StringAlign=CenterCenter
Text=[\xE70F]
MeterStyle=Set.String:S | Set.Value:S
[ButtonString1]
Meter=Shape
MeterStyle=Set.Button:S
X=(#Set.W#-#Set.L#-#Set.P#*2-190*[Set.S])
Shape=Rectangle 0,0,150,30,3,3 | StrokeWidth 0 | Extend Fill | Scale [Set.S],[Set.S],0,0
Y=([Option1:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!ActivateConfig "#JaxCore\Accessories\Hotkey"][!SetVariable Sec.Num 1 "#JaxCore\Accessories\Hotkey"][!Move (#CURRENTCONFIGX#+#CURRENTCONFIGWIDTH#/2-500/2) (#CURRENTCONFIGY#+#CURRENTCONFIGHEIGHT#/2-500/2) "#JaxCore\Accessories\Hotkey"]
[Value1]
Meter=String
Text=#Key1InString#
MeterStyle=Set.String:S | Set.Value:S
[EditButton2]
Meter=Shape
MeterStyle=Set.Button:S
OverColor=0,255,50,200
LeaveColor=0,255,50,100
X=(#Set.W#-#Set.L#-#Set.P#*2-190*[Set.S])
Shape=Rectangle (160*[Set.S]),0,(30*[Set.S]),(30*[Set.S]),3,3 | StrokeWidth 0 | Extend Fill
Y=([Option2:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!CommandMeasure Script:M "Edit(0, 0, 2)"]
[EditIcon2]
Meter=String
FontFace=Segoe MDL2 Assets
X=(-15*[Set.S])R
Y=(-15*[Set.S])R
StringAlign=CenterCenter
Text=[\xE70F]
MeterStyle=Set.String:S | Set.Value:S
[ButtonString2]
Meter=Shape
MeterStyle=Set.Button:S
X=(#Set.W#-#Set.L#-#Set.P#*2-190*[Set.S])
Shape=Rectangle 0,0,150,30,3,3 | StrokeWidth 0 | Extend Fill | Scale [Set.S],[Set.S],0,0
Y=([Option2:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!ActivateConfig "#JaxCore\Accessories\Hotkey"][!SetVariable Sec.Num 2 "#JaxCore\Accessories\Hotkey"][!Move (#CURRENTCONFIGX#+#CURRENTCONFIGWIDTH#/2-500/2) (#CURRENTCONFIGY#+#CURRENTCONFIGHEIGHT#/2-500/2) "#JaxCore\Accessories\Hotkey"]
[Value2]
Meter=String
Text=#Key2InString#
MeterStyle=Set.String:S | Set.Value:S
[EditButton3]
Meter=Shape
MeterStyle=Set.Button:S
OverColor=0,255,50,200
LeaveColor=0,255,50,100
X=(#Set.W#-#Set.L#-#Set.P#*2-190*[Set.S])
Shape=Rectangle (160*[Set.S]),0,(30*[Set.S]),(30*[Set.S]),3,3 | StrokeWidth 0 | Extend Fill
Y=([Option3:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!CommandMeasure Script:M "Edit(0, 0, 3)"]
[EditIcon3]
Meter=String
FontFace=Segoe MDL2 Assets
X=(-15*[Set.S])R
Y=(-15*[Set.S])R
StringAlign=CenterCenter
Text=[\xE70F]
MeterStyle=Set.String:S | Set.Value:S
[ButtonString3]
Meter=Shape
MeterStyle=Set.Button:S
X=(#Set.W#-#Set.L#-#Set.P#*2-190*[Set.S])
Shape=Rectangle 0,0,150,30,3,3 | StrokeWidth 0 | Extend Fill | Scale [Set.S],[Set.S],0,0
Y=([Option3:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!ActivateConfig "#JaxCore\Accessories\Hotkey"][!SetVariable Sec.Num 3 "#JaxCore\Accessories\Hotkey"][!Move (#CURRENTCONFIGX#+#CURRENTCONFIGWIDTH#/2-500/2) (#CURRENTCONFIGY#+#CURRENTCONFIGHEIGHT#/2-500/2) "#JaxCore\Accessories\Hotkey"]
[Value3]
Meter=String
Text=#Key3InString#
MeterStyle=Set.String:S | Set.Value:S
[EditButton4]
Meter=Shape
MeterStyle=Set.Button:S
OverColor=0,255,50,200
LeaveColor=0,255,50,100
X=(#Set.W#-#Set.L#-#Set.P#*2-190*[Set.S])
Shape=Rectangle (160*[Set.S]),0,(30*[Set.S]),(30*[Set.S]),3,3 | StrokeWidth 0 | Extend Fill
Y=([Option4:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!CommandMeasure Script:M "Edit(0, 0, 4)"]
[EditIcon4]
Meter=String
FontFace=Segoe MDL2 Assets
X=(-15*[Set.S])R
Y=(-15*[Set.S])R
StringAlign=CenterCenter
Text=[\xE70F]
MeterStyle=Set.String:S | Set.Value:S
[ButtonString4]
Meter=Shape
MeterStyle=Set.Button:S
X=(#Set.W#-#Set.L#-#Set.P#*2-190*[Set.S])
Shape=Rectangle 0,0,150,30,3,3 | StrokeWidth 0 | Extend Fill | Scale [Set.S],[Set.S],0,0
Y=([Option4:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!ActivateConfig "#JaxCore\Accessories\Hotkey"][!SetVariable Sec.Num 4 "#JaxCore\Accessories\Hotkey"][!Move (#CURRENTCONFIGX#+#CURRENTCONFIGWIDTH#/2-500/2) (#CURRENTCONFIGY#+#CURRENTCONFIGHEIGHT#/2-500/2) "#JaxCore\Accessories\Hotkey"]
[Value4]
Meter=String
Text=#Key4InString#
MeterStyle=Set.String:S | Set.Value:S
[EditButton5]
Meter=Shape
MeterStyle=Set.Button:S
OverColor=0,255,50,200
LeaveColor=0,255,50,100
X=(#Set.W#-#Set.L#-#Set.P#*2-190*[Set.S])
Shape=Rectangle (160*[Set.S]),0,(30*[Set.S]),(30*[Set.S]),3,3 | StrokeWidth 0 | Extend Fill
Y=([Option5:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!CommandMeasure Script:M "Edit(0, 0, 5)"]
[EditIcon5]
Meter=String
FontFace=Segoe MDL2 Assets
X=(-15*[Set.S])R
Y=(-15*[Set.S])R
StringAlign=CenterCenter
Text=[\xE70F]
MeterStyle=Set.String:S | Set.Value:S
[ButtonString5]
Meter=Shape
MeterStyle=Set.Button:S
X=(#Set.W#-#Set.L#-#Set.P#*2-190*[Set.S])
Shape=Rectangle 0,0,150,30,3,3 | StrokeWidth 0 | Extend Fill | Scale [Set.S],[Set.S],0,0
Y=([Option5:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!ActivateConfig "#JaxCore\Accessories\Hotkey"][!SetVariable Sec.Num 5 "#JaxCore\Accessories\Hotkey"][!Move (#CURRENTCONFIGX#+#CURRENTCONFIGWIDTH#/2-500/2) (#CURRENTCONFIGY#+#CURRENTCONFIGHEIGHT#/2-500/2) "#JaxCore\Accessories\Hotkey"]
[Value5]
Meter=String
Text=#Key5InString#
MeterStyle=Set.String:S | Set.Value:S
[EditButton6]
Meter=Shape
MeterStyle=Set.Button:S
OverColor=0,255,50,200
LeaveColor=0,255,50,100
X=(#Set.W#-#Set.L#-#Set.P#*2-190*[Set.S])
Shape=Rectangle (160*[Set.S]),0,(30*[Set.S]),(30*[Set.S]),3,3 | StrokeWidth 0 | Extend Fill
Y=([Option6:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!CommandMeasure Script:M "Edit(0, 0, 6)"]
[EditIcon6]
Meter=String
FontFace=Segoe MDL2 Assets
X=(-15*[Set.S])R
Y=(-15*[Set.S])R
StringAlign=CenterCenter
Text=[\xE70F]
MeterStyle=Set.String:S | Set.Value:S
[ButtonString6]
Meter=Shape
MeterStyle=Set.Button:S
X=(#Set.W#-#Set.L#-#Set.P#*2-190*[Set.S])
Shape=Rectangle 0,0,150,30,3,3 | StrokeWidth 0 | Extend Fill | Scale [Set.S],[Set.S],0,0
Y=([Option6:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!ActivateConfig "#JaxCore\Accessories\Hotkey"][!SetVariable Sec.Num 6 "#JaxCore\Accessories\Hotkey"][!Move (#CURRENTCONFIGX#+#CURRENTCONFIGWIDTH#/2-500/2) (#CURRENTCONFIGY#+#CURRENTCONFIGHEIGHT#/2-500/2) "#JaxCore\Accessories\Hotkey"]
[Value6]
Meter=String
Text=#Key6InString#
MeterStyle=Set.String:S | Set.Value:S
[EditButton7]
Meter=Shape
MeterStyle=Set.Button:S
OverColor=0,255,50,200
LeaveColor=0,255,50,100
X=(#Set.W#-#Set.L#-#Set.P#*2-190*[Set.S])
Shape=Rectangle (160*[Set.S]),0,(30*[Set.S]),(30*[Set.S]),3,3 | StrokeWidth 0 | Extend Fill
Y=([Option7:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!CommandMeasure Script:M "Edit(0, 0, 7)"]
[EditIcon7]
Meter=String
FontFace=Segoe MDL2 Assets
X=(-15*[Set.S])R
Y=(-15*[Set.S])R
StringAlign=CenterCenter
Text=[\xE70F]
MeterStyle=Set.String:S | Set.Value:S
[ButtonString7]
Meter=Shape
MeterStyle=Set.Button:S
X=(#Set.W#-#Set.L#-#Set.P#*2-190*[Set.S])
Shape=Rectangle 0,0,150,30,3,3 | StrokeWidth 0 | Extend Fill | Scale [Set.S],[Set.S],0,0
Y=([Option7:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!ActivateConfig "#JaxCore\Accessories\Hotkey"][!SetVariable Sec.Num 7 "#JaxCore\Accessories\Hotkey"][!Move (#CURRENTCONFIGX#+#CURRENTCONFIGWIDTH#/2-500/2) (#CURRENTCONFIGY#+#CURRENTCONFIGHEIGHT#/2-500/2) "#JaxCore\Accessories\Hotkey"]
[Value7]
Meter=String
Text=#Key7InString#
MeterStyle=Set.String:S | Set.Value:S
[EditButton8]
Meter=Shape
MeterStyle=Set.Button:S
OverColor=0,255,50,200
LeaveColor=0,255,50,100
X=(#Set.W#-#Set.L#-#Set.P#*2-190*[Set.S])
Shape=Rectangle (160*[Set.S]),0,(30*[Set.S]),(30*[Set.S]),3,3 | StrokeWidth 0 | Extend Fill
Y=([Option8:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!CommandMeasure Script:M "Edit(0, 0, 8)"]
[EditIcon8]
Meter=String
FontFace=Segoe MDL2 Assets
X=(-15*[Set.S])R
Y=(-15*[Set.S])R
StringAlign=CenterCenter
Text=[\xE70F]
MeterStyle=Set.String:S | Set.Value:S
[ButtonString8]
Meter=Shape
MeterStyle=Set.Button:S
X=(#Set.W#-#Set.L#-#Set.P#*2-190*[Set.S])
Shape=Rectangle 0,0,150,30,3,3 | StrokeWidth 0 | Extend Fill | Scale [Set.S],[Set.S],0,0
Y=([Option8:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!ActivateConfig "#JaxCore\Accessories\Hotkey"][!SetVariable Sec.Num 8 "#JaxCore\Accessories\Hotkey"][!Move (#CURRENTCONFIGX#+#CURRENTCONFIGWIDTH#/2-500/2) (#CURRENTCONFIGY#+#CURRENTCONFIGHEIGHT#/2-500/2) "#JaxCore\Accessories\Hotkey"]
[Value8]
Meter=String
Text=#Key8InString#
MeterStyle=Set.String:S | Set.Value:S
[Button9]
Meter=Shape
MeterStyle=Set.Button:S
OverColor=0,255,50,150
LeaveColor=0,255,50,100
Y=([Option9:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!CommandMeasure Script:M "Add()"]
[Value9]
Meter=String
Text=Add an action
StringAlign=CenterCenter
X=(150*[Set.S]/2)r
MeterStyle=Set.String:S | Set.Value:S
[Button10]
Meter=Shape
X=(-235*[Set.S])r
MeterStyle=Set.Button:S
OverColor=255,0,50,150
LeaveColor=255,0,50,100
Y=([Option9:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!CommandMeasure Script:M "Remove()"]
[Value10]
Meter=String
Text=Remove an action
StringAlign=CenterCenter
X=(150*[Set.S]/2)r
MeterStyle=Set.String:S | Set.Value:S
