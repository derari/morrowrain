
[calcFrameWidth]
Measure=Calc
Formula=((#FrameWidth#-[frameCaption:W]-16) < 300 ? 0 : 1)
Group=Frame
DynamicVariables=1
UpdateDivider=-1
OnUpdateAction=[!UpdateMeterGroup Frame][!Redraw]

[frameNW]
Meter=Image
ImageName=#@#Images\frame_nw.png
Group=Frame
UpdateDivider=-1

[frameW]
Meter=Image
ImageName=#@#Images\frame_w.png
Y=29
H=(#CURRENTCONFIGHEIGHT#-29-8)
Tile=1
Group=Frame
DynamicVariables=1
UpdateDivider=-1

[frameSW]
Meter=Image
ImageName=#@#Images\frame_sw.png
Y=(#CURRENTCONFIGHEIGHT#-8)
Group=Frame
DynamicVariables=1
UpdateDivider=-1

[frameS]
Meter=Image
ImageName=#@#Images\frame_s.png
X=8
Y=(#CURRENTCONFIGHEIGHT#-8)
W=(#FrameWidth#-8-8)
Tile=1
Group=Frame
DynamicVariables=1
UpdateDivider=-1

[frameSE]
Meter=Image
ImageName=#@#Images\frame_se.png
X=(#FrameWidth#-8)
Y=(#CURRENTCONFIGHEIGHT#-8)
Group=Frame
DynamicVariables=1
UpdateDivider=-1

[frameE]
Meter=Image
ImageName=#@#Images\frame_e.png
X=(#FrameWidth#-8)
Y=29
H=(#CURRENTCONFIGHEIGHT#-29-8)
Tile=1
Group=Frame
DynamicVariables=1
UpdateDivider=-1

[frameNE]
Meter=Image
ImageName=#@#Images\frame_ne.png
X=(#FrameWidth#-8)
Group=Frame
DynamicVariables=1
UpdateDivider=-1

[frameN]
Meter=Image
ImageName=#@#Images\frame_n.png
X=8
W=(#FrameWidth#-8-8)
Tile=1
Group=Frame
DynamicVariables=1
UpdateDivider=-1

[frameCaptionLeft]
Meter=Image
MeasureName=calcFrameWidth
ImageName=#@#Images\frame_caption_%1.png
X=6
Y=4
W=([frameCaption:X]-6)
Tile=1
Group=Frame|Caption
DynamicVariables=1
UpdateDivider=-1

[frameCaptionRight]
Meter=Image
MeasureName=calcFrameWidth
ImageName=#@#Images\frame_caption_%1.png
X=([frameCaption:X]+[frameCaption:W])
Y=4
W=([frameCaption:X]-6)
Tile=1
Group=Frame|Caption
DynamicVariables=1
UpdateDivider=-1

[frameCaptionBG]
Meter=Image
ImageName=#@#Images\caption_bg.png
Y=4
X=([frameCaption:X])
W=([frameCaption:W])
H=20
ScaleMargins=2,2,3,3
Group=Frame|Caption
DynamicVariables=1
UpdateDivider=-1

[frameCaption]
Meter=String
FontColor=#textColor2#
FontFace=#fontName#
FontSize=12
AntiAlias=1
StringAlign=Center
ClipString=0
FontSize=12
Padding=10,0,10,0
X=(#FrameWidth#/2)
Y=6
Text=
Group=Frame|Caption
DynamicVariables=1
UpdateDivider=-1

[frameButtonClose]
Meter=Image
ImageName=#@#Images\button_close.png
X=(#FrameWidth#-18-4)
Y=4
LeftMouseUpAction=[!DeactivateConfig]
Group=Frame
DynamicVariables=1
UpdateDivider=-1